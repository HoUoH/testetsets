#include "stdafx.h"
#include "Join.h"


//�׾����� ��Ҵ��� üũ
BOOL death_check(BOOL heroVisible) {
	if (heroVisible == false)
		return true;
	
	return false;
}

//�׾����� �ٽ� ����(F1)Ű�� ������ �� üũ
BOOL click_join(int key, BOOL heroVisible) {
	if (key == 1 && heroVisible == false)
		return true;

	return false;
}