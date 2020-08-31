#include <napi.h>
#include "blade_function.h"

#pragma comment(lib, "bladelib.lib")
#pragma  comment(lib, "opencv_world430.lib")

// 定义一个返回类型为 Napi String 的 blade_addon 函数, 注意此处的 info
//  传入图像父路径， 返回结果为图像名称的处理结果字符串
Napi::String Blade_addon_parent(const Napi::CallbackInfo& info) {
	Napi::Env env = info.Env();

	std::string imgsParent = info[0].As<Napi::String>();

	std::string result = blade_function_parent(imgsParent);

	return Napi::String::New(env, result);
}

//  传入字符串格式的图像绝对路径， 返回结果为图像绝对路径的处理结果字符串
Napi::String Blade_addon_filestr(const Napi::CallbackInfo& info)
{
	Napi::Env env = info.Env();

	std::string imgfilesStr = info[0].As<Napi::String>();
	std::string result = blade_function_filestr(imgfilesStr);

	return Napi::String::New(env, result);
}

// 测试：输入输出均为字符串格式
Napi::String Test_string(const Napi::CallbackInfo& info)
{
	Napi::Env env = info.Env();

	std::string inString = info[0].As<Napi::String>();
	std::string result = test_demo_string(inString);

	return Napi::String::New(env, result);
}

// 测试：输入输出均为double
Napi::Number Test_number(const Napi::CallbackInfo& info)
{
	Napi::Env env = info.Env();

	double inInt = info[0].As<Napi::Number>();
	double result = test_demo_int(inInt);

	return Napi::Number::New(env, result);
}

// 设置类似于 exports = {key:value}的模块导出
Napi::Object Init(Napi::Env env, Napi::Object exports) {
	exports.Set(
		Napi::String::New(env, "blade_addon_parent"),
		Napi::Function::New(env, Blade_addon_parent)
	);

	exports.Set(
		Napi::String::New(env, "blade_addon_filestr"),
		Napi::Function::New(env, Blade_addon_filestr)
	);

	exports.Set(
		Napi::String::New(env, "test_string"),
		Napi::Function::New(env, Test_string)
	);

	exports.Set(
		Napi::String::New(env, "test_number"),
		Napi::Function::New(env, Test_number)
	);

	return exports;
}


NODE_API_MODULE(addon, Init)
