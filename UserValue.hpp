//
//  UserValue.hpp
//  ECEDatabase
//
//  Created by rick gessner on 4/21/18.
//  Copyright © 2018 rick gessner. All rights reserved.
//

#ifndef UserValue_hpp
#define UserValue_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include "Keywords.hpp"
#include "Token.hpp"

namespace SF {
  
  class Block;
  
  struct UserValue {
    TokenType   type; //general type from parser
    Keywords    datatype; //specific type from attribute...
    
    std::string value; //for datetime or varchars...
    union {
      int32_t   anInteger;
      uint32_t  aDateTime;
      float     aFloat;
    };
    
    UserValue();
    UserValue(std::string &aValue, TokenType aType);
    UserValue(Keywords aKeyword);
    UserValue(Token &aToken);
    UserValue(const UserValue &aCopy);
    
    StatusResult  become(Keywords aDatatype);
    StatusResult  becomeInteger();
    StatusResult  becomeFloat();
    StatusResult  becomeDateTime();
    StatusResult  becomeVarchar();

  };
  
    //for holding a collection of key/values...
  typedef std::pair<std::string, UserValue> KeyValuePair;
  typedef std::vector<KeyValuePair > KeyValueList;

  class KeyValues {
  protected:
    KeyValueList keyValues;    
  public:
            KeyValues();
    bool    addKeyValue(std::string &aKey, UserValue &aValue);
            operator KeyValueList() {return keyValues;}
  };

}
#endif /* UserValue_hpp */
