//
//  test_window.cpp
//  Window
//
//  Created by 恶龙咆哮 on 2020/3/1.
//  Copyright © 2020 秦伟钦. All rights reserved.
//

#include "test_window.hpp"
int main()
{
    SDL_Window *window;
    int result=SDL_Init(SDL_INIT_VIDEO);
    if(result!=0)
    {
        SDL_Log("unable to initialize SDL :%s",SDL_GetError());
        return 1;
    }
    window= SDL_CreateWindow("testwindow", 100, 100, 1024, 768, 0);
    if(!window)
    {
        SDL_Log("failed to create window: %s",SDL_GetError);
        return 1;
    }
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
    
}
