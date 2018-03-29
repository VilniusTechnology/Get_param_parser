// SIMPLE REQUEST
// http://192.168.1.46/?&PAR01=255&PAR02=200|

// TEST STRING: GET /?&PAR01=255&PAR02=200

#include <Arduino.h>
#include "Get_params_parser.h"

Get_params_parser::Get_params_parser(String paramString){
 int maxIndex = paramString.length();

 // vut till get end
 int startPosition = paramString.indexOf('|');
 String stri = paramString.substring(0, startPosition);

  int cutFrom = 0;
  int found = 0;
  
  for(int ii=0; ii<=maxIndex; ii++){ 
    if(stri.charAt(ii) == '&' || ii == maxIndex){

      String strrr = stri.substring(cutFrom, ii);
      strrr.trim();
      strrr.replace("&", "");
      stArray[found] = strrr;

      // Serial.print(F("ONE PAIR RESULTS: "));
      // Serial.println(found);
      // Serial.println(stArray[found]);
      // Serial.println(F(" .......................... "));
      
      cutFrom = ii;
      found++;
    }
  } 
}


void Get_params_parser::parseGetParams(String stuff) {

    // Serial.println(stuff);
  
    int startPosition = stuff.indexOf('GET /');

    // Serial.println(startPosition);
    
    if (startPosition > 0) {
      // String strrr = stuff;

      // Serial.println(F("---- parseGetParams STRRRR ---- "));
      // Serial.println(stuff);
      // Serial.println(F("---- ----- ----- ----"));
      // delay(3000);
      
      // if (stuff.length() < 400) {
        parseParamString(stuff);
      // }
    }
}

void Get_params_parser::parseParamString(String data) {
  String tokensString = data.substring(7);
  tokensString.trim();
  

Serial.print(F("WILL WORK ON PARAMS STRING: "));
    Serial.println(tokensString);
    Serial.println(F("..... ..... ..... ....."));

  if(tokensString.length() > 1) {

    

    getParamsValues(tokensString);

    // Serial.println(F(".....     DONE    ....."));
  }
  
}

void Get_params_parser::getParamsValues(String data) {
  int found = 0;
  int queuNo = 0;
  int resultsCounter = 0;
  int maxIndex = data.length();

  char resultsTmp[10];
  char resultsPair[2];

  getParamsPairs(data);

  // TODO: Delete
  // String rs= getParamValue("PAR01");
  // Serial.println(F(" ::::::::::::::::::::::::: "));
  // Serial.println(rs);
}

void Get_params_parser::getParamsPairs(String data) {
  int maxIndex = data.length();

  int cutFrom = 0;
  int found = 0;
  
  for(int ii=0; ii<=maxIndex; ii++){ 
    if(data.charAt(ii) == '&' || ii == maxIndex){

      String strrr = data.substring(cutFrom, ii);
      strrr.trim();
      strrr.replace("&", "");
      stArray[found] = strrr;

      // Serial.print(F("ONE PAIR RESULTS: "));
      // Serial.println(found);
      // Serial.println(stArray[found]);
      // Serial.println(F(" .......................... "));
      
      cutFrom = ii;
      found++;
    }
  } 
}

String Get_params_parser::getParamValue(String param) {
  for(int i=0; i<=10; i++) {

      // Serial.print(F(" WILL CHECK PAIR: "));
      // Serial.println(stArray[i]);
      // Serial.print(F(" DBG: "));
      // Serial.println(stArray[i].indexOf(param));

    if (stArray[i].indexOf(param) > -1) {

      // Serial.print(F(" FOUND @: "));
      // Serial.println(stArray[i].indexOf(param));
      // Serial.print(F(" GOT IN PAIR: "));
      // Serial.println(stArray[i]);

      String strrr = stArray[i].substring(6);

      Serial.print(F(" KEY: "));
      Serial.println(param);
      Serial.print(F(" VALUE: "));
      Serial.println(strrr);
      Serial.println(F(" ---------------- "));

      // delay(1500);

      return strrr;

    }
    
  }
}

                                                                                                                