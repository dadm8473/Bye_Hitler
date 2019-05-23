#include "DXUT.h"
#include "Header.h"

CGameScene::CGameScene(int stage) :
	CScene(), playerBulletList(), enemyBulletList(), enemyList(), enemyEntryInfo(), timer(0),
	effectList(), boss(NULL), sboss(NULL), playerLife(5), rebirthTimer(0), rebirthTime(2), useCA(false), clearAttackCount(3),
	victory(false), victoryTimer(0), victoryTime(1.5f), isAddon(false), itemList(), itemCount(0), clearAttackEffectTimer(0), clearAttackEffectTime(0.5f),
	isCA(false), map(NULL), stageChange(false), stageChangeTime(1), stageChangeTimer(0)
{
	player = new CPlayer(D3DXVECTOR2(384, 700));
	player->parentScene = this; 

	this->stage = stage;

	for (int i = 0; i < 3; i++)
		addon[i] = NULL;

	map = new CMap(stage);

	for (int i = 0; i < 6; i++)
	{
		scoreNumUI[i] = CMatrix();
		scoreNumUI[i].position.x = 500 + (40 * i);
		scoreNumUI[i].position.y = 950;

		scoreNumUI[i].scale.x = 0.7f;
		scoreNumUI[i].scale.y = 0.7f;
	}

	for (int i = 0; i < 5; i++)
	{
		playerLifeUI[i] = CMatrix();
		playerLifeUI[i].position.x = 32 + (40 * i);
		playerLifeUI[i].position.y = 900;

		playerLifeUI[i].scale.x = 0.25f;
		playerLifeUI[i].scale.y = 0.25f;
	}

	for (int i = 0; i < 10; i++)
	{
		clearAttackUI[i] = CMatrix();
		clearAttackUI[i].position.x = 32 + (50 * i);
		clearAttackUI[i].position.y = 930;

		clearAttackUI[i].scale.x = 0.7f;
	}

	bossHpBG = CMatrix();
	bossHpBG.center = D3DXVECTOR2(262, 32);
	bossHpBG.position = D3DXVECTOR2(384, 32);
	bossHpBG.a = 190;

	bossHpValue = CMatrix();
	bossHpValue.center = D3DXVECTOR2(262, 32);
	bossHpValue.position = D3DXVECTOR2(390, 32);
	bossHpValue.a = 190;


	if (stage == 0)
	{
		enemyEntryInfo.push_back(EnemyEntryInfo(D3DXVECTOR2(384, -64),	3, 0));
		enemyEntryInfo.push_back(EnemyEntryInfo(D3DXVECTOR2(20, -64),	3.5f, 1));
		enemyEntryInfo.push_back(EnemyEntryInfo(D3DXVECTOR2(748, -64),	3.5f, 2));

		for (int i = 0; i < 4; i++)
		{
			enemyEntryInfo.push_back(EnemyEntryInfo(D3DXVECTOR2(20, -64), 6.5f+(i*0.5f), 1));
		}

		for (int i = 0; i < 4; i++)
		{
			enemyEntryInfo.push_back(EnemyEntryInfo(D3DXVECTOR2(748, -64), 11.5f + (i*0.5f), 2));
		}

		for (int i = 0; i < 8; i++)
		{
			enemyEntryInfo.push_back(EnemyEntryInfo(D3DXVECTOR2(100, -64), 17 + (i*0.2f), 0));
			enemyEntryInfo.push_back(EnemyEntryInfo(D3DXVECTOR2(668, -64), 17 + (i*0.2f), 0));
		}

		for (int i = 0; i < 4; i++)
		{
			enemyEntryInfo.push_back(EnemyEntryInfo(D3DXVECTOR2(20, -64), 23 + (i*0.5f), 1));
		}

		for (int i = 0; i < 4; i++)
		{
			enemyEntryInfo.push_back(EnemyEntryInfo(D3DXVECTOR2(748, -64), 28 + (i*0.5f), 2));
		}

		for (int i = 0; i < 8; i++)
		{
			enemyEntryInfo.push_back(EnemyEntryInfo(D3DXVECTOR2(100, -64), 35+(i*0.2f), 0));
			enemyEntryInfo.push_back(EnemyEntryInfo(D3DXVECTOR2(668, -64), 35+(i*0.2f), 0));
		}

		enemyEntryInfo.push_back(EnemyEntryInfo(D3DXVECTOR2(384, -64), 40.5f, 3));
		
		enemyEntryInfo.push_back(EnemyEntryInfo(D3DXVECTOR2(200, -64), 45.5f, 3));

		enemyEntryInfo.push_back(EnemyEntryInfo(D3DXVECTOR2(568, -64), 45.5f, 3));

		for (int i = 0; i < 3; i++)
		{
			enemyEntryInfo.push_back(EnemyEntryInfo(D3DXVECTOR2(1, 700), 51 + (i*0.7f), 1));
		}

		for (int i = 0; i < 3; i++)
		{
			enemyEntryInfo.push_back(EnemyEntryInfo(D3DXVECTOR2(767, 700), 51 + (i*0.7f), 2));
		}

		enemyEntryInfo.push_back(EnemyEntryInfo(D3DXVECTOR2(50, -64), 56, -1));
	}

	if (stage == 1)
	{
		gAssetManager->GetSoundAsset("BGM_Boss")->Stop();
		gAssetManager->GetSoundAsset("BGM_Stage2")->Play();

		for (int i = 0; i < 6; i++)
		{
			enemyEntryInfo.push_back(EnemyEntryInfo(D3DXVECTOR2(20, -64), 3 + (i*0.5f), 1));
		}

		enemyEntryInfo.push_back(EnemyEntryInfo(D3DXVECTOR2(100, -64), 9, 0));
		enemyEntryInfo.push_back(EnemyEntryInfo(D3DXVECTOR2(150, -64), 9, 0));
		enemyEntryInfo.push_back(EnemyEntryInfo(D3DXVECTOR2(200, -64), 9, 0));

		for (int i = 0; i < 6; i++)
		{
			enemyEntryInfo.push_back(EnemyEntryInfo(D3DXVECTOR2(20, -64), 10.5f + (i*0.5f), 1));
		}

		for (int i = 0; i < 6; i++)
		{
			enemyEntryInfo.push_back(EnemyEntryInfo(D3DXVECTOR2(748, -64), 14.5f + (i*0.5f), 2));
		}

		enemyEntryInfo.push_back(EnemyEntryInfo(D3DXVECTOR2(668, -64), 19.5f, 0));
		enemyEntryInfo.push_back(EnemyEntryInfo(D3DXVECTOR2(618, -64), 19.5f, 0));
		enemyEntryInfo.push_back(EnemyEntryInfo(D3DXVECTOR2(568, -64), 19.5f, 0));

		for (int i = 0; i < 6; i++)
		{
			enemyEntryInfo.push_back(EnemyEntryInfo(D3DXVECTOR2(748, -64), 21.5f + (i*0.5f), 2));
		}

		enemyEntryInfo.push_back(EnemyEntryInfo(D3DXVECTOR2(384, -64), 26.5f, 3));

		for (int i = 0; i < 8; i++)
		{
			enemyEntryInfo.push_back(EnemyEntryInfo(D3DXVECTOR2(38+(i*100), -64), 29, 0));
		}

		enemyEntryInfo.push_back(EnemyEntryInfo(D3DXVECTOR2(200, -64), 32.5f, 3));
		enemyEntryInfo.push_back(EnemyEntryInfo(D3DXVECTOR2(584, -64), 32.5f, 3));

		enemyEntryInfo.push_back(EnemyEntryInfo(D3DXVECTOR2(200, -64), 35, 0));
		enemyEntryInfo.push_back(EnemyEntryInfo(D3DXVECTOR2(584, -64), 35, 0));

		enemyEntryInfo.push_back(EnemyEntryInfo(D3DXVECTOR2(1, -64), 37.5f, 1));
		enemyEntryInfo.push_back(EnemyEntryInfo(D3DXVECTOR2(767, -64), 37.5f, 2));

		enemyEntryInfo.push_back(EnemyEntryInfo(D3DXVECTOR2(200, -64), 43.5f, 3));
		enemyEntryInfo.push_back(EnemyEntryInfo(D3DXVECTOR2(584, -64), 43.5f, 3));

		enemyEntryInfo.push_back(EnemyEntryInfo(D3DXVECTOR2(200, -64), 46, 0));
		enemyEntryInfo.push_back(EnemyEntryInfo(D3DXVECTOR2(584, -64), 46, 0));

		enemyEntryInfo.push_back(EnemyEntryInfo(D3DXVECTOR2(1, -64), 48.5f, 1));
		enemyEntryInfo.push_back(EnemyEntryInfo(D3DXVECTOR2(767, -64), 48.5f, 2));

		for (int i = 0; i < 8; i++)
		{
			enemyEntryInfo.push_back(EnemyEntryInfo(D3DXVECTOR2(100, -64), 51 + (i*0.2f), 0));
			enemyEntryInfo.push_back(EnemyEntryInfo(D3DXVECTOR2(668, -64), 51 + (i*0.2f), 0));
		}

		enemyEntryInfo.push_back(EnemyEntryInfo(D3DXVECTOR2(50, -64), 59, -2));

	}
}

