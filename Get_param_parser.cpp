// SIMPLE REQUEST
// http://192.168.1.46/?&PAR01=255&PAR02=200|

// TEST STRING: GET /?&PAR01=255&PAR02=200

#include <Arduino.h>
#include "Get_params_parser.h"

Get_params_parser::Get_params_parser(String paramString){
 Serial.print(F(" PARAM STRING : "));
 Serial.println(paramString);

 int endPosition = paramString.indexOf('|');
 int maxIndex = paramString.length();

 String stri = paramString.substring(0, endPosition);

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

String Get_params_parser::getParamValue(String param) {
  for(int i=0; i<=10; i++) {
    // Serial.println(F(" ---------------- ----------- -----------"));
    // Serial.print(F(" WILL CHECK PAIR: "));
    // Serial.println(stArray[i]);
    // Serial.print(F(" OF PARAM: "));
    // Serial.println(param);

    int startPosition = stArray[i].indexOf("=") + 1;
    int stopPosition = stArray[i].length();

    int positionOfParam = stArray[i].indexOf(param);

    // Serial.print(F(" Start: "));
    // Serial.println(startPosition);
    // Serial.print(F(" End: "));
    // Serial.println(stopPosition);
    // Serial.print(F(" Position of param: "));
    // Serial.println(positionOfParam);

    if (positionOfParam > -1) {

      // Serial.print(F(" FOUND @: "));
      // Serial.println(stArray[i].indexOf(param));
      // Serial.print(F(" GOT IN PAIR: "));
      // Serial.println(stArray[i]);

      String strrr = stArray[i].substring(startPosition, stopPosition);

      // Serial.print(F(" KEY: "));
      // Serial.println(param);
      // Serial.print(F(" VALUE: "));
      // Serial.println(strrr);
      // Serial.println(F(" ---------------- "));

      // delay(1500);

      return strrr;
    }

    // Serial.println(F(" ---------------- ----------- -----------"));

  }
}
