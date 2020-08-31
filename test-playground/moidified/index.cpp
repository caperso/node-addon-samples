#include <napi.h>
#include "blade_function.h"

// 测试：输入输出均为字符串格式
Napi::String Test_string(const Napi::CallbackInfo& info)
{
	Napi::Env env = info.Env();

	std::string inString = info[0].As<Napi::String>();
	std::string result = test_demo_string(inString);

	return Napi::String::New(env, result);
}

// 设置类似于 exports = {key:value}的模块导出
Napi::Object Init(Napi::Env env, Napi::Object exports) {
	exports.Set(
		Napi::String::New(env, "test_string"),
		Napi::Function::New(env, Test_string)
	);

	return exports;
}


NODE_API_MODULE(addon, Init)