CGameScene::~CGameScene()
{
	// �÷��̾�
	if (player)
		delete player;
	if (map)
		delete map;
	// �÷��̾� �Ѿ�
	for (list<CBullet*>::iterator it = playerBulletList.begin(); it != playerBulletList.end(); ++it)
	{
		if (*it)
			delete(*it);
	}
	// ��
	for (list<CEnemy*>::iterator it = enemyList.begin(); it != enemyList.end(); ++it)
	{
		if (*it)
			delete(*it);
	}
	// �� �Ѿ�
	for (list<CBullet*>::iterator it = enemyBulletList.begin(); it != enemyBulletList.end(); ++it)
	{
		if (*it)
			delete(*it);
	}
	// ����Ʈ
	for (list<CEffect*>::iterator it = effectList.begin(); it != effectList.end(); ++it)
	{
		if (*it)
			delete(*it);
	}
	// ������
	for (list<CItem*>::iterator it = itemList.begin(); it != itemList.end(); ++it)
	{
		if (*it)
			delete(*it);
	}
	// �÷��̾� �Ѿ�
	playerBulletList.clear();
}

void CGameScene::Update(float deltaTime)
{
	CScene::Update(deltaTime);



	if (player)
	{
		type = attackType;
	}
	else
	{
		attackType = 0;
	}

	// �������� �ٲٱ�
	if (stageChange == true)
	{
		stageChangeTimer += deltaTime;
		if (stageChangeTimer >= stageChangeTime)
		{
			stageChangeTimer = 0;
			CGameScene::~CGameScene();
			ChangeScene("Stage2");
		}
	}

	if (stage == 0)
	{
		gAssetManager->GetSoundAsset("BGM_Stage1")->Play();
	}
	else if (stage == 1)
	{
		gAssetManager->GetSoundAsset("BGM_Stage2")->Play();
	}

	// ���� ����� �� ��ũ�Ѱ� deltaTime ����
	if (!boss && !sboss)
	{
		map->Update(deltaTime);
		timer += deltaTime;
	}

	// �浹 üũ
	// �� - �÷��̾� �Ѿ�
	for (list<CBullet*>::iterator it = playerBulletList.begin(); it != playerBulletList.end(); ++it)
	{
		// ����
		if (boss)
		{
			RECT ref;
			if (IntersectRect(&ref, &(*it)->rect, &boss->rect))
			{
				score += 20;

				(*it)->isDestroyed = true;

				effectList.push_back(
					new CEffect((*it)->position, gAssetManager->explodeTexture, 40, 0.03f, 2, 2));

				// ���� ������ ����
				boss->hp -= (*it)->damage;
				if (boss->hp <= 0)
				{
					boss->hp = 0;
					boss->isDie = true;
				}
			}
		}

		// �߰� ����
		if (sboss)
		{
			RECT ref;
			if (IntersectRect(&ref, &(*it)->rect, &sboss->rect))
			{
				score += 20;

				(*it)->isDestroyed = true;

				effectList.push_back(
					new CEffect((*it)->position, gAssetManager->explodeTexture, 40, 0.03f, 2, 2));

				sboss->hp -= (*it)->damage;
				if (sboss->hp <= 0)
				{
					sboss->hp = 0;
					sboss->isDie = true;
				}
			}
		}

		// ��
		for (list<CEnemy*>::iterator it2 = enemyList.begin(); it2 != enemyList.end(); ++it2)
		{
			RECT ref;
			if (IntersectRect(&ref, &(*it)->rect, &(*it2)->rect))
			{
				(*it)->isDestroyed = true;

				//�� ������ ����
				if (!(*it2)->beHit)
				{
					(*it2)->beHit = true;
					(*it2)->hitRedTimer = 0;
				}

				(*it2)->hp -= (*it)->damage;
				if ((*it2)->hp <= 0)
				{
					(*it2)->isDie = true;

					itemCount++;

					if ((*it2)->type == 0)
					{
						score += 100;
						if (itemCount % 15 == 0)
							itemList.push_back(new CItem((*it2)->position, 0));
					}
					else if ((*it2)->type == 1)
					{
						score += 150;
						if (itemCount % 15 == 0)
							itemList.push_back(new CItem((*it2)->position, 0));
					}
					else if ((*it2)->type == 2)
					{
						score += 200;
						if (itemCount % 15 == 0)
							itemList.push_back(new CItem((*it2)->position, 0));
					}
					else if ((*it2)->type == 3)
					{
						score += 250;
						if (itemCount % 10 == 0)
							itemList.push_back(new CItem((*it2)->position, 1));
					}
				}
			}
		}
	}

	//������
	for (list<CItem*>::iterator it = itemList.begin(); it != itemList.end(); it++)
	{
		if (player)
		{
			RECT ref;

			if (IntersectRect(&ref, &player->rect, &(*it)->rect))
			{
				if ((*it)->type == 0)
				{
					if (attackType == 2)
					{
						if (isAddon == false)
						{
							addonSave = true;
							isAddon = true;
						}
					}
					else if (attackType < 2)
						attackType++;
					
					(*it)->isDie = true;
				}
				else if ((*it)->type == 1)
				{
					if(clearAttackCount<3)
						clearAttackCount++;
					(*it)->isDie = true;
				}
			}
		}
	}

	// ���Ѿ� - �÷��̾�
	for (list<CBullet*>::iterator it = enemyBulletList.begin(); it != enemyBulletList.end(); ++it)
	{
		if (player)
		{
			RECT ref;
			if (IntersectRect(&ref, &player->rect, &(*it)->rect) && (!player->isInvincible && !player->invincible))
			{
				player->isDie = true;
				(*it)->isDestroyed = true;
			}
		}
	}
	// �� - �÷��̾�
	for (list<CEnemy*>::iterator it = enemyList.begin(); it != enemyList.end(); ++it)
	{
		if (player)
		{
			RECT  ref;
			if (IntersectRect(&ref, &player->rect, &(*it)->rect) && (!player->isInvincible && !player->invincible))
			{
				player->isDie = true;
				(*it)->isDie = true;
			}
		}
	}
	// �� ���� ������ ���� �ð��� ���� ���� ��ȯ

	for (int i = 0; i < enemyEntryInfo.size(); i++)
	{
		if (!enemyEntryInfo[i].summoned)
		{
			if (timer >= enemyEntryInfo[i].time)
			{
				// ���� ��ȯ
				if (enemyEntryInfo[i].type == -2)
				{
					boss = new CBoss(D3DXVECTOR2(512, -256));
					boss->parentScene = this;
					gAssetManager->GetSoundAsset("BGM_Stage2")->Stop();
					gAssetManager->GetSoundAsset("BGM_Boss")->Play();

					enemyEntryInfo[i].summoned = true;
				}
				// �߰� ���� ��ȯ
				else if (enemyEntryInfo[i].type == -1)
				{
					sboss = new CsBoss(D3DXVECTOR2(337, 256));
					sboss->parentScene = this;
					gAssetManager->GetSoundAsset("BGM_Stage1")->Stop();
					gAssetManager->GetSoundAsset("BGM_Boss")->Play();

					enemyEntryInfo[i].summoned = true;
				}
				else
					// �� ��ȯ
				{
					CEnemy*enemy = new CEnemy(enemyEntryInfo[i].position, enemyEntryInfo[i].type);
					enemy->parentScene = this;

					enemyList.push_back(enemy);
					enemyEntryInfo[i].summoned = true;
				}
			}
		}
	}

	if (player)
	{
		// �÷��̾� ����
		if (GetKeyState(VK_LEFT) & 0x0800)
			player->position.x -= 400 * deltaTime;
		if (GetKeyState(VK_RIGHT) & 0x0800)
			player->position.x += 400 * deltaTime;
		if (GetKeyState(VK_UP) & 0x0800)
			player->position.y -= 400 * deltaTime;
		if (GetKeyState(VK_DOWN) & 0x0800)
			player->position.y += 400 * deltaTime;

		if (GetKeyState('X') & 0x0800)
		{
			player->Attack();
			// �ֵ�� ����
			if (addon[0])
				for (int i = 0; i < 3; i++)
					if (i == 0 || i == 2)
						addon[i]->Attack();
		}

		player->Update(deltaTime);
		// �ֵ�� ������Ʈ
		if (addon[0])
		{
			for (int i = 0; i < 3; i++)
			{
				if (i == 0 || i == 2)
				{
					if (GetKeyState(VK_LEFT) & 0x0800)
						addon[i]->position.x -= 400 * deltaTime;
					if (GetKeyState(VK_RIGHT) & 0x0800)
						addon[i]->position.x += 400 * deltaTime;
					if (GetKeyState(VK_UP) & 0x0800)
						addon[i]->position.y -= 400 * deltaTime;
					if (GetKeyState(VK_DOWN) & 0x0800)
						addon[i]->position.y += 400 * deltaTime;

					addon[i]->Update(deltaTime);
					addon[i]->parentScene = this;
				}
			}
		}
		// �÷��̾� ���
		if (player->isDie)
		{
			effectList.push_back(new CEffect(player->position, gAssetManager->explodeTexture, 40, 0.05f, 2, 2));

			effectList.push_back(new CEffect(player->position, gAssetManager->playerDieTexture, 40, 0.03f, 1, 1));

			gAssetManager->GetSoundAsset("isDie")->Play();

			// �ֵ�� ���
			addonSave = false;

			for (int i = 0; i < 3; i++)
				if (i == 0 || i == 2)
					addon[i] = NULL;

			attackType = 0;

			player = NULL;
		}
		// �ֵ�� ���̺�
		if (addonSave == true && !addon[0])
		{
			if (player)
			{
				for (int i = 0; i < 3; i++)
				{
					if (i == 0 || i == 2)
						addon[i] = new CAddon(player->position - D3DXVECTOR2(70 - 70 * i, -70));
				}

				addonSave == true;

				isAddon = false;
			}

		}
	}
		else
		{
			// �÷��̾� ��Ȱ
			rebirthTimer += deltaTime;
			if (rebirthTimer >= rebirthTime)
			{
				rebirthTimer = 0;
				if (--playerLife >= 0)
				{
					player = new CPlayer(D3DXVECTOR2(384, 700));
					player->parentScene = this;
				}
				else
				{
					// ���� �й�
					ChangeScene("Ending_GameOver");
					return;
				}
			}
		}

		// ������
		for (list<CItem*>::iterator it = itemList.begin(); it != itemList.end();)
		{
			(*it)->Update(deltaTime);
	
			if ((*it)->isDie)
			{
				delete(*it);
				it = itemList.erase(it);
			}
			else
				++it;
		}

		// ��
		for (list<CEnemy*>::iterator it = enemyList.begin(); it != enemyList.end();)
		{
			(*it)->parentScene = this;
			(*it)->Update(deltaTime);

			// ���� ��ǥ �޾ƿ��� - ����ź
			if (player && !(*it)->isDie)
				player->SetEnemyPos((*it));
			else if (player)
				player->SetEnemyPos(NULL);

			// �� ����
			if ((*it)->isDie)
			{
				effectList.push_back(new CEffect((*it)->position, gAssetManager->explodeTexture, 40, 0.03f, 2, 2));

				gAssetManager->GetSoundAsset("isDie")->Play();


				if((*it)->type == 0)
					effectList.push_back(new CEffect((*it)->position, gAssetManager->enemy1DieTexture, 40, 0.03f, 1, 1));
				else if ((*it)->type == 1 || 2)
					effectList.push_back(new CEffect((*it)->position, gAssetManager->enemy1DieTexture, 40, 0.03f, 1, 1));
				else if ((*it)->type == 3)
					effectList.push_back(new CEffect((*it)->position, gAssetManager->enemy1DieTexture, 40, 0.03f, 1, 1));
			}
			if ((*it)->isDestroyed || (*it)->isDie)
			{
				delete(*it);
				it = enemyList.erase(it);
			}
			else
				++it;
		}
		// ����
		if (boss)
		{
			boss->Update(deltaTime);

			if (player && !(boss)->isDie)
				player->SetBossPos(boss);
			else if (player)
				player->SetBossPos(NULL);


			if (boss->isDie)
			{
				delete boss;
				boss = NULL;

				for (list<CBullet*>::iterator it = enemyBulletList.begin(); it != enemyBulletList.end(); ++it)
				{
					if ((*it)->position.y > -50)
					{
						(*it)->isDestroyed = true;
					}
				}

				gAssetManager->GetSoundAsset("isDie")->Play();

				victory = true;
			}
		}
		// �߰� ����
		if (sboss)
		{
			sboss->Update(deltaTime);

			if (player && !(sboss)->isDie)
				player->SetsBossPos(sboss);
			else if (player)
				player->SetsBossPos(NULL);


			if (sboss->isDie)
			{
				delete sboss;
				sboss = NULL;

				for (list<CBullet*>::iterator it = enemyBulletList.begin(); it != enemyBulletList.end(); ++it)
				{
					if ((*it)->position.y > -50)
					{
						(*it)->isDestroyed = true;
					}
				}
				gAssetManager->GetSoundAsset("isDie")->Play();

				ChangeScene("Stage2");
			}
		}

		// �¸�
		if (victory)
		{
			victoryTimer += deltaTime;
			if (victoryTimer > victoryTime)
			{
				gAssetManager->GetSoundAsset("BGM_Boss")->Stop();
				ChangeScene("Ending_Victory");
				return;
			}
		}

		// �� �Ѿ�
		for (list<CBullet*>::iterator it = enemyBulletList.begin(); it != enemyBulletList.end(); )
		{
			(*it)->Update(deltaTime);

			if ((*it)->isDestroyed)
			{
				delete(*it);
				it = enemyBulletList.erase(it);
			}
			else
				++it;
		}
		// �÷��̾� �Ѿ�
		for (list<CBullet*>::iterator it = playerBulletList.begin(); it != playerBulletList.end();)
		{
			(*it)->Update(deltaTime);

			if ((*it)->isDestroyed)
			{
				delete(*it);
				it = playerBulletList.erase(it++);
			}
			else
				++it;
		}
		// ����Ʈ
		for (list<CEffect*>::iterator it = effectList.begin(); it != effectList.end();)
		{
			(*it)->Update(deltaTime);

			if ((*it)->isAniEnd)
			{
				delete(*it);
				it = effectList.erase(it);
			}
			else
				++it;
		}
		// Clear Attack
		if (useCA)
		{
			clearAttack->Update(deltaTime);
			clearAttackEffectTimer += deltaTime;

			if (clearAttackEffectTimer > clearAttackEffectTime)
			{
				isCA = true;
				clearAttackEffectTimer = 0;
			}
			if (isCA)
			{
				// CA ����Ʈ
				effectList.push_back(new CEffect(D3DXVECTOR2(384, 512), gAssetManager->clearAttackeffectTexture, 40, 0.01f, 2, 2));
				// �� ����Ʈ �ʱ�ȭ
				for (list<CEnemy*>::iterator it = enemyList.begin(); it != enemyList.end(); ++it)
				{
					if ((*it)->position.y > -50)
					{
						(*it)->isDie = true;
					}
				}
				// �� �Ѿ� ����Ʈ �ʱ�ȭ
				for (list<CBullet*>::iterator it = enemyBulletList.begin(); it != enemyBulletList.end(); ++it)
				{
					if ((*it)->position.y > -50)
					{
						(*it)->isDestroyed = true;
					}
				}
				if (clearAttack->isAniEnd)
				{
					useCA = false;
				}
				isCA = false;
			}
		}

		int tempScore = score;
		for (int i = 5; i >= 0; i--)
		{
			scoreNumUI[i].currentScene = tempScore % 10;
			tempScore /= 10;
		}

		for (int i = 0; i < 6; i++)
		{
			scoreNumUI[i].Update(deltaTime);
		}

		for (int i = 0; i < 5; i++)
		{
			playerLifeUI[i].Update(deltaTime);
		}

		for (int i = 0; i < 3; i++)
		{
			clearAttackUI[i].Update(deltaTime);
		}

		if (boss)
		{
			float ratio = (float)boss->hp / boss->maxHp;
			SetRect(&bossHpRect, 0, 0, 524 * ratio, 64);
			bossHpBG.Update(deltaTime);
			bossHpValue.Update(deltaTime);
		}

		if (sboss)
		{
			float ratio = (float)sboss->hp / sboss->maxHp;
			SetRect(&bossHpRect, 0, 0, 524 * ratio, 64);
			bossHpBG.Update(deltaTime);
			bossHpValue.Update(deltaTime);
		}
	}

