//
//  Page5.hpp
//  HelloCocos
//
//  Created by 枡岡真里 on 2016/03/04.
//
//

#ifndef Page5_hpp
#define Page5_hpp

#include <stdio.h>


#include "cocos2d.h"



class Page5 :public cocos2d::Layer
{
public:
    
    
    static cocos2d::Scene* createScene();
    
    Page5();
    virtual ~Page5();
    
    bool init() override;
    
    CREATE_FUNC(Page5);
    
    
};

#endif /* Page5_hpp */
