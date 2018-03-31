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
};
#endif
