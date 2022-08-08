#include "main.h"
#include "first.h"
#include "second.h"
#include "third.h"
#include "fourth.h"
#include "fifth.h"
#include "sixth.h"
#include "seventh.h"
#include "eighth.h"

auto main() -> int {
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
#endif
#define eighth

#ifdef first
    first_work();
#endif
#ifdef second
    second_work();
#endif
#ifdef third
    third_work();
#endif
#ifdef fourth
    fourth_work();
#endif
#ifdef fifth
    fifth_work();
#endif
#ifdef sixth
    sixth_work();
#endif
#ifdef seventh
    seventh_work();
#endif
#ifdef eighth
    eighth_work();
#endif

    return 0;
}