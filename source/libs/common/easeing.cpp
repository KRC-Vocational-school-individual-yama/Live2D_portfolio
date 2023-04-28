#include "easeing.h"
#include<DxLib.h>
#include<cmath>

float EASEING::easeInOutSine(float x){
	return -(cos(DX_PI_F * x) - 1.f) / 2.f;
}
float EASEING::easeInOutQuad(float x){
	return x < 0.5f ? 2.f * x * x : 1.f - pow(-2 * x + 2.f, 2.f) / 2.f;
}
float EASEING::easeInOutCubic(float x){
	return x < 0.5f ? 4.f * x * x * x : 1.f - pow(-2.f * x + 2.f, 3.f) / 2.f;
}
float EASEING::easeInOutQuart(float x){
	return x < 0.5f ? 8.f * x * x * x * x : 1.f - pow(-2.f * x + 2.f, 4.f) / 2.f;
}
float EASEING::easeInOutQuint(float x){
	return x < 0.5f ? 16.f * x * x * x * x * x : 1.f - pow(-2.f * x + 2.f, 5.f) / 2.f;
}
float EASEING::easeInOutExpo(float x){
	return static_cast<int>(x) == 0
		? 0
		: static_cast<int>(x) == 1
		? 1
		: x < 0.5f ? pow(2.f, 20.f * x - 10.f) / 2.f
		: (2.f - pow(2.f, -20.f * x + 10.f)) / 2.f;
}
float EASEING::easeInOutCirc(float x){
	return x < 0.5f
		? (1.f - sqrt(1.f - pow(2.f * x, 2.f))) / 2.f
		: (sqrt(1.f - pow(-2.f * x + 2.f, 2.f)) + 1.f) / 2.f;
}
float EASEING::easeInOutBack(float x){
	float c1 = 1.70158f;
	float c2 = c1 * 1.525f;

	return x < 0.5f
		? (pow(2.f * x, 2.f) * ((c2 + 1.f) * 2.f * x - c2)) / 2.f
		: (pow(2.f * x - 2.f, 2.f) * ((c2 + 1.f) * (x * 2.f - 2.f) + c2) + 2.f) / 2.f;

}
float EASEING::easeInOutElastic(float x){
	float c5 = (2.f * DX_PI_F) / 4.5f;

	return static_cast<int>(x) == 0
		? 0
		: static_cast<int>(x) == 1
		? 1
		: x < 0.5f
		? -(pow(2.f, 20.f * x - 10.f) * sin((20.f * x - 11.125f) * c5)) / 2.f
		: (pow(2.f, -20.f * x + 10.f) * sin((20.f * x - 11.125f) * c5)) / 2.f + 1.f;
}
float EASEING::easeOutBounce(float x){
	float n1 = 7.5625f;
	float d1 = 2.75f;

	if (x < 1.f / d1) {
		return n1 * x * x;
	}
	else if (x < 2.f / d1) {
		return n1 * (x -= 1.5f / d1) * x + 0.75f;
	}
	else if (x < 2.5f / d1) {
		return n1 * (x -= 2.25f / d1) * x + 0.9375f;
	}
	else {
		return n1 * (x -= 2.625f / d1) * x + 0.984375f;
	}
}
float EASEING::easeInOutBounce(float x){
	return x < 0.5f
		? (1.f - easeOutBounce(1.f - 2.f * x)) / 2.f
		: (1.f + easeOutBounce(2.f * x - 1.f)) / 2.f;
}

float EASEING::EInOutSine(int x){
	return 100.f*easeInOutSine(static_cast<float>(x)/100.0f);
}
float EASEING::EInOutQuad(int x){
	return 100.f * easeInOutQuad(static_cast<float>(x) / 100.0f);
}
float EASEING::EInOutCubic(int x){
	return 100.f * easeInOutCubic(static_cast<float>(x) / 100.0f);
}
float EASEING::EInOutQuart(int x){
	return 100.f * easeInOutQuart(static_cast<float>(x) / 100.0f);
}
float EASEING::EInOutQuint(int x){
	return 100.f * easeInOutQuint(static_cast<float>(x) / 100.0f);
}
float EASEING::EInOutExpo(int x){
	return 100.f * easeInOutExpo(static_cast<float>(x) / 100.0f);
}
float EASEING::EInOutCirc(int x){
	return 100.f * easeInOutCirc(static_cast<float>(x) / 100.0f);
}
float EASEING::EInOutBack(int x){
	return 100.f * easeInOutBack(static_cast<float>(x) / 100.0f);
}
float EASEING::EInOutElastic(int x){
	return 100.f * easeInOutElastic(static_cast<float>(x) / 100.0f);
}
float EASEING::EInOutBounce(int x){
	return 100.f * easeInOutBounce(static_cast<float>(x) / 100.0f);
}
