#include "DeckMng.h"
#include "player.h"
player::player(std::string image_name):objBase(image_name)
{
	data.imageName = image_name;

}

player::~player()
{
}

bool player::Init()
{
	data.imageSize = { 64,64 };
	data.pos = {SCREEN_SIZE_X/2-data.imageSize.x/2,SCREEN_SIZE_Y/4*3};
	null_data = { "NullCard",NULL_CARD,500,"data/card/N00.png",IMAGE_ID("data/card/N00.png")[0],0,0 };
	data.objType = TYPE_PLAYER;
	for (int i= 0; i < 255; i++)
	{
		keyTriger[i] = false;
	}
	state = {
		40,
		20,
		0,
		0,
		0,
		0,
		0,
		0,
		IMAGE_ID("data/card/P01.png")[0],
		null_data,
		null_data
	};
	mouse_point_card = { "NullCard",NULL_CARD,500,"data/card/N00.png",IMAGE_ID("data/card/N00.png")[0],0,0 };
	mouse_triger = false;
	return true;
}

void player::update(std::vector<objBase*>&obj, char* getKey, PhasesMng* phases)
{
	VECTOR2 crd_size = { 192,270 };
	VECTOR2 m_pos;
	GetMousePoint(&m_pos.x, &m_pos.y);
	int hand_size=phases->GetHand().size();
	std::vector<bool>delete_cnt = {};
	delete_cnt.resize(hand_size);
	for (int a = 0; a < hand_size; a++)
	{
		if (HitBoxtoPoint(m_pos, VECTOR2( 150 + (98 + 100) * a-crd_size.x/2, SCREEN_SIZE_Y / 1.0875f -crd_size.y/2),crd_size))
		{
			mouse_point_card = phases->GetHand()[a];
		}
	}
	

}

void player::damage(int damage_num)
{
	state.HP += ((state.defense + state.add_defence - state.def_defense) - damage_num>0?0: (state.defense + state.add_defence - state.def_defense) - damage_num);
}

void player::Draw(PhasesMng* phases)
{
	VECTOR crd_size = { 192,270 };
	VECTOR im_pos = { SCREEN_SIZE_X / 2 - crd_size.x / 2 ,SCREEN_SIZE_Y / 1.5 - crd_size.y / 2 };
	DrawRotaGraph(SCREEN_SIZE_X/2, SCREEN_SIZE_Y/1.5f,1.0f, 0, state.card_handle, true, false);										//プレイヤーカードの描写
	DrawRotaGraph(im_pos.x - crd_size.x - 10+crd_size.x/2, SCREEN_SIZE_Y / 1.5f, 1, 0, state.weapon_card.image_handle, true);		//武器カードの描写
	DrawRotaGraph(im_pos.x + crd_size.x + 10+crd_size.x/2, SCREEN_SIZE_Y / 1.5f, 1, 0, state.armor_card.image_handle, true);		//防具カードの描写
	DrawRotaGraph(crd_size.x / 2 + 20, SCREEN_SIZE_Y / 1.5f, 1, 0, mouse_point_card.image_handle, true);
	int hand_size = phases->GetHand().size();
	crd_size = { crd_size.x * 0.75f,crd_size.y * 0.75f };

	for (int a = 0; a < hand_size; a++)
	{
		DrawRotaGraph(150 + (98+100) * a, SCREEN_SIZE_Y /1.0875, 0.75, 0, phases->GetHand()[a].image_handle, true);
		DrawBox(150 + (98 + 100) * a - crd_size.x / 2, SCREEN_SIZE_Y / 1.0875f - crd_size.y / 2, 150 + (98 + 100) * a - crd_size.x / 2 + crd_size.x, SCREEN_SIZE_Y / 1.0875f - crd_size.y / 2 + crd_size.y, 0x000000, false);

		// SCREEN_SIZE_X/hand_size
	}
}

void player::attack(std::vector<objBase*>& obj)
{
	for (auto itr : obj)
	{
		if (itr->GetObjctType() == TYPE_ENEMY)
		{
			itr->damage(state.attack + state.add_attack + state.def_attack);
		}
	}
	
}

int player::GetDefense()
{
	return state.defense+state.add_defence+state.def_defense;
}

void player::Standby(DeckMng* card)
{
	
			VECTOR2 crd_size = { 192*0.75f,270*0.75f };
			VECTOR2 m_pos;
			GetMousePoint(&m_pos.x, &m_pos.y);
			int hand_size = card->GetHand().size();
			std::vector<bool>delete_cnt = {};
			delete_cnt.resize(hand_size);
	if ((GetMouseInput() & MOUSE_INPUT_LEFT) == 1)
	{
		if (!mouse_triger)
		{
			mouse_triger = true;
			for (int a = 0; a < hand_size; a++)
			{
				if (HitBoxtoPoint(m_pos, VECTOR2(150 + (98 + 100) * a - crd_size.x / 2, SCREEN_SIZE_Y / 1.0875f - crd_size.y / 2), crd_size))
				{
					switch (card->GetHand()[a].type)
					{
						case WEAPON_CARD:
							state.weapon_card = card->GetHand()[a];
							state.attack = state.weapon_card.attack;
							card->ChangeHand(a, null_data);
							break;
						case ARMOR_CARD:
							state.armor_card = card->GetHand()[a];
							state.defense = state.armor_card.defense;
							card->ChangeHand(a, null_data);
							break;
						case ITEM_CARD:
							Item(card->GetHand()[a]);
							card->ChangeHand(a, null_data);
							break;
						default:
							break;
					} 
					
				}
			}
			
		}

	}
	else {
		mouse_triger = false;
	}
}

void player::Reset()
{
	state.weapon_card = null_data;
	state.armor_card = null_data;
}





void player::move(char* getKey)
{
	

}

bool player::HitBoxtoPoint(VECTOR2 point_pos, VECTOR2 box_pos, VECTOR2 box_size)
{
	if (point_pos.x >= box_pos.x && point_pos.y >= box_pos.y &&
		point_pos.x <= box_pos.x + box_size.x && point_pos.y >= box_pos.y &&
		point_pos.x >= box_pos.x && point_pos.y <= box_pos.y + box_size.y &&
		point_pos.x <= box_pos.x + box_size.x && point_pos.y <= box_pos.y + box_size.y)
	{
		return true;
	}
	else
	{
		return false;
	}

}

void player::Item(CardData data)
{
	switch (data.item_type)
	{
	case RECOVERY_HP:
		state.HP += data.attack;
		break;
	case RECOVERY_MP:
		state.MP += data.attack;
		break;
	case ADD_ATTACK:
		state.add_attack += data.attack;
		break;
	case ADD_DEFENSE:
		state.add_defence += data.defense;
		break;
	case NO_EFFECT:
	case ITEM_TYPE_MAX:
	default:
		break;
	}
}
