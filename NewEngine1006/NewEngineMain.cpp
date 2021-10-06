/*
새로운 엔진을 만들려고 합니다. 우리가 만들려는 엔진은 초기화 기능이 있습니다.
당연히 엔진 종료시 자료를 정리합니다.
매 프레임에 실행하는 이벤트를 Tick이라고 합니다.
엔진은 또한 입력을 받고 화면에 렌더링을 합니다.
엔진이 가지고 있는 객체들이 충돌을 처리하는 이벤트(BeginOverlop)가 있습니다.
Actor는 매 프레임마다 처리하는 걸 Tick이라고 합니다.
Actor 최초 실행시 이벤트를 BeginPlay라고 합니다.
Actor도 입력을 처리하고 렌더링을 하고 충돌 처리를 합니다.
*/

#include <iostream>

#include "Engine.h"
#include "Actor.h"

using namespace std;

int main()
{
	Engine Engine1;
	Actor Actor1;

	return 0;
}