void CGameScene::Render(LPD3DXSPRITE sprite)
{
	CScene::Render(sprite);

	map->Render(sprite);

	// �� �Ѿ�
	for (list<CBullet*>::iterator it = enemyBulletList.begin(); it != enemyBulletList.end(); ++it)
	{
		(*it)->Render(sprite);
	}
	// ��
	for (list<CEnemy*>::iterator it = enemyList.begin(); it != enemyList.end(); ++it)
		//if sMPN
	{
		(*it)->Render(sprite);
	}
	// ������
	for (list<CItem*>::iterator it = itemList.begin(); it != itemList.end(); it++)
	{
		(*it)->Render(sprite);
	}
	// ����
	for (int i = 0; i < 6; i++)
	{
		scoreNumUI[i].Draw(sprite, gAssetManager->numberTexture);
	}
	// �÷��̾� ����
	for (int i = 0; i < 5; i++)
	{
		if (playerLife > i)
			playerLifeUI[i].Draw(sprite, gAssetManager->playerTexture);
	}
	// CA ����
	for (int i = 0; i < 5; i++)
	{
		if (clearAttackCount > i)
			clearAttackUI[i].Draw(sprite, gAssetManager->clearAttackcountTexture);
	}
	// ����
	if (boss)
	{
		boss->Render(sprite);
	}
	// �߰� ����
	if (sboss)
	{
		sboss->Render(sprite);
	}
	// �÷��̾� �Ѿ�
	for (list<CBullet*>::iterator it = playerBulletList.begin(); it != playerBulletList.end(); ++it)
	{
		(*it)->Render(sprite);
	}
	// �÷��̾�
	if (player)
	{
		player->Render(sprite);
	}

	// �ֵ��
	if (addon[0])
		for (int i = 0; i < 3; i++)
			if (i == 0 || i == 2)
				addon[i]->Render(sprite);
	// ����Ʈ �׸���
	for (list<CEffect*>::iterator it = effectList.begin(); it != effectList.end(); ++it)
	{
		(*it)->Render(sprite);
	}
	// Ŭ���� ���� �׸���
	if (useCA)
	{
		clearAttack->Draw(sprite, gAssetManager->clearAttackTexture);
	}
	// ���� ü�¹�
	if (boss)
	{
		bossHpValue.Draw(sprite, gAssetManager->bossHp, &bossHpRect);
		bossHpBG.Draw(sprite, gAssetManager->bossHpBG);
	}
	// �߰� ���� ü�¹�
	if (sboss)
	{
		bossHpValue.Draw(sprite, gAssetManager->bossHp, &bossHpRect);
		bossHpBG.Draw(sprite, gAssetManager->bossHpBG);
	}
}

