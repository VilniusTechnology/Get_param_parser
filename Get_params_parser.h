#ifndef Get_params_parser_h
#define Get_params_parser_h
 
#include <Arduino.h>
 
class Get_params_parser
{
	public:
	 	Get_params_parser(String paramString);  //Constructor.
	 	String getParamValue(String param);
	private:
		 String stArray[10];
		 void parseGetParams(String stuff);
		 void parseParamString(String data);
		 void getParamsValues(String data);
		 void getParamsPairs(String data);
};
#endif