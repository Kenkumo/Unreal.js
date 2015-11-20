#pragma once

struct FIsolateHelper
{
	v8::Isolate* isolate_;

	FIsolateHelper(v8::Isolate* isolate)
		: isolate_(isolate)
	{}

	FORCEINLINE v8::Local<v8::String> Keyword(const FString& String)
	{
		return V8_KeywordString(isolate_, String);
	}

	FORCEINLINE v8::Local<v8::String> Keyword(const char* String)
	{
		return V8_KeywordString(isolate_, String);
	}

	FORCEINLINE v8::Local<v8::String> String(const FString& InString)
	{
		return V8_String(isolate_, InString);
	}

	FORCEINLINE v8::Local<v8::String> String(const char* InString)
	{
		return V8_String(isolate_, InString);
	}

	FORCEINLINE v8::Local<External> External(void* Data)
	{
		return External::New(isolate_, Data);
	}

	FORCEINLINE v8::Local<v8::FunctionTemplate> FunctionTemplate()
	{
		return FunctionTemplate::New(isolate_);
	}

	FORCEINLINE v8::Local<v8::FunctionTemplate> FunctionTemplate(FunctionCallback Callback)
	{
		return FunctionTemplate::New(isolate_, Callback);
	}

	FORCEINLINE v8::Local<v8::FunctionTemplate> FunctionTemplate(FunctionCallback Callback, void* Data)
	{
		return FunctionTemplate::New(isolate_, Callback, External(Data));
	}

	void Throw(const FString& InString)
	{
		isolate_->ThrowException(v8::Exception::Error(String(InString)));
	}
};