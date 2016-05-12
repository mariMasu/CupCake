//
//  Page3.hpp
//  HelloCocos
//
//  Created by 枡岡真里 on 2016/03/04.
//
//

#ifndef Page3_hpp
#define Page3_hpp

#include <stdio.h>

#include "cocos2d.h"



class Page3 :public cocos2d::Layer
{
public:
    
    int _tapNum = 0;

    
    static cocos2d::Scene* createScene();
    
    Page3();
    virtual ~Page3();
    
    bool init() override;
    
    CREATE_FUNC(Page3);
    
    
};

#endif /* Page3_hpp */
