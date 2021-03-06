#include "pch.h"
#include "MainMenuScene.h"
#include "MainMenuView.h"
#include "VisibleRect.h"
#include "GameDelegate.h"

//------------------------------------------------------------------//
MainMenuScene::MainMenuScene(): m_pMainMenu(NULL)
{

}

MainMenuScene::~MainMenuScene()
{

}

void MainMenuScene::onEnter()
{
    GameSceneBase::onEnter();

}

bool MainMenuScene::init(bool fromGame)
{
    if (GameSceneBase::init())
    {
        m_pMainMenu = new MainMenuView();
        m_pMainMenu->init(fromGame);

        if (fromGame)
        {
            m_pMainMenu->getStartButton()->setTarget(this, menu_selector(MainMenuScene::startCallback));
        }
        else
        {
            m_pMainMenu->getStartButton()->setTarget(this, menu_selector(MainMenuScene::startCallback));
        }

        addChild(m_pMainMenu);
        m_pMainMenu->release();

        return true;
    }

    return false;
}

void MainMenuScene::startCallback(CCObject * pSender)
{
    GameDelegate::sharedGameDelegate()->startGame();
}


void MainMenuScene::returnCallback( CCObject * pSender )
{
    GameDelegate::sharedGameDelegate()->returnToGame();
}
