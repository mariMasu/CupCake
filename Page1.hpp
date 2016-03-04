//
//  Page1.hpp
//  HelloCocos
//
//  Created by 枡岡真里 on 2016/02/28.
//
//

#ifndef Page1_hpp
#define Page1_hpp

#include <stdio.h>

#include "cocos2d.h"



class Page1 :public cocos2d::Layer
{
    
    
    
public:
    
    
    static cocos2d::Scene* createScene();
    
    Page1();
    virtual ~Page1();
    
    bool init() override;
    
    CREATE_FUNC(Page1);
    
    
};

#endif /* Page1_hpp */
