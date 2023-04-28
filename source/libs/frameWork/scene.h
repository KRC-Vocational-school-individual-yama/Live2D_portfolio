#pragma once
#include<list>
#include<string>

class Object;

class Scene {
public:
	Scene()					;
	virtual ~Scene()		;
	virtual void Update()	;
	virtual void Draw()		;

	/// <summary>
	/// オブジェクトの生成
	/// <para>リストに追加し
	/// アドレスを返す</para>
	/// </summary>
	/// <returns></returns>
	template<class C>
	C* Create() {
		C* tempObject= new C(this);
		ObjectParam node;
		node.object = tempObject;
		objectList.emplace_back(node);
		rankChange = true;
		return tempObject;
	}

	template<class C>
	C* Create(std::string name) {
		C* tempObject = new C(this);
		ObjectParam node;
		node.object = tempObject;
		node.name = name;
		objectList.emplace_back(node);
		rankChange = true;
		return tempObject;
	}

	/// <summary>
	/// <para>オブジェクトの呼び出し</para>
	/// <para>同じクラスを上から1つ取ってくる</para>
	/// </summary>
	/// <returns></returns>
	template<class C>
	C* Invoke();


	//名前と上から1つ呼び出し
	template<class C>
	C* Invoke(std::string name);

	//複数呼び出し
	template<class C>
	std::list<C*> Invokes();

	//名前とクラス指定　呼び出し
	template<class C>
	std::list<C*> Invokes(std::string name);

	//名前から複数呼び出し
	std::list<Object*> Invokes(std::string name);

	/// <summary>
	/// <para>オブジェクトの破棄</para>
	/// <para>同じクラスを上から1つ消す</para>
	/// </summary>
	/// <typeparam name="C"></typeparam>
	template<class C>
	void Destroy();

	/// <summary>
	/// <para>オブジェクトの破棄</para>
	/// <para>同じクラスを上から1つ消す</para>
	/// </summary>
	/// <param name="object"></param>
	void Destroy(Object* object);

	/// <summary>
	/// 全てのオブジェクト更新停止
	/// </summary>
	void AllUpdateStop();

	/// <summary>
	/// 全てのオブジェクト更新開始
	/// </summary>
	void AllUpdateStart();

	/// <summary>
	/// 描画優先順位変更 昇順
	/// </summary>
	/// <param name="obj  ">変更したいオブジェクト</param>
	/// <param name="rank">優先度</param>
	void Scene::ChangeDispRank(Object* obj, int rank);

private:
	struct ObjectParam {
		bool wantInit;//初期化
		int dispRank;//draw優先順位
		std::string name;//所属名
		Object* object;//オブジェクト

		ObjectParam()
			:wantInit(true)
			,object(nullptr)
			,dispRank(100)
			,name{""}
		{}
	};

	void AllDestroy();//全てのオブジェクトを削除
	void DestroyDrawObject(Object* object);//描画オブジェクト破棄
	static bool DispSort(const ObjectParam& rank1, const ObjectParam& rank2);//入れ替え

	std::list<ObjectParam>objectList;//オブジェクト記録用
	std::list<ObjectParam>objectDrawList;//オブジェクト描画用
	bool rankChange;//描画変更予約

};

template<class C>
inline C* Scene::Invoke() {
	for (ObjectParam node : objectList) {
		C* object = dynamic_cast<C*>(node.object);
		if (object != nullptr)
			return object;
	}
	return nullptr;
}

template<class C>
inline C* Scene::Invoke(std::string name) {
	for (ObjectParam& node : objectList) {
		C* object = dynamic_cast<C*>(node.object);
		if (object == nullptr)
			continue;
		if (node.name != name)
			continue;
		return object;
	}
	return nullptr;
}

template<class C>
inline std::list<C*> Scene::Invokes() {
	std::list<C*> list;
	for (auto& m : objectList) {
		C* object = dynamic_cast<C*>(m.object);
		if (object != nullptr)
			list.emplace_back(object);
	}
	return list;
}


template<class C>
std::list<C*> Scene::Invokes(std::string name) {
	std::list<C*>list;
	for (auto& m : objectList) {
		C* object = dynamic_cast<C*>(m.object);

		if (object == nullptr)
			continue;
		if (m.name != name)
			continue;

		list.emplace_back(object);
	}
	return list;
}

template<class C>
inline void Scene::Destroy() {
	for (auto it = objectList.begin(); it != objectList.end(); ) {
		C* object = dynamic_cast<C*>((*it).object);
		if (object != nullptr) {
			delete object;
			object = nullptr;

			it = objectList.erase(it);
			return;
		}
		else {
			++it;
		}
	}
}
