//
//  Page2.hpp
//  HelloCocos
//
//  Created by 枡岡真里 on 2016/03/03.
//
//

#ifndef Page2_hpp
#define Page2_hpp

#include <stdio.h>

#include "cocos2d.h"



class Page2 :public cocos2d::Layer
{
public:
    
    int _tapNum = 0;
    
    static cocos2d::Scene* createScene();
    
    Page2();
    virtual ~Page2();
    
    bool init() override;
    
    CREATE_FUNC(Page2);
    
    
};

#endif /* Page2_hpp */
