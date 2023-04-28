#pragma once
namespace color{
		//h0`360
		//s0`255
		//v0`255
	int inline GetHSV(int h, int s, int v) {

		float hr = (float)h, sg = (float)s, vb = (float)v;
		float r = 0.f, g = 0.f, b = 0.f;
		float max = 0.f, min = 0.f;
		max = vb;
		min = vb - ((sg / 255) * vb);

		float num[6];
		num[0] = hr / 60;
		num[1] = (120 - hr) / 60;
		num[2] = (hr - 120) / 60;
		num[3] = (240 - hr) / 60;
		num[4] = (hr - 240) / 60;
		num[5] = (360 - hr) / 60;
		float mid = max - min;
		bool flag[6];
		flag[0] = hr >= 0 && hr < 60;
		flag[1] = hr >= 60 && hr < 120;
		flag[2] = hr >= 120 && hr < 180;
		flag[3] = hr >= 180 && hr < 240;
		flag[4] = hr >= 240 && hr < 300;
		flag[5] = hr >= 300 && hr <= 360;
		for (int i = 0; i < 6; i++) {
			if (!flag[i])continue;
			switch (i) {
			case 0:
				r = max;
				g = num[i] * mid + min;
				b = min;
				break;
			case 1:
				r = num[i] * mid + min;
				g = max;
				b = min;
				break;
			case 2:
				r = min;
				g = max;
				b = num[i] * mid + min;
				break;
			case 3:
				r = min;
				g = num[i] * mid + min;
				b = max;
				break;
			case 4:
				r = num[i] * mid + min;
				g = min;
				b = max;
				break;
			case 5:
				r = max;
				g = min;
				b = num[i] * mid + min;
				break;
			default:
				break;
			}
		}

		int color = ((int)r << 16) + ((int)g << 8) + (int)b;
		return color;
	}
}