void CGameScene::MsgProc(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	CScene::MsgProc(uMsg, wParam, lParam);

	switch (uMsg)
	{
	case WM_KEYDOWN:
		switch (wParam)
		{
			// ClearAttack
		case 'C':
			ClearAttack();
			break;
			// ����
		case VK_F1:
			if (player)
				player->invincible = !player->invincible;
			break;
			//���� ���׷��̵�
		case VK_F2:
			if (player)
			{
				if (attackType == 0)
					attackType = 1;
				else if (attackType == 1)
					attackType = 2;
				else if (attackType == 2)
					attackType = 0;
			}
			break;
			// �ֵ��
		case VK_F3:
			if (player)
			{
				if (!addon[0])
				{
					isAddon = true;
					addonSave = true;
				}
				else if (addon[0])
				{
					for (int i = 0; i < 3; i++)
						if (i == 0 || i == 2)
							addon[i] = NULL;
					addonSave = false;
				}
			}
			break;
				// Ÿ��Ʋ�� ��ȯ
		case VK_F4:
			CGameScene::~CGameScene();
			ChangeScene("Title");
			gAssetManager->GetSoundAsset("BGM_Boss")->Stop();
			gAssetManager->GetSoundAsset("BGM_Stage1")->Stop();
			gAssetManager->GetSoundAsset("BGM_Stage2")->Stop();
			gAssetManager->GetSoundAsset("BGM_Win")->Stop();
			gAssetManager->GetSoundAsset("BGM_Lose")->Stop();
			gAssetManager->GetSoundAsset("BGM_Title")->Stop();
			break;
			// �������� 1�� ��ȯ
		case VK_F5:
			CGameScene::~CGameScene();
			ChangeScene("Stage1");
			gAssetManager->GetSoundAsset("BGM_Boss")->Stop();
			gAssetManager->GetSoundAsset("BGM_Stage1")->Stop();
			gAssetManager->GetSoundAsset("BGM_Stage2")->Stop();
			gAssetManager->GetSoundAsset("BGM_Win")->Stop();
			gAssetManager->GetSoundAsset("BGM_Lose")->Stop();
			gAssetManager->GetSoundAsset("BGM_Title")->Stop();
			break;
			// �������� 2�� ��ȯ
		case VK_F6:
			CGameScene::~CGameScene();
			ChangeScene("Stage2");
			gAssetManager->GetSoundAsset("BGM_Boss")->Stop();
			gAssetManager->GetSoundAsset("BGM_Stage1")->Stop();
			gAssetManager->GetSoundAsset("BGM_Stage2")->Stop();
			gAssetManager->GetSoundAsset("BGM_Win")->Stop();
			gAssetManager->GetSoundAsset("BGM_Lose")->Stop();
			gAssetManager->GetSoundAsset("BGM_Title")->Stop();
			break;
			}
			break;
		}
	}



void CGameScene::ClearAttack()
{
	if (player)
	{
		if (clearAttackCount > 0)
		{
			clearAttack = new CMatrix();
			clearAttack->SetAnimation(31, 0.03f, false);
			useCA = true;
			
			clearAttackCount--;
		}
	}
}