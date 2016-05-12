//
//  Page4.hpp
//  HelloCocos
//
//  Created by 枡岡真里 on 2016/03/04.
//
//

#ifndef Page4_hpp
#define Page4_hpp

#include <stdio.h>

#include "cocos2d.h"



class Page4 :public cocos2d::Layer
{
public:
    
    int _tapNum = 0;
    
    static cocos2d::Scene* createScene();
    
    Page4();
    virtual ~Page4();
    
    bool init() override;
    
    CREATE_FUNC(Page4);
    
    
};

#endif /* Page4_hpp */
