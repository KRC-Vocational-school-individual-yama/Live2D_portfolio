#pragma once

#include"myDxLib.h"

#include<string>
#include<list>
class Scene;
class Component;

class Object {
public:
	Object(Scene* sc);
	virtual ~Object();
	virtual void Init()		;
	virtual void Update()	;
	virtual void Draw()		;


	/// <summary>
	/// 所属シーン取得
	/// </summary>
	/// <returns></returns>
	Scene* GetScene()			{ return myScene	;}



	/// <summary>
	/// コンポーネントの生成
	/// <para>リストに追加し
	/// アドレスを返す</para>
	/// </summary>
	/// <returns></returns>
	template<class C>
	C* Create() {
		C* sendCom = new C(this);
		ComponentParam send;
		send.myComponent = sendCom;

		comPonentList.emplace_back(send);
		return sendCom;
	}
	/// <summary>
	/// コンポーネントの生成
	/// <para>リストに追加し
	/// アドレスを返す</para>
	/// </summary>
	/// <returns></returns>
	template<class C>
	C* Create(std::string name) {
		C* sendCom = new C(this);
		ComponentParam send;
		send.myComponent = sendCom;
		send.name = name;

		comPonentList.emplace_back(send);
		return sendCom;
	}


	/// <summary>
	/// <para>コンポーネントの呼び出し</para>
	/// <para>同じクラスを上から1つ取ってくる</para>
	/// </summary>
	/// <returns></returns>
	template<class C>
	C* Invoke() {
		for (auto& aCom : comPonentList) {
			C* send =  dynamic_cast<C*>(aCom.myComponent);
			if (!send)
				continue;

			return send;
		}

		return nullptr;
	}

	/// <summary>
	/// <para>コンポーネントの破棄</para>
	/// <para>同じクラスを上から1つ消す</para>
	/// </summary>
	/// <typeparam name="C"></typeparam>
	template<class C>
	void Destroy() {
		for (auto it = comPonentList.begin(); it != comPonentList.end();) {
			C* aCom = (*it);

			if (aCom) {
				delete aCom;
				it = comPonentList.erase(it);
			}
			else {
				it++;
			}

		}
	}

	void SetComponent(Component* setComponent);

	/// <summary>
	/// 破棄フラグ　ゲッター
	/// </summary>
	/// <returns></returns>
	const bool GetDestroy()		{ return myDestroy	;}

	/// <summary>
	/// 更新停止フラグ　ゲッター
	/// </summary>
	/// <returns></returns>
	const bool GetStopUpdate() { return myStopUpdate; }

	/// <summary>
	/// 破棄フラグ　セッター
	/// </summary>
	/// <param name="_flag"></param>
	void MyDestroy()			{ myDestroy = true	;}

	/// <summary>
	/// 更新停止フラグ　セッター
	/// </summary>
	/// <param name="true	">stop</param>
	/// <param name="false	">start</param>
	/// <returns></returns>
	void SetMyUpdate(bool flag = false) { myStopUpdate = flag; }

private:
	struct ComponentParam{
		Component* myComponent;
		std::string name;
		bool wantInit;

		ComponentParam()
			:myComponent(nullptr)
			,wantInit{true}
			,name("")
		{}
	};

	Scene* myScene		;//所属シーン
	bool myDestroy		;//破棄フラグ
	bool myStopUpdate	;//更新停止フラグ true：停止
	std::list<ComponentParam>comPonentList;
	//std::list<Component*>comPonentList;
};
