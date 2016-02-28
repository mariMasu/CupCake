//
//  CupcakeTitle.hpp
//  HelloCocos
//
//  Created by 枡岡真里 on 2016/02/28.
//
//

#ifndef CupcakeTitle_hpp
#define CupcakeTitle_hpp

#include <stdio.h>


#include "cocos2d.h"

class CupcakeTitle : public cocos2d::Layer
{

public:
    CupcakeTitle();
    
    virtual ~CupcakeTitle();
    
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    
    // implement the "static create()" method manually
    
    CREATE_FUNC(CupcakeTitle);
};


#endif /* CupcakeTitle_hpp */
