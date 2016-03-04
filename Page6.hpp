//
//  Page6.hpp
//  HelloCocos
//
//  Created by 枡岡真里 on 2016/03/04.
//
//

#ifndef Page6_hpp
#define Page6_hpp

#include <stdio.h>
#include "cocos2d.h"



class Page6 :public cocos2d::Layer
{
public:
    
    
    static cocos2d::Scene* createScene();
    
    Page6();
    virtual ~Page6();
    
    bool init() override;
    
    CREATE_FUNC(Page6);
    
    
};
#endif /* Page6_hpp */
