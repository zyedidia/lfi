#include <stdint.h>
#include <stdbool.h>
static int cg_encode(uint8_t *input){
	 bool b;
	goto node5453;
node5736:
	b = randbool();
	if (b) {
		input[1] |= (1 << 2);
		goto node716;
	} else {
		input[1] &= ~(1 << 2);
		goto node5898;
	}
node1702:
	b = true;
	if (b) {
		input[2] |= (1 << 4);
		goto node2117;
	} else {
		input[2] &= ~(1 << 4);
		return 0;
	}
node1430:
	b = true;
	if (b) {
		input[2] |= (1 << 3);
		goto node1806;
	} else {
		input[2] &= ~(1 << 3);
		return 0;
	}
node5279:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node6204;
	} else {
		input[3] &= ~(1 << 5);
		return 4;
	}
node7879:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node1969;
	} else {
		input[3] &= ~(1 << 4);
		goto node568;
	}
node7915:
	b = randbool();
	if (b) {
		input[1] |= (1 << 3);
		goto node5507;
	} else {
		input[1] &= ~(1 << 3);
		goto node7724;
	}
node1595:
	b = true;
	if (b) {
		input[1] |= (1 << 3);
		goto node1944;
	} else {
		input[1] &= ~(1 << 3);
		return 0;
	}
node193:
	b = true;
	if (b) {
		input[1] |= (1 << 0);
		return 10;
	} else {
		input[1] &= ~(1 << 0);
		return 0;
	}
node1341:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node9113;
	}
node3727:
	b = true;
	if (b) {
		input[4] |= (1 << 7);
		goto node1455;
	} else {
		input[4] &= ~(1 << 7);
		return 0;
	}
node5235:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node8246;
	} else {
		input[3] &= ~(1 << 7);
		goto node2709;
	}
node5240:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node8494;
	}
node7211:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node1524;
	} else {
		input[3] &= ~(1 << 2);
		goto node4074;
	}
node8655:
	b = true;
	if (b) {
		input[4] |= (1 << 7);
		goto node1558;
	} else {
		input[4] &= ~(1 << 7);
		return 0;
	}
node611:
	b = false;
	if (b) {
		input[3] |= (1 << 2);
		return 0;
	} else {
		input[3] &= ~(1 << 2);
		goto node7124;
	}
node6499:
	b = true;
	if (b) {
		input[4] |= (1 << 7);
		goto node7662;
	} else {
		input[4] &= ~(1 << 7);
		return 0;
	}
node6773:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node4354;
	} else {
		input[2] &= ~(1 << 3);
		goto node6052;
	}
node5684:
	b = randbool();
	if (b) {
		input[2] |= (1 << 0);
		goto node667;
	} else {
		input[2] &= ~(1 << 0);
		goto node76;
	}
node3517:
	b = false;
	if (b) {
		input[3] |= (1 << 6);
		return 0;
	} else {
		input[3] &= ~(1 << 6);
		goto node391;
	}
node7229:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node3321;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node746:
	b = false;
	if (b) {
		input[2] |= (1 << 3);
		return 0;
	} else {
		input[2] &= ~(1 << 3);
		goto node8737;
	}
node8008:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node6494;
	} else {
		input[2] &= ~(1 << 2);
		goto node6764;
	}
node6661:
	b = false;
	if (b) {
		input[2] |= (1 << 1);
		return 0;
	} else {
		input[2] &= ~(1 << 1);
		goto node167;
	}
node7318:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node2077;
	} else {
		input[3] &= ~(1 << 7);
		goto node7037;
	}
node6515:
	b = randbool();
	if (b) {
		input[4] |= (1 << 4);
		goto node5729;
	} else {
		input[4] &= ~(1 << 4);
		goto node1013;
	}
node1131:
	b = true;
	if (b) {
		input[3] |= (1 << 0);
		goto node873;
	} else {
		input[3] &= ~(1 << 0);
		return 0;
	}
node9293:
	b = false;
	if (b) {
		input[4] |= (1 << 7);
		return 0;
	} else {
		input[4] &= ~(1 << 7);
		goto node4776;
	}
node1499:
	b = randbool();
	if (b) {
		input[1] |= (1 << 5);
		goto node7533;
	} else {
		input[1] &= ~(1 << 5);
		goto node9223;
	}
node8369:
	b = randbool();
	if (b) {
		input[1] |= (1 << 2);
		goto node7645;
	} else {
		input[1] &= ~(1 << 2);
		goto node6728;
	}
node4125:
	b = false;
	if (b) {
		input[2] |= (1 << 7);
		return 0;
	} else {
		input[2] &= ~(1 << 7);
		goto node4525;
	}
node4991:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node1226;
	} else {
		input[2] &= ~(1 << 5);
		goto node7654;
	}
node4911:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node7888;
	} else {
		input[3] &= ~(1 << 5);
		goto node5937;
	}
node4227:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node2745;
	} else {
		input[3] &= ~(1 << 4);
		goto node7904;
	}
node5529:
	b = true;
	if (b) {
		input[4] |= (1 << 6);
		goto node6841;
	} else {
		input[4] &= ~(1 << 6);
		return 0;
	}
node5505:
	b = false;
	if (b) {
		input[3] |= (1 << 2);
		return 0;
	} else {
		input[3] &= ~(1 << 2);
		goto node1895;
	}
node1152:
	b = randbool();
	if (b) {
		input[3] |= (1 << 1);
		goto node137;
	} else {
		input[3] &= ~(1 << 1);
		goto node4735;
	}
node8977:
	b = true;
	if (b) {
		input[1] |= (1 << 1);
		goto node7057;
	} else {
		input[1] &= ~(1 << 1);
		return 0;
	}
node4956:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node5836;
	} else {
		input[2] &= ~(1 << 6);
		goto node3663;
	}
node6079:
	b = false;
	if (b) {
		input[2] |= (1 << 3);
		return 0;
	} else {
		input[2] &= ~(1 << 3);
		goto node7470;
	}
node8742:
	b = false;
	if (b) {
		input[2] |= (1 << 1);
		return 0;
	} else {
		input[2] &= ~(1 << 1);
		goto node8838;
	}
node4375:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node6308;
	} else {
		input[3] &= ~(1 << 5);
		goto node8028;
	}
node285:
	b = false;
	if (b) {
		input[4] |= (1 << 7);
		return 0;
	} else {
		input[4] &= ~(1 << 7);
		goto node5873;
	}
node3687:
	b = false;
	if (b) {
		input[1] |= (1 << 3);
		return 0;
	} else {
		input[1] &= ~(1 << 3);
		goto node362;
	}
node9339:
	b = true;
	if (b) {
		input[3] |= (1 << 7);
		goto node8449;
	} else {
		input[3] &= ~(1 << 7);
		return 0;
	}
node9151:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node5334;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node928:
	b = false;
	if (b) {
		input[4] |= (1 << 5);
		return 0;
	} else {
		input[4] &= ~(1 << 5);
		goto node8374;
	}
node4499:
	b = false;
	if (b) {
		input[4] |= (1 << 4);
		return 0;
	} else {
		input[4] &= ~(1 << 4);
		goto node5377;
	}
node8570:
	b = false;
	if (b) {
		input[4] |= (1 << 0);
		return 0;
	} else {
		input[4] &= ~(1 << 0);
		goto node231;
	}
node6248:
	b = true;
	if (b) {
		input[1] |= (1 << 3);
		return 2;
	} else {
		input[1] &= ~(1 << 3);
		return 0;
	}
node533:
	b = false;
	if (b) {
		input[2] |= (1 << 7);
		return 0;
	} else {
		input[2] &= ~(1 << 7);
		goto node7127;
	}
node1220:
	b = true;
	if (b) {
		input[2] |= (1 << 4);
		goto node854;
	} else {
		input[2] &= ~(1 << 4);
		return 0;
	}
node2774:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node3510;
	} else {
		input[2] &= ~(1 << 3);
		goto node8262;
	}
node6715:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node5784;
	} else {
		input[2] &= ~(1 << 2);
		goto node5345;
	}
node6832:
	b = true;
	if (b) {
		input[2] |= (1 << 2);
		goto node5810;
	} else {
		input[2] &= ~(1 << 2);
		return 0;
	}
node4686:
	b = false;
	if (b) {
		input[1] |= (1 << 4);
		return 0;
	} else {
		input[1] &= ~(1 << 4);
		goto node5993;
	}
node8558:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node9033;
	} else {
		input[2] &= ~(1 << 6);
		goto node2535;
	}
node5271:
	b = randbool();
	if (b) {
		input[5] |= (1 << 6);
		goto node4616;
	} else {
		input[5] &= ~(1 << 6);
		goto node2463;
	}
node5914:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node3725;
	} else {
		input[2] &= ~(1 << 3);
		goto node8272;
	}
node3792:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node7544;
	} else {
		input[3] &= ~(1 << 7);
		goto node5238;
	}
node2175:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node1181;
	} else {
		input[3] &= ~(1 << 4);
		goto node3733;
	}
node3866:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node4296;
	} else {
		input[2] &= ~(1 << 6);
		goto node3351;
	}
node2535:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node5697;
	} else {
		input[2] &= ~(1 << 5);
		goto node7314;
	}
node2327:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node7180;
	} else {
		input[2] &= ~(1 << 5);
		goto node1597;
	}
node1379:
	b = true;
	if (b) {
		input[2] |= (1 << 2);
		goto node8307;
	} else {
		input[2] &= ~(1 << 2);
		return 0;
	}
node6555:
	b = true;
	if (b) {
		input[2] |= (1 << 2);
		goto node3463;
	} else {
		input[2] &= ~(1 << 2);
		return 0;
	}
node5536:
	b = false;
	if (b) {
		input[2] |= (1 << 1);
		return 0;
	} else {
		input[2] &= ~(1 << 1);
		goto node6044;
	}
node24:
	b = randbool();
	if (b) {
		input[1] |= (1 << 4);
		goto node26;
	} else {
		input[1] &= ~(1 << 4);
		return 6;
	}
node981:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node8321;
	} else {
		input[2] &= ~(1 << 4);
		goto node6323;
	}
node6132:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node2887;
	} else {
		input[3] &= ~(1 << 6);
		goto node2210;
	}
node5997:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node6194;
	} else {
		input[3] &= ~(1 << 2);
		goto node6778;
	}
node7540:
	b = false;
	if (b) {
		input[4] |= (1 << 3);
		return 0;
	} else {
		input[4] &= ~(1 << 3);
		goto node1009;
	}
node2002:
	b = randbool();
	if (b) {
		input[1] |= (1 << 0);
		goto node4037;
	} else {
		input[1] &= ~(1 << 0);
		goto node2511;
	}
node8518:
	b = false;
	if (b) {
		input[3] |= (1 << 1);
		return 0;
	} else {
		input[3] &= ~(1 << 1);
		goto node2851;
	}
node7686:
	b = true;
	if (b) {
		input[4] |= (1 << 4);
		goto node5194;
	} else {
		input[4] &= ~(1 << 4);
		return 0;
	}
node8482:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		return 3;
	} else {
		input[2] &= ~(1 << 5);
		goto node4564;
	}
node5094:
	b = false;
	if (b) {
		input[3] |= (1 << 7);
		return 0;
	} else {
		input[3] &= ~(1 << 7);
		goto node9315;
	}
node4191:
	b = true;
	if (b) {
		input[3] |= (1 << 7);
		goto node3599;
	} else {
		input[3] &= ~(1 << 7);
		return 0;
	}
node398:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node6487;
	} else {
		input[3] &= ~(1 << 4);
		goto node2945;
	}
node7084:
	b = randbool();
	if (b) {
		input[3] |= (1 << 1);
		goto node8574;
	} else {
		input[3] &= ~(1 << 1);
		goto node7156;
	}
node534:
	b = true;
	if (b) {
		input[2] |= (1 << 2);
		goto node907;
	} else {
		input[2] &= ~(1 << 2);
		return 0;
	}
node8264:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node663;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node3624:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node8719;
	} else {
		input[3] &= ~(1 << 7);
		goto node2792;
	}
node6598:
	b = true;
	if (b) {
		input[3] |= (1 << 6);
		goto node5053;
	} else {
		input[3] &= ~(1 << 6);
		return 0;
	}
node7546:
	b = randbool();
	if (b) {
		input[4] |= (1 << 6);
		goto node2091;
	} else {
		input[4] &= ~(1 << 6);
		goto node2324;
	}
node5677:
	b = true;
	if (b) {
		input[4] |= (1 << 2);
		goto node2206;
	} else {
		input[4] &= ~(1 << 2);
		return 0;
	}
node1125:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node2852;
	} else {
		input[3] &= ~(1 << 6);
		goto node8150;
	}
node4914:
	b = false;
	if (b) {
		input[3] |= (1 << 2);
		return 0;
	} else {
		input[3] &= ~(1 << 2);
		goto node8269;
	}
node8096:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node6293;
	} else {
		input[2] &= ~(1 << 4);
		goto node6772;
	}
node8354:
	b = true;
	if (b) {
		input[2] |= (1 << 4);
		goto node5169;
	} else {
		input[2] &= ~(1 << 4);
		return 0;
	}
node2719:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node2623;
	}
node660:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node2187;
	} else {
		input[2] &= ~(1 << 3);
		goto node8285;
	}
node8017:
	b = false;
	if (b) {
		input[2] |= (1 << 3);
		return 0;
	} else {
		input[2] &= ~(1 << 3);
		return 7;
	}
node1529:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node9163;
	} else {
		input[3] &= ~(1 << 7);
		goto node7281;
	}
node7853:
	b = randbool();
	if (b) {
		input[1] |= (1 << 5);
		goto node7896;
	} else {
		input[1] &= ~(1 << 5);
		goto node5903;
	}
node421:
	b = true;
	if (b) {
		input[3] |= (1 << 6);
		goto node7942;
	} else {
		input[3] &= ~(1 << 6);
		return 0;
	}
node776:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node2688;
	} else {
		input[3] &= ~(1 << 5);
		goto node5391;
	}
node3522:
	b = true;
	if (b) {
		input[3] |= (1 << 0);
		return 4;
	} else {
		input[3] &= ~(1 << 0);
		return 0;
	}
node4212:
	b = true;
	if (b) {
		input[4] |= (1 << 4);
		goto node4902;
	} else {
		input[4] &= ~(1 << 4);
		return 0;
	}
node6954:
	b = randbool();
	if (b) {
		input[4] |= (1 << 2);
		goto node5570;
	} else {
		input[4] &= ~(1 << 2);
		goto node4813;
	}
node543:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node8696;
	} else {
		input[2] &= ~(1 << 5);
		goto node8455;
	}
node3382:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node3091;
	} else {
		input[3] &= ~(1 << 3);
		goto node3985;
	}
node1418:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node2526;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node4839:
	b = randbool();
	if (b) {
		input[4] |= (1 << 4);
		goto node7392;
	} else {
		input[4] &= ~(1 << 4);
		goto node904;
	}
node4435:
	b = randbool();
	if (b) {
		input[2] |= (1 << 0);
		goto node739;
	} else {
		input[2] &= ~(1 << 0);
		goto node6427;
	}
node5581:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node3381;
	} else {
		input[3] &= ~(1 << 6);
		goto node6979;
	}
node937:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node7632;
	} else {
		input[3] &= ~(1 << 4);
		goto node777;
	}
node6638:
	b = false;
	if (b) {
		input[4] |= (1 << 4);
		return 0;
	} else {
		input[4] &= ~(1 << 4);
		goto node7768;
	}
node3868:
	b = true;
	if (b) {
		input[1] |= (1 << 0);
		goto node1565;
	} else {
		input[1] &= ~(1 << 0);
		return 0;
	}
node4855:
	b = false;
	if (b) {
		input[2] |= (1 << 5);
		return 0;
	} else {
		input[2] &= ~(1 << 5);
		goto node7930;
	}
node6074:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		goto node7235;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node3420:
	b = true;
	if (b) {
		input[3] |= (1 << 6);
		goto node869;
	} else {
		input[3] &= ~(1 << 6);
		return 0;
	}
node7048:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node7882;
	} else {
		input[3] &= ~(1 << 6);
		goto node4272;
	}
node5111:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node8891;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node3856:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node8267;
	}
node7753:
	b = false;
	if (b) {
		input[4] |= (1 << 5);
		return 0;
	} else {
		input[4] &= ~(1 << 5);
		goto node6844;
	}
node9230:
	b = randbool();
	if (b) {
		input[5] |= (1 << 2);
		goto node1526;
	} else {
		input[5] &= ~(1 << 2);
		return 6;
	}
node6820:
	b = true;
	if (b) {
		input[2] |= (1 << 2);
		goto node3527;
	} else {
		input[2] &= ~(1 << 2);
		return 0;
	}
node605:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node4523;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node7794:
	b = false;
	if (b) {
		input[3] |= (1 << 0);
		return 0;
	} else {
		input[3] &= ~(1 << 0);
		goto node8896;
	}
node1651:
	b = randbool();
	if (b) {
		input[1] |= (1 << 1);
		goto node1937;
	} else {
		input[1] &= ~(1 << 1);
		goto node6186;
	}
node7382:
	b = randbool();
	if (b) {
		input[2] |= (1 << 7);
		goto node5168;
	} else {
		input[2] &= ~(1 << 7);
		goto node7783;
	}
node8787:
	b = false;
	if (b) {
		input[2] |= (1 << 5);
		return 0;
	} else {
		input[2] &= ~(1 << 5);
		goto node745;
	}
node1121:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node5680;
	} else {
		input[3] &= ~(1 << 7);
		goto node4270;
	}
node7911:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node937;
	} else {
		input[3] &= ~(1 << 5);
		goto node3589;
	}
node1823:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node4735;
	} else {
		input[3] &= ~(1 << 2);
		goto node4905;
	}
node6050:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node2793;
	}
node8597:
	b = true;
	if (b) {
		input[3] |= (1 << 7);
		goto node8640;
	} else {
		input[3] &= ~(1 << 7);
		return 0;
	}
node6034:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node9269;
	}
node5029:
	b = false;
	if (b) {
		input[3] |= (1 << 0);
		return 0;
	} else {
		input[3] &= ~(1 << 0);
		goto node2989;
	}
node5436:
	b = false;
	if (b) {
		input[4] |= (1 << 0);
		return 0;
	} else {
		input[4] &= ~(1 << 0);
		goto node8656;
	}
node8579:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node7064;
	}
node7947:
	b = false;
	if (b) {
		input[3] |= (1 << 1);
		return 0;
	} else {
		input[3] &= ~(1 << 1);
		goto node2989;
	}
node524:
	b = true;
	if (b) {
		input[3] |= (1 << 0);
		goto node4093;
	} else {
		input[3] &= ~(1 << 0);
		return 0;
	}
node2194:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node8325;
	} else {
		input[3] &= ~(1 << 7);
		goto node1574;
	}
node2995:
	b = false;
	if (b) {
		input[3] |= (1 << 2);
		return 0;
	} else {
		input[3] &= ~(1 << 2);
		goto node2958;
	}
node3117:
	b = true;
	if (b) {
		input[1] |= (1 << 0);
		goto node7811;
	} else {
		input[1] &= ~(1 << 0);
		return 0;
	}
node6977:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node6323;
	} else {
		input[2] &= ~(1 << 4);
		goto node8443;
	}
node4919:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node8737;
	} else {
		input[2] &= ~(1 << 4);
		goto node746;
	}
node3521:
	b = false;
	if (b) {
		input[2] |= (1 << 3);
		return 0;
	} else {
		input[2] &= ~(1 << 3);
		goto node6673;
	}
node8771:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node535;
	} else {
		input[2] &= ~(1 << 1);
		goto node847;
	}
node3464:
	b = randbool();
	if (b) {
		input[2] |= (1 << 0);
		goto node2679;
	} else {
		input[2] &= ~(1 << 0);
		goto node4234;
	}
node2079:
	b = true;
	if (b) {
		input[4] |= (1 << 3);
		goto node6954;
	} else {
		input[4] &= ~(1 << 3);
		return 0;
	}
node481:
	b = true;
	if (b) {
		input[2] |= (1 << 2);
		goto node7133;
	} else {
		input[2] &= ~(1 << 2);
		return 0;
	}
node4548:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node5846;
	} else {
		input[3] &= ~(1 << 4);
		goto node1507;
	}
node121:
	b = true;
	if (b) {
		input[4] |= (1 << 3);
		goto node9187;
	} else {
		input[4] &= ~(1 << 3);
		return 0;
	}
node2793:
	b = true;
	if (b) {
		input[2] |= (1 << 3);
		goto node817;
	} else {
		input[2] &= ~(1 << 3);
		return 0;
	}
node958:
	b = true;
	if (b) {
		input[3] |= (1 << 6);
		goto node31;
	} else {
		input[3] &= ~(1 << 6);
		return 0;
	}
node5890:
	b = randbool();
	if (b) {
		input[3] |= (1 << 0);
		return 9;
	} else {
		input[3] &= ~(1 << 0);
		goto node6100;
	}
node7050:
	b = randbool();
	if (b) {
		input[1] |= (1 << 6);
		goto node2055;
	} else {
		input[1] &= ~(1 << 6);
		goto node4707;
	}
node8003:
	b = false;
	if (b) {
		input[2] |= (1 << 1);
		return 0;
	} else {
		input[2] &= ~(1 << 1);
		goto node7226;
	}
node1413:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node780;
	} else {
		input[3] &= ~(1 << 4);
		goto node2218;
	}
node7105:
	b = true;
	if (b) {
		input[3] |= (1 << 2);
		goto node6985;
	} else {
		input[3] &= ~(1 << 2);
		return 0;
	}
node1733:
	b = false;
	if (b) {
		input[4] |= (1 << 0);
		return 0;
	} else {
		input[4] &= ~(1 << 0);
		goto node1519;
	}
node6114:
	b = randbool();
	if (b) {
		input[4] |= (1 << 3);
		goto node4897;
	} else {
		input[4] &= ~(1 << 3);
		goto node6929;
	}
node9277:
	b = true;
	if (b) {
		input[1] |= (1 << 2);
		goto node6510;
	} else {
		input[1] &= ~(1 << 2);
		return 0;
	}
node961:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node5232;
	} else {
		input[2] &= ~(1 << 5);
		goto node8277;
	}
node6237:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node5976;
	} else {
		input[2] &= ~(1 << 4);
		goto node1604;
	}
node1779:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node9007;
	} else {
		input[3] &= ~(1 << 5);
		goto node1268;
	}
node7572:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node2909;
	} else {
		input[3] &= ~(1 << 5);
		goto node548;
	}
node6037:
	b = randbool();
	if (b) {
		input[4] |= (1 << 7);
		goto node894;
	} else {
		input[4] &= ~(1 << 7);
		goto node410;
	}
node1138:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node2025;
	} else {
		input[3] &= ~(1 << 6);
		goto node7061;
	}
node7332:
	b = true;
	if (b) {
		input[3] |= (1 << 1);
		goto node4336;
	} else {
		input[3] &= ~(1 << 1);
		return 0;
	}
node6693:
	b = randbool();
	if (b) {
		input[4] |= (1 << 6);
		goto node7575;
	} else {
		input[4] &= ~(1 << 6);
		goto node1306;
	}
node8791:
	b = false;
	if (b) {
		input[4] |= (1 << 2);
		return 0;
	} else {
		input[4] &= ~(1 << 2);
		goto node6198;
	}
node1462:
	b = true;
	if (b) {
		input[2] |= (1 << 6);
		goto node5218;
	} else {
		input[2] &= ~(1 << 6);
		return 0;
	}
node2799:
	b = false;
	if (b) {
		input[3] |= (1 << 7);
		return 0;
	} else {
		input[3] &= ~(1 << 7);
		goto node4532;
	}
node1879:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node3765;
	} else {
		input[3] &= ~(1 << 4);
		goto node7437;
	}
node3893:
	b = randbool();
	if (b) {
		input[1] |= (1 << 2);
		goto node715;
	} else {
		input[1] &= ~(1 << 2);
		goto node2343;
	}
node2866:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node278;
	} else {
		input[3] &= ~(1 << 6);
		goto node8156;
	}
node6258:
	b = true;
	if (b) {
		input[3] |= (1 << 6);
		goto node1740;
	} else {
		input[3] &= ~(1 << 6);
		return 0;
	}
node8270:
	b = false;
	if (b) {
		input[4] |= (1 << 4);
		return 0;
	} else {
		input[4] &= ~(1 << 4);
		goto node2729;
	}
node634:
	b = true;
	if (b) {
		input[4] |= (1 << 3);
		goto node2713;
	} else {
		input[4] &= ~(1 << 3);
		return 0;
	}
node5664:
	b = randbool();
	if (b) {
		input[3] |= (1 << 1);
		return 5;
	} else {
		input[3] &= ~(1 << 1);
		goto node4445;
	}
node7336:
	b = randbool();
	if (b) {
		input[4] |= (1 << 7);
		goto node782;
	} else {
		input[4] &= ~(1 << 7);
		goto node1425;
	}
node3549:
	b = true;
	if (b) {
		input[1] |= (1 << 0);
		goto node60;
	} else {
		input[1] &= ~(1 << 0);
		return 0;
	}
node2895:
	b = true;
	if (b) {
		input[2] |= (1 << 6);
		goto node7234;
	} else {
		input[2] &= ~(1 << 6);
		return 0;
	}
node8860:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node6397;
	}
node6552:
	b = false;
	if (b) {
		input[2] |= (1 << 0);
		return 0;
	} else {
		input[2] &= ~(1 << 0);
		goto node2283;
	}
node6662:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node8571;
	} else {
		input[3] &= ~(1 << 7);
		goto node7270;
	}
node1316:
	b = false;
	if (b) {
		input[3] |= (1 << 2);
		return 0;
	} else {
		input[3] &= ~(1 << 2);
		goto node5452;
	}
node2892:
	b = randbool();
	if (b) {
		input[1] |= (1 << 4);
		goto node1650;
	} else {
		input[1] &= ~(1 << 4);
		goto node1763;
	}
node9271:
	b = false;
	if (b) {
		input[2] |= (1 << 7);
		return 0;
	} else {
		input[2] &= ~(1 << 7);
		goto node5767;
	}
node6346:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node5649;
	}
node7600:
	b = randbool();
	if (b) {
		input[3] |= (1 << 0);
		goto node7632;
	} else {
		input[3] &= ~(1 << 0);
		goto node6663;
	}
node2609:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node2519;
	} else {
		input[3] &= ~(1 << 6);
		goto node7562;
	}
node2871:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node1251;
	} else {
		input[3] &= ~(1 << 5);
		goto node1818;
	}
node4912:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node6271;
	}
node8891:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node2764;
	} else {
		input[3] &= ~(1 << 3);
		goto node7411;
	}
node2110:
	b = true;
	if (b) {
		input[3] |= (1 << 2);
		goto node4629;
	} else {
		input[3] &= ~(1 << 2);
		return 0;
	}
node6914:
	b = false;
	if (b) {
		input[4] |= (1 << 0);
		return 0;
	} else {
		input[4] &= ~(1 << 0);
		goto node5417;
	}
node25:
	b = randbool();
	if (b) {
		input[2] |= (1 << 7);
		goto node9068;
	} else {
		input[2] &= ~(1 << 7);
		goto node3719;
	}
node3580:
	b = true;
	if (b) {
		input[2] |= (1 << 3);
		goto node5361;
	} else {
		input[2] &= ~(1 << 3);
		return 0;
	}
node5375:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node357;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node8822:
	b = randbool();
	if (b) {
		input[1] |= (1 << 0);
		goto node5062;
	} else {
		input[1] &= ~(1 << 0);
		goto node4326;
	}
node5982:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		goto node4752;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node7271:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node1655;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node4954:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node7949;
	}
node3181:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node6985;
	} else {
		input[3] &= ~(1 << 2);
		goto node1994;
	}
node1274:
	b = true;
	if (b) {
		input[3] |= (1 << 0);
		goto node1392;
	} else {
		input[3] &= ~(1 << 0);
		return 0;
	}
node7339:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node8776;
	}
node3941:
	b = false;
	if (b) {
		input[3] |= (1 << 0);
		return 0;
	} else {
		input[3] &= ~(1 << 0);
		goto node3888;
	}
node4742:
	b = true;
	if (b) {
		input[1] |= (1 << 2);
		goto node2253;
	} else {
		input[1] &= ~(1 << 2);
		return 0;
	}
node6464:
	b = false;
	if (b) {
		input[2] |= (1 << 5);
		return 0;
	} else {
		input[2] &= ~(1 << 5);
		goto node1024;
	}
node7851:
	b = true;
	if (b) {
		input[2] |= (1 << 3);
		goto node5740;
	} else {
		input[2] &= ~(1 << 3);
		return 0;
	}
node2441:
	b = false;
	if (b) {
		input[2] |= (1 << 5);
		return 0;
	} else {
		input[2] &= ~(1 << 5);
		goto node4633;
	}
node5539:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node5837;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node4030:
	b = false;
	if (b) {
		input[3] |= (1 << 2);
		return 0;
	} else {
		input[3] &= ~(1 << 2);
		goto node8785;
	}
node4858:
	b = randbool();
	if (b) {
		input[4] |= (1 << 0);
		return 9;
	} else {
		input[4] &= ~(1 << 0);
		return 5;
	}
node133:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node383;
	} else {
		input[3] &= ~(1 << 6);
		goto node5285;
	}
node6726:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node4523;
	} else {
		input[3] &= ~(1 << 5);
		goto node7018;
	}
node9164:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node5751;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node5386:
	b = true;
	if (b) {
		input[3] |= (1 << 2);
		goto node857;
	} else {
		input[3] &= ~(1 << 2);
		return 0;
	}
node2346:
	b = true;
	if (b) {
		input[3] |= (1 << 0);
		goto node8019;
	} else {
		input[3] &= ~(1 << 0);
		return 0;
	}
node3767:
	b = randbool();
	if (b) {
		input[2] |= (1 << 7);
		goto node5772;
	} else {
		input[2] &= ~(1 << 7);
		goto node6461;
	}
node4414:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node6838;
	}
node6138:
	b = false;
	if (b) {
		input[2] |= (1 << 0);
		return 0;
	} else {
		input[2] &= ~(1 << 0);
		goto node8781;
	}
node7160:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node4722;
	} else {
		input[3] &= ~(1 << 6);
		goto node3441;
	}
node4575:
	b = true;
	if (b) {
		input[3] |= (1 << 0);
		goto node5495;
	} else {
		input[3] &= ~(1 << 0);
		return 0;
	}
node231:
	b = randbool();
	if (b) {
		input[5] |= (1 << 7);
		goto node5021;
	} else {
		input[5] &= ~(1 << 7);
		goto node6417;
	}
node1293:
	b = randbool();
	if (b) {
		input[1] |= (1 << 2);
		goto node8830;
	} else {
		input[1] &= ~(1 << 2);
		goto node5005;
	}
node3578:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node2259;
	} else {
		input[3] &= ~(1 << 6);
		goto node7634;
	}
node493:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node4693;
	} else {
		input[3] &= ~(1 << 4);
		goto node5750;
	}
node8691:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node4387;
	} else {
		input[3] &= ~(1 << 3);
		goto node5839;
	}
node235:
	b = true;
	if (b) {
		input[4] |= (1 << 7);
		goto node5529;
	} else {
		input[4] &= ~(1 << 7);
		return 0;
	}
node3910:
	b = true;
	if (b) {
		input[4] |= (1 << 5);
		goto node9187;
	} else {
		input[4] &= ~(1 << 5);
		return 0;
	}
node9247:
	b = false;
	if (b) {
		input[1] |= (1 << 2);
		return 0;
	} else {
		input[1] &= ~(1 << 2);
		goto node122;
	}
node2718:
	b = false;
	if (b) {
		input[2] |= (1 << 6);
		return 0;
	} else {
		input[2] &= ~(1 << 6);
		goto node7268;
	}
node7611:
	b = true;
	if (b) {
		input[2] |= (1 << 3);
		goto node66;
	} else {
		input[2] &= ~(1 << 3);
		return 0;
	}
node8062:
	b = true;
	if (b) {
		input[3] |= (1 << 7);
		goto node4022;
	} else {
		input[3] &= ~(1 << 7);
		return 0;
	}
node3321:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node2629;
	}
node334:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node3453;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node7445:
	b = false;
	if (b) {
		input[1] |= (1 << 1);
		return 0;
	} else {
		input[1] &= ~(1 << 1);
		goto node6996;
	}
node3816:
	b = randbool();
	if (b) {
		input[1] |= (1 << 0);
		goto node1877;
	} else {
		input[1] &= ~(1 << 0);
		goto node1844;
	}
node560:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node6382;
	} else {
		input[3] &= ~(1 << 2);
		goto node4941;
	}
node9101:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node6462;
	} else {
		input[3] &= ~(1 << 2);
		goto node857;
	}
node7585:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node7592;
	} else {
		input[2] &= ~(1 << 5);
		goto node1108;
	}
node3668:
	b = false;
	if (b) {
		input[3] |= (1 << 7);
		return 0;
	} else {
		input[3] &= ~(1 << 7);
		goto node1138;
	}
node7892:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node6019;
	} else {
		input[3] &= ~(1 << 6);
		goto node134;
	}
node5903:
	b = randbool();
	if (b) {
		input[1] |= (1 << 4);
		goto node7745;
	} else {
		input[1] &= ~(1 << 4);
		goto node5859;
	}
node8090:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node7887;
	} else {
		input[2] &= ~(1 << 3);
		goto node6153;
	}
node4754:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node2950;
	} else {
		input[3] &= ~(1 << 6);
		goto node1557;
	}
node7795:
	b = randbool();
	if (b) {
		input[1] |= (1 << 5);
		goto node8377;
	} else {
		input[1] &= ~(1 << 5);
		goto node1944;
	}
node63:
	b = randbool();
	if (b) {
		input[1] |= (1 << 3);
		goto node706;
	} else {
		input[1] &= ~(1 << 3);
		goto node9264;
	}
node5775:
	b = randbool();
	if (b) {
		input[3] |= (1 << 1);
		goto node5112;
	} else {
		input[3] &= ~(1 << 1);
		goto node4972;
	}
node7156:
	b = true;
	if (b) {
		input[3] |= (1 << 0);
		goto node6462;
	} else {
		input[3] &= ~(1 << 0);
		return 0;
	}
node3556:
	b = false;
	if (b) {
		input[1] |= (1 << 2);
		return 0;
	} else {
		input[1] &= ~(1 << 2);
		goto node6170;
	}
node2795:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node5383;
	} else {
		input[3] &= ~(1 << 6);
		goto node4744;
	}
node2532:
	b = false;
	if (b) {
		input[4] |= (1 << 2);
		return 0;
	} else {
		input[4] &= ~(1 << 2);
		goto node7203;
	}
node5266:
	b = true;
	if (b) {
		input[1] |= (1 << 6);
		goto node6061;
	} else {
		input[1] &= ~(1 << 6);
		return 0;
	}
node682:
	b = randbool();
	if (b) {
		input[1] |= (1 << 4);
		goto node3369;
	} else {
		input[1] &= ~(1 << 4);
		return 3;
	}
node1330:
	b = true;
	if (b) {
		input[1] |= (1 << 0);
		goto node4485;
	} else {
		input[1] &= ~(1 << 0);
		return 0;
	}
node342:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node3445;
	} else {
		input[2] &= ~(1 << 4);
		goto node962;
	}
node5774:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node4475;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node7722:
	b = true;
	if (b) {
		input[4] |= (1 << 3);
		goto node4266;
	} else {
		input[4] &= ~(1 << 3);
		return 0;
	}
node4957:
	b = true;
	if (b) {
		input[2] |= (1 << 4);
		goto node7536;
	} else {
		input[2] &= ~(1 << 4);
		return 0;
	}
node4650:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node2003;
	} else {
		input[2] &= ~(1 << 3);
		goto node1210;
	}
node9168:
	b = false;
	if (b) {
		input[5] |= (1 << 7);
		return 0;
	} else {
		input[5] &= ~(1 << 7);
		goto node1068;
	}
node8382:
	b = false;
	if (b) {
		input[5] |= (1 << 7);
		return 0;
	} else {
		input[5] &= ~(1 << 7);
		goto node1436;
	}
node4165:
	b = true;
	if (b) {
		input[1] |= (1 << 2);
		goto node3461;
	} else {
		input[1] &= ~(1 << 2);
		return 0;
	}
node3000:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node2880;
	} else {
		input[2] &= ~(1 << 6);
		goto node8165;
	}
node469:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node7156;
	} else {
		input[3] &= ~(1 << 2);
		goto node9469;
	}
node1089:
	b = false;
	if (b) {
		input[3] |= (1 << 0);
		return 0;
	} else {
		input[3] &= ~(1 << 0);
		goto node4558;
	}
node1865:
	b = randbool();
	if (b) {
		input[1] |= (1 << 0);
		goto node241;
	} else {
		input[1] &= ~(1 << 0);
		goto node3557;
	}
node2809:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node7365;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node6413:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node920;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node6351:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node6559;
	} else {
		input[3] &= ~(1 << 3);
		goto node7632;
	}
node4425:
	b = false;
	if (b) {
		input[3] |= (1 << 2);
		return 0;
	} else {
		input[3] &= ~(1 << 2);
		goto node1152;
	}
node4198:
	b = randbool();
	if (b) {
		input[5] |= (1 << 4);
		goto node2463;
	} else {
		input[5] &= ~(1 << 4);
		goto node2333;
	}
node1102:
	b = randbool();
	if (b) {
		input[6] |= (1 << 5);
		goto node8504;
	} else {
		input[6] &= ~(1 << 5);
		goto node6261;
	}
node9223:
	b = false;
	if (b) {
		input[1] |= (1 << 4);
		return 0;
	} else {
		input[1] &= ~(1 << 4);
		goto node8596;
	}
node5722:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node1678;
	} else {
		input[2] &= ~(1 << 5);
		goto node5706;
	}
node4958:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node9054;
	} else {
		input[2] &= ~(1 << 2);
		goto node7887;
	}
node5275:
	b = false;
	if (b) {
		input[3] |= (1 << 7);
		return 0;
	} else {
		input[3] &= ~(1 << 7);
		goto node7060;
	}
node547:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node1909;
	}
node4139:
	b = randbool();
	if (b) {
		input[3] |= (1 << 1);
		goto node3650;
	} else {
		input[3] &= ~(1 << 1);
		goto node7632;
	}
node3349:
	b = false;
	if (b) {
		input[2] |= (1 << 3);
		return 0;
	} else {
		input[2] &= ~(1 << 3);
		goto node6330;
	}
node7109:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node1828;
	}
node6754:
	b = randbool();
	if (b) {
		input[0] |= (1 << 3);
		goto node9275;
	} else {
		input[0] &= ~(1 << 3);
		goto node396;
	}
node5207:
	b = randbool();
	if (b) {
		input[1] |= (1 << 4);
		goto node1944;
	} else {
		input[1] &= ~(1 << 4);
		goto node4850;
	}
node5334:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node5715;
	} else {
		input[3] &= ~(1 << 4);
		goto node2945;
	}
node5516:
	b = false;
	if (b) {
		input[4] |= (1 << 4);
		return 0;
	} else {
		input[4] &= ~(1 << 4);
		goto node5863;
	}
node9140:
	b = randbool();
	if (b) {
		input[1] |= (1 << 2);
		goto node5925;
	} else {
		input[1] &= ~(1 << 2);
		goto node6186;
	}
node5723:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node7986;
	} else {
		input[2] &= ~(1 << 4);
		goto node6411;
	}
node8456:
	b = false;
	if (b) {
		input[2] |= (1 << 3);
		return 0;
	} else {
		input[2] &= ~(1 << 3);
		goto node4833;
	}
node1710:
	b = false;
	if (b) {
		input[2] |= (1 << 1);
		return 0;
	} else {
		input[2] &= ~(1 << 1);
		goto node764;
	}
node95:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node8545;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node6815:
	b = randbool();
	if (b) {
		input[3] |= (1 << 1);
		goto node2584;
	} else {
		input[3] &= ~(1 << 1);
		goto node6462;
	}
node8960:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node8776;
	} else {
		input[3] &= ~(1 << 5);
		goto node2952;
	}
node9152:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node3917;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node965:
	b = true;
	if (b) {
		input[1] |= (1 << 1);
		goto node1803;
	} else {
		input[1] &= ~(1 << 1);
		return 0;
	}
node2858:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node8839;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node8868:
	b = true;
	if (b) {
		input[3] |= (1 << 2);
		goto node9318;
	} else {
		input[3] &= ~(1 << 2);
		return 0;
	}
node4386:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node955;
	} else {
		input[2] &= ~(1 << 5);
		goto node1081;
	}
node1050:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node6553;
	} else {
		input[2] &= ~(1 << 3);
		goto node6852;
	}
node3462:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node8765;
	} else {
		input[2] &= ~(1 << 2);
		goto node8301;
	}
node1216:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node5585;
	} else {
		input[3] &= ~(1 << 5);
		goto node7944;
	}
node7367:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node4356;
	}
node1298:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node2341;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node838:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node5958;
	} else {
		input[3] &= ~(1 << 6);
		goto node9340;
	}
node5861:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node6568;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node4685:
	b = randbool();
	if (b) {
		input[4] |= (1 << 6);
		goto node33;
	} else {
		input[4] &= ~(1 << 6);
		goto node7166;
	}
node3137:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node1682;
	} else {
		input[3] &= ~(1 << 4);
		goto node9164;
	}
node2492:
	b = true;
	if (b) {
		input[3] |= (1 << 2);
		goto node896;
	} else {
		input[3] &= ~(1 << 2);
		return 0;
	}
node740:
	b = true;
	if (b) {
		input[4] |= (1 << 7);
		goto node820;
	} else {
		input[4] &= ~(1 << 7);
		return 0;
	}
node7767:
	b = false;
	if (b) {
		input[4] |= (1 << 4);
		return 0;
	} else {
		input[4] &= ~(1 << 4);
		goto node5139;
	}
node2235:
	b = randbool();
	if (b) {
		input[5] |= (1 << 4);
		goto node5645;
	} else {
		input[5] &= ~(1 << 4);
		goto node2533;
	}
node8994:
	b = false;
	if (b) {
		input[1] |= (1 << 3);
		return 0;
	} else {
		input[1] &= ~(1 << 3);
		goto node4657;
	}
node3965:
	b = true;
	if (b) {
		input[2] |= (1 << 6);
		goto node3730;
	} else {
		input[2] &= ~(1 << 6);
		return 0;
	}
node8759:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node4410;
	} else {
		input[2] &= ~(1 << 4);
		goto node1207;
	}
node3193:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node2158;
	} else {
		input[3] &= ~(1 << 2);
		goto node5422;
	}
node1164:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node5759;
	} else {
		input[3] &= ~(1 << 2);
		goto node8476;
	}
node4864:
	b = false;
	if (b) {
		input[3] |= (1 << 2);
		return 0;
	} else {
		input[3] &= ~(1 << 2);
		goto node4611;
	}
node8837:
	b = randbool();
	if (b) {
		input[1] |= (1 << 0);
		goto node6186;
	} else {
		input[1] &= ~(1 << 0);
		goto node1898;
	}
node7939:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node942;
	} else {
		input[2] &= ~(1 << 6);
		goto node3768;
	}
node8545:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node2899;
	} else {
		input[3] &= ~(1 << 4);
		goto node1018;
	}
node5472:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node2745;
	}
node6297:
	b = false;
	if (b) {
		input[3] |= (1 << 1);
		return 0;
	} else {
		input[3] &= ~(1 << 1);
		goto node7632;
	}
node7938:
	b = true;
	if (b) {
		input[4] |= (1 << 3);
		goto node3990;
	} else {
		input[4] &= ~(1 << 3);
		return 0;
	}
node2579:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node7887;
	} else {
		input[2] &= ~(1 << 3);
		goto node3568;
	}
node2217:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node1011;
	}
node5942:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node7632;
	} else {
		input[3] &= ~(1 << 3);
		goto node7889;
	}
node579:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node8871;
	} else {
		input[3] &= ~(1 << 3);
		goto node438;
	}
node6220:
	b = false;
	if (b) {
		input[4] |= (1 << 7);
		return 0;
	} else {
		input[4] &= ~(1 << 7);
		goto node7709;
	}
node4699:
	b = true;
	if (b) {
		input[4] |= (1 << 3);
		goto node8674;
	} else {
		input[4] &= ~(1 << 3);
		return 0;
	}
node4707:
	b = false;
	if (b) {
		input[1] |= (1 << 5);
		return 0;
	} else {
		input[1] &= ~(1 << 5);
		goto node8595;
	}
node6548:
	b = randbool();
	if (b) {
		input[1] |= (1 << 4);
		return 2;
	} else {
		input[1] &= ~(1 << 4);
		goto node1090;
	}
node1000:
	b = true;
	if (b) {
		input[2] |= (1 << 2);
		goto node6243;
	} else {
		input[2] &= ~(1 << 2);
		return 0;
	}
node7523:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node4457;
	} else {
		input[3] &= ~(1 << 6);
		goto node4739;
	}
node1912:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node4628;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node7927:
	b = randbool();
	if (b) {
		input[1] |= (1 << 3);
		goto node7503;
	} else {
		input[1] &= ~(1 << 3);
		goto node8218;
	}
node2032:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node3795;
	}
node6574:
	b = false;
	if (b) {
		input[2] |= (1 << 2);
		return 0;
	} else {
		input[2] &= ~(1 << 2);
		goto node8307;
	}
node7824:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node3131;
	} else {
		input[3] &= ~(1 << 3);
		goto node3718;
	}
node4033:
	b = randbool();
	if (b) {
		input[1] |= (1 << 4);
		goto node1930;
	} else {
		input[1] &= ~(1 << 4);
		goto node2472;
	}
node7929:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node8986;
	} else {
		input[2] &= ~(1 << 6);
		goto node553;
	}
node7420:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node5348;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node143:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node8390;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node6062:
	b = false;
	if (b) {
		input[4] |= (1 << 5);
		return 0;
	} else {
		input[4] &= ~(1 << 5);
		goto node8738;
	}
node8118:
	b = randbool();
	if (b) {
		input[1] |= (1 << 3);
		goto node6186;
	} else {
		input[1] &= ~(1 << 3);
		goto node9140;
	}
node6153:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node9122;
	} else {
		input[2] &= ~(1 << 2);
		goto node641;
	}
node7846:
	b = true;
	if (b) {
		input[3] |= (1 << 6);
		goto node7419;
	} else {
		input[3] &= ~(1 << 6);
		return 0;
	}
node3909:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node4188;
	} else {
		input[3] &= ~(1 << 4);
		goto node1382;
	}
node9241:
	b = false;
	if (b) {
		input[3] |= (1 << 0);
		return 0;
	} else {
		input[3] &= ~(1 << 0);
		goto node3820;
	}
node7741:
	b = false;
	if (b) {
		input[4] |= (1 << 0);
		return 0;
	} else {
		input[4] &= ~(1 << 0);
		return 7;
	}
node970:
	b = false;
	if (b) {
		input[3] |= (1 << 7);
		return 0;
	} else {
		input[3] &= ~(1 << 7);
		goto node5749;
	}
node925:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node7975;
	} else {
		input[3] &= ~(1 << 6);
		goto node2329;
	}
node5448:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node5759;
	} else {
		input[3] &= ~(1 << 3);
		goto node6235;
	}
node136:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node461;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node4479:
	b = false;
	if (b) {
		input[4] |= (1 << 2);
		return 0;
	} else {
		input[4] &= ~(1 << 2);
		goto node8201;
	}
node8701:
	b = randbool();
	if (b) {
		input[0] |= (1 << 2);
		goto node8256;
	} else {
		input[0] &= ~(1 << 2);
		goto node6130;
	}
node5964:
	b = randbool();
	if (b) {
		input[2] |= (1 << 7);
		goto node5168;
	} else {
		input[2] &= ~(1 << 7);
		goto node8185;
	}
node2483:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node3320;
	} else {
		input[3] &= ~(1 << 7);
		goto node1034;
	}
node6335:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node7291;
	} else {
		input[2] &= ~(1 << 6);
		goto node5853;
	}
node6896:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node7550;
	} else {
		input[3] &= ~(1 << 6);
		goto node8813;
	}
node8341:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node7517;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node4104:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node9347;
	}
node6585:
	b = true;
	if (b) {
		input[3] |= (1 << 2);
		goto node6923;
	} else {
		input[3] &= ~(1 << 2);
		return 0;
	}
node3950:
	b = randbool();
	if (b) {
		input[2] |= (1 << 0);
		goto node6428;
	} else {
		input[2] &= ~(1 << 0);
		goto node3981;
	}
node9153:
	b = false;
	if (b) {
		input[3] |= (1 << 1);
		return 0;
	} else {
		input[3] &= ~(1 << 1);
		goto node5983;
	}
node1291:
	b = false;
	if (b) {
		input[4] |= (1 << 4);
		return 0;
	} else {
		input[4] &= ~(1 << 4);
		goto node7938;
	}
node2333:
	b = true;
	if (b) {
		input[5] |= (1 << 3);
		goto node2463;
	} else {
		input[5] &= ~(1 << 3);
		return 0;
	}
node810:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node633;
	}
node7513:
	b = false;
	if (b) {
		input[4] |= (1 << 3);
		return 0;
	} else {
		input[4] &= ~(1 << 3);
		goto node2284;
	}
node550:
	b = true;
	if (b) {
		input[1] |= (1 << 6);
		goto node5311;
	} else {
		input[1] &= ~(1 << 6);
		return 0;
	}
node2927:
	b = true;
	if (b) {
		input[1] |= (1 << 0);
		return 6;
	} else {
		input[1] &= ~(1 << 0);
		return 0;
	}
node9286:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node2485;
	} else {
		input[2] &= ~(1 << 6);
		goto node1662;
	}
node4784:
	b = randbool();
	if (b) {
		input[3] |= (1 << 1);
		goto node6212;
	} else {
		input[3] &= ~(1 << 1);
		goto node4735;
	}
node4682:
	b = false;
	if (b) {
		input[4] |= (1 << 7);
		return 0;
	} else {
		input[4] &= ~(1 << 7);
		goto node4572;
	}
node6424:
	b = randbool();
	if (b) {
		input[2] |= (1 << 7);
		goto node4980;
	} else {
		input[2] &= ~(1 << 7);
		goto node3905;
	}
node7906:
	b = false;
	if (b) {
		input[2] |= (1 << 6);
		return 0;
	} else {
		input[2] &= ~(1 << 6);
		goto node4952;
	}
node1342:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node8532;
	}
node6266:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node3520;
	} else {
		input[3] &= ~(1 << 3);
		goto node7287;
	}
node2091:
	b = false;
	if (b) {
		input[4] |= (1 << 5);
		return 0;
	} else {
		input[4] &= ~(1 << 5);
		goto node5037;
	}
node3223:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node7429;
	} else {
		input[3] &= ~(1 << 4);
		goto node6738;
	}
node6943:
	b = randbool();
	if (b) {
		input[1] |= (1 << 5);
		goto node7829;
	} else {
		input[1] &= ~(1 << 5);
		goto node4620;
	}
node2981:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node1792;
	} else {
		input[3] &= ~(1 << 6);
		goto node5126;
	}
node504:
	b = true;
	if (b) {
		input[1] |= (1 << 1);
		goto node5231;
	} else {
		input[1] &= ~(1 << 1);
		return 0;
	}
node3325:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node7223;
	} else {
		input[2] &= ~(1 << 6);
		goto node3562;
	}
node3838:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node554;
	} else {
		input[3] &= ~(1 << 5);
		goto node8930;
	}
node417:
	b = false;
	if (b) {
		input[3] |= (1 << 2);
		return 0;
	} else {
		input[3] &= ~(1 << 2);
		goto node8216;
	}
node4517:
	b = true;
	if (b) {
		input[4] |= (1 << 2);
		goto node1317;
	} else {
		input[4] &= ~(1 << 2);
		return 0;
	}
node1566:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node3491;
	} else {
		input[2] &= ~(1 << 6);
		goto node954;
	}
node6480:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node4448;
	} else {
		input[2] &= ~(1 << 2);
		goto node6371;
	}
node1744:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node8924;
	} else {
		input[2] &= ~(1 << 2);
		goto node918;
	}
node4777:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node2350;
	} else {
		input[3] &= ~(1 << 4);
		return 5;
	}
node3588:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node6034;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node4413:
	b = randbool();
	if (b) {
		input[1] |= (1 << 7);
		goto node326;
	} else {
		input[1] &= ~(1 << 7);
		goto node192;
	}
node8153:
	b = false;
	if (b) {
		input[2] |= (1 << 6);
		return 0;
	} else {
		input[2] &= ~(1 << 6);
		goto node1288;
	}
node8281:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node1366;
	}
node2069:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node4568;
	} else {
		input[2] &= ~(1 << 3);
		goto node5281;
	}
node3145:
	b = true;
	if (b) {
		input[2] |= (1 << 2);
		goto node5219;
	} else {
		input[2] &= ~(1 << 2);
		return 0;
	}
node6670:
	b = false;
	if (b) {
		input[2] |= (1 << 1);
		return 0;
	} else {
		input[2] &= ~(1 << 1);
		goto node847;
	}
node706:
	b = randbool();
	if (b) {
		input[1] |= (1 << 2);
		goto node5082;
	} else {
		input[1] &= ~(1 << 2);
		goto node180;
	}
node1938:
	b = false;
	if (b) {
		input[2] |= (1 << 3);
		return 0;
	} else {
		input[2] &= ~(1 << 3);
		goto node5379;
	}
node1930:
	b = false;
	if (b) {
		input[1] |= (1 << 2);
		return 0;
	} else {
		input[1] &= ~(1 << 2);
		goto node2843;
	}
node1675:
	b = true;
	if (b) {
		input[1] |= (1 << 0);
		goto node922;
	} else {
		input[1] &= ~(1 << 0);
		return 0;
	}
node7359:
	b = true;
	if (b) {
		input[2] |= (1 << 3);
		return 5;
	} else {
		input[2] &= ~(1 << 3);
		return 0;
	}
node7300:
	b = false;
	if (b) {
		input[2] |= (1 << 1);
		return 0;
	} else {
		input[2] &= ~(1 << 1);
		goto node3073;
	}
node6081:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node3236;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node9232:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node2014;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node8217:
	b = randbool();
	if (b) {
		input[1] |= (1 << 2);
		goto node1714;
	} else {
		input[1] &= ~(1 << 2);
		goto node7346;
	}
node7057:
	b = false;
	if (b) {
		input[2] |= (1 << 7);
		return 0;
	} else {
		input[2] &= ~(1 << 7);
		goto node1064;
	}
node2517:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node2600;
	}
node8975:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node2034;
	} else {
		input[2] &= ~(1 << 4);
		goto node619;
	}
node153:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		goto node6775;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node9243:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		return 7;
	} else {
		input[2] &= ~(1 << 1);
		goto node8613;
	}
node1807:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node1824;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node1269:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node5778;
	}
node5041:
	b = true;
	if (b) {
		input[2] |= (1 << 2);
		goto node7739;
	} else {
		input[2] &= ~(1 << 2);
		return 0;
	}
node7651:
	b = randbool();
	if (b) {
		input[0] |= (1 << 0);
		goto node3065;
	} else {
		input[0] &= ~(1 << 0);
		goto node5689;
	}
node7393:
	b = randbool();
	if (b) {
		input[1] |= (1 << 6);
		goto node743;
	} else {
		input[1] &= ~(1 << 6);
		goto node7828;
	}
node201:
	b = randbool();
	if (b) {
		input[1] |= (1 << 5);
		goto node5790;
	} else {
		input[1] &= ~(1 << 5);
		goto node3852;
	}
node3417:
	b = randbool();
	if (b) {
		input[2] |= (1 << 7);
		goto node1133;
	} else {
		input[2] &= ~(1 << 7);
		goto node4122;
	}
node5948:
	b = true;
	if (b) {
		input[2] |= (1 << 6);
		goto node1420;
	} else {
		input[2] &= ~(1 << 6);
		return 0;
	}
node9018:
	b = true;
	if (b) {
		input[2] |= (1 << 2);
		goto node307;
	} else {
		input[2] &= ~(1 << 2);
		return 0;
	}
node7342:
	b = randbool();
	if (b) {
		input[2] |= (1 << 7);
		goto node7519;
	} else {
		input[2] &= ~(1 << 7);
		goto node8334;
	}
node2723:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node6323;
	} else {
		input[2] &= ~(1 << 4);
		goto node9354;
	}
node5886:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node6553;
	} else {
		input[2] &= ~(1 << 3);
		goto node7643;
	}
node5967:
	b = false;
	if (b) {
		input[1] |= (1 << 4);
		return 0;
	} else {
		input[1] &= ~(1 << 4);
		goto node281;
	}
node4437:
	b = randbool();
	if (b) {
		input[1] |= (1 << 3);
		goto node1295;
	} else {
		input[1] &= ~(1 << 3);
		goto node592;
	}
node2963:
	b = false;
	if (b) {
		input[2] |= (1 << 6);
		return 0;
	} else {
		input[2] &= ~(1 << 6);
		goto node2948;
	}
node5457:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node208;
	} else {
		input[2] &= ~(1 << 5);
		goto node8737;
	}
node1801:
	b = randbool();
	if (b) {
		input[1] |= (1 << 4);
		goto node5910;
	} else {
		input[1] &= ~(1 << 4);
		goto node240;
	}
node2691:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node6206;
	} else {
		input[2] &= ~(1 << 6);
		goto node3252;
	}
node158:
	b = false;
	if (b) {
		input[2] |= (1 << 2);
		return 0;
	} else {
		input[2] &= ~(1 << 2);
		goto node4939;
	}
node1422:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node3312;
	}
node8357:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node6757;
	} else {
		input[3] &= ~(1 << 4);
		goto node2292;
	}
node1670:
	b = true;
	if (b) {
		input[2] |= (1 << 7);
		goto node4081;
	} else {
		input[2] &= ~(1 << 7);
		return 0;
	}
node6049:
	b = false;
	if (b) {
		input[2] |= (1 << 5);
		return 0;
	} else {
		input[2] &= ~(1 << 5);
		goto node3830;
	}
node9073:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node3092;
	} else {
		input[3] &= ~(1 << 7);
		goto node3125;
	}
node6987:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node6801;
	} else {
		input[3] &= ~(1 << 3);
		goto node3132;
	}
node3724:
	b = randbool();
	if (b) {
		input[4] |= (1 << 4);
		goto node3888;
	} else {
		input[4] &= ~(1 << 4);
		goto node1568;
	}
node2222:
	b = true;
	if (b) {
		input[1] |= (1 << 1);
		goto node3945;
	} else {
		input[1] &= ~(1 << 1);
		return 0;
	}
node9310:
	b = false;
	if (b) {
		input[3] |= (1 << 6);
		return 0;
	} else {
		input[3] &= ~(1 << 6);
		goto node4552;
	}
node9396:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node8747;
	} else {
		input[3] &= ~(1 << 5);
		goto node6800;
	}
node2891:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node5494;
	} else {
		input[3] &= ~(1 << 5);
		goto node2542;
	}
node8850:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node6527;
	}
node1793:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node2115;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node9457:
	b = true;
	if (b) {
		input[2] |= (1 << 2);
		goto node949;
	} else {
		input[2] &= ~(1 << 2);
		return 0;
	}
node5011:
	b = true;
	if (b) {
		input[3] |= (1 << 2);
		goto node3157;
	} else {
		input[3] &= ~(1 << 2);
		return 0;
	}
node5588:
	b = false;
	if (b) {
		input[4] |= (1 << 5);
		return 0;
	} else {
		input[4] &= ~(1 << 5);
		goto node6178;
	}
node3474:
	b = true;
	if (b) {
		input[4] |= (1 << 3);
		goto node7680;
	} else {
		input[4] &= ~(1 << 3);
		return 0;
	}
node2033:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node5691;
	}
node7545:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node4872;
	} else {
		input[3] &= ~(1 << 5);
		goto node1859;
	}
node5420:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node1914;
	} else {
		input[3] &= ~(1 << 5);
		goto node7000;
	}
node7062:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node8276;
	}
node1078:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node1110;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node4885:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node857;
	} else {
		input[3] &= ~(1 << 3);
		goto node7842;
	}
node5246:
	b = false;
	if (b) {
		input[2] |= (1 << 5);
		return 0;
	} else {
		input[2] &= ~(1 << 5);
		goto node2837;
	}
node6000:
	b = false;
	if (b) {
		input[5] |= (1 << 1);
		return 0;
	} else {
		input[5] &= ~(1 << 1);
		goto node3230;
	}
node98:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node8725;
	} else {
		input[2] &= ~(1 << 5);
		return 3;
	}
node8848:
	b = false;
	if (b) {
		input[2] |= (1 << 2);
		return 0;
	} else {
		input[2] &= ~(1 << 2);
		goto node61;
	}
node5562:
	b = false;
	if (b) {
		input[3] |= (1 << 6);
		return 0;
	} else {
		input[3] &= ~(1 << 6);
		goto node7720;
	}
node6444:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node1641;
	}
node3317:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node6021;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node750:
	b = false;
	if (b) {
		input[3] |= (1 << 1);
		return 0;
	} else {
		input[3] &= ~(1 << 1);
		goto node3941;
	}
node9004:
	b = randbool();
	if (b) {
		input[1] |= (1 << 3);
		goto node8698;
	} else {
		input[1] &= ~(1 << 3);
		goto node2592;
	}
node7071:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node1613;
	}
node6560:
	b = false;
	if (b) {
		input[4] |= (1 << 2);
		return 0;
	} else {
		input[4] &= ~(1 << 2);
		goto node5417;
	}
node1029:
	b = true;
	if (b) {
		input[5] |= (1 << 3);
		goto node3994;
	} else {
		input[5] &= ~(1 << 3);
		return 0;
	}
node7213:
	b = true;
	if (b) {
		input[4] |= (1 << 4);
		goto node2261;
	} else {
		input[4] &= ~(1 << 4);
		return 0;
	}
node8486:
	b = false;
	if (b) {
		input[1] |= (1 << 2);
		return 0;
	} else {
		input[1] &= ~(1 << 2);
		goto node6217;
	}
node4021:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node4094;
	} else {
		input[2] &= ~(1 << 6);
		goto node7492;
	}
node3598:
	b = randbool();
	if (b) {
		input[2] |= (1 << 0);
		goto node3799;
	} else {
		input[2] &= ~(1 << 0);
		goto node5094;
	}
node3124:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node2231;
	} else {
		input[3] &= ~(1 << 7);
		goto node9422;
	}
node6058:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node794;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node5319:
	b = randbool();
	if (b) {
		input[4] |= (1 << 5);
		goto node9344;
	} else {
		input[4] &= ~(1 << 5);
		goto node5904;
	}
node3921:
	b = true;
	if (b) {
		input[2] |= (1 << 6);
		return 4;
	} else {
		input[2] &= ~(1 << 6);
		return 0;
	}
node4638:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node3629;
	} else {
		input[2] &= ~(1 << 5);
		goto node8508;
	}
node3923:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node267;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node8717:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node6098;
	} else {
		input[3] &= ~(1 << 7);
		goto node7748;
	}
node3625:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node8189;
	} else {
		input[3] &= ~(1 << 5);
		goto node8416;
	}
node7954:
	b = randbool();
	if (b) {
		input[1] |= (1 << 3);
		goto node8698;
	} else {
		input[1] &= ~(1 << 3);
		goto node3707;
	}
node2977:
	b = false;
	if (b) {
		input[2] |= (1 << 1);
		return 0;
	} else {
		input[2] &= ~(1 << 1);
		goto node7806;
	}
node2701:
	b = randbool();
	if (b) {
		input[4] |= (1 << 7);
		goto node1346;
	} else {
		input[4] &= ~(1 << 7);
		goto node8648;
	}
node8817:
	b = false;
	if (b) {
		input[2] |= (1 << 3);
		return 0;
	} else {
		input[2] &= ~(1 << 3);
		goto node1806;
	}
node2357:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		goto node8320;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node6476:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node649;
	} else {
		input[3] &= ~(1 << 7);
		goto node7846;
	}
node8094:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node1235;
	} else {
		input[3] &= ~(1 << 3);
		goto node1742;
	}
node4842:
	b = false;
	if (b) {
		input[1] |= (1 << 0);
		return 0;
	} else {
		input[1] &= ~(1 << 0);
		goto node5256;
	}
node6409:
	b = true;
	if (b) {
		input[2] |= (1 << 2);
		goto node5414;
	} else {
		input[2] &= ~(1 << 2);
		return 0;
	}
node4123:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node8627;
	}
node5841:
	b = true;
	if (b) {
		input[4] |= (1 << 7);
		goto node6909;
	} else {
		input[4] &= ~(1 << 7);
		return 0;
	}
node1314:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node6739;
	} else {
		input[3] &= ~(1 << 4);
		goto node5510;
	}
node5212:
	b = false;
	if (b) {
		input[3] |= (1 << 0);
		return 0;
	} else {
		input[3] &= ~(1 << 0);
		goto node5170;
	}
node5456:
	b = false;
	if (b) {
		input[4] |= (1 << 5);
		return 0;
	} else {
		input[4] &= ~(1 << 5);
		goto node1123;
	}
node6122:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node8728;
	} else {
		input[3] &= ~(1 << 5);
		goto node357;
	}
node4160:
	b = randbool();
	if (b) {
		input[4] |= (1 << 5);
		goto node3911;
	} else {
		input[4] &= ~(1 << 5);
		goto node840;
	}
node3813:
	b = randbool();
	if (b) {
		input[4] |= (1 << 4);
		goto node3850;
	} else {
		input[4] &= ~(1 << 4);
		goto node2642;
	}
node4541:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node8976;
	} else {
		input[2] &= ~(1 << 5);
		goto node9190;
	}
node5706:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node9440;
	} else {
		input[2] &= ~(1 << 4);
		goto node7168;
	}
node8303:
	b = false;
	if (b) {
		input[3] |= (1 << 7);
		return 0;
	} else {
		input[3] &= ~(1 << 7);
		goto node71;
	}
node8538:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node3892;
	} else {
		input[3] &= ~(1 << 5);
		goto node1946;
	}
node2837:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node7877;
	}
node8253:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node7549;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node3496:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		return 4;
	} else {
		input[3] &= ~(1 << 4);
		goto node5058;
	}
node1948:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node160;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node4990:
	b = true;
	if (b) {
		input[3] |= (1 << 0);
		return 9;
	} else {
		input[3] &= ~(1 << 0);
		return 0;
	}
node2055:
	b = false;
	if (b) {
		input[1] |= (1 << 5);
		return 0;
	} else {
		input[1] &= ~(1 << 5);
		goto node5349;
	}
node7787:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node3248;
	} else {
		input[2] &= ~(1 << 4);
		goto node1226;
	}
node5159:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node6224;
	} else {
		input[2] &= ~(1 << 3);
		goto node5975;
	}
node9131:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node3112;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node7266:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node8462;
	} else {
		input[3] &= ~(1 << 2);
		goto node7084;
	}
node5338:
	b = true;
	if (b) {
		input[3] |= (1 << 0);
		goto node3508;
	} else {
		input[3] &= ~(1 << 0);
		return 0;
	}
node9193:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node1673;
	} else {
		input[3] &= ~(1 << 6);
		goto node4103;
	}
node8800:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node2479;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node2219:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node8908;
	}
node8201:
	b = false;
	if (b) {
		input[4] |= (1 << 1);
		return 0;
	} else {
		input[4] &= ~(1 << 1);
		goto node5055;
	}
node3340:
	b = true;
	if (b) {
		input[5] |= (1 << 2);
		goto node3846;
	} else {
		input[5] &= ~(1 << 2);
		return 0;
	}
node1485:
	b = randbool();
	if (b) {
		input[0] |= (1 << 3);
		goto node1737;
	} else {
		input[0] &= ~(1 << 3);
		goto node7469;
	}
node9093:
	b = randbool();
	if (b) {
		input[2] |= (1 << 7);
		goto node8148;
	} else {
		input[2] &= ~(1 << 7);
		goto node5519;
	}
node4774:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node5421;
	} else {
		input[3] &= ~(1 << 5);
		goto node2089;
	}
node2226:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node262;
	} else {
		input[3] &= ~(1 << 4);
		goto node8661;
	}
node7919:
	b = true;
	if (b) {
		input[3] |= (1 << 2);
		goto node6303;
	} else {
		input[3] &= ~(1 << 2);
		return 0;
	}
node7718:
	b = true;
	if (b) {
		input[4] |= (1 << 6);
		goto node3607;
	} else {
		input[4] &= ~(1 << 6);
		return 0;
	}
node7198:
	b = randbool();
	if (b) {
		input[4] |= (1 << 6);
		goto node1101;
	} else {
		input[4] &= ~(1 << 6);
		goto node2585;
	}
node2740:
	b = randbool();
	if (b) {
		input[0] |= (1 << 0);
		goto node6608;
	} else {
		input[0] &= ~(1 << 0);
		goto node1738;
	}
node8119:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node5475;
	} else {
		input[2] &= ~(1 << 6);
		goto node3172;
	}
node877:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		goto node3944;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node1388:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node2771;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node2037:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node440;
	}
node4024:
	b = true;
	if (b) {
		input[4] |= (1 << 6);
		goto node6463;
	} else {
		input[4] &= ~(1 << 6);
		return 0;
	}
node3140:
	b = false;
	if (b) {
		input[3] |= (1 << 7);
		return 0;
	} else {
		input[3] &= ~(1 << 7);
		goto node6634;
	}
node5008:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node1822;
	} else {
		input[3] &= ~(1 << 6);
		goto node5042;
	}
node2956:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node9080;
	} else {
		input[3] &= ~(1 << 6);
		goto node1405;
	}
node4893:
	b = false;
	if (b) {
		input[3] |= (1 << 2);
		return 0;
	} else {
		input[3] &= ~(1 << 2);
		goto node4794;
	}
node7233:
	b = randbool();
	if (b) {
		input[0] |= (1 << 3);
		goto node7553;
	} else {
		input[0] &= ~(1 << 3);
		return 2;
	}
node743:
	b = randbool();
	if (b) {
		input[1] |= (1 << 5);
		goto node1944;
	} else {
		input[1] &= ~(1 << 5);
		goto node1393;
	}
node9084:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node7493;
	}
node8209:
	b = false;
	if (b) {
		input[2] |= (1 << 3);
		return 0;
	} else {
		input[2] &= ~(1 << 3);
		goto node6832;
	}
node4663:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node3799;
	} else {
		input[2] &= ~(1 << 1);
		goto node8809;
	}
node5996:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node445;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node4011:
	b = false;
	if (b) {
		input[2] |= (1 << 7);
		return 0;
	} else {
		input[2] &= ~(1 << 7);
		goto node6610;
	}
node5853:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node9328;
	} else {
		input[2] &= ~(1 << 5);
		goto node6938;
	}
node5233:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node7386;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node8672:
	b = true;
	if (b) {
		input[3] |= (1 << 6);
		goto node250;
	} else {
		input[3] &= ~(1 << 6);
		return 0;
	}
node7589:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node5336;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node8904:
	b = true;
	if (b) {
		input[3] |= (1 << 2);
		goto node276;
	} else {
		input[3] &= ~(1 << 2);
		return 0;
	}
node5597:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node1371;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node2786:
	b = true;
	if (b) {
		input[3] |= (1 << 7);
		goto node8227;
	} else {
		input[3] &= ~(1 << 7);
		return 0;
	}
node4986:
	b = false;
	if (b) {
		input[4] |= (1 << 7);
		return 0;
	} else {
		input[4] &= ~(1 << 7);
		goto node8935;
	}
node8504:
	b = randbool();
	if (b) {
		input[6] |= (1 << 4);
		goto node6261;
	} else {
		input[6] &= ~(1 << 4);
		goto node5141;
	}
node4089:
	b = true;
	if (b) {
		input[1] |= (1 << 0);
		goto node588;
	} else {
		input[1] &= ~(1 << 0);
		return 0;
	}
node174:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node1104;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node8951:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node7411;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node8069:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node1488;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node2650:
	b = true;
	if (b) {
		input[2] |= (1 << 3);
		goto node1119;
	} else {
		input[2] &= ~(1 << 3);
		return 0;
	}
node4709:
	b = false;
	if (b) {
		input[2] |= (1 << 1);
		return 0;
	} else {
		input[2] &= ~(1 << 1);
		goto node4997;
	}
node8870:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node5606;
	} else {
		input[3] &= ~(1 << 7);
		goto node7846;
	}
node2617:
	b = false;
	if (b) {
		input[3] |= (1 << 6);
		return 0;
	} else {
		input[3] &= ~(1 << 6);
		goto node643;
	}
node1020:
	b = randbool();
	if (b) {
		input[6] |= (1 << 4);
		goto node5265;
	} else {
		input[6] &= ~(1 << 4);
		goto node1426;
	}
node2564:
	b = false;
	if (b) {
		input[2] |= (1 << 7);
		return 0;
	} else {
		input[2] &= ~(1 << 7);
		goto node4679;
	}
node3128:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node7152;
	} else {
		input[2] &= ~(1 << 3);
		goto node7636;
	}
node3393:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node5442;
	} else {
		input[3] &= ~(1 << 4);
		goto node1624;
	}
node5349:
	b = false;
	if (b) {
		input[1] |= (1 << 4);
		return 0;
	} else {
		input[1] &= ~(1 << 4);
		goto node4401;
	}
node6869:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node6164;
	} else {
		input[2] &= ~(1 << 4);
		goto node6096;
	}
node6495:
	b = true;
	if (b) {
		input[1] |= (1 << 2);
		goto node8977;
	} else {
		input[1] &= ~(1 << 2);
		return 0;
	}
node2004:
	b = true;
	if (b) {
		input[2] |= (1 << 2);
		goto node7870;
	} else {
		input[2] &= ~(1 << 2);
		return 0;
	}
node5698:
	b = true;
	if (b) {
		input[3] |= (1 << 6);
		goto node7882;
	} else {
		input[3] &= ~(1 << 6);
		return 0;
	}
node788:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node9001;
	}
node9205:
	b = true;
	if (b) {
		input[4] |= (1 << 3);
		goto node6326;
	} else {
		input[4] &= ~(1 << 3);
		return 0;
	}
node4102:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node460;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node1888:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node5104;
	} else {
		input[3] &= ~(1 << 5);
		goto node5027;
	}
node4759:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node5415;
	} else {
		input[3] &= ~(1 << 5);
		goto node5047;
	}
node4148:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node2995;
	}
node5151:
	b = true;
	if (b) {
		input[4] |= (1 << 5);
		goto node6173;
	} else {
		input[4] &= ~(1 << 5);
		return 0;
	}
node8290:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node378;
	} else {
		input[2] &= ~(1 << 5);
		goto node7673;
	}
node6281:
	b = false;
	if (b) {
		input[3] |= (1 << 6);
		return 0;
	} else {
		input[3] &= ~(1 << 6);
		goto node4348;
	}
node1381:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node5385;
	} else {
		input[3] &= ~(1 << 6);
		goto node4705;
	}
node4821:
	b = false;
	if (b) {
		input[4] |= (1 << 5);
		return 0;
	} else {
		input[4] &= ~(1 << 5);
		goto node9040;
	}
node6527:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node3294;
	}
node1994:
	b = false;
	if (b) {
		input[3] |= (1 << 1);
		return 0;
	} else {
		input[3] &= ~(1 << 1);
		goto node6671;
	}
node6618:
	b = randbool();
	if (b) {
		input[4] |= (1 << 4);
		goto node2904;
	} else {
		input[4] &= ~(1 << 4);
		goto node7914;
	}
node8180:
	b = false;
	if (b) {
		input[4] |= (1 << 1);
		return 0;
	} else {
		input[4] &= ~(1 << 1);
		goto node8082;
	}
node4536:
	b = randbool();
	if (b) {
		input[1] |= (1 << 0);
		goto node533;
	} else {
		input[1] &= ~(1 << 0);
		goto node7277;
	}
node4132:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node8702;
	} else {
		input[2] &= ~(1 << 4);
		goto node6986;
	}
node267:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node4792;
	} else {
		input[3] &= ~(1 << 7);
		goto node3948;
	}
node1905:
	b = randbool();
	if (b) {
		input[5] |= (1 << 6);
		goto node9357;
	} else {
		input[5] &= ~(1 << 6);
		goto node5786;
	}
node1737:
	b = randbool();
	if (b) {
		input[0] |= (1 << 2);
		return 1;
	} else {
		input[0] &= ~(1 << 2);
		goto node4766;
	}
node5340:
	b = randbool();
	if (b) {
		input[1] |= (1 << 4);
		goto node8602;
	} else {
		input[1] &= ~(1 << 4);
		goto node3483;
	}
node1295:
	b = randbool();
	if (b) {
		input[1] |= (1 << 2);
		goto node1435;
	} else {
		input[1] &= ~(1 << 2);
		goto node7277;
	}
node4585:
	b = true;
	if (b) {
		input[2] |= (1 << 2);
		goto node6371;
	} else {
		input[2] &= ~(1 << 2);
		return 0;
	}
node7353:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node5297;
	} else {
		input[3] &= ~(1 << 5);
		goto node251;
	}
node6801:
	b = true;
	if (b) {
		input[3] |= (1 << 2);
		goto node952;
	} else {
		input[3] &= ~(1 << 2);
		return 0;
	}
node4251:
	b = randbool();
	if (b) {
		input[1] |= (1 << 3);
		goto node4165;
	} else {
		input[1] &= ~(1 << 3);
		goto node4361;
	}
node6877:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node703;
	} else {
		input[2] &= ~(1 << 5);
		goto node4642;
	}
node6966:
	b = false;
	if (b) {
		input[2] |= (1 << 3);
		return 0;
	} else {
		input[2] &= ~(1 << 3);
		goto node8499;
	}
node8652:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node6436;
	} else {
		input[3] &= ~(1 << 4);
		goto node4350;
	}
node3718:
	b = false;
	if (b) {
		input[3] |= (1 << 2);
		return 0;
	} else {
		input[3] &= ~(1 << 2);
		goto node9355;
	}
node8708:
	b = true;
	if (b) {
		input[2] |= (1 << 4);
		goto node6595;
	} else {
		input[2] &= ~(1 << 4);
		return 0;
	}
node3109:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		goto node4456;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node1307:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node6110;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node6898:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node137;
	} else {
		input[3] &= ~(1 << 3);
		goto node1458;
	}
node5150:
	b = true;
	if (b) {
		input[3] |= (1 << 0);
		goto node7456;
	} else {
		input[3] &= ~(1 << 0);
		return 0;
	}
node7066:
	b = true;
	if (b) {
		input[4] |= (1 << 5);
		goto node2183;
	} else {
		input[4] &= ~(1 << 5);
		return 0;
	}
node3971:
	b = true;
	if (b) {
		input[1] |= (1 << 6);
		goto node197;
	} else {
		input[1] &= ~(1 << 6);
		return 0;
	}
node479:
	b = randbool();
	if (b) {
		input[1] |= (1 << 3);
		goto node5070;
	} else {
		input[1] &= ~(1 << 3);
		goto node1706;
	}
node8084:
	b = true;
	if (b) {
		input[1] |= (1 << 2);
		goto node6593;
	} else {
		input[1] &= ~(1 << 2);
		return 0;
	}
node2619:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node2919;
	} else {
		input[2] &= ~(1 << 3);
		goto node3665;
	}
node9060:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node7874;
	} else {
		input[3] &= ~(1 << 6);
		goto node2683;
	}
node773:
	b = true;
	if (b) {
		input[4] |= (1 << 6);
		goto node6062;
	} else {
		input[4] &= ~(1 << 6);
		return 0;
	}
node7029:
	b = true;
	if (b) {
		input[2] |= (1 << 6);
		goto node7901;
	} else {
		input[2] &= ~(1 << 6);
		return 0;
	}
node4639:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node7044;
	} else {
		input[2] &= ~(1 << 2);
		goto node8792;
	}
node8914:
	b = true;
	if (b) {
		input[3] |= (1 << 6);
		return 5;
	} else {
		input[3] &= ~(1 << 6);
		return 0;
	}
node944:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node5314;
	} else {
		input[3] &= ~(1 << 5);
		goto node2604;
	}
node4173:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node8865;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node7827:
	b = randbool();
	if (b) {
		input[1] |= (1 << 6);
		goto node9427;
	} else {
		input[1] &= ~(1 << 6);
		goto node9463;
	}
node6626:
	b = false;
	if (b) {
		input[2] |= (1 << 2);
		return 0;
	} else {
		input[2] &= ~(1 << 2);
		goto node3922;
	}
node1337:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node31;
	} else {
		input[3] &= ~(1 << 6);
		goto node4561;
	}
node380:
	b = false;
	if (b) {
		input[3] |= (1 << 6);
		return 0;
	} else {
		input[3] &= ~(1 << 6);
		goto node4934;
	}
node292:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node6803;
	} else {
		input[3] &= ~(1 << 7);
		goto node3361;
	}
node8278:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node8294;
	} else {
		input[3] &= ~(1 << 4);
		goto node8548;
	}
node5657:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node7766;
	} else {
		input[3] &= ~(1 << 4);
		goto node7815;
	}
node1993:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node7247;
	}
node8067:
	b = false;
	if (b) {
		input[4] |= (1 << 3);
		return 0;
	} else {
		input[4] &= ~(1 << 3);
		goto node4232;
	}
node6741:
	b = false;
	if (b) {
		input[4] |= (1 << 1);
		return 0;
	} else {
		input[4] &= ~(1 << 1);
		goto node6914;
	}
node1987:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node4493;
	} else {
		input[3] &= ~(1 << 6);
		goto node1537;
	}
node7706:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node137;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node4844:
	b = false;
	if (b) {
		input[3] |= (1 << 2);
		return 0;
	} else {
		input[3] &= ~(1 << 2);
		goto node3569;
	}
node531:
	b = randbool();
	if (b) {
		input[3] |= (1 << 1);
		goto node2374;
	} else {
		input[3] &= ~(1 << 1);
		goto node57;
	}
node3978:
	b = true;
	if (b) {
		input[4] |= (1 << 6);
		goto node3979;
	} else {
		input[4] &= ~(1 << 6);
		return 0;
	}
node9378:
	b = randbool();
	if (b) {
		input[4] |= (1 << 2);
		goto node7791;
	} else {
		input[4] &= ~(1 << 2);
		goto node7777;
	}
node5269:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node5928;
	}
node74:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node5756;
	} else {
		input[3] &= ~(1 << 2);
		goto node6297;
	}
node3083:
	b = false;
	if (b) {
		input[3] |= (1 << 2);
		return 0;
	} else {
		input[3] &= ~(1 << 2);
		goto node7920;
	}
node7625:
	b = randbool();
	if (b) {
		input[4] |= (1 << 5);
		goto node7477;
	} else {
		input[4] &= ~(1 << 5);
		goto node6221;
	}
node1490:
	b = randbool();
	if (b) {
		input[4] |= (1 << 3);
		goto node4865;
	} else {
		input[4] &= ~(1 << 3);
		goto node8751;
	}
node7529:
	b = true;
	if (b) {
		input[1] |= (1 << 1);
		goto node9382;
	} else {
		input[1] &= ~(1 << 1);
		return 0;
	}
node1701:
	b = false;
	if (b) {
		input[2] |= (1 << 7);
		return 0;
	} else {
		input[2] &= ~(1 << 7);
		goto node1127;
	}
node6175:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node259;
	} else {
		input[2] &= ~(1 << 4);
		goto node1174;
	}
node4461:
	b = randbool();
	if (b) {
		input[1] |= (1 << 5);
		goto node2228;
	} else {
		input[1] &= ~(1 << 5);
		goto node1782;
	}
node5328:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node4259;
	} else {
		input[2] &= ~(1 << 2);
		goto node6900;
	}
node3514:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node6708;
	} else {
		input[3] &= ~(1 << 4);
		goto node79;
	}
node7178:
	b = true;
	if (b) {
		input[1] |= (1 << 6);
		goto node732;
	} else {
		input[1] &= ~(1 << 6);
		return 0;
	}
node7503:
	b = randbool();
	if (b) {
		input[1] |= (1 << 2);
		goto node7645;
	} else {
		input[1] &= ~(1 << 2);
		goto node2874;
	}
node9283:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node137;
	} else {
		input[3] &= ~(1 << 2);
		goto node1445;
	}
node6516:
	b = false;
	if (b) {
		input[4] |= (1 << 4);
		return 0;
	} else {
		input[4] &= ~(1 << 4);
		goto node4549;
	}
node7113:
	b = true;
	if (b) {
		input[4] |= (1 << 3);
		goto node3258;
	} else {
		input[4] &= ~(1 << 3);
		return 0;
	}
node6472:
	b = randbool();
	if (b) {
		input[1] |= (1 << 5);
		goto node836;
	} else {
		input[1] &= ~(1 << 5);
		return 2;
	}
node4928:
	b = randbool();
	if (b) {
		input[1] |= (1 << 3);
		goto node6643;
	} else {
		input[1] &= ~(1 << 3);
		goto node5097;
	}
node1045:
	b = true;
	if (b) {
		input[1] |= (1 << 1);
		goto node454;
	} else {
		input[1] &= ~(1 << 1);
		return 0;
	}
node8002:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node1160;
	} else {
		input[2] &= ~(1 << 4);
		goto node8146;
	}
node6354:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node7227;
	} else {
		input[2] &= ~(1 << 1);
		goto node1120;
	}
node9393:
	b = false;
	if (b) {
		input[4] |= (1 << 4);
		return 0;
	} else {
		input[4] &= ~(1 << 4);
		goto node467;
	}
node7536:
	b = false;
	if (b) {
		input[2] |= (1 << 3);
		return 0;
	} else {
		input[2] &= ~(1 << 3);
		goto node8671;
	}
node7975:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node7766;
	} else {
		input[3] &= ~(1 << 5);
		goto node5657;
	}
node4760:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node4451;
	} else {
		input[3] &= ~(1 << 4);
		goto node3520;
	}
node581:
	b = true;
	if (b) {
		input[4] |= (1 << 3);
		goto node1880;
	} else {
		input[4] &= ~(1 << 3);
		return 0;
	}
node5301:
	b = randbool();
	if (b) {
		input[1] |= (1 << 2);
		goto node1177;
	} else {
		input[1] &= ~(1 << 2);
		goto node5766;
	}
node7642:
	b = true;
	if (b) {
		input[1] |= (1 << 1);
		goto node4180;
	} else {
		input[1] &= ~(1 << 1);
		return 0;
	}
node2086:
	b = true;
	if (b) {
		input[2] |= (1 << 5);
		goto node9429;
	} else {
		input[2] &= ~(1 << 5);
		return 0;
	}
node4747:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node5724;
	} else {
		input[3] &= ~(1 << 7);
		goto node5481;
	}
node368:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node7573;
	} else {
		input[3] &= ~(1 << 5);
		goto node9350;
	}
node1188:
	b = randbool();
	if (b) {
		input[0] |= (1 << 0);
		goto node183;
	} else {
		input[0] &= ~(1 << 0);
		goto node7935;
	}
node6592:
	b = randbool();
	if (b) {
		input[1] |= (1 << 2);
		goto node41;
	} else {
		input[1] &= ~(1 << 2);
		goto node4201;
	}
node837:
	b = randbool();
	if (b) {
		input[1] |= (1 << 0);
		goto node3920;
	} else {
		input[1] &= ~(1 << 0);
		goto node6578;
	}
node3017:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node8364;
	} else {
		input[3] &= ~(1 << 6);
		goto node1052;
	}
node7766:
	b = true;
	if (b) {
		input[3] |= (1 << 2);
		goto node8783;
	} else {
		input[3] &= ~(1 << 2);
		return 0;
	}
node4908:
	b = randbool();
	if (b) {
		input[1] |= (1 << 4);
		goto node114;
	} else {
		input[1] &= ~(1 << 4);
		goto node6249;
	}
node9319:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node9218;
	} else {
		input[2] &= ~(1 << 2);
		goto node6553;
	}
node4247:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node5546;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node3434:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node5368;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node7935:
	b = randbool();
	if (b) {
		input[1] |= (1 << 7);
		goto node8510;
	} else {
		input[1] &= ~(1 << 7);
		goto node6786;
	}
node8071:
	b = false;
	if (b) {
		input[2] |= (1 << 5);
		return 0;
	} else {
		input[2] &= ~(1 << 5);
		goto node3760;
	}
node1731:
	b = false;
	if (b) {
		input[2] |= (1 << 3);
		return 0;
	} else {
		input[2] &= ~(1 << 3);
		goto node450;
	}
node4504:
	b = true;
	if (b) {
		input[3] |= (1 << 7);
		goto node838;
	} else {
		input[3] &= ~(1 << 7);
		return 0;
	}
node4144:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node2554;
	} else {
		input[3] &= ~(1 << 7);
		goto node6558;
	}
node6974:
	b = randbool();
	if (b) {
		input[5] |= (1 << 7);
		goto node9327;
	} else {
		input[5] &= ~(1 << 7);
		goto node4365;
	}
node5730:
	b = randbool();
	if (b) {
		input[1] |= (1 << 6);
		goto node1499;
	} else {
		input[1] &= ~(1 << 6);
		goto node8524;
	}
node2276:
	b = true;
	if (b) {
		input[2] |= (1 << 2);
		goto node1076;
	} else {
		input[2] &= ~(1 << 2);
		return 0;
	}
node8294:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node8548;
	}
node360:
	b = true;
	if (b) {
		input[4] |= (1 << 1);
		goto node5305;
	} else {
		input[4] &= ~(1 << 1);
		return 0;
	}
node953:
	b = true;
	if (b) {
		input[2] |= (1 << 6);
		goto node471;
	} else {
		input[2] &= ~(1 << 6);
		return 0;
	}
node3009:
	b = true;
	if (b) {
		input[3] |= (1 << 6);
		goto node383;
	} else {
		input[3] &= ~(1 << 6);
		return 0;
	}
node106:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node9030;
	} else {
		input[3] &= ~(1 << 6);
		goto node2867;
	}
node6708:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node7836;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node984:
	b = true;
	if (b) {
		input[4] |= (1 << 5);
		goto node2993;
	} else {
		input[4] &= ~(1 << 5);
		return 0;
	}
node7206:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node8211;
	}
node6812:
	b = false;
	if (b) {
		input[3] |= (1 << 6);
		return 0;
	} else {
		input[3] &= ~(1 << 6);
		goto node5539;
	}
node7240:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node1681;
	} else {
		input[3] &= ~(1 << 6);
		goto node5332;
	}
node1946:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node9452;
	} else {
		input[3] &= ~(1 << 4);
		goto node3600;
	}
node1104:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node4015;
	} else {
		input[3] &= ~(1 << 4);
		goto node334;
	}
node8739:
	b = false;
	if (b) {
		input[1] |= (1 << 6);
		return 0;
	} else {
		input[1] &= ~(1 << 6);
		goto node1062;
	}
node2046:
	b = false;
	if (b) {
		input[4] |= (1 << 3);
		return 0;
	} else {
		input[4] &= ~(1 << 3);
		goto node2297;
	}
node302:
	b = randbool();
	if (b) {
		input[4] |= (1 << 2);
		goto node325;
	} else {
		input[4] &= ~(1 << 2);
		goto node7321;
	}
node768:
	b = false;
	if (b) {
		input[6] |= (1 << 0);
		return 0;
	} else {
		input[6] &= ~(1 << 0);
		return 8;
	}
node4468:
	b = randbool();
	if (b) {
		input[2] |= (1 << 7);
		goto node4223;
	} else {
		input[2] &= ~(1 << 7);
		goto node5323;
	}
node4807:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node8076;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node5639:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node2671;
	} else {
		input[3] &= ~(1 << 4);
		goto node6076;
	}
node9351:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node3236;
	}
node3741:
	b = false;
	if (b) {
		input[3] |= (1 << 1);
		return 0;
	} else {
		input[3] &= ~(1 << 1);
		goto node3005;
	}
node2289:
	b = true;
	if (b) {
		input[3] |= (1 << 2);
		goto node5604;
	} else {
		input[3] &= ~(1 << 2);
		return 0;
	}
node782:
	b = randbool();
	if (b) {
		input[4] |= (1 << 5);
		goto node7644;
	} else {
		input[4] &= ~(1 << 5);
		goto node6858;
	}
node7810:
	b = randbool();
	if (b) {
		input[1] |= (1 << 1);
		goto node8616;
	} else {
		input[1] &= ~(1 << 1);
		goto node3122;
	}
node7316:
	b = true;
	if (b) {
		input[1] |= (1 << 1);
		goto node5071;
	} else {
		input[1] &= ~(1 << 1);
		return 0;
	}
node3173:
	b = true;
	if (b) {
		input[2] |= (1 << 3);
		goto node4202;
	} else {
		input[2] &= ~(1 << 3);
		return 0;
	}
node1841:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node6569;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node3506:
	b = true;
	if (b) {
		input[3] |= (1 << 2);
		goto node3741;
	} else {
		input[3] &= ~(1 << 2);
		return 0;
	}
node1920:
	b = false;
	if (b) {
		input[4] |= (1 << 3);
		return 0;
	} else {
		input[4] &= ~(1 << 3);
		goto node3679;
	}
node6379:
	b = false;
	if (b) {
		input[4] |= (1 << 3);
		return 0;
	} else {
		input[4] &= ~(1 << 3);
		goto node1611;
	}
node9374:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node3097;
	} else {
		input[2] &= ~(1 << 4);
		goto node7797;
	}
node4786:
	b = false;
	if (b) {
		input[2] |= (1 << 2);
		return 0;
	} else {
		input[2] &= ~(1 << 2);
		goto node6197;
	}
node3987:
	b = randbool();
	if (b) {
		input[3] |= (1 << 1);
		goto node1407;
	} else {
		input[3] &= ~(1 << 1);
		goto node4403;
	}
node4368:
	b = true;
	if (b) {
		input[0] |= (1 << 1);
		goto node5108;
	} else {
		input[0] &= ~(1 << 1);
		return 0;
	}
node3115:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node851;
	} else {
		input[2] &= ~(1 << 1);
		goto node7887;
	}
node146:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		goto node6434;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node430:
	b = true;
	if (b) {
		input[5] |= (1 << 5);
		goto node2073;
	} else {
		input[5] &= ~(1 << 5);
		return 0;
	}
node3483:
	b = false;
	if (b) {
		input[1] |= (1 << 3);
		return 0;
	} else {
		input[1] &= ~(1 << 3);
		goto node2534;
	}
node3207:
	b = randbool();
	if (b) {
		input[1] |= (1 << 1);
		goto node1665;
	} else {
		input[1] &= ~(1 << 1);
		goto node1339;
	}
node5350:
	b = true;
	if (b) {
		input[1] |= (1 << 0);
		goto node26;
	} else {
		input[1] &= ~(1 << 0);
		return 0;
	}
node792:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node3462;
	} else {
		input[2] &= ~(1 << 3);
		goto node9346;
	}
node4196:
	b = true;
	if (b) {
		input[2] |= (1 << 3);
		goto node9174;
	} else {
		input[2] &= ~(1 << 3);
		return 0;
	}
node2941:
	b = true;
	if (b) {
		input[3] |= (1 << 6);
		goto node6058;
	} else {
		input[3] &= ~(1 << 6);
		return 0;
	}
node5702:
	b = randbool();
	if (b) {
		input[0] |= (1 << 5);
		goto node7984;
	} else {
		input[0] &= ~(1 << 5);
		goto node2272;
	}
node2577:
	b = true;
	if (b) {
		input[1] |= (1 << 1);
		goto node3773;
	} else {
		input[1] &= ~(1 << 1);
		return 0;
	}
node5154:
	b = false;
	if (b) {
		input[2] |= (1 << 5);
		return 0;
	} else {
		input[2] &= ~(1 << 5);
		goto node4185;
	}
node5145:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node1536;
	} else {
		input[3] &= ~(1 << 6);
		goto node3756;
	}
node6842:
	b = randbool();
	if (b) {
		input[4] |= (1 << 4);
		goto node467;
	} else {
		input[4] &= ~(1 << 4);
		goto node5069;
	}
node1088:
	b = false;
	if (b) {
		input[3] |= (1 << 7);
		return 0;
	} else {
		input[3] &= ~(1 << 7);
		goto node7330;
	}
node4415:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node3643;
	} else {
		input[3] &= ~(1 << 3);
		goto node2296;
	}
node4130:
	b = false;
	if (b) {
		input[3] |= (1 << 2);
		return 0;
	} else {
		input[3] &= ~(1 << 2);
		goto node2530;
	}
node7429:
	b = false;
	if (b) {
		input[3] |= (1 << 2);
		return 0;
	} else {
		input[3] &= ~(1 << 2);
		goto node8801;
	}
node2339:
	b = false;
	if (b) {
		input[4] |= (1 << 4);
		return 0;
	} else {
		input[4] &= ~(1 << 4);
		goto node4631;
	}
node798:
	b = false;
	if (b) {
		input[5] |= (1 << 0);
		return 0;
	} else {
		input[5] &= ~(1 << 0);
		goto node2006;
	}
node7358:
	b = false;
	if (b) {
		input[2] |= (1 << 3);
		return 0;
	} else {
		input[2] &= ~(1 << 3);
		goto node3445;
	}
node4096:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node4932;
	} else {
		input[2] &= ~(1 << 1);
		goto node6775;
	}
node8884:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node8666;
	} else {
		input[3] &= ~(1 << 7);
		goto node7319;
	}
node6240:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node8805;
	} else {
		input[3] &= ~(1 << 3);
		goto node759;
	}
node6642:
	b = randbool();
	if (b) {
		input[1] |= (1 << 2);
		return 6;
	} else {
		input[1] &= ~(1 << 2);
		goto node1743;
	}
node1937:
	b = randbool();
	if (b) {
		input[1] |= (1 << 0);
		goto node4909;
	} else {
		input[1] &= ~(1 << 0);
		goto node6186;
	}
node6867:
	b = true;
	if (b) {
		input[2] |= (1 << 5);
		goto node1702;
	} else {
		input[2] &= ~(1 << 5);
		return 0;
	}
node5632:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node366;
	} else {
		input[2] &= ~(1 << 1);
		goto node8092;
	}
node2305:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node3726;
	}
node6525:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node9254;
	} else {
		input[3] &= ~(1 << 3);
		goto node1345;
	}
node1933:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node5720;
	}
node8019:
	b = true;
	if (b) {
		input[4] |= (1 << 7);
		goto node6119;
	} else {
		input[4] &= ~(1 << 7);
		return 0;
	}
node5371:
	b = randbool();
	if (b) {
		input[0] |= (1 << 0);
		goto node6680;
	} else {
		input[0] &= ~(1 << 0);
		goto node5253;
	}
node9155:
	b = randbool();
	if (b) {
		input[1] |= (1 << 4);
		goto node5924;
	} else {
		input[1] &= ~(1 << 4);
		goto node6520;
	}
node4796:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node521;
	} else {
		input[2] &= ~(1 << 6);
		goto node3810;
	}
node8012:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		goto node1868;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node7281:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node5482;
	} else {
		input[3] &= ~(1 << 6);
		goto node3952;
	}
node3779:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node4029;
	} else {
		input[3] &= ~(1 << 4);
		goto node1718;
	}
node2556:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node4751;
	} else {
		input[2] &= ~(1 << 4);
		goto node7493;
	}
node4143:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node5162;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node8973:
	b = false;
	if (b) {
		input[4] |= (1 << 7);
		return 0;
	} else {
		input[4] &= ~(1 << 7);
		goto node8452;
	}
node6714:
	b = randbool();
	if (b) {
		input[4] |= (1 << 5);
		goto node4898;
	} else {
		input[4] &= ~(1 << 5);
		goto node7983;
	}
node3176:
	b = true;
	if (b) {
		input[4] |= (1 << 4);
		goto node5048;
	} else {
		input[4] &= ~(1 << 4);
		return 0;
	}
node2539:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node3262;
	} else {
		input[2] &= ~(1 << 6);
		goto node227;
	}
node1124:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node2130;
	} else {
		input[2] &= ~(1 << 6);
		goto node8737;
	}
node7122:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		goto node6627;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node3974:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		return 5;
	} else {
		input[2] &= ~(1 << 1);
		goto node3465;
	}
node3460:
	b = randbool();
	if (b) {
		input[6] |= (1 << 5);
		goto node6694;
	} else {
		input[6] &= ~(1 << 5);
		goto node2042;
	}
node8098:
	b = false;
	if (b) {
		input[2] |= (1 << 2);
		return 0;
	} else {
		input[2] &= ~(1 << 2);
		goto node6575;
	}
node808:
	b = false;
	if (b) {
		input[2] |= (1 << 1);
		return 0;
	} else {
		input[2] &= ~(1 << 1);
		goto node1442;
	}
node3765:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node6177;
	}
node498:
	b = true;
	if (b) {
		input[1] |= (1 << 1);
		goto node2564;
	} else {
		input[1] &= ~(1 << 1);
		return 0;
	}
node2976:
	b = randbool();
	if (b) {
		input[2] |= (1 << 7);
		goto node853;
	} else {
		input[2] &= ~(1 << 7);
		goto node4328;
	}
node413:
	b = randbool();
	if (b) {
		input[2] |= (1 << 0);
		goto node8505;
	} else {
		input[2] &= ~(1 << 0);
		goto node7293;
	}
node251:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node5442;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node1071:
	b = false;
	if (b) {
		input[1] |= (1 << 0);
		return 0;
	} else {
		input[1] &= ~(1 << 0);
		goto node7140;
	}
node6224:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node2100;
	} else {
		input[2] &= ~(1 << 2);
		goto node2553;
	}
node2792:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node1325;
	} else {
		input[3] &= ~(1 << 6);
		goto node8034;
	}
node5907:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node2199;
	} else {
		input[3] &= ~(1 << 4);
		goto node1624;
	}
node7015:
	b = randbool();
	if (b) {
		input[4] |= (1 << 3);
		goto node598;
	} else {
		input[4] &= ~(1 << 3);
		goto node7576;
	}
node2325:
	b = randbool();
	if (b) {
		input[1] |= (1 << 2);
		goto node4818;
	} else {
		input[1] &= ~(1 << 2);
		goto node5543;
	}
node1197:
	b = false;
	if (b) {
		input[6] |= (1 << 7);
		return 0;
	} else {
		input[6] &= ~(1 << 7);
		goto node8897;
	}
node2478:
	b = true;
	if (b) {
		input[4] |= (1 << 4);
		goto node4372;
	} else {
		input[4] &= ~(1 << 4);
		return 0;
	}
node7921:
	b = randbool();
	if (b) {
		input[6] |= (1 << 5);
		goto node6401;
	} else {
		input[6] &= ~(1 << 5);
		goto node2092;
	}
node5110:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node8845;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node4674:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node5073;
	}
node9129:
	b = true;
	if (b) {
		input[1] |= (1 << 1);
		goto node6983;
	} else {
		input[1] &= ~(1 << 1);
		return 0;
	}
node1296:
	b = false;
	if (b) {
		input[2] |= (1 << 7);
		return 0;
	} else {
		input[2] &= ~(1 << 7);
		goto node4727;
	}
node8560:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node2049;
	} else {
		input[2] &= ~(1 << 4);
		goto node5360;
	}
node8210:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node7887;
	} else {
		input[2] &= ~(1 << 2);
		goto node907;
	}
node3822:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node7388;
	} else {
		input[2] &= ~(1 << 1);
		goto node9326;
	}
node9180:
	b = true;
	if (b) {
		input[3] |= (1 << 6);
		goto node2871;
	} else {
		input[3] &= ~(1 << 6);
		return 0;
	}
node2863:
	b = true;
	if (b) {
		input[4] |= (1 << 1);
		goto node4894;
	} else {
		input[4] &= ~(1 << 1);
		return 0;
	}
node2695:
	b = true;
	if (b) {
		input[1] |= (1 << 6);
		goto node1812;
	} else {
		input[1] &= ~(1 << 6);
		return 0;
	}
node2623:
	b = true;
	if (b) {
		input[2] |= (1 << 3);
		goto node5712;
	} else {
		input[2] &= ~(1 << 3);
		return 0;
	}
node6077:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node5252;
	} else {
		input[3] &= ~(1 << 2);
		goto node5653;
	}
node2286:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node6853;
	} else {
		input[2] &= ~(1 << 2);
		goto node808;
	}
node6377:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node2247;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node7283:
	b = randbool();
	if (b) {
		input[4] |= (1 << 7);
		goto node4024;
	} else {
		input[4] &= ~(1 << 7);
		goto node9437;
	}
node4670:
	b = false;
	if (b) {
		input[4] |= (1 << 3);
		return 0;
	} else {
		input[4] &= ~(1 << 3);
		goto node467;
	}
node2854:
	b = randbool();
	if (b) {
		input[1] |= (1 << 7);
		goto node5847;
	} else {
		input[1] &= ~(1 << 7);
		goto node8144;
	}
node4550:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node8470;
	} else {
		input[2] &= ~(1 << 6);
		goto node4310;
	}
node3546:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node8379;
	} else {
		input[3] &= ~(1 << 3);
		goto node5701;
	}
node6210:
	b = true;
	if (b) {
		input[3] |= (1 << 2);
		goto node6805;
	} else {
		input[3] &= ~(1 << 2);
		return 0;
	}
node9244:
	b = true;
	if (b) {
		input[3] |= (1 << 0);
		goto node4986;
	} else {
		input[3] &= ~(1 << 0);
		return 0;
	}
node917:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		goto node253;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node6435:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node2820;
	}
node1508:
	b = false;
	if (b) {
		input[3] |= (1 << 0);
		return 0;
	} else {
		input[3] &= ~(1 << 0);
		goto node8973;
	}
node354:
	b = false;
	if (b) {
		input[5] |= (1 << 5);
		return 0;
	} else {
		input[5] &= ~(1 << 5);
		goto node2385;
	}
node2665:
	b = randbool();
	if (b) {
		input[1] |= (1 << 5);
		goto node5097;
	} else {
		input[1] &= ~(1 << 5);
		goto node6384;
	}
node557:
	b = true;
	if (b) {
		input[2] |= (1 << 2);
		goto node5321;
	} else {
		input[2] &= ~(1 << 2);
		return 0;
	}
node8301:
	b = false;
	if (b) {
		input[2] |= (1 << 1);
		return 0;
	} else {
		input[2] &= ~(1 << 1);
		goto node3799;
	}
node4088:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node6391;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node572:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node2287;
	} else {
		input[3] &= ~(1 << 5);
		goto node3075;
	}
node9070:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node6917;
	} else {
		input[3] &= ~(1 << 3);
		goto node6462;
	}
node4059:
	b = randbool();
	if (b) {
		input[1] |= (1 << 7);
		goto node3900;
	} else {
		input[1] &= ~(1 << 7);
		goto node4121;
	}
node6615:
	b = true;
	if (b) {
		input[2] |= (1 << 3);
		goto node3854;
	} else {
		input[2] &= ~(1 << 3);
		return 0;
	}
node4720:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node3405;
	} else {
		input[2] &= ~(1 << 1);
		goto node117;
	}
node7036:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		goto node2625;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node1290:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node7429;
	} else {
		input[3] &= ~(1 << 4);
		goto node3280;
	}
node6845:
	b = false;
	if (b) {
		input[4] |= (1 << 2);
		return 0;
	} else {
		input[4] &= ~(1 << 2);
		goto node8463;
	}
node2472:
	b = randbool();
	if (b) {
		input[1] |= (1 << 3);
		goto node2161;
	} else {
		input[1] &= ~(1 << 3);
		goto node1930;
	}
node7292:
	b = false;
	if (b) {
		input[2] |= (1 << 2);
		return 0;
	} else {
		input[2] &= ~(1 << 2);
		goto node2582;
	}
node1226:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node222;
	} else {
		input[2] &= ~(1 << 2);
		return 3;
	}
node5327:
	b = true;
	if (b) {
		input[3] |= (1 << 1);
		goto node9244;
	} else {
		input[3] &= ~(1 << 1);
		return 0;
	}
node6637:
	b = randbool();
	if (b) {
		input[3] |= (1 << 1);
		goto node5983;
	} else {
		input[3] &= ~(1 << 1);
		goto node6037;
	}
node2421:
	b = true;
	if (b) {
		input[3] |= (1 << 0);
		goto node5759;
	} else {
		input[3] &= ~(1 << 0);
		return 0;
	}
node7182:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node616;
	} else {
		input[2] &= ~(1 << 4);
		goto node5159;
	}
node8812:
	b = true;
	if (b) {
		input[2] |= (1 << 2);
		goto node14;
	} else {
		input[2] &= ~(1 << 2);
		return 0;
	}
node5330:
	b = false;
	if (b) {
		input[2] |= (1 << 2);
		return 0;
	} else {
		input[2] &= ~(1 << 2);
		goto node719;
	}
node6738:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node5576;
	} else {
		input[3] &= ~(1 << 3);
		goto node7429;
	}
node3038:
	b = randbool();
	if (b) {
		input[3] |= (1 << 1);
		goto node5100;
	} else {
		input[3] &= ~(1 << 1);
		goto node5492;
	}
node8686:
	b = false;
	if (b) {
		input[3] |= (1 << 1);
		return 0;
	} else {
		input[3] &= ~(1 << 1);
		goto node3345;
	}
node7013:
	b = randbool();
	if (b) {
		input[1] |= (1 << 3);
		goto node2001;
	} else {
		input[1] &= ~(1 << 3);
		goto node525;
	}
node2003:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node6814;
	} else {
		input[2] &= ~(1 << 2);
		goto node1084;
	}
node4626:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		goto node2187;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node6412:
	b = false;
	if (b) {
		input[2] |= (1 << 0);
		return 0;
	} else {
		input[2] &= ~(1 << 0);
		goto node2167;
	}
node7381:
	b = false;
	if (b) {
		input[4] |= (1 << 4);
		return 0;
	} else {
		input[4] &= ~(1 << 4);
		goto node6650;
	}
node2258:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node2656;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node3297:
	b = randbool();
	if (b) {
		input[2] |= (1 << 0);
		goto node4696;
	} else {
		input[2] &= ~(1 << 0);
		goto node7730;
	}
node4477:
	b = randbool();
	if (b) {
		input[2] |= (1 << 0);
		goto node3576;
	} else {
		input[2] &= ~(1 << 0);
		goto node8870;
	}
node8053:
	b = false;
	if (b) {
		input[4] |= (1 << 7);
		return 0;
	} else {
		input[4] &= ~(1 << 7);
		goto node3844;
	}
node5030:
	b = false;
	if (b) {
		input[4] |= (1 << 3);
		return 0;
	} else {
		input[4] &= ~(1 << 3);
		goto node990;
	}
node6858:
	b = randbool();
	if (b) {
		input[4] |= (1 << 2);
		goto node2960;
	} else {
		input[4] &= ~(1 << 2);
		return 5;
	}
node938:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node489;
	} else {
		input[2] &= ~(1 << 2);
		goto node569;
	}
node8948:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node1578;
	} else {
		input[3] &= ~(1 << 7);
		goto node7425;
	}
node476:
	b = true;
	if (b) {
		input[3] |= (1 << 7);
		goto node6911;
	} else {
		input[3] &= ~(1 << 7);
		return 0;
	}
node6581:
	b = randbool();
	if (b) {
		input[1] |= (1 << 0);
		goto node3417;
	} else {
		input[1] &= ~(1 << 0);
		goto node428;
	}
node5747:
	b = true;
	if (b) {
		input[2] |= (1 << 4);
		goto node9089;
	} else {
		input[2] &= ~(1 << 4);
		return 0;
	}
node2742:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node9070;
	}
node6030:
	b = randbool();
	if (b) {
		input[4] |= (1 << 5);
		goto node7710;
	} else {
		input[4] &= ~(1 << 5);
		goto node4217;
	}
node7136:
	b = true;
	if (b) {
		input[4] |= (1 << 7);
		goto node9356;
	} else {
		input[4] &= ~(1 << 7);
		return 0;
	}
node3195:
	b = true;
	if (b) {
		input[2] |= (1 << 7);
		goto node328;
	} else {
		input[2] &= ~(1 << 7);
		return 0;
	}
node7731:
	b = randbool();
	if (b) {
		input[2] |= (1 << 7);
		goto node3337;
	} else {
		input[2] &= ~(1 << 7);
		goto node3861;
	}
node5165:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node4589;
	} else {
		input[2] &= ~(1 << 6);
		goto node8272;
	}
node1174:
	b = false;
	if (b) {
		input[2] |= (1 << 3);
		return 0;
	} else {
		input[2] &= ~(1 << 3);
		goto node7757;
	}
node5855:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node7243;
	} else {
		input[2] &= ~(1 << 3);
		goto node6404;
	}
node5089:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node1758;
	} else {
		input[3] &= ~(1 << 6);
		goto node3037;
	}
node2455:
	b = randbool();
	if (b) {
		input[0] |= (1 << 1);
		goto node1023;
	} else {
		input[0] &= ~(1 << 1);
		return 1;
	}
node7476:
	b = false;
	if (b) {
		input[2] |= (1 << 6);
		return 0;
	} else {
		input[2] &= ~(1 << 6);
		goto node3983;
	}
node1672:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node1960;
	} else {
		input[2] &= ~(1 << 5);
		goto node2965;
	}
node1964:
	b = randbool();
	if (b) {
		input[3] |= (1 << 1);
		goto node3995;
	} else {
		input[3] &= ~(1 << 1);
		goto node5960;
	}
node8200:
	b = false;
	if (b) {
		input[4] |= (1 << 1);
		return 0;
	} else {
		input[4] &= ~(1 << 1);
		goto node2367;
	}
node5860:
	b = true;
	if (b) {
		input[3] |= (1 << 6);
		goto node6690;
	} else {
		input[3] &= ~(1 << 6);
		return 0;
	}
node5376:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node5700;
	} else {
		input[3] &= ~(1 << 6);
		goto node4088;
	}
node6571:
	b = true;
	if (b) {
		input[1] |= (1 << 1);
		goto node5142;
	} else {
		input[1] &= ~(1 << 1);
		return 0;
	}
node1361:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node2666;
	} else {
		input[2] &= ~(1 << 4);
		goto node9215;
	}
node3637:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node8971;
	} else {
		input[2] &= ~(1 << 4);
		goto node4447;
	}
node315:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node3191;
	} else {
		input[2] &= ~(1 << 3);
		goto node1465;
	}
node4503:
	b = false;
	if (b) {
		input[2] |= (1 << 0);
		return 0;
	} else {
		input[2] &= ~(1 << 0);
		goto node8421;
	}
node8251:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node292;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node1511:
	b = randbool();
	if (b) {
		input[5] |= (1 << 5);
		goto node2249;
	} else {
		input[5] &= ~(1 << 5);
		goto node4199;
	}
node5454:
	b = randbool();
	if (b) {
		input[1] |= (1 << 2);
		goto node2577;
	} else {
		input[1] &= ~(1 << 2);
		goto node2843;
	}
node2150:
	b = true;
	if (b) {
		input[3] |= (1 << 7);
		goto node3606;
	} else {
		input[3] &= ~(1 << 7);
		return 0;
	}
node5268:
	b = true;
	if (b) {
		input[3] |= (1 << 7);
		goto node2383;
	} else {
		input[3] &= ~(1 << 7);
		return 0;
	}
node7166:
	b = true;
	if (b) {
		input[4] |= (1 << 5);
		goto node9050;
	} else {
		input[4] &= ~(1 << 5);
		return 0;
	}
node5867:
	b = false;
	if (b) {
		input[1] |= (1 << 5);
		return 0;
	} else {
		input[1] &= ~(1 << 5);
		goto node7288;
	}
node8345:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node5737;
	} else {
		input[2] &= ~(1 << 5);
		goto node2130;
	}
node4347:
	b = false;
	if (b) {
		input[2] |= (1 << 0);
		return 0;
	} else {
		input[2] &= ~(1 << 0);
		goto node3612;
	}
node6254:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node5166;
	} else {
		input[3] &= ~(1 << 4);
		goto node8579;
	}
node6513:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node2450;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node8139:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node2652;
	} else {
		input[3] &= ~(1 << 3);
		goto node2663;
	}
node4860:
	b = false;
	if (b) {
		input[2] |= (1 << 5);
		return 0;
	} else {
		input[2] &= ~(1 << 5);
		goto node8136;
	}
node4564:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		return 3;
	} else {
		input[2] &= ~(1 << 4);
		goto node2299;
	}
node2131:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node2119;
	} else {
		input[3] &= ~(1 << 5);
		goto node318;
	}
node5184:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node4465;
	} else {
		input[3] &= ~(1 << 5);
		goto node5391;
	}
node5083:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node3055;
	} else {
		input[3] &= ~(1 << 2);
		goto node6297;
	}
node2310:
	b = true;
	if (b) {
		input[1] |= (1 << 2);
		goto node2019;
	} else {
		input[1] &= ~(1 << 2);
		return 0;
	}
node3812:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node6588;
	} else {
		input[3] &= ~(1 << 7);
		goto node7618;
	}
node6415:
	b = true;
	if (b) {
		input[3] |= (1 << 0);
		return 5;
	} else {
		input[3] &= ~(1 << 0);
		return 0;
	}
node8426:
	b = true;
	if (b) {
		input[1] |= (1 << 0);
		goto node7028;
	} else {
		input[1] &= ~(1 << 0);
		return 0;
	}
node3863:
	b = false;
	if (b) {
		input[2] |= (1 << 2);
		return 0;
	} else {
		input[2] &= ~(1 << 2);
		goto node190;
	}
node2675:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node3516;
	} else {
		input[2] &= ~(1 << 2);
		goto node3102;
	}
node9330:
	b = false;
	if (b) {
		input[2] |= (1 << 1);
		return 0;
	} else {
		input[2] &= ~(1 << 1);
		goto node436;
	}
node1780:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node8235;
	} else {
		input[3] &= ~(1 << 3);
		goto node58;
	}
node2775:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node8879;
	} else {
		input[2] &= ~(1 << 2);
		goto node4249;
	}
node1588:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node8012;
	} else {
		input[2] &= ~(1 << 2);
		goto node8879;
	}
node366:
	b = randbool();
	if (b) {
		input[2] |= (1 << 0);
		goto node2483;
	} else {
		input[2] &= ~(1 << 0);
		goto node2029;
	}
node207:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node2881;
	} else {
		input[2] &= ~(1 << 5);
		goto node736;
	}
node5660:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node7154;
	} else {
		input[2] &= ~(1 << 1);
		goto node4790;
	}
node4304:
	b = randbool();
	if (b) {
		input[2] |= (1 << 0);
		goto node9458;
	} else {
		input[2] &= ~(1 << 0);
		goto node2678;
	}
node1191:
	b = true;
	if (b) {
		input[4] |= (1 << 4);
		goto node6759;
	} else {
		input[4] &= ~(1 << 4);
		return 0;
	}
node4818:
	b = true;
	if (b) {
		input[1] |= (1 << 1);
		goto node6402;
	} else {
		input[1] &= ~(1 << 1);
		return 0;
	}
node6946:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node3023;
	} else {
		input[2] &= ~(1 << 1);
		goto node482;
	}
node3048:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node235;
	} else {
		input[3] &= ~(1 << 4);
		goto node6382;
	}
node8695:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node7047;
	} else {
		input[2] &= ~(1 << 5);
		goto node3825;
	}
node6279:
	b = true;
	if (b) {
		input[2] |= (1 << 4);
		goto node1597;
	} else {
		input[2] &= ~(1 << 4);
		return 0;
	}
node4367:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node9194;
	}
node7438:
	b = true;
	if (b) {
		input[3] |= (1 << 2);
		goto node673;
	} else {
		input[3] &= ~(1 << 2);
		return 0;
	}
node7417:
	b = false;
	if (b) {
		input[4] |= (1 << 0);
		return 0;
	} else {
		input[4] &= ~(1 << 0);
		goto node9168;
	}
node2985:
	b = true;
	if (b) {
		input[2] |= (1 << 6);
		goto node98;
	} else {
		input[2] &= ~(1 << 6);
		return 0;
	}
node1587:
	b = true;
	if (b) {
		input[4] |= (1 << 5);
		goto node7714;
	} else {
		input[4] &= ~(1 << 5);
		return 0;
	}
node4455:
	b = randbool();
	if (b) {
		input[1] |= (1 << 5);
		goto node5070;
	} else {
		input[1] &= ~(1 << 5);
		goto node783;
	}
node7426:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node7418;
	} else {
		input[3] &= ~(1 << 6);
		goto node7481;
	}
node6648:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node1976;
	}
node490:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node8900;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node6953:
	b = true;
	if (b) {
		input[2] |= (1 << 2);
		goto node758;
	} else {
		input[2] &= ~(1 << 2);
		return 0;
	}
node4713:
	b = false;
	if (b) {
		input[3] |= (1 << 7);
		return 0;
	} else {
		input[3] &= ~(1 << 7);
		goto node4716;
	}
node9005:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node2336;
	} else {
		input[3] &= ~(1 << 6);
		goto node7138;
	}
node6011:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node8619;
	} else {
		input[3] &= ~(1 << 5);
		goto node5582;
	}
node1591:
	b = false;
	if (b) {
		input[3] |= (1 << 2);
		return 0;
	} else {
		input[3] &= ~(1 << 2);
		goto node4845;
	}
node6148:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node4826;
	} else {
		input[2] &= ~(1 << 3);
		goto node8797;
	}
node7622:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node1450;
	} else {
		input[2] &= ~(1 << 2);
		goto node6670;
	}
node7898:
	b = true;
	if (b) {
		input[3] |= (1 << 7);
		goto node4814;
	} else {
		input[3] &= ~(1 << 7);
		return 0;
	}
node4140:
	b = randbool();
	if (b) {
		input[4] |= (1 << 5);
		goto node1364;
	} else {
		input[4] &= ~(1 << 5);
		goto node1148;
	}
node2533:
	b = true;
	if (b) {
		input[5] |= (1 << 3);
		goto node5645;
	} else {
		input[5] &= ~(1 << 3);
		return 0;
	}
node7640:
	b = true;
	if (b) {
		input[1] |= (1 << 3);
		goto node3468;
	} else {
		input[1] &= ~(1 << 3);
		return 0;
	}
node733:
	b = true;
	if (b) {
		input[1] |= (1 << 0);
		goto node542;
	} else {
		input[1] &= ~(1 << 0);
		return 0;
	}
node5671:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node4847;
	} else {
		input[2] &= ~(1 << 3);
		goto node7887;
	}
node277:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node4734;
	} else {
		input[3] &= ~(1 << 6);
		goto node5384;
	}
node8610:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node385;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node7012:
	b = randbool();
	if (b) {
		input[4] |= (1 << 4);
		goto node3490;
	} else {
		input[4] &= ~(1 << 4);
		goto node6659;
	}
node2502:
	b = randbool();
	if (b) {
		input[1] |= (1 << 5);
		goto node682;
	} else {
		input[1] &= ~(1 << 5);
		return 3;
	}
node9245:
	b = randbool();
	if (b) {
		input[5] |= (1 << 1);
		return 7;
	} else {
		input[5] &= ~(1 << 1);
		goto node224;
	}
node2284:
	b = randbool();
	if (b) {
		input[4] |= (1 << 2);
		goto node8200;
	} else {
		input[4] &= ~(1 << 2);
		goto node702;
	}
node3292:
	b = randbool();
	if (b) {
		input[2] |= (1 << 7);
		goto node7734;
	} else {
		input[2] &= ~(1 << 7);
		goto node4653;
	}
node588:
	b = randbool();
	if (b) {
		input[2] |= (1 << 7);
		goto node4276;
	} else {
		input[2] &= ~(1 << 7);
		goto node4334;
	}
node1535:
	b = true;
	if (b) {
		input[3] |= (1 << 6);
		goto node329;
	} else {
		input[3] &= ~(1 << 6);
		return 0;
	}
node2115:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node2746;
	}
node1346:
	b = true;
	if (b) {
		input[4] |= (1 << 6);
		goto node6321;
	} else {
		input[4] &= ~(1 << 6);
		return 0;
	}
node426:
	b = randbool();
	if (b) {
		input[4] |= (1 << 6);
		goto node9204;
	} else {
		input[4] &= ~(1 << 6);
		goto node3565;
	}
node3714:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node8090;
	} else {
		input[2] &= ~(1 << 4);
		goto node4258;
	}
node4458:
	b = true;
	if (b) {
		input[3] |= (1 << 7);
		goto node4298;
	} else {
		input[3] &= ~(1 << 7);
		return 0;
	}
node8449:
	b = true;
	if (b) {
		input[3] |= (1 << 6);
		goto node9267;
	} else {
		input[3] &= ~(1 << 6);
		return 0;
	}
node3775:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node578;
	} else {
		input[3] &= ~(1 << 5);
		goto node289;
	}
node1180:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node7852;
	} else {
		input[3] &= ~(1 << 3);
		goto node1383;
	}
node9253:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node6194;
	} else {
		input[3] &= ~(1 << 2);
		goto node8854;
	}
node3943:
	b = randbool();
	if (b) {
		input[0] |= (1 << 0);
		goto node751;
	} else {
		input[0] &= ~(1 << 0);
		goto node4937;
	}
node5274:
	b = randbool();
	if (b) {
		input[1] |= (1 << 5);
		goto node4025;
	} else {
		input[1] &= ~(1 << 5);
		goto node3659;
	}
node2890:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node4181;
	} else {
		input[2] &= ~(1 << 3);
		goto node2293;
	}
node8640:
	b = true;
	if (b) {
		input[3] |= (1 << 6);
		goto node5763;
	} else {
		input[3] &= ~(1 << 6);
		return 0;
	}
node5014:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node3457;
	} else {
		input[3] &= ~(1 << 4);
		goto node9312;
	}
node4593:
	b = randbool();
	if (b) {
		input[1] |= (1 << 4);
		goto node1930;
	} else {
		input[1] &= ~(1 << 4);
		goto node7398;
	}
node7378:
	b = false;
	if (b) {
		input[1] |= (1 << 1);
		return 0;
	} else {
		input[1] &= ~(1 << 1);
		goto node1971;
	}
node3198:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node5768;
	} else {
		input[2] &= ~(1 << 5);
		goto node9144;
	}
node7676:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node8920;
	}
node8852:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node5345;
	} else {
		input[2] &= ~(1 << 1);
		goto node1995;
	}
node8801:
	b = false;
	if (b) {
		input[3] |= (1 << 1);
		return 0;
	} else {
		input[3] &= ~(1 << 1);
		goto node4735;
	}
node1965:
	b = false;
	if (b) {
		input[4] |= (1 << 3);
		return 0;
	} else {
		input[4] &= ~(1 << 3);
		goto node3764;
	}
node1254:
	b = true;
	if (b) {
		input[4] |= (1 << 2);
		goto node81;
	} else {
		input[4] &= ~(1 << 2);
		return 0;
	}
node5985:
	b = false;
	if (b) {
		input[5] |= (1 << 5);
		return 0;
	} else {
		input[5] &= ~(1 << 5);
		goto node6026;
	}
node6184:
	b = false;
	if (b) {
		input[3] |= (1 << 1);
		return 0;
	} else {
		input[3] &= ~(1 << 1);
		return 4;
	}
node842:
	b = true;
	if (b) {
		input[4] |= (1 << 2);
		goto node7416;
	} else {
		input[4] &= ~(1 << 2);
		return 0;
	}
node5654:
	b = randbool();
	if (b) {
		input[1] |= (1 << 0);
		goto node1259;
	} else {
		input[1] &= ~(1 << 0);
		goto node763;
	}
node4001:
	b = randbool();
	if (b) {
		input[2] |= (1 << 7);
		goto node7399;
	} else {
		input[2] &= ~(1 << 7);
		goto node5351;
	}
node1059:
	b = randbool();
	if (b) {
		input[2] |= (1 << 0);
		goto node6562;
	} else {
		input[2] &= ~(1 << 0);
		goto node6748;
	}
node7604:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node8864;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node4159:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node3450;
	} else {
		input[3] &= ~(1 << 5);
		goto node5907;
	}
node5205:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node5018;
	}
node83:
	b = true;
	if (b) {
		input[1] |= (1 << 1);
		goto node1112;
	} else {
		input[1] &= ~(1 << 1);
		return 0;
	}
node2632:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		goto node6780;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node9461:
	b = false;
	if (b) {
		input[2] |= (1 << 0);
		return 0;
	} else {
		input[2] &= ~(1 << 0);
		goto node9405;
	}
node3303:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		return 3;
	} else {
		input[2] &= ~(1 << 4);
		goto node1143;
	}
node7023:
	b = false;
	if (b) {
		input[2] |= (1 << 3);
		return 0;
	} else {
		input[2] &= ~(1 << 3);
		goto node3753;
	}
node9377:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node2109;
	} else {
		input[3] &= ~(1 << 4);
		goto node8494;
	}
node411:
	b = randbool();
	if (b) {
		input[5] |= (1 << 4);
		goto node9230;
	} else {
		input[5] &= ~(1 << 4);
		goto node3446;
	}
node4284:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node4023;
	} else {
		input[3] &= ~(1 << 4);
		goto node2021;
	}
node4523:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node234;
	} else {
		input[3] &= ~(1 << 4);
		goto node794;
	}
node5038:
	b = randbool();
	if (b) {
		input[7] |= (1 << 6);
		goto node3133;
	} else {
		input[7] &= ~(1 << 6);
		goto node3058;
	}
node650:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node7545;
	} else {
		input[3] &= ~(1 << 6);
		goto node6086;
	}
node5333:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node5727;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node2186:
	b = randbool();
	if (b) {
		input[4] |= (1 << 3);
		goto node5729;
	} else {
		input[4] &= ~(1 << 3);
		goto node4420;
	}
node6982:
	b = randbool();
	if (b) {
		input[1] |= (1 << 7);
		goto node6619;
	} else {
		input[1] &= ~(1 << 7);
		goto node4121;
	}
node5592:
	b = randbool();
	if (b) {
		input[1] |= (1 << 5);
		goto node3436;
	} else {
		input[1] &= ~(1 << 5);
		goto node3205;
	}
node8519:
	b = randbool();
	if (b) {
		input[1] |= (1 << 5);
		goto node7077;
	} else {
		input[1] &= ~(1 << 5);
		goto node3468;
	}
node2954:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node2317;
	} else {
		input[2] &= ~(1 << 5);
		goto node982;
	}
node5185:
	b = false;
	if (b) {
		input[2] |= (1 << 3);
		return 0;
	} else {
		input[2] &= ~(1 << 3);
		goto node3629;
	}
node220:
	b = randbool();
	if (b) {
		input[4] |= (1 << 6);
		goto node5151;
	} else {
		input[4] &= ~(1 << 6);
		goto node5943;
	}
node4137:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node1226;
	} else {
		input[2] &= ~(1 << 5);
		goto node7335;
	}
node8607:
	b = false;
	if (b) {
		input[2] |= (1 << 3);
		return 0;
	} else {
		input[2] &= ~(1 << 3);
		goto node3825;
	}
node6538:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node9380;
	} else {
		input[3] &= ~(1 << 6);
		goto node844;
	}
node6970:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node2858;
	} else {
		input[3] &= ~(1 << 6);
		goto node2071;
	}
node1068:
	b = randbool();
	if (b) {
		input[5] |= (1 << 6);
		goto node2385;
	} else {
		input[5] &= ~(1 << 6);
		goto node5497;
	}
node2178:
	b = true;
	if (b) {
		input[2] |= (1 << 6);
		goto node4860;
	} else {
		input[2] &= ~(1 << 6);
		return 0;
	}
node899:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node9214;
	} else {
		input[2] &= ~(1 << 6);
		goto node7728;
	}
node2029:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node9258;
	} else {
		input[3] &= ~(1 << 7);
		goto node2569;
	}
node6558:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node2162;
	} else {
		input[3] &= ~(1 << 6);
		goto node2391;
	}
node1258:
	b = randbool();
	if (b) {
		input[4] |= (1 << 7);
		goto node5496;
	} else {
		input[4] &= ~(1 << 7);
		goto node5554;
	}
node513:
	b = false;
	if (b) {
		input[4] |= (1 << 3);
		return 0;
	} else {
		input[4] &= ~(1 << 3);
		goto node6347;
	}
node7188:
	b = false;
	if (b) {
		input[1] |= (1 << 2);
		return 0;
	} else {
		input[1] &= ~(1 << 2);
		goto node4344;
	}
node26:
	b = randbool();
	if (b) {
		input[2] |= (1 << 7);
		goto node2178;
	} else {
		input[2] &= ~(1 << 7);
		goto node3866;
	}
node4069:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node6958;
	} else {
		input[3] &= ~(1 << 4);
		goto node7632;
	}
node1712:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node5190;
	} else {
		input[3] &= ~(1 << 4);
		goto node8548;
	}
node3671:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		return 4;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node2544:
	b = randbool();
	if (b) {
		input[2] |= (1 << 7);
		goto node5168;
	} else {
		input[2] &= ~(1 << 7);
		goto node5133;
	}
node7757:
	b = false;
	if (b) {
		input[2] |= (1 << 2);
		return 0;
	} else {
		input[2] &= ~(1 << 2);
		goto node3538;
	}
node7697:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node8391;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node5504:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node2133;
	}
node801:
	b = true;
	if (b) {
		input[1] |= (1 << 0);
		goto node7140;
	} else {
		input[1] &= ~(1 << 0);
		return 0;
	}
node4727:
	b = false;
	if (b) {
		input[2] |= (1 << 6);
		return 0;
	} else {
		input[2] &= ~(1 << 6);
		goto node1332;
	}
node1857:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node5914;
	} else {
		input[2] &= ~(1 << 4);
		goto node8272;
	}
node3582:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		goto node3897;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node9251:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node1953;
	}
node4015:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node3453;
	} else {
		input[3] &= ~(1 << 3);
		goto node7932;
	}
node53:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node3896;
	}
node7614:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node196;
	} else {
		input[3] &= ~(1 << 4);
		goto node5917;
	}
node5569:
	b = false;
	if (b) {
		input[3] |= (1 << 0);
		return 0;
	} else {
		input[3] &= ~(1 << 0);
		goto node2373;
	}
node7834:
	b = randbool();
	if (b) {
		input[6] |= (1 << 4);
		goto node2042;
	} else {
		input[6] &= ~(1 << 4);
		goto node8333;
	}
node1947:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node4963;
	} else {
		input[3] &= ~(1 << 4);
		goto node3506;
	}
node8398:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node6092;
	}
node8805:
	b = false;
	if (b) {
		input[3] |= (1 << 2);
		return 0;
	} else {
		input[3] &= ~(1 << 2);
		goto node7452;
	}
node3679:
	b = false;
	if (b) {
		input[4] |= (1 << 2);
		return 0;
	} else {
		input[4] &= ~(1 << 2);
		goto node360;
	}
node1890:
	b = randbool();
	if (b) {
		input[1] |= (1 << 7);
		goto node6333;
	} else {
		input[1] &= ~(1 << 7);
		goto node3585;
	}
node4385:
	b = true;
	if (b) {
		input[4] |= (1 << 5);
		goto node7163;
	} else {
		input[4] &= ~(1 << 5);
		return 0;
	}
node8775:
	b = false;
	if (b) {
		input[2] |= (1 << 5);
		return 0;
	} else {
		input[2] &= ~(1 << 5);
		goto node221;
	}
node6484:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node4543;
	} else {
		input[3] &= ~(1 << 5);
		goto node5153;
	}
node3479:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node8365;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node7310:
	b = randbool();
	if (b) {
		input[5] |= (1 << 1);
		return 7;
	} else {
		input[5] &= ~(1 << 1);
		goto node6120;
	}
node7454:
	b = randbool();
	if (b) {
		input[1] |= (1 << 1);
		goto node1603;
	} else {
		input[1] &= ~(1 << 1);
		goto node2229;
	}
node589:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node6323;
	} else {
		input[2] &= ~(1 << 5);
		goto node2723;
	}
node6930:
	b = false;
	if (b) {
		input[4] |= (1 << 2);
		return 0;
	} else {
		input[4] &= ~(1 << 2);
		goto node697;
	}
node3121:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node7632;
	} else {
		input[3] &= ~(1 << 2);
		goto node8205;
	}
node8352:
	b = randbool();
	if (b) {
		input[1] |= (1 << 6);
		goto node8913;
	} else {
		input[1] &= ~(1 << 6);
		goto node5735;
	}
node1516:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node5247;
	} else {
		input[2] &= ~(1 << 4);
		goto node2130;
	}
node2546:
	b = true;
	if (b) {
		input[2] |= (1 << 4);
		goto node2372;
	} else {
		input[2] &= ~(1 << 4);
		return 0;
	}
node6072:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node7887;
	} else {
		input[2] &= ~(1 << 2);
		goto node851;
	}
node6654:
	b = randbool();
	if (b) {
		input[2] |= (1 << 0);
		goto node1893;
	} else {
		input[2] &= ~(1 << 0);
		goto node1162;
	}
node5555:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node2114;
	} else {
		input[3] &= ~(1 << 7);
		goto node223;
	}
node45:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node2198;
	} else {
		input[2] &= ~(1 << 5);
		goto node1486;
	}
node3370:
	b = true;
	if (b) {
		input[2] |= (1 << 3);
		goto node3825;
	} else {
		input[2] &= ~(1 << 3);
		return 0;
	}
node9081:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node8173;
	} else {
		input[3] &= ~(1 << 4);
		goto node3389;
	}
node2521:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node3520;
	} else {
		input[3] &= ~(1 << 3);
		goto node529;
	}
node5407:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node2181;
	} else {
		input[3] &= ~(1 << 2);
		goto node9388;
	}
node8386:
	b = randbool();
	if (b) {
		input[2] |= (1 << 0);
		goto node5345;
	} else {
		input[2] &= ~(1 << 0);
		goto node2136;
	}
node6948:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node5316;
	} else {
		input[3] &= ~(1 << 3);
		goto node7462;
	}
node151:
	b = false;
	if (b) {
		input[4] |= (1 << 2);
		return 0;
	} else {
		input[4] &= ~(1 << 2);
		goto node9365;
	}
node5566:
	b = true;
	if (b) {
		input[2] |= (1 << 5);
		goto node1734;
	} else {
		input[2] &= ~(1 << 5);
		return 0;
	}
node5416:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node9361;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node6567:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		return 5;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node2244:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node6134;
	} else {
		input[3] &= ~(1 << 3);
		goto node9076;
	}
node762:
	b = randbool();
	if (b) {
		input[1] |= (1 << 0);
		goto node7727;
	} else {
		input[1] &= ~(1 << 0);
		goto node7277;
	}
node6396:
	b = true;
	if (b) {
		input[1] |= (1 << 0);
		goto node1271;
	} else {
		input[1] &= ~(1 << 0);
		return 0;
	}
node6818:
	b = false;
	if (b) {
		input[4] |= (1 << 7);
		return 0;
	} else {
		input[4] &= ~(1 << 7);
		goto node1698;
	}
node7679:
	b = true;
	if (b) {
		input[4] |= (1 << 2);
		goto node8305;
	} else {
		input[4] &= ~(1 << 2);
		return 0;
	}
node7110:
	b = false;
	if (b) {
		input[4] |= (1 << 1);
		return 0;
	} else {
		input[4] &= ~(1 << 1);
		goto node439;
	}
node6774:
	b = true;
	if (b) {
		input[2] |= (1 << 3);
		goto node5362;
	} else {
		input[2] &= ~(1 << 3);
		return 0;
	}
node3397:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node808;
	} else {
		input[2] &= ~(1 << 2);
		goto node8147;
	}
node1409:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node3415;
	} else {
		input[3] &= ~(1 << 5);
		goto node8028;
	}
node8242:
	b = randbool();
	if (b) {
		input[3] |= (1 << 1);
		goto node3520;
	} else {
		input[3] &= ~(1 << 1);
		goto node4357;
	}
node120:
	b = randbool();
	if (b) {
		input[3] |= (1 << 1);
		goto node324;
	} else {
		input[3] &= ~(1 << 1);
		goto node1777;
	}
node4365:
	b = randbool();
	if (b) {
		input[5] |= (1 << 6);
		goto node9327;
	} else {
		input[5] &= ~(1 << 6);
		goto node9230;
	}
node4968:
	b = false;
	if (b) {
		input[2] |= (1 << 5);
		return 0;
	} else {
		input[2] &= ~(1 << 5);
		goto node757;
	}
node8389:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		goto node4240;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node5178:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node213;
	} else {
		input[3] &= ~(1 << 5);
		goto node4548;
	}
node2629:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node339;
	}
node8673:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node3520;
	} else {
		input[3] &= ~(1 << 3);
		goto node1983;
	}
node3107:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node4204;
	} else {
		input[3] &= ~(1 << 3);
		goto node3520;
	}
node2301:
	b = randbool();
	if (b) {
		input[1] |= (1 << 2);
		goto node3737;
	} else {
		input[1] &= ~(1 << 2);
		goto node6008;
	}
node8726:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node99;
	}
node7320:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node5510;
	}
node4350:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node8070;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node8967:
	b = false;
	if (b) {
		input[2] |= (1 << 1);
		return 0;
	} else {
		input[2] &= ~(1 << 1);
		goto node3798;
	}
node622:
	b = false;
	if (b) {
		input[3] |= (1 << 6);
		return 0;
	} else {
		input[3] &= ~(1 << 6);
		goto node5634;
	}
node9366:
	b = true;
	if (b) {
		input[1] |= (1 << 0);
		goto node184;
	} else {
		input[1] &= ~(1 << 0);
		return 0;
	}
node6493:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node6955;
	}
node8894:
	b = randbool();
	if (b) {
		input[1] |= (1 << 0);
		goto node1266;
	} else {
		input[1] &= ~(1 << 0);
		goto node7886;
	}
node1607:
	b = false;
	if (b) {
		input[2] |= (1 << 3);
		return 0;
	} else {
		input[2] &= ~(1 << 3);
		goto node7035;
	}
node805:
	b = true;
	if (b) {
		input[1] |= (1 << 1);
		goto node2349;
	} else {
		input[1] &= ~(1 << 1);
		return 0;
	}
node97:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node2913;
	} else {
		input[2] &= ~(1 << 5);
		goto node6367;
	}
node3833:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node831;
	} else {
		input[3] &= ~(1 << 5);
		goto node4323;
	}
node6591:
	b = randbool();
	if (b) {
		input[0] |= (1 << 0);
		return 5;
	} else {
		input[0] &= ~(1 << 0);
		return 2;
	}
node9439:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node7907;
	} else {
		input[2] &= ~(1 << 5);
		goto node736;
	}
node4026:
	b = false;
	if (b) {
		input[2] |= (1 << 2);
		return 0;
	} else {
		input[2] &= ~(1 << 2);
		goto node3938;
	}
node9195:
	b = true;
	if (b) {
		input[2] |= (1 << 2);
		goto node2762;
	} else {
		input[2] &= ~(1 << 2);
		return 0;
	}
node7235:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node2136;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node729:
	b = false;
	if (b) {
		input[3] |= (1 << 7);
		return 0;
	} else {
		input[3] &= ~(1 << 7);
		goto node5793;
	}
node701:
	b = randbool();
	if (b) {
		input[4] |= (1 << 6);
		goto node664;
	} else {
		input[4] &= ~(1 << 6);
		goto node5608;
	}
node2770:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node4998;
	} else {
		input[2] &= ~(1 << 4);
		goto node4447;
	}
node4824:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node1267;
	}
node2043:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node5345;
	} else {
		input[2] &= ~(1 << 3);
		goto node4622;
	}
node3358:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node7479;
	} else {
		input[2] &= ~(1 << 2);
		goto node8798;
	}
node4581:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node4255;
	} else {
		input[3] &= ~(1 << 4);
		goto node7412;
	}
node290:
	b = false;
	if (b) {
		input[4] |= (1 << 7);
		return 0;
	} else {
		input[4] &= ~(1 << 7);
		goto node478;
	}
node2591:
	b = true;
	if (b) {
		input[1] |= (1 << 6);
		goto node2502;
	} else {
		input[1] &= ~(1 << 6);
		return 0;
	}
node4209:
	b = randbool();
	if (b) {
		input[1] |= (1 << 3);
		goto node3214;
	} else {
		input[1] &= ~(1 << 3);
		goto node4467;
	}
node8220:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node54;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node7249:
	b = false;
	if (b) {
		input[1] |= (1 << 2);
		return 0;
	} else {
		input[1] &= ~(1 << 2);
		goto node514;
	}
node5670:
	b = false;
	if (b) {
		input[1] |= (1 << 2);
		return 0;
	} else {
		input[1] &= ~(1 << 2);
		goto node7445;
	}
node4330:
	b = randbool();
	if (b) {
		input[1] |= (1 << 0);
		goto node4480;
	} else {
		input[1] &= ~(1 << 0);
		goto node725;
	}
node8512:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node6792;
	} else {
		input[2] &= ~(1 << 5);
		goto node886;
	}
node3685:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node2762;
	} else {
		input[2] &= ~(1 << 2);
		goto node5956;
	}
node1542:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node2058;
	}
node1460:
	b = randbool();
	if (b) {
		input[3] |= (1 << 1);
		goto node7582;
	} else {
		input[3] &= ~(1 << 1);
		goto node6462;
	}
node1850:
	b = randbool();
	if (b) {
		input[4] |= (1 << 6);
		goto node34;
	} else {
		input[4] &= ~(1 << 6);
		goto node475;
	}
node4428:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node8797;
	} else {
		input[2] &= ~(1 << 5);
		goto node5181;
	}
node2313:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node8478;
	} else {
		input[2] &= ~(1 << 3);
		goto node6788;
	}
node3997:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node338;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node2967:
	b = randbool();
	if (b) {
		input[2] |= (1 << 0);
		goto node1372;
	} else {
		input[2] &= ~(1 << 0);
		goto node4292;
	}
node2036:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node6863;
	} else {
		input[3] &= ~(1 << 5);
		goto node548;
	}
node8230:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node1164;
	} else {
		input[3] &= ~(1 << 3);
		goto node4124;
	}
node2495:
	b = false;
	if (b) {
		input[5] |= (1 << 3);
		return 0;
	} else {
		input[5] &= ~(1 << 3);
		goto node6344;
	}
node9119:
	b = true;
	if (b) {
		input[5] |= (1 << 3);
		goto node4199;
	} else {
		input[5] &= ~(1 << 3);
		return 0;
	}
node9206:
	b = false;
	if (b) {
		input[2] |= (1 << 7);
		return 0;
	} else {
		input[2] &= ~(1 << 7);
		goto node6601;
	}
node4862:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node1268;
	}
node7691:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node2468;
	}
node3044:
	b = false;
	if (b) {
		input[4] |= (1 << 3);
		return 0;
	} else {
		input[4] &= ~(1 << 3);
		goto node8974;
	}
node6322:
	b = randbool();
	if (b) {
		input[4] |= (1 << 1);
		return 6;
	} else {
		input[4] &= ~(1 << 1);
		goto node3694;
	}
node8250:
	b = true;
	if (b) {
		input[4] |= (1 << 5);
		goto node9444;
	} else {
		input[4] &= ~(1 << 5);
		return 0;
	}
node5020:
	b = true;
	if (b) {
		input[4] |= (1 << 3);
		goto node3888;
	} else {
		input[4] &= ~(1 << 3);
		return 0;
	}
node8077:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node8174;
	}
node1334:
	b = true;
	if (b) {
		input[3] |= (1 << 2);
		goto node5686;
	} else {
		input[3] &= ~(1 << 2);
		return 0;
	}
node7410:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node7105;
	}
node1236:
	b = false;
	if (b) {
		input[3] |= (1 << 1);
		return 0;
	} else {
		input[3] &= ~(1 << 1);
		goto node2421;
	}
node1678:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node2116;
	} else {
		input[2] &= ~(1 << 4);
		goto node5499;
	}
node4716:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node8364;
	} else {
		input[3] &= ~(1 << 6);
		goto node944;
	}
node9061:
	b = true;
	if (b) {
		input[3] |= (1 << 6);
		return 4;
	} else {
		input[3] &= ~(1 << 6);
		return 0;
	}
node6658:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node1609;
	}
node7354:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node6177;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node440:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node5622;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node6692:
	b = false;
	if (b) {
		input[3] |= (1 << 1);
		return 0;
	} else {
		input[3] &= ~(1 << 1);
		goto node896;
	}
node747:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node868;
	} else {
		input[2] &= ~(1 << 2);
		goto node9425;
	}
node7404:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node4322;
	} else {
		input[3] &= ~(1 << 5);
		goto node2337;
	}
node6498:
	b = true;
	if (b) {
		input[3] |= (1 << 2);
		goto node8723;
	} else {
		input[3] &= ~(1 << 2);
		return 0;
	}
node6989:
	b = randbool();
	if (b) {
		input[4] |= (1 << 4);
		goto node7983;
	} else {
		input[4] &= ~(1 << 4);
		goto node139;
	}
node3628:
	b = false;
	if (b) {
		input[1] |= (1 << 4);
		return 0;
	} else {
		input[1] &= ~(1 << 4);
		goto node8317;
	}
node92:
	b = false;
	if (b) {
		input[2] |= (1 << 5);
		return 0;
	} else {
		input[2] &= ~(1 << 5);
		goto node7626;
	}
node8274:
	b = false;
	if (b) {
		input[2] |= (1 << 5);
		return 0;
	} else {
		input[2] &= ~(1 << 5);
		goto node6700;
	}
node2196:
	b = true;
	if (b) {
		input[3] |= (1 << 1);
		goto node8495;
	} else {
		input[3] &= ~(1 << 1);
		return 0;
	}
node6797:
	b = false;
	if (b) {
		input[5] |= (1 << 1);
		return 0;
	} else {
		input[5] &= ~(1 << 1);
		goto node4725;
	}
node3384:
	b = true;
	if (b) {
		input[5] |= (1 << 6);
		goto node2538;
	} else {
		input[5] &= ~(1 << 6);
		return 0;
	}
node5230:
	b = true;
	if (b) {
		input[1] |= (1 << 1);
		goto node4036;
	} else {
		input[1] &= ~(1 << 1);
		return 0;
	}
node2216:
	b = true;
	if (b) {
		input[1] |= (1 << 1);
		goto node3804;
	} else {
		input[1] &= ~(1 << 1);
		return 0;
	}
node4660:
	b = randbool();
	if (b) {
		input[2] |= (1 << 0);
		goto node3074;
	} else {
		input[2] &= ~(1 << 0);
		goto node4924;
	}
node2853:
	b = false;
	if (b) {
		input[3] |= (1 << 1);
		return 0;
	} else {
		input[3] &= ~(1 << 1);
		goto node618;
	}
node6546:
	b = randbool();
	if (b) {
		input[3] |= (1 << 1);
		goto node4108;
	} else {
		input[3] &= ~(1 << 1);
		goto node6462;
	}
node8452:
	b = false;
	if (b) {
		input[4] |= (1 << 6);
		return 0;
	} else {
		input[4] &= ~(1 << 6);
		goto node3039;
	}
node7899:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node3416;
	} else {
		input[3] &= ~(1 << 4);
		goto node5917;
	}
node6612:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node4844;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node1283:
	b = false;
	if (b) {
		input[1] |= (1 << 4);
		return 0;
	} else {
		input[1] &= ~(1 << 4);
		goto node7131;
	}
node4285:
	b = randbool();
	if (b) {
		input[2] |= (1 << 7);
		goto node377;
	} else {
		input[2] &= ~(1 << 7);
		goto node6222;
	}
node4407:
	b = true;
	if (b) {
		input[3] |= (1 << 6);
		goto node1992;
	} else {
		input[3] &= ~(1 << 6);
		return 0;
	}
node2452:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node9081;
	} else {
		input[3] &= ~(1 << 5);
		goto node1246;
	}
node571:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node1194;
	} else {
		input[3] &= ~(1 << 5);
		goto node5153;
	}
node573:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node623;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node8109:
	b = false;
	if (b) {
		input[4] |= (1 << 1);
		return 0;
	} else {
		input[4] &= ~(1 << 1);
		goto node8556;
	}
node3276:
	b = randbool();
	if (b) {
		input[0] |= (1 << 2);
		goto node3647;
	} else {
		input[0] &= ~(1 << 2);
		goto node2917;
	}
node7490:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node2129;
	} else {
		input[2] &= ~(1 << 6);
		goto node2256;
	}
node4802:
	b = true;
	if (b) {
		input[2] |= (1 << 2);
		goto node7887;
	} else {
		input[2] &= ~(1 << 2);
		return 0;
	}
node7855:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node8619;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node2157:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node5583;
	}
node2378:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node1007;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node8467:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node5610;
	} else {
		input[3] &= ~(1 << 3);
		goto node8627;
	}
node8555:
	b = true;
	if (b) {
		input[4] |= (1 << 1);
		goto node5055;
	} else {
		input[4] &= ~(1 << 1);
		return 0;
	}
node2994:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		goto node9196;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node5190:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node8548;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node2935:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node160;
	} else {
		input[3] &= ~(1 << 3);
		goto node7987;
	}
node602:
	b = true;
	if (b) {
		input[5] |= (1 << 7);
		goto node2664;
	} else {
		input[5] &= ~(1 << 7);
		return 0;
	}
node1079:
	b = randbool();
	if (b) {
		input[5] |= (1 << 0);
		return 10;
	} else {
		input[5] &= ~(1 << 0);
		return 6;
	}
node6401:
	b = randbool();
	if (b) {
		input[6] |= (1 << 4);
		goto node2092;
	} else {
		input[6] &= ~(1 << 4);
		goto node6964;
	}
node5630:
	b = false;
	if (b) {
		input[1] |= (1 << 4);
		return 0;
	} else {
		input[1] &= ~(1 << 4);
		goto node2618;
	}
node3538:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node3799;
	} else {
		input[2] &= ~(1 << 1);
		goto node3571;
	}
node3418:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		goto node3253;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node8823:
	b = true;
	if (b) {
		input[3] |= (1 << 7);
		goto node2921;
	} else {
		input[3] &= ~(1 << 7);
		return 0;
	}
node8572:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node3631;
	} else {
		input[3] &= ~(1 << 3);
		goto node3083;
	}
node5955:
	b = false;
	if (b) {
		input[3] |= (1 << 0);
		return 0;
	} else {
		input[3] &= ~(1 << 0);
		goto node7703;
	}
node2229:
	b = randbool();
	if (b) {
		input[1] |= (1 << 0);
		goto node6186;
	} else {
		input[1] &= ~(1 << 0);
		goto node510;
	}
node8409:
	b = randbool();
	if (b) {
		input[2] |= (1 << 0);
		goto node8383;
	} else {
		input[2] &= ~(1 << 0);
		goto node9339;
	}
node5755:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node548;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node8659:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node137;
	} else {
		input[3] &= ~(1 << 2);
		goto node4784;
	}
node4852:
	b = randbool();
	if (b) {
		input[2] |= (1 << 0);
		return 8;
	} else {
		input[2] &= ~(1 << 0);
		goto node8410;
	}
node472:
	b = true;
	if (b) {
		input[2] |= (1 << 2);
		goto node8453;
	} else {
		input[2] &= ~(1 << 2);
		return 0;
	}
node9192:
	b = randbool();
	if (b) {
		input[2] |= (1 << 0);
		goto node1027;
	} else {
		input[2] &= ~(1 << 0);
		goto node2426;
	}
node1770:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node4834;
	} else {
		input[3] &= ~(1 << 7);
		goto node5278;
	}
node4722:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node7473;
	} else {
		input[3] &= ~(1 << 5);
		goto node548;
	}
node6366:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node2174;
	} else {
		input[2] &= ~(1 << 4);
		goto node2390;
	}
node4783:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node4509;
	}
node7434:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node1298;
	}
node5027:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node7348;
	} else {
		input[3] &= ~(1 << 4);
		goto node5979;
	}
node1123:
	b = false;
	if (b) {
		input[4] |= (1 << 4);
		return 0;
	} else {
		input[4] &= ~(1 << 4);
		goto node4902;
	}
node8496:
	b = randbool();
	if (b) {
		input[6] |= (1 << 6);
		goto node4075;
	} else {
		input[6] &= ~(1 << 6);
		goto node4032;
	}
node1652:
	b = true;
	if (b) {
		input[1] |= (1 << 0);
		return 4;
	} else {
		input[1] &= ~(1 << 0);
		return 0;
	}
node3357:
	b = true;
	if (b) {
		input[1] |= (1 << 0);
		goto node5824;
	} else {
		input[1] &= ~(1 << 0);
		return 0;
	}
node8038:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		return 4;
	} else {
		input[2] &= ~(1 << 1);
		goto node4758;
	}
node7539:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node7175;
	}
node7094:
	b = randbool();
	if (b) {
		input[4] |= (1 << 2);
		goto node7203;
	} else {
		input[4] &= ~(1 << 2);
		goto node4079;
	}
node4907:
	b = true;
	if (b) {
		input[7] |= (1 << 3);
		goto node6368;
	} else {
		input[7] &= ~(1 << 3);
		return 0;
	}
node3662:
	b = randbool();
	if (b) {
		input[1] |= (1 << 3);
		goto node744;
	} else {
		input[1] &= ~(1 << 3);
		goto node2123;
	}
node314:
	b = randbool();
	if (b) {
		input[1] |= (1 << 0);
		goto node1898;
	} else {
		input[1] &= ~(1 << 0);
		goto node6186;
	}
node6139:
	b = true;
	if (b) {
		input[1] |= (1 << 0);
		goto node6424;
	} else {
		input[1] &= ~(1 << 0);
		return 0;
	}
node8976:
	b = true;
	if (b) {
		input[2] |= (1 << 4);
		goto node7004;
	} else {
		input[2] &= ~(1 << 4);
		return 0;
	}
node3935:
	b = false;
	if (b) {
		input[3] |= (1 << 2);
		return 0;
	} else {
		input[3] &= ~(1 << 2);
		goto node8473;
	}
node1393:
	b = randbool();
	if (b) {
		input[1] |= (1 << 4);
		goto node1944;
	} else {
		input[1] &= ~(1 << 4);
		goto node5993;
	}
node1617:
	b = randbool();
	if (b) {
		input[2] |= (1 << 7);
		goto node2895;
	} else {
		input[2] &= ~(1 << 7);
		goto node7490;
	}
node8284:
	b = randbool();
	if (b) {
		input[2] |= (1 << 7);
		goto node9068;
	} else {
		input[2] &= ~(1 << 7);
		goto node7466;
	}
node4509:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node8438;
	}
node6616:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node3265;
	}
node9371:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node8135;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node6076:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node6037;
	} else {
		input[3] &= ~(1 << 3);
		goto node9159;
	}
node2846:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node6082;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node8631:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		return 3;
	} else {
		input[2] &= ~(1 << 1);
		goto node3798;
	}
node2865:
	b = false;
	if (b) {
		input[3] |= (1 << 6);
		return 0;
	} else {
		input[3] &= ~(1 << 6);
		goto node7634;
	}
node5651:
	b = false;
	if (b) {
		input[3] |= (1 << 6);
		return 0;
	} else {
		input[3] &= ~(1 << 6);
		goto node191;
	}
node2234:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node6419;
	} else {
		input[3] &= ~(1 << 5);
		return 4;
	}
node2600:
	b = true;
	if (b) {
		input[3] |= (1 << 1);
		goto node5983;
	} else {
		input[3] &= ~(1 << 1);
		return 0;
	}
node2779:
	b = true;
	if (b) {
		input[3] |= (1 << 1);
		goto node4070;
	} else {
		input[3] &= ~(1 << 1);
		return 0;
	}
node6671:
	b = false;
	if (b) {
		input[3] |= (1 << 0);
		return 0;
	} else {
		input[3] &= ~(1 << 0);
		goto node3520;
	}
node4190:
	b = randbool();
	if (b) {
		input[4] |= (1 << 6);
		goto node6443;
	} else {
		input[4] &= ~(1 << 6);
		goto node1309;
	}
node4008:
	b = randbool();
	if (b) {
		input[4] |= (1 << 5);
		goto node4153;
	} else {
		input[4] &= ~(1 << 5);
		goto node875;
	}
node2319:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node5838;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node269:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node5401;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node8751:
	b = randbool();
	if (b) {
		input[4] |= (1 << 2);
		goto node7110;
	} else {
		input[4] &= ~(1 << 2);
		goto node439;
	}
node1621:
	b = randbool();
	if (b) {
		input[1] |= (1 << 1);
		goto node2511;
	} else {
		input[1] &= ~(1 << 1);
		goto node2002;
	}
node7285:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node99;
	} else {
		input[2] &= ~(1 << 4);
		goto node1597;
	}
node3568:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node6075;
	} else {
		input[2] &= ~(1 << 2);
		goto node7887;
	}
node420:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node9290;
	} else {
		input[2] &= ~(1 << 1);
		goto node4923;
	}
node2362:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node1218;
	} else {
		input[3] &= ~(1 << 6);
		goto node4050;
	}
node9235:
	b = randbool();
	if (b) {
		input[4] |= (1 << 7);
		goto node6962;
	} else {
		input[4] &= ~(1 << 7);
		goto node9398;
	}
node7673:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node2714;
	} else {
		input[2] &= ~(1 << 4);
		goto node6115;
	}
node8097:
	b = false;
	if (b) {
		input[2] |= (1 << 3);
		return 0;
	} else {
		input[2] &= ~(1 << 3);
		goto node2187;
	}
node346:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		goto node5545;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node8924:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node918;
	} else {
		input[2] &= ~(1 << 1);
		goto node3799;
	}
node9099:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node5724;
	} else {
		input[3] &= ~(1 << 7);
		goto node4379;
	}
node7780:
	b = false;
	if (b) {
		input[3] |= (1 << 2);
		return 0;
	} else {
		input[3] &= ~(1 << 2);
		goto node8279;
	}
node2142:
	b = true;
	if (b) {
		input[2] |= (1 << 6);
		goto node6517;
	} else {
		input[2] &= ~(1 << 6);
		return 0;
	}
node5469:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node2941;
	} else {
		input[3] &= ~(1 << 7);
		goto node642;
	}
node8588:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node7155;
	} else {
		input[3] &= ~(1 << 5);
		goto node6456;
	}
node5750:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node137;
	} else {
		input[3] &= ~(1 << 3);
		goto node8516;
	}
node7632:
	b = false;
	if (b) {
		input[4] |= (1 << 7);
		return 0;
	} else {
		input[4] &= ~(1 << 7);
		goto node3711;
	}
node1975:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node3153;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node8548:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node1056;
	} else {
		input[3] &= ~(1 << 2);
		return 5;
	}
node7102:
	b = true;
	if (b) {
		input[1] |= (1 << 0);
		goto node9401;
	} else {
		input[1] &= ~(1 << 0);
		return 0;
	}
node4969:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node1867;
	} else {
		input[2] &= ~(1 << 3);
		goto node6596;
	}
node8321:
	b = false;
	if (b) {
		input[2] |= (1 << 3);
		return 0;
	} else {
		input[2] &= ~(1 << 3);
		goto node6323;
	}
node8025:
	b = true;
	if (b) {
		input[2] |= (1 << 2);
		goto node146;
	} else {
		input[2] &= ~(1 << 2);
		return 0;
	}
node1031:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node3359;
	} else {
		input[2] &= ~(1 << 1);
		goto node6654;
	}
node222:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		return 3;
	} else {
		input[2] &= ~(1 << 1);
		goto node1228;
	}
node8806:
	b = false;
	if (b) {
		input[4] |= (1 << 6);
		return 0;
	} else {
		input[4] &= ~(1 << 6);
		goto node7609;
	}
node306:
	b = true;
	if (b) {
		input[4] |= (1 << 6);
		goto node741;
	} else {
		input[4] &= ~(1 << 6);
		return 0;
	}
node7394:
	b = randbool();
	if (b) {
		input[1] |= (1 << 6);
		goto node4917;
	} else {
		input[1] &= ~(1 << 6);
		goto node3072;
	}
node5474:
	b = randbool();
	if (b) {
		input[1] |= (1 << 5);
		goto node2802;
	} else {
		input[1] &= ~(1 << 5);
		goto node7022;
	}
node8513:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node3539;
	}
node8664:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node216;
	} else {
		input[2] &= ~(1 << 1);
		goto node6412;
	}
node4938:
	b = randbool();
	if (b) {
		input[2] |= (1 << 7);
		goto node2639;
	} else {
		input[2] &= ~(1 << 7);
		goto node6750;
	}
node1141:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node4592;
	}
node9447:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node4459;
	} else {
		input[3] &= ~(1 << 3);
		goto node6077;
	}
node3491:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node8353;
	} else {
		input[2] &= ~(1 << 5);
		goto node1486;
	}
node5762:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node7167;
	}
node7035:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node7286;
	} else {
		input[2] &= ~(1 << 2);
		goto node737;
	}
node6126:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node1548;
	} else {
		input[3] &= ~(1 << 6);
		goto node3313;
	}
node5001:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node2408;
	}
node5640:
	b = randbool();
	if (b) {
		input[4] |= (1 << 6);
		goto node7129;
	} else {
		input[4] &= ~(1 << 6);
		goto node6883;
	}
node1196:
	b = true;
	if (b) {
		input[5] |= (1 << 5);
		goto node7248;
	} else {
		input[5] &= ~(1 << 5);
		return 0;
	}
node9071:
	b = false;
	if (b) {
		input[1] |= (1 << 2);
		return 0;
	} else {
		input[1] &= ~(1 << 2);
		goto node2798;
	}
node8111:
	b = true;
	if (b) {
		input[1] |= (1 << 1);
		goto node2843;
	} else {
		input[1] &= ~(1 << 1);
		return 0;
	}
node3023:
	b = false;
	if (b) {
		input[3] |= (1 << 7);
		return 0;
	} else {
		input[3] &= ~(1 << 7);
		goto node8112;
	}
node1687:
	b = false;
	if (b) {
		input[3] |= (1 << 7);
		return 0;
	} else {
		input[3] &= ~(1 << 7);
		goto node3785;
	}
node260:
	b = false;
	if (b) {
		input[3] |= (1 << 7);
		return 0;
	} else {
		input[3] &= ~(1 << 7);
		goto node1082;
	}
node910:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node123;
	} else {
		input[3] &= ~(1 << 4);
		goto node7580;
	}
node3061:
	b = randbool();
	if (b) {
		input[1] |= (1 << 1);
		goto node6083;
	} else {
		input[1] &= ~(1 << 1);
		goto node6432;
	}
node7497:
	b = true;
	if (b) {
		input[2] |= (1 << 6);
		goto node7719;
	} else {
		input[2] &= ~(1 << 6);
		return 0;
	}
node8591:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node7117;
	} else {
		input[2] &= ~(1 << 3);
		goto node4239;
	}
node5832:
	b = false;
	if (b) {
		input[2] |= (1 << 2);
		return 0;
	} else {
		input[2] &= ~(1 << 2);
		goto node6074;
	}
node5739:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node3353;
	} else {
		input[2] &= ~(1 << 2);
		goto node2791;
	}
node8359:
	b = false;
	if (b) {
		input[4] |= (1 << 2);
		return 0;
	} else {
		input[4] &= ~(1 << 2);
		goto node5950;
	}
node4866:
	b = randbool();
	if (b) {
		input[5] |= (1 << 6);
		goto node2385;
	} else {
		input[5] &= ~(1 << 6);
		goto node1754;
	}
node4394:
	b = false;
	if (b) {
		input[1] |= (1 << 4);
		return 0;
	} else {
		input[1] &= ~(1 << 4);
		goto node7999;
	}
node4195:
	b = randbool();
	if (b) {
		input[1] |= (1 << 3);
		goto node4338;
	} else {
		input[1] &= ~(1 << 3);
		goto node50;
	}
node4339:
	b = randbool();
	if (b) {
		input[1] |= (1 << 0);
		goto node5627;
	} else {
		input[1] &= ~(1 << 0);
		goto node9094;
	}
node551:
	b = randbool();
	if (b) {
		input[1] |= (1 << 0);
		goto node6186;
	} else {
		input[1] &= ~(1 << 0);
		goto node8740;
	}
node7942:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node143;
	} else {
		input[3] &= ~(1 << 5);
		goto node1522;
	}
node7620:
	b = randbool();
	if (b) {
		input[3] |= (1 << 1);
		return 8;
	} else {
		input[3] &= ~(1 << 1);
		goto node927;
	}
node6269:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node1477;
	} else {
		input[2] &= ~(1 << 5);
		goto node2546;
	}
node4577:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node3115;
	} else {
		input[2] &= ~(1 << 2);
		goto node7887;
	}
node6431:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node1459;
	}
node875:
	b = randbool();
	if (b) {
		input[4] |= (1 << 2);
		goto node8713;
	} else {
		input[4] &= ~(1 << 2);
		return 6;
	}
node7039:
	b = randbool();
	if (b) {
		input[1] |= (1 << 3);
		goto node6186;
	} else {
		input[1] &= ~(1 << 3);
		goto node8158;
	}
node4324:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node780;
	} else {
		input[3] &= ~(1 << 4);
		goto node9001;
	}
node1945:
	b = true;
	if (b) {
		input[2] |= (1 << 4);
		goto node7359;
	} else {
		input[2] &= ~(1 << 4);
		return 0;
	}
node1318:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node1597;
	} else {
		input[2] &= ~(1 << 4);
		goto node93;
	}
node5140:
	b = randbool();
	if (b) {
		input[5] |= (1 << 1);
		return 6;
	} else {
		input[5] &= ~(1 << 1);
		goto node798;
	}
node2294:
	b = false;
	if (b) {
		input[2] |= (1 << 1);
		return 0;
	} else {
		input[2] &= ~(1 << 1);
		goto node4247;
	}
node6325:
	b = false;
	if (b) {
		input[3] |= (1 << 6);
		return 0;
	} else {
		input[3] &= ~(1 << 6);
		goto node1645;
	}
node7441:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node7043;
	} else {
		input[3] &= ~(1 << 2);
		goto node8380;
	}
node540:
	b = true;
	if (b) {
		input[3] |= (1 << 1);
		goto node9289;
	} else {
		input[3] &= ~(1 << 1);
		return 0;
	}
node2484:
	b = false;
	if (b) {
		input[4] |= (1 << 7);
		return 0;
	} else {
		input[4] &= ~(1 << 7);
		goto node4317;
	}
node5238:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node4647;
	} else {
		input[3] &= ~(1 << 6);
		goto node3071;
	}
node3185:
	b = true;
	if (b) {
		input[3] |= (1 << 6);
		goto node4774;
	} else {
		input[3] &= ~(1 << 6);
		return 0;
	}
node6321:
	b = true;
	if (b) {
		input[4] |= (1 << 5);
		goto node4212;
	} else {
		input[4] &= ~(1 << 5);
		return 0;
	}
node1214:
	b = false;
	if (b) {
		input[1] |= (1 << 5);
		return 0;
	} else {
		input[1] &= ~(1 << 5);
		goto node786;
	}
node8650:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		goto node3271;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node8493:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node4163;
	} else {
		input[3] &= ~(1 << 5);
		goto node6441;
	}
node2191:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node6776;
	} else {
		input[3] &= ~(1 << 5);
		goto node2248;
	}
node1353:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node2288;
	} else {
		input[3] &= ~(1 << 4);
		goto node6395;
	}
node6649:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node2989;
	} else {
		input[3] &= ~(1 << 2);
		goto node1176;
	}
node4431:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node4119;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node1515:
	b = true;
	if (b) {
		input[4] |= (1 << 3);
		goto node7137;
	} else {
		input[4] &= ~(1 << 3);
		return 0;
	}
node1838:
	b = randbool();
	if (b) {
		input[1] |= (1 << 4);
		goto node6248;
	} else {
		input[1] &= ~(1 << 4);
		return 2;
	}
node7995:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node3799;
	} else {
		input[2] &= ~(1 << 1);
		goto node94;
	}
node8258:
	b = false;
	if (b) {
		input[3] |= (1 << 7);
		return 0;
	} else {
		input[3] &= ~(1 << 7);
		goto node7170;
	}
node7873:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node2669;
	} else {
		input[3] &= ~(1 << 6);
		goto node7146;
	}
node7060:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node2225;
	} else {
		input[3] &= ~(1 << 6);
		goto node8960;
	}
node1219:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node8241;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node2904:
	b = randbool();
	if (b) {
		input[4] |= (1 << 3);
		goto node4672;
	} else {
		input[4] &= ~(1 << 3);
		goto node7502;
	}
node510:
	b = randbool();
	if (b) {
		input[2] |= (1 << 7);
		goto node3921;
	} else {
		input[2] &= ~(1 << 7);
		goto node9014;
	}
node5551:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node3714;
	} else {
		input[2] &= ~(1 << 5);
		goto node3749;
	}
node3037:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node780;
	} else {
		input[3] &= ~(1 << 5);
		goto node474;
	}
node9058:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node7920;
	} else {
		input[3] &= ~(1 << 2);
		goto node9469;
	}
node3845:
	b = true;
	if (b) {
		input[4] |= (1 << 5);
		goto node3547;
	} else {
		input[4] &= ~(1 << 5);
		return 0;
	}
node3622:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node6912;
	} else {
		input[3] &= ~(1 << 5);
		goto node4387;
	}
node883:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node464;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node7439:
	b = false;
	if (b) {
		input[2] |= (1 << 5);
		return 0;
	} else {
		input[2] &= ~(1 << 5);
		goto node5733;
	}
node164:
	b = true;
	if (b) {
		input[2] |= (1 << 4);
		goto node5718;
	} else {
		input[2] &= ~(1 << 4);
		return 0;
	}
node7278:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node66;
	} else {
		input[2] &= ~(1 << 3);
		goto node9182;
	}
node8211:
	b = true;
	if (b) {
		input[2] |= (1 << 2);
		return 3;
	} else {
		input[2] &= ~(1 << 2);
		return 0;
	}
node3081:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node8760;
	} else {
		input[3] &= ~(1 << 7);
		goto node4617;
	}
node4049:
	b = false;
	if (b) {
		input[3] |= (1 << 6);
		return 0;
	} else {
		input[3] &= ~(1 << 6);
		goto node6485;
	}
node1861:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node8406;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node3101:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node7123;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node6963:
	b = false;
	if (b) {
		input[4] |= (1 << 4);
		return 0;
	} else {
		input[4] &= ~(1 << 4);
		goto node9336;
	}
node555:
	b = false;
	if (b) {
		input[4] |= (1 << 2);
		return 0;
	} else {
		input[4] &= ~(1 << 2);
		goto node6289;
	}
node6168:
	b = randbool();
	if (b) {
		input[1] |= (1 << 2);
		return 2;
	} else {
		input[1] &= ~(1 << 2);
		goto node724;
	}
node6919:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		return 7;
	} else {
		input[2] &= ~(1 << 1);
		goto node7463;
	}
node5471:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node3062;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node528:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node5138;
	}
node3650:
	b = false;
	if (b) {
		input[3] |= (1 << 0);
		return 0;
	} else {
		input[3] &= ~(1 << 0);
		goto node7632;
	}
node8117:
	b = randbool();
	if (b) {
		input[7] |= (1 << 4);
		goto node1376;
	} else {
		input[7] &= ~(1 << 4);
		goto node8957;
	}
node3263:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		goto node9028;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node1228:
	b = randbool();
	if (b) {
		input[2] |= (1 << 0);
		return 7;
	} else {
		input[2] &= ~(1 << 0);
		goto node3027;
	}
node3992:
	b = false;
	if (b) {
		input[3] |= (1 << 6);
		return 0;
	} else {
		input[3] &= ~(1 << 6);
		goto node4055;
	}
node2381:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node4812;
	} else {
		input[3] &= ~(1 << 5);
		goto node6005;
	}
node8993:
	b = true;
	if (b) {
		input[3] |= (1 << 1);
		goto node4575;
	} else {
		input[3] &= ~(1 << 1);
		return 0;
	}
node4228:
	b = false;
	if (b) {
		input[4] |= (1 << 4);
		return 0;
	} else {
		input[4] &= ~(1 << 4);
		goto node5263;
	}
node5658:
	b = true;
	if (b) {
		input[1] |= (1 << 2);
		goto node6186;
	} else {
		input[1] &= ~(1 << 2);
		return 0;
	}
node6157:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node2889;
	} else {
		input[2] &= ~(1 << 6);
		goto node7305;
	}
node5121:
	b = true;
	if (b) {
		input[3] |= (1 << 7);
		goto node3807;
	} else {
		input[3] &= ~(1 << 7);
		return 0;
	}
node3027:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node3119;
	} else {
		input[3] &= ~(1 << 7);
		goto node246;
	}
node6508:
	b = true;
	if (b) {
		input[3] |= (1 << 2);
		goto node6372;
	} else {
		input[3] &= ~(1 << 2);
		return 0;
	}
node4573:
	b = randbool();
	if (b) {
		input[0] |= (1 << 3);
		goto node8990;
	} else {
		input[0] &= ~(1 << 3);
		goto node6590;
	}
node708:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node1791;
	} else {
		input[2] &= ~(1 << 4);
		goto node1487;
	}
node6056:
	b = true;
	if (b) {
		input[3] |= (1 << 6);
		goto node8875;
	} else {
		input[3] &= ~(1 << 6);
		return 0;
	}
node4506:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node5156;
	} else {
		input[3] &= ~(1 << 6);
		goto node1216;
	}
node9311:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node3926;
	}
node4312:
	b = randbool();
	if (b) {
		input[4] |= (1 << 6);
		goto node9343;
	} else {
		input[4] &= ~(1 << 6);
		goto node9454;
	}
node6229:
	b = false;
	if (b) {
		input[4] |= (1 << 3);
		return 0;
	} else {
		input[4] &= ~(1 << 3);
		goto node1208;
	}
node6217:
	b = false;
	if (b) {
		input[1] |= (1 << 1);
		return 0;
	} else {
		input[1] &= ~(1 << 1);
		goto node7645;
	}
node2370:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node6669;
	} else {
		input[2] &= ~(1 << 4);
		goto node2354;
	}
node5544:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node2081;
	} else {
		input[2] &= ~(1 << 3);
		goto node1097;
	}
node6196:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node6850;
	} else {
		input[2] &= ~(1 << 1);
		return 3;
	}
node6853:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		goto node6622;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node5313:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node1282;
	} else {
		input[3] &= ~(1 << 5);
		goto node160;
	}
node921:
	b = false;
	if (b) {
		input[4] |= (1 << 1);
		return 0;
	} else {
		input[4] &= ~(1 << 1);
		goto node6437;
	}
node1198:
	b = false;
	if (b) {
		input[6] |= (1 << 1);
		return 0;
	} else {
		input[6] &= ~(1 << 1);
		goto node5561;
	}
node1898:
	b = false;
	if (b) {
		input[2] |= (1 << 7);
		return 0;
	} else {
		input[2] &= ~(1 << 7);
		goto node6231;
	}
node4998:
	b = false;
	if (b) {
		input[2] |= (1 << 3);
		return 0;
	} else {
		input[2] &= ~(1 << 3);
		goto node1831;
	}
node8442:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node6009;
	} else {
		input[2] &= ~(1 << 3);
		goto node6090;
	}
node9197:
	b = randbool();
	if (b) {
		input[2] |= (1 << 0);
		goto node2840;
	} else {
		input[2] &= ~(1 << 0);
		goto node3675;
	}
node6766:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node9211;
	}
node9009:
	b = true;
	if (b) {
		input[4] |= (1 << 5);
		goto node2141;
	} else {
		input[4] &= ~(1 << 5);
		return 0;
	}
node460:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node651;
	}
node9359:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node6458;
	}
node786:
	b = false;
	if (b) {
		input[1] |= (1 << 4);
		return 0;
	} else {
		input[1] &= ~(1 << 4);
		goto node9004;
	}
node7446:
	b = randbool();
	if (b) {
		input[1] |= (1 << 1);
		goto node6292;
	} else {
		input[1] &= ~(1 << 1);
		goto node2031;
	}
node3535:
	b = false;
	if (b) {
		input[3] |= (1 << 7);
		return 0;
	} else {
		input[3] &= ~(1 << 7);
		goto node4856;
	}
node7379:
	b = false;
	if (b) {
		input[3] |= (1 << 7);
		return 0;
	} else {
		input[3] &= ~(1 << 7);
		goto node6970;
	}
node6385:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node3701;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node3615:
	b = randbool();
	if (b) {
		input[5] |= (1 << 7);
		goto node9327;
	} else {
		input[5] &= ~(1 << 7);
		goto node311;
	}
node4899:
	b = false;
	if (b) {
		input[2] |= (1 << 6);
		return 0;
	} else {
		input[2] &= ~(1 << 6);
		goto node2972;
	}
node5675:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node1050;
	} else {
		input[2] &= ~(1 << 4);
		goto node8923;
	}
node3141:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node2323;
	} else {
		input[3] &= ~(1 << 6);
		goto node5957;
	}
node7436:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node7320;
	} else {
		input[3] &= ~(1 << 4);
		goto node5510;
	}
node8950:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node1919;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node9353:
	b = false;
	if (b) {
		input[3] |= (1 << 1);
		return 0;
	} else {
		input[3] &= ~(1 << 1);
		goto node789;
	}
node789:
	b = randbool();
	if (b) {
		input[3] |= (1 << 0);
		goto node6462;
	} else {
		input[3] &= ~(1 << 0);
		goto node2395;
	}
node4409:
	b = randbool();
	if (b) {
		input[2] |= (1 << 7);
		goto node889;
	} else {
		input[2] &= ~(1 << 7);
		goto node4205;
	}
node2116:
	b = true;
	if (b) {
		input[2] |= (1 << 3);
		goto node1815;
	} else {
		input[2] &= ~(1 << 3);
		return 0;
	}
node641:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node7887;
	} else {
		input[2] &= ~(1 << 1);
		goto node117;
	}
node8502:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node4323;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node7558:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node4836;
	} else {
		input[3] &= ~(1 << 4);
		goto node3101;
	}
node3076:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node74;
	}
node2815:
	b = randbool();
	if (b) {
		input[7] |= (1 << 0);
		return 12;
	} else {
		input[7] &= ~(1 << 0);
		return 8;
	}
node1365:
	b = randbool();
	if (b) {
		input[4] |= (1 << 2);
		goto node8305;
	} else {
		input[4] &= ~(1 << 2);
		goto node8707;
	}
node8542:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node5544;
	} else {
		input[2] &= ~(1 << 4);
		goto node1097;
	}
node3232:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		goto node6138;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node7370:
	b = true;
	if (b) {
		input[3] |= (1 << 6);
		goto node8221;
	} else {
		input[3] &= ~(1 << 6);
		return 0;
	}
node1396:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node2217;
	} else {
		input[3] &= ~(1 << 4);
		goto node3975;
	}
node3677:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node3594;
	}
node1904:
	b = randbool();
	if (b) {
		input[3] |= (1 << 0);
		goto node6462;
	} else {
		input[3] &= ~(1 << 0);
		goto node2989;
	}
node2931:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node214;
	}
node3968:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node3430;
	} else {
		input[2] &= ~(1 << 3);
		goto node8098;
	}
node111:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node1026;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node4604:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node3986;
	} else {
		input[3] &= ~(1 << 3);
		goto node7833;
	}
node5490:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node512;
	} else {
		input[3] &= ~(1 << 3);
		goto node6890;
	}
node4714:
	b = false;
	if (b) {
		input[3] |= (1 << 1);
		return 0;
	} else {
		input[3] &= ~(1 << 1);
		goto node9240;
	}
node3224:
	b = false;
	if (b) {
		input[6] |= (1 << 1);
		return 0;
	} else {
		input[6] &= ~(1 << 1);
		goto node89;
	}
node4454:
	b = randbool();
	if (b) {
		input[1] |= (1 << 6);
		goto node8519;
	} else {
		input[1] &= ~(1 << 6);
		goto node7723;
	}
node7132:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node1546;
	} else {
		input[2] &= ~(1 << 4);
		goto node3145;
	}
node338:
	b = false;
	if (b) {
		input[3] |= (1 << 7);
		return 0;
	} else {
		input[3] &= ~(1 << 7);
		goto node7665;
	}
node4579:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node6113;
	} else {
		input[3] &= ~(1 << 3);
		goto node1984;
	}
node4404:
	b = randbool();
	if (b) {
		input[1] |= (1 << 7);
		goto node582;
	} else {
		input[1] &= ~(1 << 7);
		goto node6152;
	}
node8696:
	b = true;
	if (b) {
		input[2] |= (1 << 4);
		goto node823;
	} else {
		input[2] &= ~(1 << 4);
		return 0;
	}
node8863:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		goto node4627;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node5656:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node4048;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node8654:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node5759;
	} else {
		input[3] &= ~(1 << 2);
		goto node8007;
	}
node2788:
	b = randbool();
	if (b) {
		input[6] |= (1 << 6);
		goto node3347;
	} else {
		input[6] &= ~(1 << 6);
		goto node5264;
	}
node1488:
	b = true;
	if (b) {
		input[3] |= (1 << 2);
		goto node4135;
	} else {
		input[3] &= ~(1 << 2);
		return 0;
	}
node8402:
	b = false;
	if (b) {
		input[6] |= (1 << 1);
		return 0;
	} else {
		input[6] &= ~(1 << 1);
		goto node2501;
	}
node6231:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node1597;
	} else {
		input[2] &= ~(1 << 6);
		goto node1226;
	}
node5085:
	b = true;
	if (b) {
		input[2] |= (1 << 6);
		goto node5267;
	} else {
		input[2] &= ~(1 << 6);
		return 0;
	}
node9144:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node7655;
	}
node4603:
	b = false;
	if (b) {
		input[2] |= (1 << 1);
		return 0;
	} else {
		input[2] &= ~(1 << 1);
		goto node4151;
	}
node6109:
	b = true;
	if (b) {
		input[3] |= (1 << 7);
		goto node649;
	} else {
		input[3] &= ~(1 << 7);
		return 0;
	}
node2659:
	b = true;
	if (b) {
		input[3] |= (1 << 7);
		goto node2145;
	} else {
		input[3] &= ~(1 << 7);
		return 0;
	}
node2203:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node8871;
	} else {
		input[3] &= ~(1 << 4);
		goto node6127;
	}
node6127:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node8871;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node2073:
	b = randbool();
	if (b) {
		input[5] |= (1 << 4);
		goto node6651;
	} else {
		input[5] &= ~(1 << 4);
		goto node1476;
	}
node2761:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node8024;
	} else {
		input[2] &= ~(1 << 4);
		goto node1429;
	}
node5879:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node7887;
	} else {
		input[2] &= ~(1 << 2);
		goto node4087;
	}
node1717:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node7572;
	} else {
		input[3] &= ~(1 << 6);
		goto node6282;
	}
node3243:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node2059;
	} else {
		input[3] &= ~(1 << 6);
		goto node1409;
	}
node1599:
	b = true;
	if (b) {
		input[3] |= (1 << 1);
		goto node8380;
	} else {
		input[3] &= ~(1 << 1);
		return 0;
	}
node4584:
	b = false;
	if (b) {
		input[1] |= (1 << 2);
		return 0;
	} else {
		input[1] &= ~(1 << 2);
		goto node2222;
	}
node5545:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node2434;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node5401:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node3520;
	} else {
		input[3] &= ~(1 << 2);
		goto node948;
	}
node6526:
	b = true;
	if (b) {
		input[1] |= (1 << 3);
		goto node7086;
	} else {
		input[1] &= ~(1 << 3);
		return 0;
	}
node5892:
	b = false;
	if (b) {
		input[2] |= (1 << 1);
		return 0;
	} else {
		input[2] &= ~(1 << 1);
		goto node1189;
	}
node1548:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node3313;
	}
node3202:
	b = randbool();
	if (b) {
		input[4] |= (1 << 6);
		goto node3990;
	} else {
		input[4] &= ~(1 << 6);
		goto node4671;
	}
node7861:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node9228;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node4469:
	b = true;
	if (b) {
		input[3] |= (1 << 2);
		goto node5759;
	} else {
		input[3] &= ~(1 << 2);
		return 0;
	}
node7904:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node2745;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node2810:
	b = false;
	if (b) {
		input[3] |= (1 << 2);
		return 0;
	} else {
		input[3] &= ~(1 << 2);
		goto node6762;
	}
node4620:
	b = true;
	if (b) {
		input[1] |= (1 << 4);
		return 2;
	} else {
		input[1] &= ~(1 << 4);
		return 0;
	}
node7592:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node4890;
	} else {
		input[2] &= ~(1 << 4);
		goto node1108;
	}
node7813:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node5223;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node9361:
	b = false;
	if (b) {
		input[3] |= (1 << 7);
		return 0;
	} else {
		input[3] &= ~(1 << 7);
		goto node1381;
	}
node6271:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node8676;
	} else {
		input[3] &= ~(1 << 4);
		goto node548;
	}
node537:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node8436;
	}
node5584:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node9476;
	} else {
		input[3] &= ~(1 << 2);
		goto node9388;
	}
node8198:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node9177;
	} else {
		input[3] &= ~(1 << 2);
		goto node3638;
	}
node3064:
	b = false;
	if (b) {
		input[4] |= (1 << 6);
		return 0;
	} else {
		input[4] &= ~(1 << 6);
		goto node3018;
	}
node4436:
	b = randbool();
	if (b) {
		input[4] |= (1 << 4);
		goto node1611;
	} else {
		input[4] &= ~(1 << 4);
		goto node2127;
	}
node96:
	b = true;
	if (b) {
		input[5] |= (1 << 2);
		goto node7692;
	} else {
		input[5] &= ~(1 << 2);
		return 0;
	}
node6990:
	b = randbool();
	if (b) {
		input[1] |= (1 << 5);
		goto node3348;
	} else {
		input[1] &= ~(1 << 5);
		goto node4462;
	}
node1206:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node1144;
	} else {
		input[3] &= ~(1 << 6);
		goto node1072;
	}
node1047:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node5978;
	} else {
		input[3] &= ~(1 << 5);
		goto node591;
	}
node214:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node780;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node1235:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node4139;
	} else {
		input[3] &= ~(1 << 2);
		goto node6682;
	}
node6200:
	b = true;
	if (b) {
		input[3] |= (1 << 1);
		goto node2346;
	} else {
		input[3] &= ~(1 << 1);
		return 0;
	}
node3087:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node8765;
	} else {
		input[2] &= ~(1 << 2);
		goto node5345;
	}
node100:
	b = false;
	if (b) {
		input[4] |= (1 << 7);
		return 0;
	} else {
		input[4] &= ~(1 << 7);
		goto node1870;
	}
node6779:
	b = true;
	if (b) {
		input[2] |= (1 << 2);
		goto node8263;
	} else {
		input[2] &= ~(1 << 2);
		return 0;
	}
node6864:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node1451;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node3993:
	b = false;
	if (b) {
		input[4] |= (1 << 4);
		return 0;
	} else {
		input[4] &= ~(1 << 4);
		goto node8506;
	}
node7398:
	b = randbool();
	if (b) {
		input[1] |= (1 << 3);
		goto node5454;
	} else {
		input[1] &= ~(1 << 3);
		goto node1930;
	}
node4395:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node6408;
	}
node5758:
	b = true;
	if (b) {
		input[2] |= (1 << 2);
		goto node7499;
	} else {
		input[2] &= ~(1 << 2);
		return 0;
	}
node6917:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node7920;
	} else {
		input[3] &= ~(1 << 2);
		goto node6462;
	}
node627:
	b = randbool();
	if (b) {
		input[4] |= (1 << 6);
		goto node9204;
	} else {
		input[4] &= ~(1 << 6);
		goto node8029;
	}
node3764:
	b = false;
	if (b) {
		input[4] |= (1 << 2);
		return 0;
	} else {
		input[4] &= ~(1 << 2);
		goto node3555;
	}
node6593:
	b = true;
	if (b) {
		input[1] |= (1 << 1);
		goto node7699;
	} else {
		input[1] &= ~(1 << 1);
		return 0;
	}
node372:
	b = false;
	if (b) {
		input[3] |= (1 << 7);
		return 0;
	} else {
		input[3] &= ~(1 << 7);
		goto node4940;
	}
node3857:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node5756;
	} else {
		input[3] &= ~(1 << 2);
		goto node4098;
	}
node1526:
	b = randbool();
	if (b) {
		input[5] |= (1 << 1);
		return 6;
	} else {
		input[5] &= ~(1 << 1);
		goto node885;
	}
node3712:
	b = true;
	if (b) {
		input[2] |= (1 << 7);
		goto node3099;
	} else {
		input[2] &= ~(1 << 7);
		return 0;
	}
node9248:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		goto node5849;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node9188:
	b = randbool();
	if (b) {
		input[1] |= (1 << 4);
		goto node1559;
	} else {
		input[1] &= ~(1 << 4);
		goto node8675;
	}
node6167:
	b = randbool();
	if (b) {
		input[1] |= (1 << 2);
		goto node37;
	} else {
		input[1] &= ~(1 << 2);
		goto node7475;
	}
node6792:
	b = false;
	if (b) {
		input[2] |= (1 << 2);
		return 0;
	} else {
		input[2] &= ~(1 << 2);
		goto node8147;
	}
node4761:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node6553;
	} else {
		input[2] &= ~(1 << 2);
		goto node847;
	}
node8227:
	b = true;
	if (b) {
		input[3] |= (1 << 6);
		goto node605;
	} else {
		input[3] &= ~(1 << 6);
		return 0;
	}
node4466:
	b = false;
	if (b) {
		input[4] |= (1 << 0);
		return 0;
	} else {
		input[4] &= ~(1 << 0);
		goto node5891;
	}
node9142:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node9251;
	} else {
		input[3] &= ~(1 << 6);
		goto node5444;
	}
node5053:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node3671;
	} else {
		input[3] &= ~(1 << 5);
		return 4;
	}
node6503:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node8265;
	}
node2012:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node3649;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node8472:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node7043;
	} else {
		input[3] &= ~(1 << 2);
		goto node2488;
	}
node4583:
	b = randbool();
	if (b) {
		input[4] |= (1 << 5);
		goto node3899;
	} else {
		input[4] &= ~(1 << 5);
		goto node3673;
	}
node7986:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node5500;
	} else {
		input[2] &= ~(1 << 3);
		goto node8075;
	}
node4797:
	b = randbool();
	if (b) {
		input[2] |= (1 << 0);
		goto node2328;
	} else {
		input[2] &= ~(1 << 0);
		goto node8515;
	}
node9473:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node5421;
	} else {
		input[3] &= ~(1 << 5);
		goto node6524;
	}
node8547:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node2013;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node4995:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node69;
	} else {
		input[3] &= ~(1 << 3);
		goto node3132;
	}
node2171:
	b = randbool();
	if (b) {
		input[4] |= (1 << 7);
		goto node8763;
	} else {
		input[4] &= ~(1 << 7);
		goto node8648;
	}
node5197:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node4030;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node2998:
	b = true;
	if (b) {
		input[4] |= (1 << 3);
		goto node6746;
	} else {
		input[4] &= ~(1 << 3);
		return 0;
	}
node4406:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node195;
	} else {
		input[2] &= ~(1 << 6);
		goto node1369;
	}
node7364:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node1483;
	} else {
		input[2] &= ~(1 << 4);
		goto node6403;
	}
node8552:
	b = true;
	if (b) {
		input[2] |= (1 << 3);
		goto node3811;
	} else {
		input[2] &= ~(1 << 3);
		return 0;
	}
node8435:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node3614;
	} else {
		input[3] &= ~(1 << 5);
		goto node2543;
	}
node887:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node6767;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node2929:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node7824;
	} else {
		input[3] &= ~(1 << 4);
		goto node9312;
	}
node5968:
	b = randbool();
	if (b) {
		input[1] |= (1 << 0);
		return 7;
	} else {
		input[1] &= ~(1 << 0);
		goto node5746;
	}
node1939:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		goto node7747;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node4355:
	b = true;
	if (b) {
		input[3] |= (1 << 6);
		goto node3740;
	} else {
		input[3] &= ~(1 << 6);
		return 0;
	}
node7895:
	b = false;
	if (b) {
		input[5] |= (1 << 0);
		return 0;
	} else {
		input[5] &= ~(1 << 0);
		return 7;
	}
node5780:
	b = randbool();
	if (b) {
		input[2] |= (1 << 7);
		goto node7029;
	} else {
		input[2] &= ~(1 << 7);
		goto node4421;
	}
node2783:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node2069;
	} else {
		input[2] &= ~(1 << 4);
		goto node5281;
	}
node1451:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node2090;
	}
node3050:
	b = true;
	if (b) {
		input[3] |= (1 << 0);
		goto node3520;
	} else {
		input[3] &= ~(1 << 0);
		return 0;
	}
node2422:
	b = true;
	if (b) {
		input[4] |= (1 << 4);
		goto node3990;
	} else {
		input[4] &= ~(1 << 4);
		return 0;
	}
node4442:
	b = randbool();
	if (b) {
		input[0] |= (1 << 2);
		goto node2643;
	} else {
		input[0] &= ~(1 << 2);
		goto node1349;
	}
node2172:
	b = false;
	if (b) {
		input[1] |= (1 << 6);
		return 0;
	} else {
		input[1] &= ~(1 << 6);
		goto node6121;
	}
node135:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node6133;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node5347:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node4255;
	}
node259:
	b = true;
	if (b) {
		input[2] |= (1 << 3);
		goto node7262;
	} else {
		input[2] &= ~(1 << 3);
		return 0;
	}
node710:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node7736;
	}
node5305:
	b = false;
	if (b) {
		input[4] |= (1 << 0);
		return 0;
	} else {
		input[4] &= ~(1 << 0);
		goto node8463;
	}
node2881:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node315;
	} else {
		input[2] &= ~(1 << 4);
		goto node7887;
	}
node2045:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node7923;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node7638:
	b = randbool();
	if (b) {
		input[4] |= (1 << 6);
		goto node1525;
	} else {
		input[4] &= ~(1 << 6);
		goto node2278;
	}
node5308:
	b = true;
	if (b) {
		input[3] |= (1 << 6);
		goto node7294;
	} else {
		input[3] &= ~(1 << 6);
		return 0;
	}
node4022:
	b = true;
	if (b) {
		input[3] |= (1 << 6);
		goto node2011;
	} else {
		input[3] &= ~(1 << 6);
		return 0;
	}
node279:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node8468;
	}
node3627:
	b = false;
	if (b) {
		input[3] |= (1 << 1);
		return 0;
	} else {
		input[3] &= ~(1 << 1);
		goto node7933;
	}
node1552:
	b = randbool();
	if (b) {
		input[7] |= (1 << 1);
		return 8;
	} else {
		input[7] &= ~(1 << 1);
		goto node2815;
	}
node1594:
	b = false;
	if (b) {
		input[1] |= (1 << 5);
		return 0;
	} else {
		input[1] &= ~(1 << 5);
		goto node6710;
	}
node2314:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node3398;
	} else {
		input[2] &= ~(1 << 2);
		goto node641;
	}
node8992:
	b = false;
	if (b) {
		input[2] |= (1 << 0);
		return 0;
	} else {
		input[2] &= ~(1 << 0);
		goto node2010;
	}
node1230:
	b = randbool();
	if (b) {
		input[4] |= (1 << 2);
		goto node1317;
	} else {
		input[4] &= ~(1 << 2);
		goto node6959;
	}
node5883:
	b = true;
	if (b) {
		input[1] |= (1 << 1);
		goto node6763;
	} else {
		input[1] &= ~(1 << 1);
		return 0;
	}
node6517:
	b = true;
	if (b) {
		input[2] |= (1 << 4);
		goto node2299;
	} else {
		input[2] &= ~(1 << 4);
		return 0;
	}
node47:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node8312;
	}
node6784:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node6297;
	} else {
		input[3] &= ~(1 << 2);
		goto node3055;
	}
node9012:
	b = true;
	if (b) {
		input[4] |= (1 << 5);
		goto node9335;
	} else {
		input[4] &= ~(1 << 5);
		return 0;
	}
node760:
	b = randbool();
	if (b) {
		input[4] |= (1 << 7);
		goto node4829;
	} else {
		input[4] &= ~(1 << 7);
		goto node286;
	}
node8898:
	b = randbool();
	if (b) {
		input[2] |= (1 << 7);
		goto node900;
	} else {
		input[2] &= ~(1 << 7);
		goto node7357;
	}
node8427:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node5201;
	} else {
		input[2] &= ~(1 << 5);
		goto node2130;
	}
node5462:
	b = true;
	if (b) {
		input[2] |= (1 << 4);
		goto node8962;
	} else {
		input[2] &= ~(1 << 4);
		return 0;
	}
node7682:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node1607;
	}
node2299:
	b = false;
	if (b) {
		input[2] |= (1 << 3);
		return 0;
	} else {
		input[2] &= ~(1 << 3);
		return 4;
	}
node1716:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node4806;
	} else {
		input[2] &= ~(1 << 1);
		goto node4477;
	}
node7273:
	b = randbool();
	if (b) {
		input[1] |= (1 << 6);
		goto node8913;
	} else {
		input[1] &= ~(1 << 6);
		goto node2665;
	}
node8816:
	b = true;
	if (b) {
		input[2] |= (1 << 6);
		goto node8851;
	} else {
		input[2] &= ~(1 << 6);
		return 0;
	}
node6535:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node3349;
	}
node6454:
	b = false;
	if (b) {
		input[2] |= (1 << 1);
		return 0;
	} else {
		input[2] &= ~(1 << 1);
		goto node7014;
	}
node6155:
	b = randbool();
	if (b) {
		input[2] |= (1 << 0);
		goto node291;
	} else {
		input[2] &= ~(1 << 0);
		goto node9062;
	}
node5394:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node3274;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node2964:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node5911;
	} else {
		input[2] &= ~(1 << 6);
		goto node2179;
	}
node172:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node5738;
	} else {
		input[2] &= ~(1 << 3);
		goto node5828;
	}
node3597:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node8768;
	} else {
		input[2] &= ~(1 << 3);
		goto node5976;
	}
node4359:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node2436;
	} else {
		input[3] &= ~(1 << 5);
		goto node5161;
	}
node5558:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node2636;
	} else {
		input[3] &= ~(1 << 3);
		goto node662;
	}
node1021:
	b = randbool();
	if (b) {
		input[6] |= (1 << 1);
		return 7;
	} else {
		input[6] &= ~(1 << 1);
		goto node3858;
	}
node2454:
	b = true;
	if (b) {
		input[4] |= (1 << 5);
		goto node9321;
	} else {
		input[4] &= ~(1 << 5);
		return 0;
	}
node7984:
	b = false;
	if (b) {
		input[0] |= (1 << 4);
		return 0;
	} else {
		input[0] &= ~(1 << 4);
		goto node4573;
	}
node8779:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node1653;
	} else {
		input[2] &= ~(1 << 6);
		goto node1097;
	}
node1055:
	b = true;
	if (b) {
		input[2] |= (1 << 2);
		goto node7036;
	} else {
		input[2] &= ~(1 << 2);
		return 0;
	}
node7146:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node3716;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node5291:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node9446;
	} else {
		input[3] &= ~(1 << 5);
		goto node8004;
	}
node2764:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node7632;
	} else {
		input[3] &= ~(1 << 2);
		goto node6297;
	}
node1171:
	b = randbool();
	if (b) {
		input[1] |= (1 << 1);
		goto node6186;
	} else {
		input[1] &= ~(1 << 1);
		goto node5142;
	}
node6603:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node2130;
	} else {
		input[2] &= ~(1 << 4);
		goto node8607;
	}
node61:
	b = false;
	if (b) {
		input[2] |= (1 << 1);
		return 0;
	} else {
		input[2] &= ~(1 << 1);
		goto node1417;
	}
node5346:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node8278;
	} else {
		input[3] &= ~(1 << 5);
		goto node8548;
	}
node6699:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node1630;
	} else {
		input[2] &= ~(1 << 5);
		goto node8737;
	}
node8790:
	b = true;
	if (b) {
		input[2] |= (1 << 3);
		goto node6820;
	} else {
		input[2] &= ~(1 << 3);
		return 0;
	}
node3665:
	b = false;
	if (b) {
		input[2] |= (1 << 2);
		return 0;
	} else {
		input[2] &= ~(1 << 2);
		goto node1297;
	}
node8778:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node6207;
	} else {
		input[2] &= ~(1 << 6);
		goto node8413;
	}
node3252:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node4390;
	} else {
		input[2] &= ~(1 << 5);
		goto node1203;
	}
node1027:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node2403;
	} else {
		input[3] &= ~(1 << 7);
		goto node1956;
	}
node8265:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node9450;
	}
node6926:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node3520;
	} else {
		input[3] &= ~(1 << 3);
		goto node2996;
	}
node669:
	b = false;
	if (b) {
		input[3] |= (1 << 0);
		return 0;
	} else {
		input[3] &= ~(1 << 0);
		goto node580;
	}
node179:
	b = randbool();
	if (b) {
		input[4] |= (1 << 1);
		goto node3127;
	} else {
		input[4] &= ~(1 << 1);
		goto node7576;
	}
node2372:
	b = false;
	if (b) {
		input[3] |= (1 << 7);
		return 0;
	} else {
		input[3] &= ~(1 << 7);
		goto node7523;
	}
node3732:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node903;
	}
node2476:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node5269;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node8632:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node2672;
	} else {
		input[3] &= ~(1 << 3);
		goto node9137;
	}
node466:
	b = randbool();
	if (b) {
		input[3] |= (1 << 1);
		goto node1592;
	} else {
		input[3] &= ~(1 << 1);
		goto node5100;
	}
node9321:
	b = true;
	if (b) {
		input[4] |= (1 << 4);
		goto node2984;
	} else {
		input[4] &= ~(1 << 4);
		return 0;
	}
node4218:
	b = randbool();
	if (b) {
		input[0] |= (1 << 2);
		goto node7389;
	} else {
		input[0] &= ~(1 << 2);
		goto node7773;
	}
node6459:
	b = true;
	if (b) {
		input[1] |= (1 << 6);
		goto node9103;
	} else {
		input[1] &= ~(1 << 6);
		return 0;
	}
node1347:
	b = false;
	if (b) {
		input[2] |= (1 << 6);
		return 0;
	} else {
		input[2] &= ~(1 << 6);
		goto node4662;
	}
node2023:
	b = true;
	if (b) {
		input[2] |= (1 << 3);
		goto node6323;
	} else {
		input[2] &= ~(1 << 3);
		return 0;
	}
node3360:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node1340;
	} else {
		input[3] &= ~(1 << 7);
		goto node5278;
	}
node8587:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node6064;
	} else {
		input[3] &= ~(1 << 5);
		goto node7766;
	}
node2253:
	b = true;
	if (b) {
		input[1] |= (1 << 1);
		goto node8041;
	} else {
		input[1] &= ~(1 << 1);
		return 0;
	}
node317:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node3248;
	} else {
		input[2] &= ~(1 << 4);
		goto node165;
	}
node7237:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node5355;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node8231:
	b = randbool();
	if (b) {
		input[3] |= (1 << 1);
		goto node3520;
	} else {
		input[3] &= ~(1 << 1);
		goto node2041;
	}
node736:
	b = true;
	if (b) {
		input[2] |= (1 << 4);
		goto node2257;
	} else {
		input[2] &= ~(1 << 4);
		return 0;
	}
node6653:
	b = false;
	if (b) {
		input[2] |= (1 << 1);
		return 0;
	} else {
		input[2] &= ~(1 << 1);
		goto node6551;
	}
node78:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node2992;
	} else {
		input[3] &= ~(1 << 5);
		goto node7788;
	}
node4183:
	b = false;
	if (b) {
		input[4] |= (1 << 5);
		return 0;
	} else {
		input[4] &= ~(1 << 5);
		goto node4630;
	}
node2428:
	b = false;
	if (b) {
		input[2] |= (1 << 3);
		return 0;
	} else {
		input[2] &= ~(1 << 3);
		goto node1484;
	}
node6293:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node3487;
	} else {
		input[2] &= ~(1 << 3);
		goto node4639;
	}
node554:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node4977;
	} else {
		input[3] &= ~(1 << 4);
		goto node3600;
	}
node6830:
	b = false;
	if (b) {
		input[3] |= (1 << 2);
		return 0;
	} else {
		input[3] &= ~(1 << 2);
		goto node4926;
	}
node2058:
	b = true;
	if (b) {
		input[3] |= (1 << 2);
		goto node1152;
	} else {
		input[3] &= ~(1 << 2);
		return 0;
	}
node6995:
	b = randbool();
	if (b) {
		input[1] |= (1 << 6);
		goto node4501;
	} else {
		input[1] &= ~(1 << 6);
		goto node8260;
	}
node1427:
	b = false;
	if (b) {
		input[2] |= (1 << 5);
		return 0;
	} else {
		input[2] &= ~(1 << 5);
		goto node968;
	}
node242:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node3398;
	} else {
		input[2] &= ~(1 << 2);
		goto node379;
	}
node7299:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node7802;
	} else {
		input[2] &= ~(1 << 1);
		goto node2302;
	}
node2464:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node6042;
	}
node8296:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node5034;
	} else {
		input[2] &= ~(1 << 1);
		goto node8457;
	}
node3880:
	b = randbool();
	if (b) {
		input[3] |= (1 << 0);
		goto node2395;
	} else {
		input[3] &= ~(1 << 0);
		goto node4740;
	}
node1691:
	b = true;
	if (b) {
		input[4] |= (1 << 3);
		goto node6416;
	} else {
		input[4] &= ~(1 << 3);
		return 0;
	}
node1872:
	b = randbool();
	if (b) {
		input[1] |= (1 << 2);
		goto node805;
	} else {
		input[1] &= ~(1 << 2);
		goto node497;
	}
node2369:
	b = true;
	if (b) {
		input[1] |= (1 << 0);
		goto node4285;
	} else {
		input[1] &= ~(1 << 0);
		return 0;
	}
node4189:
	b = true;
	if (b) {
		input[3] |= (1 << 1);
		goto node297;
	} else {
		input[3] &= ~(1 << 1);
		return 0;
	}
node6899:
	b = randbool();
	if (b) {
		input[4] |= (1 << 4);
		goto node9092;
	} else {
		input[4] &= ~(1 << 4);
		goto node5449;
	}
node3634:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node6496;
	} else {
		input[2] &= ~(1 << 5);
		goto node1597;
	}
node1320:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node9038;
	} else {
		input[2] &= ~(1 << 3);
		goto node6101;
	}
node8308:
	b = true;
	if (b) {
		input[3] |= (1 << 6);
		goto node7011;
	} else {
		input[3] &= ~(1 << 6);
		return 0;
	}
node3362:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node2358;
	} else {
		input[3] &= ~(1 << 4);
		goto node911;
	}
node7848:
	b = true;
	if (b) {
		input[4] |= (1 << 7);
		goto node5669;
	} else {
		input[4] &= ~(1 << 7);
		return 0;
	}
node6198:
	b = randbool();
	if (b) {
		input[4] |= (1 << 1);
		goto node3327;
	} else {
		input[4] &= ~(1 << 1);
		goto node7203;
	}
node5179:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node2320;
	} else {
		input[3] &= ~(1 << 4);
		goto node3434;
	}
node5494:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node9100;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node2654:
	b = randbool();
	if (b) {
		input[1] |= (1 << 3);
		goto node3566;
	} else {
		input[1] &= ~(1 << 3);
		goto node271;
	}
node5626:
	b = randbool();
	if (b) {
		input[1] |= (1 << 2);
		goto node7645;
	} else {
		input[1] &= ~(1 << 2);
		goto node9129;
	}
node8520:
	b = randbool();
	if (b) {
		input[1] |= (1 << 2);
		goto node7518;
	} else {
		input[1] &= ~(1 << 2);
		goto node314;
	}
node102:
	b = true;
	if (b) {
		input[1] |= (1 << 1);
		goto node6396;
	} else {
		input[1] &= ~(1 << 1);
		return 0;
	}
node4201:
	b = randbool();
	if (b) {
		input[1] |= (1 << 1);
		goto node6581;
	} else {
		input[1] &= ~(1 << 1);
		goto node3283;
	}
node1893:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node829;
	} else {
		input[3] &= ~(1 << 7);
		goto node8939;
	}
node4108:
	b = randbool();
	if (b) {
		input[3] |= (1 << 0);
		goto node2395;
	} else {
		input[3] &= ~(1 << 0);
		goto node6462;
	}
node6610:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node2844;
	} else {
		input[2] &= ~(1 << 6);
		goto node639;
	}
node473:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node5080;
	}
node1098:
	b = true;
	if (b) {
		input[3] |= (1 << 2);
		goto node8279;
	} else {
		input[3] &= ~(1 << 2);
		return 0;
	}
node1911:
	b = false;
	if (b) {
		input[2] |= (1 << 0);
		return 0;
	} else {
		input[2] &= ~(1 << 0);
		goto node7941;
	}
node5594:
	b = false;
	if (b) {
		input[2] |= (1 << 6);
		return 0;
	} else {
		input[2] &= ~(1 << 6);
		goto node3469;
	}
node7069:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node4787;
	} else {
		input[2] &= ~(1 << 2);
		goto node3385;
	}
node7293:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node8449;
	} else {
		input[3] &= ~(1 << 7);
		goto node7846;
	}
node6264:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node6145;
	} else {
		input[3] &= ~(1 << 4);
		goto node2576;
	}
node5568:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node2975;
	} else {
		input[3] &= ~(1 << 3);
		goto node5668;
	}
node6212:
	b = randbool();
	if (b) {
		input[3] |= (1 << 0);
		goto node137;
	} else {
		input[3] &= ~(1 << 0);
		goto node285;
	}
node7629:
	b = true;
	if (b) {
		input[3] |= (1 << 2);
		goto node9002;
	} else {
		input[3] &= ~(1 << 2);
		return 0;
	}
node2989:
	b = randbool();
	if (b) {
		input[4] |= (1 << 7);
		goto node894;
	} else {
		input[4] &= ~(1 << 7);
		goto node2193;
	}
node1265:
	b = false;
	if (b) {
		input[1] |= (1 << 2);
		return 0;
	} else {
		input[1] &= ~(1 << 2);
		goto node5230;
	}
node3773:
	b = true;
	if (b) {
		input[1] |= (1 << 0);
		goto node860;
	} else {
		input[1] &= ~(1 << 0);
		return 0;
	}
node3937:
	b = false;
	if (b) {
		input[2] |= (1 << 2);
		return 0;
	} else {
		input[2] &= ~(1 << 2);
		goto node7090;
	}
node9118:
	b = randbool();
	if (b) {
		input[2] |= (1 << 0);
		goto node1770;
	} else {
		input[2] &= ~(1 << 0);
		goto node3360;
	}
node3953:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node5385;
	} else {
		input[3] &= ~(1 << 6);
		goto node5346;
	}
node3669:
	b = true;
	if (b) {
		input[3] |= (1 << 6);
		goto node523;
	} else {
		input[3] &= ~(1 << 6);
		return 0;
	}
node5973:
	b = false;
	if (b) {
		input[4] |= (1 << 2);
		return 0;
	} else {
		input[4] &= ~(1 << 2);
		goto node6358;
	}
node2356:
	b = true;
	if (b) {
		input[4] |= (1 << 1);
		goto node3695;
	} else {
		input[4] &= ~(1 << 1);
		return 0;
	}
node1266:
	b = randbool();
	if (b) {
		input[2] |= (1 << 7);
		goto node986;
	} else {
		input[2] &= ~(1 << 7);
		goto node4918;
	}
node7099:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node6271;
	} else {
		input[3] &= ~(1 << 5);
		goto node7473;
	}
node2270:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node6686;
	} else {
		input[3] &= ~(1 << 3);
		goto node6220;
	}
node5647:
	b = randbool();
	if (b) {
		input[3] |= (1 << 1);
		goto node2868;
	} else {
		input[3] &= ~(1 << 1);
		goto node5466;
	}
node6758:
	b = randbool();
	if (b) {
		input[4] |= (1 << 6);
		goto node2877;
	} else {
		input[4] &= ~(1 << 6);
		goto node5319;
	}
node3339:
	b = randbool();
	if (b) {
		input[4] |= (1 << 4);
		goto node3888;
	} else {
		input[4] &= ~(1 << 4);
		goto node5020;
	}
node1255:
	b = randbool();
	if (b) {
		input[1] |= (1 << 7);
		goto node4020;
	} else {
		input[1] &= ~(1 << 7);
		goto node9052;
	}
node8906:
	b = randbool();
	if (b) {
		input[1] |= (1 << 0);
		goto node2481;
	} else {
		input[1] &= ~(1 << 0);
		goto node5617;
	}
node4698:
	b = randbool();
	if (b) {
		input[4] |= (1 << 4);
		goto node7079;
	} else {
		input[4] &= ~(1 << 4);
		goto node5830;
	}
node7959:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node2202;
	}
node3118:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node8530;
	} else {
		input[2] &= ~(1 << 4);
		goto node1054;
	}
node274:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node9410;
	} else {
		input[3] &= ~(1 << 6);
		goto node4556;
	}
node8133:
	b = false;
	if (b) {
		input[3] |= (1 << 6);
		return 0;
	} else {
		input[3] &= ~(1 << 6);
		goto node8255;
	}
node2899:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node5002;
	} else {
		input[3] &= ~(1 << 3);
		goto node425;
	}
node245:
	b = randbool();
	if (b) {
		input[4] |= (1 << 2);
		goto node2961;
	} else {
		input[4] &= ~(1 << 2);
		goto node4813;
	}
node247:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node685;
	} else {
		input[3] &= ~(1 << 5);
		goto node7766;
	}
node2439:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node1099;
	} else {
		input[3] &= ~(1 << 3);
		goto node8868;
	}
node2104:
	b = true;
	if (b) {
		input[3] |= (1 << 2);
		goto node1896;
	} else {
		input[3] &= ~(1 << 2);
		return 0;
	}
node217:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node6648;
	}
node5839:
	b = true;
	if (b) {
		input[3] |= (1 << 2);
		goto node2331;
	} else {
		input[3] &= ~(1 << 2);
		return 0;
	}
node6641:
	b = randbool();
	if (b) {
		input[1] |= (1 << 4);
		goto node5924;
	} else {
		input[1] &= ~(1 << 4);
		goto node6704;
	}
node3151:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node2644;
	}
node703:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node5678;
	} else {
		input[2] &= ~(1 << 4);
		goto node4642;
	}
node8323:
	b = false;
	if (b) {
		input[2] |= (1 << 0);
		return 0;
	} else {
		input[2] &= ~(1 << 0);
		goto node5537;
	}
node5209:
	b = false;
	if (b) {
		input[3] |= (1 << 7);
		return 0;
	} else {
		input[3] &= ~(1 << 7);
		goto node958;
	}
node9157:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node2974;
	} else {
		input[3] &= ~(1 << 6);
		goto node8850;
	}
node6942:
	b = false;
	if (b) {
		input[1] |= (1 << 5);
		return 0;
	} else {
		input[1] &= ~(1 << 5);
		goto node7957;
	}
node8328:
	b = randbool();
	if (b) {
		input[2] |= (1 << 7);
		goto node4903;
	} else {
		input[2] &= ~(1 << 7);
		goto node4846;
	}
node131:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node6440;
	} else {
		input[3] &= ~(1 << 7);
		goto node6871;
	}
node7142:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node4145;
	} else {
		input[3] &= ~(1 << 4);
		goto node4757;
	}
node5653:
	b = randbool();
	if (b) {
		input[3] |= (1 << 1);
		goto node2221;
	} else {
		input[3] &= ~(1 << 1);
		goto node3050;
	}
node297:
	b = true;
	if (b) {
		input[3] |= (1 << 0);
		goto node896;
	} else {
		input[3] &= ~(1 << 0);
		return 0;
	}
node9256:
	b = randbool();
	if (b) {
		input[4] |= (1 << 1);
		goto node2808;
	} else {
		input[4] &= ~(1 << 1);
		goto node439;
	}
node4945:
	b = true;
	if (b) {
		input[3] |= (1 << 7);
		goto node6056;
	} else {
		input[3] &= ~(1 << 7);
		return 0;
	}
node7974:
	b = true;
	if (b) {
		input[3] |= (1 << 7);
		goto node8163;
	} else {
		input[3] &= ~(1 << 7);
		return 0;
	}
node2295:
	b = false;
	if (b) {
		input[3] |= (1 << 7);
		return 0;
	} else {
		input[3] &= ~(1 << 7);
		goto node7965;
	}
node4127:
	b = true;
	if (b) {
		input[3] |= (1 << 7);
		goto node5376;
	} else {
		input[3] &= ~(1 << 7);
		return 0;
	}
node2419:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node3321;
	}
node1584:
	b = randbool();
	if (b) {
		input[4] |= (1 << 3);
		goto node8259;
	} else {
		input[4] &= ~(1 << 3);
		goto node5387;
	}
node5749:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node4912;
	} else {
		input[3] &= ~(1 << 6);
		goto node3495;
	}
node1776:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node5862;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node1709:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node9126;
	} else {
		input[2] &= ~(1 << 1);
		goto node225;
	}
node300:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node8340;
	} else {
		input[3] &= ~(1 << 6);
		goto node9199;
	}
node447:
	b = false;
	if (b) {
		input[4] |= (1 << 5);
		return 0;
	} else {
		input[4] &= ~(1 << 5);
		goto node7381;
	}
node4061:
	b = false;
	if (b) {
		input[2] |= (1 << 6);
		return 0;
	} else {
		input[2] &= ~(1 << 6);
		goto node8291;
	}
node5655:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node8759;
	} else {
		input[2] &= ~(1 << 5);
		goto node1207;
	}
node2767:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		return 4;
	} else {
		input[2] &= ~(1 << 1);
		goto node4852;
	}
node5424:
	b = randbool();
	if (b) {
		input[2] |= (1 << 0);
		goto node2825;
	} else {
		input[2] &= ~(1 << 0);
		goto node1087;
	}
node357:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node6678;
	} else {
		input[3] &= ~(1 << 2);
		return 8;
	}
node3399:
	b = false;
	if (b) {
		input[3] |= (1 << 0);
		return 0;
	} else {
		input[3] &= ~(1 << 0);
		goto node2347;
	}
node7112:
	b = true;
	if (b) {
		input[3] |= (1 << 0);
		goto node2584;
	} else {
		input[3] &= ~(1 << 0);
		return 0;
	}
node4534:
	b = true;
	if (b) {
		input[4] |= (1 << 2);
		goto node5003;
	} else {
		input[4] &= ~(1 << 2);
		return 0;
	}
node1706:
	b = randbool();
	if (b) {
		input[1] |= (1 << 2);
		goto node1813;
	} else {
		input[1] &= ~(1 << 2);
		goto node790;
	}
node7518:
	b = randbool();
	if (b) {
		input[1] |= (1 << 1);
		goto node314;
	} else {
		input[1] &= ~(1 << 1);
		goto node6186;
	}
node401:
	b = false;
	if (b) {
		input[2] |= (1 << 6);
		return 0;
	} else {
		input[2] &= ~(1 << 6);
		goto node6350;
	}
node9340:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node5446;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node1145:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node6528;
	} else {
		input[3] &= ~(1 << 5);
		goto node7785;
	}
node2382:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node2726;
	} else {
		input[3] &= ~(1 << 3);
		goto node409;
	}
node6334:
	b = randbool();
	if (b) {
		input[1] |= (1 << 0);
		goto node4984;
	} else {
		input[1] &= ~(1 << 0);
		goto node6620;
	}
node2621:
	b = false;
	if (b) {
		input[2] |= (1 << 7);
		return 0;
	} else {
		input[2] &= ~(1 << 7);
		goto node4210;
	}
node2536:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node3324;
	} else {
		input[3] &= ~(1 << 3);
		goto node6835;
	}
node927:
	b = false;
	if (b) {
		input[3] |= (1 << 0);
		return 0;
	} else {
		input[3] &= ~(1 << 0);
		return 8;
	}
node518:
	b = true;
	if (b) {
		input[4] |= (1 << 5);
		goto node6623;
	} else {
		input[4] &= ~(1 << 5);
		return 0;
	}
node8745:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node1938;
	}
node6070:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node6752;
	} else {
		input[3] &= ~(1 << 3);
		goto node3827;
	}
node2610:
	b = false;
	if (b) {
		input[3] |= (1 << 2);
		return 0;
	} else {
		input[3] &= ~(1 << 2);
		goto node5686;
	}
node6886:
	b = true;
	if (b) {
		input[2] |= (1 << 2);
		goto node1051;
	} else {
		input[2] &= ~(1 << 2);
		return 0;
	}
node1955:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node5773;
	} else {
		input[2] &= ~(1 << 1);
		goto node5463;
	}
node9301:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node5812;
	} else {
		input[3] &= ~(1 << 5);
		goto node2226;
	}
node7971:
	b = randbool();
	if (b) {
		input[4] |= (1 << 4);
		goto node990;
	} else {
		input[4] &= ~(1 << 4);
		goto node797;
	}
node8315:
	b = false;
	if (b) {
		input[4] |= (1 << 2);
		return 0;
	} else {
		input[4] &= ~(1 << 2);
		goto node8247;
	}
node3754:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node5987;
	} else {
		input[3] &= ~(1 << 7);
		goto node5400;
	}
node2975:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node7252;
	} else {
		input[3] &= ~(1 << 2);
		goto node4098;
	}
node7893:
	b = true;
	if (b) {
		input[4] |= (1 << 7);
		goto node3138;
	} else {
		input[4] &= ~(1 << 7);
		return 0;
	}
node5542:
	b = true;
	if (b) {
		input[1] |= (1 << 1);
		goto node2369;
	} else {
		input[1] &= ~(1 << 1);
		return 0;
	}
node1151:
	b = false;
	if (b) {
		input[2] |= (1 << 2);
		return 0;
	} else {
		input[2] &= ~(1 << 2);
		goto node2008;
	}
node243:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node4067;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node7953:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node3228;
	}
node5988:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node289;
	} else {
		input[3] &= ~(1 << 4);
		goto node7412;
	}
node3674:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node7023;
	} else {
		input[2] &= ~(1 << 4);
		goto node3753;
	}
node6251:
	b = true;
	if (b) {
		input[2] |= (1 << 2);
		goto node1663;
	} else {
		input[2] &= ~(1 << 2);
		return 0;
	}
node8876:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node871;
	} else {
		input[3] &= ~(1 << 2);
		goto node5211;
	}
node1095:
	b = false;
	if (b) {
		input[3] |= (1 << 0);
		return 0;
	} else {
		input[3] &= ~(1 << 0);
		goto node2509;
	}
node6442:
	b = randbool();
	if (b) {
		input[4] |= (1 << 6);
		goto node4393;
	} else {
		input[4] &= ~(1 << 6);
		goto node7484;
	}
node4169:
	b = false;
	if (b) {
		input[4] |= (1 << 4);
		return 0;
	} else {
		input[4] &= ~(1 << 4);
		goto node3809;
	}
node1834:
	b = false;
	if (b) {
		input[2] |= (1 << 3);
		return 0;
	} else {
		input[2] &= ~(1 << 3);
		goto node3501;
	}
node9038:
	b = false;
	if (b) {
		input[2] |= (1 << 2);
		return 0;
	} else {
		input[2] &= ~(1 << 2);
		goto node3822;
	}
node4680:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node7236;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node5189:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node2084;
	}
node263:
	b = false;
	if (b) {
		input[3] |= (1 << 2);
		return 0;
	} else {
		input[3] &= ~(1 << 2);
		goto node5381;
	}
node8896:
	b = true;
	if (b) {
		input[4] |= (1 << 7);
		goto node1489;
	} else {
		input[4] &= ~(1 << 7);
		return 0;
	}
node1415:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node6279;
	} else {
		input[2] &= ~(1 << 5);
		goto node1597;
	}
node5373:
	b = false;
	if (b) {
		input[3] |= (1 << 7);
		return 0;
	} else {
		input[3] &= ~(1 << 7);
		goto node4769;
	}
node7296:
	b = false;
	if (b) {
		input[4] |= (1 << 7);
		return 0;
	} else {
		input[4] &= ~(1 << 7);
		goto node5012;
	}
node3250:
	b = randbool();
	if (b) {
		input[0] |= (1 << 0);
		goto node2184;
	} else {
		input[0] &= ~(1 << 0);
		goto node2970;
	}
node7960:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node1010;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node1875:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node8392;
	} else {
		input[3] &= ~(1 << 4);
		goto node560;
	}
node8173:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node3650;
	} else {
		input[3] &= ~(1 << 3);
		goto node5083;
	}
node5251:
	b = true;
	if (b) {
		input[3] |= (1 << 2);
		goto node4189;
	} else {
		input[3] &= ~(1 << 2);
		return 0;
	}
node5112:
	b = false;
	if (b) {
		input[3] |= (1 << 0);
		return 0;
	} else {
		input[3] &= ~(1 << 0);
		goto node7296;
	}
node3078:
	b = true;
	if (b) {
		input[4] |= (1 << 6);
		goto node5456;
	} else {
		input[4] &= ~(1 << 6);
		return 0;
	}
node8497:
	b = randbool();
	if (b) {
		input[1] |= (1 << 2);
		goto node4512;
	} else {
		input[1] &= ~(1 << 2);
		goto node5289;
	}
node1886:
	b = false;
	if (b) {
		input[2] |= (1 << 5);
		return 0;
	} else {
		input[2] &= ~(1 << 5);
		goto node5493;
	}
node2335:
	b = true;
	if (b) {
		input[3] |= (1 << 6);
		goto node2700;
	} else {
		input[3] &= ~(1 << 6);
		return 0;
	}
node4453:
	b = true;
	if (b) {
		input[3] |= (1 << 0);
		goto node298;
	} else {
		input[3] &= ~(1 << 0);
		return 0;
	}
node3681:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node1939;
	} else {
		input[2] &= ~(1 << 2);
		goto node7510;
	}
node1940:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node7835;
	} else {
		input[3] &= ~(1 << 5);
		goto node940;
	}
node7011:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node2392;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node6317:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node5072;
	} else {
		input[3] &= ~(1 << 4);
		goto node1924;
	}
node414:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node2450;
	} else {
		input[3] &= ~(1 << 4);
		goto node6513;
	}
node3746:
	b = false;
	if (b) {
		input[1] |= (1 << 2);
		return 0;
	} else {
		input[1] &= ~(1 << 2);
		goto node498;
	}
node2481:
	b = randbool();
	if (b) {
		input[2] |= (1 << 7);
		goto node8464;
	} else {
		input[2] &= ~(1 << 7);
		goto node1237;
	}
node1332:
	b = false;
	if (b) {
		input[2] |= (1 << 5);
		return 0;
	} else {
		input[2] &= ~(1 << 5);
		goto node1039;
	}
node5155:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node9185;
	}
node6985:
	b = true;
	if (b) {
		input[3] |= (1 << 1);
		goto node8921;
	} else {
		input[3] &= ~(1 << 1);
		return 0;
	}
node1037:
	b = true;
	if (b) {
		input[2] |= (1 << 6);
		goto node8482;
	} else {
		input[2] &= ~(1 << 6);
		return 0;
	}
node5605:
	b = false;
	if (b) {
		input[2] |= (1 << 5);
		return 0;
	} else {
		input[2] &= ~(1 << 5);
		goto node9299;
	}
node8849:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		goto node5000;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node1450:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		goto node5233;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node5829:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		return 5;
	} else {
		input[2] &= ~(1 << 1);
		goto node3342;
	}
node4171:
	b = true;
	if (b) {
		input[3] |= (1 << 6);
		goto node2082;
	} else {
		input[3] &= ~(1 << 6);
		return 0;
	}
node8436:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node1896;
	}
node7290:
	b = true;
	if (b) {
		input[1] |= (1 << 0);
		goto node6369;
	} else {
		input[1] &= ~(1 << 0);
		return 0;
	}
node689:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node3947;
	} else {
		input[2] &= ~(1 << 2);
		goto node7396;
	}
node8263:
	b = false;
	if (b) {
		input[2] |= (1 << 1);
		return 0;
	} else {
		input[2] &= ~(1 << 1);
		goto node8613;
	}
node3903:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node3940;
	} else {
		input[3] &= ~(1 << 6);
		goto node8212;
	}
node7308:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node137;
	} else {
		input[3] &= ~(1 << 2);
		goto node1152;
	}
node8730:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node1995;
	} else {
		input[2] &= ~(1 << 1);
		goto node8457;
	}
node796:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node1975;
	}
node2755:
	b = true;
	if (b) {
		input[1] |= (1 << 5);
		goto node4394;
	} else {
		input[1] &= ~(1 << 5);
		return 0;
	}
node8883:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node4601;
	} else {
		input[2] &= ~(1 << 6);
		goto node1572;
	}
node8011:
	b = false;
	if (b) {
		input[2] |= (1 << 5);
		return 0;
	} else {
		input[2] &= ~(1 << 5);
		goto node4452;
	}
node5087:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node6425;
	} else {
		input[2] &= ~(1 << 3);
		goto node3610;
	}
node3208:
	b = false;
	if (b) {
		input[2] |= (1 << 2);
		return 0;
	} else {
		input[2] &= ~(1 << 2);
		goto node6068;
	}
node5432:
	b = true;
	if (b) {
		input[2] |= (1 << 2);
		goto node2425;
	} else {
		input[2] &= ~(1 << 2);
		return 0;
	}
node280:
	b = false;
	if (b) {
		input[4] |= (1 << 0);
		return 0;
	} else {
		input[4] &= ~(1 << 0);
		goto node602;
	}
node3829:
	b = true;
	if (b) {
		input[5] |= (1 << 5);
		goto node3788;
	} else {
		input[5] &= ~(1 << 5);
		return 0;
	}
node3790:
	b = false;
	if (b) {
		input[2] |= (1 << 6);
		return 0;
	} else {
		input[2] &= ~(1 << 6);
		goto node1038;
	}
node3961:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node5247;
	}
node665:
	b = randbool();
	if (b) {
		input[1] |= (1 << 0);
		goto node3195;
	} else {
		input[1] &= ~(1 << 0);
		goto node2213;
	}
node2547:
	b = true;
	if (b) {
		input[2] |= (1 << 3);
		goto node1003;
	} else {
		input[2] &= ~(1 << 3);
		return 0;
	}
node3331:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		goto node4363;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node6897:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node3502;
	} else {
		input[3] &= ~(1 << 4);
		goto node3107;
	}
node4305:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node5008;
	} else {
		input[3] &= ~(1 << 7);
		goto node7302;
	}
node3227:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node3787;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node2689:
	b = false;
	if (b) {
		input[5] |= (1 << 1);
		return 0;
	} else {
		input[5] &= ~(1 << 1);
		goto node1768;
	}
node7962:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node3664;
	} else {
		input[2] &= ~(1 << 4);
		goto node563;
	}
node8724:
	b = randbool();
	if (b) {
		input[1] |= (1 << 2);
		return 3;
	} else {
		input[1] &= ~(1 << 2);
		goto node5952;
	}
node1813:
	b = false;
	if (b) {
		input[1] |= (1 << 0);
		return 0;
	} else {
		input[1] &= ~(1 << 0);
		goto node6582;
	}
node5485:
	b = randbool();
	if (b) {
		input[6] |= (1 << 3);
		goto node2042;
	} else {
		input[6] &= ~(1 << 3);
		goto node5342;
	}
node9122:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node8928;
	} else {
		input[2] &= ~(1 << 1);
		goto node7887;
	}
node1246:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node8249;
	} else {
		input[3] &= ~(1 << 4);
		goto node8950;
	}
node2722:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node7632;
	} else {
		input[3] &= ~(1 << 2);
		goto node4139;
	}
node1094:
	b = randbool();
	if (b) {
		input[3] |= (1 << 1);
		return 6;
	} else {
		input[3] &= ~(1 << 1);
		goto node255;
	}
node5554:
	b = randbool();
	if (b) {
		input[4] |= (1 << 6);
		goto node1101;
	} else {
		input[4] &= ~(1 << 6);
		goto node1012;
	}
node5293:
	b = randbool();
	if (b) {
		input[0] |= (1 << 1);
		goto node5108;
	} else {
		input[0] &= ~(1 << 1);
		goto node5703;
	}
node4054:
	b = false;
	if (b) {
		input[1] |= (1 << 0);
		return 0;
	} else {
		input[1] &= ~(1 << 0);
		goto node4513;
	}
node8944:
	b = false;
	if (b) {
		input[2] |= (1 << 6);
		return 0;
	} else {
		input[2] &= ~(1 << 6);
		goto node1248;
	}
node7314:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node947;
	} else {
		input[2] &= ~(1 << 4);
		goto node8170;
	}
node2118:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node117;
	} else {
		input[2] &= ~(1 << 1);
		goto node3972;
	}
node7352:
	b = true;
	if (b) {
		input[3] |= (1 << 7);
		goto node5698;
	} else {
		input[3] &= ~(1 << 7);
		return 0;
	}
node4950:
	b = true;
	if (b) {
		input[4] |= (1 << 4);
		goto node4213;
	} else {
		input[4] &= ~(1 << 4);
		return 0;
	}
node9052:
	b = randbool();
	if (b) {
		input[1] |= (1 << 6);
		goto node4799;
	} else {
		input[1] &= ~(1 << 6);
		goto node5419;
	}
node3396:
	b = randbool();
	if (b) {
		input[1] |= (1 << 2);
		goto node648;
	} else {
		input[1] &= ~(1 << 2);
		goto node2674;
	}
node6207:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node6952;
	} else {
		input[2] &= ~(1 << 5);
		goto node6366;
	}
node2434:
	b = false;
	if (b) {
		input[3] |= (1 << 7);
		return 0;
	} else {
		input[3] &= ~(1 << 7);
		goto node4254;
	}
node8188:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node8493;
	} else {
		input[3] &= ~(1 << 6);
		goto node3744;
	}
node8348:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node6372;
	} else {
		input[3] &= ~(1 << 3);
		goto node2672;
	}
node7615:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node1573;
	} else {
		input[2] &= ~(1 << 3);
		goto node6932;
	}
node5079:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node7404;
	} else {
		input[3] &= ~(1 << 6);
		goto node6183;
	}
node2162:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node2929;
	} else {
		input[3] &= ~(1 << 5);
		goto node9371;
	}
node2940:
	b = true;
	if (b) {
		input[7] |= (1 << 0);
		return 9;
	} else {
		input[7] &= ~(1 << 0);
		return 0;
	}
node2168:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node1397;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node548:
	b = true;
	if (b) {
		input[3] |= (1 << 2);
		goto node9372;
	} else {
		input[3] &= ~(1 << 2);
		return 0;
	}
node5255:
	b = randbool();
	if (b) {
		input[1] |= (1 << 3);
		goto node4432;
	} else {
		input[1] &= ~(1 << 3);
		return 2;
	}
node497:
	b = false;
	if (b) {
		input[1] |= (1 << 1);
		return 0;
	} else {
		input[1] &= ~(1 << 1);
		goto node3834;
	}
node7424:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node6936;
	} else {
		input[2] &= ~(1 << 6);
		goto node3284;
	}
node1809:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node5006;
	} else {
		input[2] &= ~(1 << 3);
		goto node2675;
	}
node2588:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node5322;
	} else {
		input[3] &= ~(1 << 5);
		goto node9254;
	}
node6781:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node7246;
	} else {
		input[3] &= ~(1 << 5);
		goto node8776;
	}
node7224:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node8542;
	} else {
		input[2] &= ~(1 << 5);
		goto node1097;
	}
node5783:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node1666;
	} else {
		input[2] &= ~(1 << 3);
		goto node689;
	}
node9146:
	b = true;
	if (b) {
		input[3] |= (1 << 6);
		goto node2067;
	} else {
		input[3] &= ~(1 << 6);
		return 0;
	}
node4697:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node6382;
	} else {
		input[3] &= ~(1 << 2);
		goto node7082;
	}
node8706:
	b = randbool();
	if (b) {
		input[4] |= (1 << 4);
		goto node7540;
	} else {
		input[4] &= ~(1 << 4);
		goto node3570;
	}
node2397:
	b = randbool();
	if (b) {
		input[1] |= (1 << 5);
		goto node4943;
	} else {
		input[1] &= ~(1 << 5);
		goto node7086;
	}
node1374:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node3466;
	}
node9032:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node1929;
	} else {
		input[3] &= ~(1 << 3);
		goto node4469;
	}
node5609:
	b = true;
	if (b) {
		input[4] |= (1 << 3);
		goto node7197;
	} else {
		input[4] &= ~(1 << 3);
		return 0;
	}
node2410:
	b = randbool();
	if (b) {
		input[0] |= (1 << 0);
		goto node2828;
	} else {
		input[0] &= ~(1 << 0);
		goto node2184;
	}
node7967:
	b = randbool();
	if (b) {
		input[1] |= (1 << 4);
		return 2;
	} else {
		input[1] &= ~(1 << 4);
		goto node3632;
	}
node609:
	b = false;
	if (b) {
		input[1] |= (1 << 3);
		return 0;
	} else {
		input[1] &= ~(1 << 3);
		goto node8511;
	}
node6463:
	b = true;
	if (b) {
		input[4] |= (1 << 5);
		return 6;
	} else {
		input[4] &= ~(1 << 5);
		return 0;
	}
node2183:
	b = false;
	if (b) {
		input[4] |= (1 << 4);
		return 0;
	} else {
		input[4] &= ~(1 << 4);
		goto node1935;
	}
node2878:
	b = randbool();
	if (b) {
		input[5] |= (1 << 6);
		goto node1511;
	} else {
		input[5] &= ~(1 << 6);
		goto node4199;
	}
node4528:
	b = false;
	if (b) {
		input[1] |= (1 << 5);
		return 0;
	} else {
		input[1] &= ~(1 << 5);
		goto node5426;
	}
node287:
	b = randbool();
	if (b) {
		input[1] |= (1 << 0);
		goto node5628;
	} else {
		input[1] &= ~(1 << 0);
		goto node2894;
	}
node5061:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node4837;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node4180:
	b = false;
	if (b) {
		input[1] |= (1 << 0);
		return 0;
	} else {
		input[1] &= ~(1 << 0);
		goto node5593;
	}
node2361:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node2839;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node5084:
	b = true;
	if (b) {
		input[5] |= (1 << 6);
		goto node7157;
	} else {
		input[5] &= ~(1 << 6);
		return 0;
	}
node7262:
	b = true;
	if (b) {
		input[2] |= (1 << 2);
		goto node4730;
	} else {
		input[2] &= ~(1 << 2);
		return 0;
	}
node1144:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node6064;
	} else {
		input[3] &= ~(1 << 5);
		goto node4757;
	}
node8656:
	b = false;
	if (b) {
		input[5] |= (1 << 7);
		return 0;
	} else {
		input[5] &= ~(1 << 7);
		goto node4866;
	}
node7297:
	b = false;
	if (b) {
		input[4] |= (1 << 5);
		return 0;
	} else {
		input[4] &= ~(1 << 5);
		goto node8270;
	}
node8483:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node2257;
	} else {
		input[2] &= ~(1 << 4);
		goto node7887;
	}
node1986:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		goto node3319;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node5434:
	b = true;
	if (b) {
		input[3] |= (1 << 7);
		goto node507;
	} else {
		input[3] &= ~(1 << 7);
		return 0;
	}
node5009:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node8100;
	} else {
		input[3] &= ~(1 << 6);
		goto node6731;
	}
node9307:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node5072;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node58:
	b = true;
	if (b) {
		input[4] |= (1 << 7);
		goto node1042;
	} else {
		input[4] &= ~(1 << 7);
		return 0;
	}
node6353:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node7493;
	} else {
		input[2] &= ~(1 << 4);
		goto node4751;
	}
node5876:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node5295;
	} else {
		input[2] &= ~(1 << 3);
		goto node7470;
	}
node8505:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node3966;
	} else {
		input[3] &= ~(1 << 7);
		goto node7847;
	}
node5685:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node1257;
	} else {
		input[3] &= ~(1 << 3);
		goto node5100;
	}
node6113:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node3631;
	} else {
		input[3] &= ~(1 << 2);
		goto node7551;
	}
node8395:
	b = false;
	if (b) {
		input[4] |= (1 << 7);
		return 0;
	} else {
		input[4] &= ~(1 << 7);
		goto node4341;
	}
node8866:
	b = randbool();
	if (b) {
		input[1] |= (1 << 3);
		goto node6592;
	} else {
		input[1] &= ~(1 << 3);
		goto node3659;
	}
node9401:
	b = randbool();
	if (b) {
		input[2] |= (1 << 7);
		goto node2985;
	} else {
		input[2] &= ~(1 << 7);
		goto node4796;
	}
node3996:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node322;
	} else {
		input[2] &= ~(1 << 4);
		goto node6862;
	}
node7245:
	b = true;
	if (b) {
		input[3] |= (1 << 7);
		goto node1894;
	} else {
		input[3] &= ~(1 << 7);
		return 0;
	}
node4553:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node4723;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node5367:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node4978;
	}
node6370:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node1358;
	} else {
		input[2] &= ~(1 << 5);
		return 3;
	}
node8353:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node5087;
	} else {
		input[2] &= ~(1 << 4);
		goto node3862;
	}
node7565:
	b = false;
	if (b) {
		input[1] |= (1 << 6);
		return 0;
	} else {
		input[1] &= ~(1 << 6);
		goto node1214;
	}
node5210:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node4711;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node2551:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node1445;
	} else {
		input[3] &= ~(1 << 2);
		goto node5422;
	}
node7559:
	b = true;
	if (b) {
		input[4] |= (1 << 1);
		goto node5417;
	} else {
		input[4] &= ~(1 << 1);
		return 0;
	}
node8338:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node9139;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node6159:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node6324;
	} else {
		input[3] &= ~(1 << 7);
		goto node3669;
	}
node692:
	b = false;
	if (b) {
		input[3] |= (1 << 6);
		return 0;
	} else {
		input[3] &= ~(1 << 6);
		goto node2633;
	}
node903:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node3456;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node2524:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node3156;
	}
node6235:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node8476;
	} else {
		input[3] &= ~(1 << 2);
		goto node1896;
	}
node2165:
	b = false;
	if (b) {
		input[1] |= (1 << 0);
		return 0;
	} else {
		input[1] &= ~(1 << 0);
		goto node614;
	}
node5025:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node4747;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node5607:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node6435;
	} else {
		input[3] &= ~(1 << 6);
		goto node883;
	}
node1016:
	b = randbool();
	if (b) {
		input[1] |= (1 << 4);
		goto node6473;
	} else {
		input[1] &= ~(1 << 4);
		goto node7486;
	}
node6337:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node8448;
	} else {
		input[2] &= ~(1 << 5);
		goto node5940;
	}
node5520:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node9354;
	}
node8710:
	b = false;
	if (b) {
		input[2] |= (1 << 6);
		return 0;
	} else {
		input[2] &= ~(1 << 6);
		goto node3575;
	}
node8859:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node4086;
	} else {
		input[2] &= ~(1 << 5);
		goto node659;
	}
node8831:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node4397;
	} else {
		input[2] &= ~(1 << 2);
		goto node488;
	}
node8307:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		goto node117;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node631:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node6045;
	} else {
		input[3] &= ~(1 << 7);
		goto node4478;
	}
node1502:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node1614;
	} else {
		input[3] &= ~(1 << 4);
		goto node137;
	}
node2239:
	b = false;
	if (b) {
		input[1] |= (1 << 2);
		return 0;
	} else {
		input[1] &= ~(1 << 2);
		goto node1907;
	}
node5476:
	b = false;
	if (b) {
		input[2] |= (1 << 2);
		return 0;
	} else {
		input[2] &= ~(1 << 2);
		goto node8415;
	}
node4253:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		goto node6053;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node4448:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		goto node1900;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node1322:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		goto node5290;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node671:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node8166;
	} else {
		input[2] &= ~(1 << 5);
		goto node6323;
	}
node8306:
	b = true;
	if (b) {
		input[2] |= (1 << 2);
		goto node4771;
	} else {
		input[2] &= ~(1 << 2);
		return 0;
	}
node5777:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node3088;
	} else {
		input[3] &= ~(1 << 2);
		goto node137;
	}
node4879:
	b = false;
	if (b) {
		input[3] |= (1 << 2);
		return 0;
	} else {
		input[3] &= ~(1 << 2);
		goto node161;
	}
node6834:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node3477;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node9355:
	b = false;
	if (b) {
		input[3] |= (1 << 1);
		return 0;
	} else {
		input[3] &= ~(1 << 1);
		goto node6194;
	}
node4987:
	b = true;
	if (b) {
		input[4] |= (1 << 0);
		goto node7576;
	} else {
		input[4] &= ~(1 << 0);
		return 0;
	}
node8922:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node8170;
	}
node9295:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node692;
	} else {
		input[3] &= ~(1 << 7);
		goto node4651;
	}
node4717:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node7675;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node9364:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node8873;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node8070:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node1445;
	} else {
		input[3] &= ~(1 << 2);
		goto node8279;
	}
node5484:
	b = true;
	if (b) {
		input[4] |= (1 << 7);
		goto node1871;
	} else {
		input[4] &= ~(1 << 7);
		return 0;
	}
node7368:
	b = false;
	if (b) {
		input[2] |= (1 << 7);
		return 0;
	} else {
		input[2] &= ~(1 << 7);
		goto node3180;
	}
node9201:
	b = randbool();
	if (b) {
		input[1] |= (1 << 1);
		goto node3633;
	} else {
		input[1] &= ~(1 << 1);
		goto node8318;
	}
node6182:
	b = false;
	if (b) {
		input[2] |= (1 << 1);
		return 0;
	} else {
		input[2] &= ~(1 << 1);
		goto node8576;
	}
node8703:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node3420;
	} else {
		input[3] &= ~(1 << 7);
		goto node1239;
	}
node5681:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node644;
	}
node2153:
	b = true;
	if (b) {
		input[4] |= (1 << 2);
		goto node4174;
	} else {
		input[4] &= ~(1 << 2);
		return 0;
	}
node6872:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node7740;
	} else {
		input[3] &= ~(1 << 5);
		goto node9186;
	}
node3494:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node7420;
	}
node657:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node4105;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node80:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node8940;
	} else {
		input[3] &= ~(1 << 2);
		goto node9475;
	}
node8621:
	b = randbool();
	if (b) {
		input[4] |= (1 << 7);
		goto node1346;
	} else {
		input[4] &= ~(1 << 7);
		goto node6693;
	}
node1250:
	b = randbool();
	if (b) {
		input[1] |= (1 << 5);
		goto node4594;
	} else {
		input[1] &= ~(1 << 5);
		goto node6531;
	}
node5753:
	b = true;
	if (b) {
		input[1] |= (1 << 2);
		return 2;
	} else {
		input[1] &= ~(1 << 2);
		return 0;
	}
node2039:
	b = false;
	if (b) {
		input[1] |= (1 << 2);
		return 0;
	} else {
		input[1] &= ~(1 << 2);
		goto node6262;
	}
node1041:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node7412;
	} else {
		input[3] &= ~(1 << 5);
		goto node289;
	}
node4648:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		return 4;
	} else {
		input[3] &= ~(1 << 3);
		goto node6866;
	}
node3745:
	b = false;
	if (b) {
		input[3] |= (1 << 2);
		return 0;
	} else {
		input[3] &= ~(1 << 2);
		goto node1002;
	}
node40:
	b = randbool();
	if (b) {
		input[1] |= (1 << 4);
		goto node7039;
	} else {
		input[1] &= ~(1 << 4);
		goto node8118;
	}
node9011:
	b = false;
	if (b) {
		input[4] |= (1 << 7);
		return 0;
	} else {
		input[4] &= ~(1 << 7);
		goto node426;
	}
node2127:
	b = true;
	if (b) {
		input[4] |= (1 << 3);
		goto node1611;
	} else {
		input[4] &= ~(1 << 3);
		return 0;
	}
node221:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node1226;
	}
node405:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node1722;
	} else {
		input[2] &= ~(1 << 4);
		goto node5671;
	}
node6522:
	b = false;
	if (b) {
		input[2] |= (1 << 1);
		return 0;
	} else {
		input[2] &= ~(1 << 1);
		goto node5887;
	}
node3344:
	b = false;
	if (b) {
		input[3] |= (1 << 6);
		return 0;
	} else {
		input[3] &= ~(1 << 6);
		goto node6503;
	}
node4356:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node574;
	} else {
		input[3] &= ~(1 << 4);
		goto node1382;
	}
node1367:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node3520;
	} else {
		input[3] &= ~(1 << 2);
		goto node1126;
	}
node7149:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node5809;
	} else {
		input[2] &= ~(1 << 4);
		goto node4719;
	}
node5596:
	b = true;
	if (b) {
		input[2] |= (1 << 2);
		goto node9330;
	} else {
		input[2] &= ~(1 << 2);
		return 0;
	}
node104:
	b = randbool();
	if (b) {
		input[2] |= (1 << 0);
		goto node5035;
	} else {
		input[2] &= ~(1 << 0);
		goto node9459;
	}
node1575:
	b = randbool();
	if (b) {
		input[0] |= (1 << 3);
		return 5;
	} else {
		input[0] &= ~(1 << 3);
		return 2;
	}
node6848:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node9413;
	} else {
		input[2] &= ~(1 << 3);
		goto node6052;
	}
node7319:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node8666;
	} else {
		input[3] &= ~(1 << 6);
		goto node2588;
	}
node5109:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node1914;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node7252:
	b = true;
	if (b) {
		input[3] |= (1 << 1);
		goto node7525;
	} else {
		input[3] &= ~(1 << 1);
		return 0;
	}
node9050:
	b = false;
	if (b) {
		input[4] |= (1 << 3);
		return 0;
	} else {
		input[4] &= ~(1 << 3);
		goto node9078;
	}
node2254:
	b = true;
	if (b) {
		input[1] |= (1 << 1);
		goto node6561;
	} else {
		input[1] &= ~(1 << 1);
		return 0;
	}
node7457:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node5980;
	} else {
		input[2] &= ~(1 << 6);
		goto node6049;
	}
node9367:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node2568;
	} else {
		input[2] &= ~(1 << 4);
		goto node7521;
	}
node6740:
	b = true;
	if (b) {
		input[3] |= (1 << 2);
		goto node9355;
	} else {
		input[3] &= ~(1 << 2);
		return 0;
	}
node9017:
	b = true;
	if (b) {
		input[3] |= (1 << 0);
		goto node4267;
	} else {
		input[3] &= ~(1 << 0);
		return 0;
	}
node3168:
	b = false;
	if (b) {
		input[4] |= (1 << 0);
		return 0;
	} else {
		input[4] &= ~(1 << 0);
		goto node2463;
	}
node5820:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node5040;
	} else {
		input[2] &= ~(1 << 6);
		goto node9150;
	}
node5219:
	b = false;
	if (b) {
		input[2] |= (1 << 1);
		return 0;
	} else {
		input[2] &= ~(1 << 1);
		goto node2166;
	}
node6324:
	b = true;
	if (b) {
		input[3] |= (1 << 6);
		goto node908;
	} else {
		input[3] &= ~(1 << 6);
		return 0;
	}
node4298:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node1612;
	} else {
		input[3] &= ~(1 << 6);
		goto node995;
	}
node5729:
	b = randbool();
	if (b) {
		input[4] |= (1 << 2);
		goto node6322;
	} else {
		input[4] &= ~(1 << 2);
		return 6;
	}
node4983:
	b = true;
	if (b) {
		input[1] |= (1 << 1);
		goto node1286;
	} else {
		input[1] &= ~(1 << 1);
		return 0;
	}
node7549:
	b = false;
	if (b) {
		input[3] |= (1 << 7);
		return 0;
	} else {
		input[3] &= ~(1 << 7);
		goto node1324;
	}
node3222:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node3655;
	} else {
		input[3] &= ~(1 << 6);
		goto node8373;
	}
node3257:
	b = true;
	if (b) {
		input[4] |= (1 << 3);
		goto node6659;
	} else {
		input[4] &= ~(1 << 3);
		return 0;
	}
node836:
	b = false;
	if (b) {
		input[1] |= (1 << 4);
		return 0;
	} else {
		input[1] &= ~(1 << 4);
		return 2;
	}
node1303:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node7735;
	}
node2044:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		goto node9384;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node5322:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node9254;
	} else {
		input[3] &= ~(1 << 4);
		goto node6525;
	}
node5966:
	b = true;
	if (b) {
		input[4] |= (1 << 4);
		goto node9078;
	} else {
		input[4] &= ~(1 << 4);
		return 0;
	}
node7847:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node7367;
	} else {
		input[3] &= ~(1 << 6);
		goto node6010;
	}
node7331:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node578;
	} else {
		input[3] &= ~(1 << 5);
		goto node7412;
	}
node7392:
	b = randbool();
	if (b) {
		input[4] |= (1 << 2);
		goto node714;
	} else {
		input[4] &= ~(1 << 2);
		return 7;
	}
node8901:
	b = randbool();
	if (b) {
		input[2] |= (1 << 7);
		goto node655;
	} else {
		input[2] &= ~(1 << 7);
		goto node6195;
	}
node3956:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node2445;
	} else {
		input[2] &= ~(1 << 6);
		goto node8290;
	}
node3270:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node6387;
	} else {
		input[2] &= ~(1 << 6);
		goto node8945;
	}
node8089:
	b = false;
	if (b) {
		input[2] |= (1 << 5);
		return 0;
	} else {
		input[2] &= ~(1 << 5);
		goto node4414;
	}
node2599:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node5047;
	}
node5927:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node3478;
	}
node1012:
	b = true;
	if (b) {
		input[4] |= (1 << 5);
		goto node1648;
	} else {
		input[4] &= ~(1 << 5);
		return 0;
	}
node6418:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node3425;
	} else {
		input[2] &= ~(1 << 2);
		goto node7299;
	}
node3392:
	b = false;
	if (b) {
		input[2] |= (1 << 0);
		return 0;
	} else {
		input[2] &= ~(1 << 0);
		goto node3046;
	}
node2908:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node1759;
	}
node1859:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node3235;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node4741:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node3497;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node319:
	b = true;
	if (b) {
		input[3] |= (1 << 2);
		goto node7007;
	} else {
		input[3] &= ~(1 << 2);
		return 0;
	}
node7626:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node8552;
	}
node7639:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node1632;
	} else {
		input[3] &= ~(1 << 4);
		goto node8122;
	}
node8164:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node4529;
	} else {
		input[3] &= ~(1 << 4);
		goto node5989;
	}
node2134:
	b = true;
	if (b) {
		input[3] |= (1 << 1);
		goto node1481;
	} else {
		input[3] &= ~(1 << 1);
		return 0;
	}
node108:
	b = false;
	if (b) {
		input[3] |= (1 << 0);
		return 0;
	} else {
		input[3] &= ~(1 << 0);
		goto node2841;
	}
node8374:
	b = randbool();
	if (b) {
		input[4] |= (1 << 4);
		goto node2998;
	} else {
		input[4] &= ~(1 << 4);
		goto node5377;
	}
node1349:
	b = randbool();
	if (b) {
		input[0] |= (1 << 1);
		goto node2402;
	} else {
		input[0] &= ~(1 << 1);
		goto node5683;
	}
node6839:
	b = false;
	if (b) {
		input[3] |= (1 << 2);
		return 0;
	} else {
		input[3] &= ~(1 << 2);
		goto node2997;
	}
node3865:
	b = false;
	if (b) {
		input[4] |= (1 << 4);
		return 0;
	} else {
		input[4] &= ~(1 << 4);
		goto node4237;
	}
node5426:
	b = false;
	if (b) {
		input[1] |= (1 << 4);
		return 0;
	} else {
		input[1] &= ~(1 << 4);
		goto node7800;
	}
node5183:
	b = false;
	if (b) {
		input[2] |= (1 << 1);
		return 0;
	} else {
		input[2] &= ~(1 << 1);
		goto node1040;
	}
node6529:
	b = true;
	if (b) {
		input[3] |= (1 << 2);
		goto node9475;
	} else {
		input[3] &= ~(1 << 2);
		return 0;
	}
node2997:
	b = randbool();
	if (b) {
		input[3] |= (1 << 1);
		goto node7112;
	} else {
		input[3] &= ~(1 << 1);
		goto node2584;
	}
node6650:
	b = false;
	if (b) {
		input[4] |= (1 << 3);
		return 0;
	} else {
		input[4] &= ~(1 << 3);
		goto node4599;
	}
node4667:
	b = true;
	if (b) {
		input[2] |= (1 << 4);
		goto node4969;
	} else {
		input[2] &= ~(1 << 4);
		return 0;
	}
node2886:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node7161;
	} else {
		input[3] &= ~(1 << 5);
		goto node7141;
	}
node3386:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node594;
	} else {
		input[3] &= ~(1 << 5);
		goto node7766;
	}
node7648:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node2821;
	} else {
		input[3] &= ~(1 << 2);
		goto node6462;
	}
node7649:
	b = randbool();
	if (b) {
		input[1] |= (1 << 4);
		goto node1650;
	} else {
		input[1] &= ~(1 << 4);
		goto node3094;
	}
node7754:
	b = randbool();
	if (b) {
		input[1] |= (1 << 2);
		goto node2843;
	} else {
		input[1] &= ~(1 << 2);
		goto node5479;
	}
node5263:
	b = true;
	if (b) {
		input[4] |= (1 << 3);
		goto node5677;
	} else {
		input[4] &= ~(1 << 3);
		return 0;
	}
node1356:
	b = false;
	if (b) {
		input[5] |= (1 << 3);
		return 0;
	} else {
		input[5] &= ~(1 << 3);
		goto node5938;
	}
node4637:
	b = randbool();
	if (b) {
		input[6] |= (1 << 3);
		goto node629;
	} else {
		input[6] &= ~(1 << 3);
		goto node6260;
	}
node2249:
	b = randbool();
	if (b) {
		input[5] |= (1 << 4);
		goto node4199;
	} else {
		input[5] &= ~(1 << 4);
		goto node9119;
	}
node4513:
	b = false;
	if (b) {
		input[2] |= (1 << 7);
		return 0;
	} else {
		input[2] &= ~(1 << 7);
		goto node1238;
	}
node7258:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node4429;
	} else {
		input[3] &= ~(1 << 5);
		goto node9106;
	}
node4162:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node4516;
	}
node4557:
	b = true;
	if (b) {
		input[3] |= (1 << 2);
		goto node1543;
	} else {
		input[3] &= ~(1 << 2);
		return 0;
	}
node9049:
	b = randbool();
	if (b) {
		input[3] |= (1 << 1);
		goto node3481;
	} else {
		input[3] &= ~(1 << 1);
		goto node3520;
	}
node4630:
	b = false;
	if (b) {
		input[4] |= (1 << 4);
		return 0;
	} else {
		input[4] &= ~(1 << 4);
		goto node4670;
	}
node9024:
	b = false;
	if (b) {
		input[1] |= (1 << 5);
		return 0;
	} else {
		input[1] &= ~(1 << 5);
		goto node7650;
	}
node6073:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node2187;
	} else {
		input[2] &= ~(1 << 2);
		goto node1605;
	}
node7422:
	b = true;
	if (b) {
		input[4] |= (1 << 0);
		goto node439;
	} else {
		input[4] &= ~(1 << 0);
		return 0;
	}
node6763:
	b = true;
	if (b) {
		input[1] |= (1 << 0);
		goto node670;
	} else {
		input[1] &= ~(1 << 0);
		return 0;
	}
node343:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		goto node1602;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node6619:
	b = true;
	if (b) {
		input[1] |= (1 << 6);
		goto node8724;
	} else {
		input[1] &= ~(1 << 6);
		return 0;
	}
node1328:
	b = false;
	if (b) {
		input[2] |= (1 << 5);
		return 0;
	} else {
		input[2] &= ~(1 << 5);
		goto node8447;
	}
node8068:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node3278;
	}
node9108:
	b = false;
	if (b) {
		input[3] |= (1 << 1);
		return 0;
	} else {
		input[3] &= ~(1 << 1);
		goto node8380;
	}
node3345:
	b = true;
	if (b) {
		input[3] |= (1 << 0);
		goto node6220;
	} else {
		input[3] &= ~(1 << 0);
		return 0;
	}
node6191:
	b = randbool();
	if (b) {
		input[1] |= (1 << 4);
		goto node3251;
	} else {
		input[1] &= ~(1 << 4);
		goto node6186;
	}
node3707:
	b = randbool();
	if (b) {
		input[1] |= (1 << 2);
		goto node7733;
	} else {
		input[1] &= ~(1 << 2);
		goto node6728;
	}
node2986:
	b = false;
	if (b) {
		input[2] |= (1 << 5);
		return 0;
	} else {
		input[2] &= ~(1 << 5);
		goto node449;
	}
node5731:
	b = true;
	if (b) {
		input[2] |= (1 << 5);
		goto node4695;
	} else {
		input[2] &= ~(1 << 5);
		return 0;
	}
node6042:
	b = false;
	if (b) {
		input[2] |= (1 << 3);
		return 0;
	} else {
		input[2] &= ~(1 << 3);
		goto node1456;
	}
node2371:
	b = true;
	if (b) {
		input[2] |= (1 << 2);
		goto node2994;
	} else {
		input[2] &= ~(1 << 2);
		return 0;
	}
node9225:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node547;
	} else {
		input[3] &= ~(1 << 6);
		goto node21;
	}
node1688:
	b = false;
	if (b) {
		input[3] |= (1 << 2);
		return 0;
	} else {
		input[3] &= ~(1 << 2);
		goto node4735;
	}
node1936:
	b = false;
	if (b) {
		input[1] |= (1 << 6);
		return 0;
	} else {
		input[1] &= ~(1 << 6);
		goto node1498;
	}
node3905:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node1156;
	} else {
		input[2] &= ~(1 << 6);
		goto node1854;
	}
node8716:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node2882;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node3939:
	b = randbool();
	if (b) {
		input[2] |= (1 << 0);
		goto node1583;
	} else {
		input[2] &= ~(1 << 0);
		goto node9171;
	}
node8234:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node1771;
	} else {
		input[3] &= ~(1 << 7);
		goto node1179;
	}
node3772:
	b = true;
	if (b) {
		input[1] |= (1 << 3);
		goto node8084;
	} else {
		input[1] &= ~(1 << 3);
		return 0;
	}
node46:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node645;
	} else {
		input[3] &= ~(1 << 4);
		goto node6948;
	}
node9137:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node2158;
	} else {
		input[3] &= ~(1 << 2);
		goto node9355;
	}
node6066:
	b = false;
	if (b) {
		input[3] |= (1 << 2);
		return 0;
	} else {
		input[3] &= ~(1 << 2);
		goto node959;
	}
node9462:
	b = randbool();
	if (b) {
		input[0] |= (1 << 2);
		goto node4368;
	} else {
		input[0] &= ~(1 << 2);
		goto node6389;
	}
node5796:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node5551;
	} else {
		input[2] &= ~(1 << 6);
		goto node2223;
	}
node8690:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node1959;
	} else {
		input[2] &= ~(1 << 6);
		goto node5731;
	}
node1576:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node1226;
	} else {
		input[2] &= ~(1 << 4);
		goto node3248;
	}
node284:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node6457;
	}
node5250:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node9158;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node4142:
	b = randbool();
	if (b) {
		input[1] |= (1 << 2);
		goto node180;
	} else {
		input[1] &= ~(1 << 2);
		return 2;
	}
node7247:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node3898;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node5393:
	b = randbool();
	if (b) {
		input[4] |= (1 << 6);
		goto node9187;
	} else {
		input[4] &= ~(1 << 6);
		goto node7983;
	}
node3073:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node9156;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node381:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node2061;
	} else {
		input[3] &= ~(1 << 5);
		goto node1859;
	}
node1299:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node2158;
	} else {
		input[3] &= ~(1 << 3);
		goto node4878;
	}
node1130:
	b = true;
	if (b) {
		input[3] |= (1 << 0);
		return 7;
	} else {
		input[3] &= ~(1 << 0);
		return 0;
	}
node9098:
	b = false;
	if (b) {
		input[2] |= (1 << 5);
		return 0;
	} else {
		input[2] &= ~(1 << 5);
		goto node4832;
	}
node642:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node6227;
	} else {
		input[3] &= ~(1 << 6);
		goto node8761;
	}
node89:
	b = true;
	if (b) {
		input[6] |= (1 << 0);
		return 9;
	} else {
		input[6] &= ~(1 << 0);
		return 0;
	}
node3619:
	b = randbool();
	if (b) {
		input[1] |= (1 << 7);
		goto node257;
	} else {
		input[1] &= ~(1 << 7);
		goto node2065;
	}
node8811:
	b = true;
	if (b) {
		input[1] |= (1 << 2);
		goto node4083;
	} else {
		input[1] &= ~(1 << 2);
		return 0;
	}
node9324:
	b = true;
	if (b) {
		input[2] |= (1 << 6);
		goto node6147;
	} else {
		input[2] &= ~(1 << 6);
		return 0;
	}
node962:
	b = true;
	if (b) {
		input[2] |= (1 << 3);
		goto node3445;
	} else {
		input[2] &= ~(1 << 3);
		return 0;
	}
node5614:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node7495;
	} else {
		input[3] &= ~(1 << 7);
		goto node4651;
	}
node1697:
	b = true;
	if (b) {
		input[3] |= (1 << 0);
		goto node9293;
	} else {
		input[3] &= ~(1 << 0);
		return 0;
	}
node821:
	b = true;
	if (b) {
		input[1] |= (1 << 4);
		goto node1419;
	} else {
		input[1] &= ~(1 << 4);
		return 0;
	}
node5093:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node8937;
	} else {
		input[2] &= ~(1 << 5);
		goto node976;
	}
node8995:
	b = true;
	if (b) {
		input[2] |= (1 << 3);
		goto node2987;
	} else {
		input[2] &= ~(1 << 3);
		return 0;
	}
node3423:
	b = randbool();
	if (b) {
		input[6] |= (1 << 1);
		return 8;
	} else {
		input[6] &= ~(1 << 1);
		goto node768;
	}
node9391:
	b = true;
	if (b) {
		input[1] |= (1 << 0);
		goto node4080;
	} else {
		input[1] &= ~(1 << 0);
		return 0;
	}
node2888:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node7990;
	} else {
		input[2] &= ~(1 << 6);
		goto node8803;
	}
node4065:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node7603;
	} else {
		input[2] &= ~(1 << 4);
		goto node553;
	}
node1478:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node7851;
	}
node8415:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		goto node7103;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node5264:
	b = true;
	if (b) {
		input[6] |= (1 << 2);
		goto node1664;
	} else {
		input[6] &= ~(1 << 2);
		return 0;
	}
node716:
	b = true;
	if (b) {
		input[1] |= (1 << 0);
		goto node2511;
	} else {
		input[1] &= ~(1 << 0);
		return 0;
	}
node4485:
	b = randbool();
	if (b) {
		input[2] |= (1 << 7);
		goto node6256;
	} else {
		input[2] &= ~(1 << 7);
		goto node1107;
	}
node8024:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node9243;
	} else {
		input[2] &= ~(1 << 2);
		return 7;
	}
node4890:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node8008;
	} else {
		input[2] &= ~(1 << 3);
		goto node1108;
	}
node7216:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node1334;
	}
node8417:
	b = false;
	if (b) {
		input[3] |= (1 << 2);
		return 0;
	} else {
		input[3] &= ~(1 << 2);
		goto node1362;
	}
node4323:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node9407;
	}
node8662:
	b = randbool();
	if (b) {
		input[1] |= (1 << 5);
		goto node7566;
	} else {
		input[1] &= ~(1 << 5);
		goto node4955;
	}
node4559:
	b = randbool();
	if (b) {
		input[1] |= (1 << 3);
		goto node8217;
	} else {
		input[1] &= ~(1 << 3);
		goto node7188;
	}
node7544:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node6483;
	} else {
		input[3] &= ~(1 << 6);
		goto node1173;
	}
node5680:
	b = true;
	if (b) {
		input[3] |= (1 << 6);
		goto node5303;
	} else {
		input[3] &= ~(1 << 6);
		return 0;
	}
node7914:
	b = randbool();
	if (b) {
		input[4] |= (1 << 3);
		goto node2939;
	} else {
		input[4] &= ~(1 << 3);
		goto node439;
	}
node6688:
	b = randbool();
	if (b) {
		input[1] |= (1 << 3);
		goto node6168;
	} else {
		input[1] &= ~(1 << 3);
		goto node5753;
	}
node6602:
	b = randbool();
	if (b) {
		input[4] |= (1 << 2);
		goto node6741;
	} else {
		input[4] &= ~(1 << 2);
		goto node7804;
	}
node1150:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node9130;
	} else {
		input[2] &= ~(1 << 4);
		goto node8503;
	}
node9233:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node5406;
	}
node4031:
	b = false;
	if (b) {
		input[4] |= (1 << 5);
		return 0;
	} else {
		input[4] &= ~(1 << 5);
		goto node5516;
	}
node70:
	b = randbool();
	if (b) {
		input[4] |= (1 << 4);
		goto node3295;
	} else {
		input[4] &= ~(1 << 4);
		goto node9187;
	}
node4867:
	b = true;
	if (b) {
		input[5] |= (1 << 4);
		goto node442;
	} else {
		input[5] &= ~(1 << 4);
		return 0;
	}
node5171:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node1643;
	} else {
		input[2] &= ~(1 << 5);
		goto node8226;
	}
node8665:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node9112;
	} else {
		input[3] &= ~(1 << 6);
		goto node78;
	}
node1459:
	b = true;
	if (b) {
		input[3] |= (1 << 2);
		goto node1281;
	} else {
		input[3] &= ~(1 << 2);
		return 0;
	}
node3138:
	b = true;
	if (b) {
		input[4] |= (1 << 6);
		goto node4337;
	} else {
		input[4] &= ~(1 << 6);
		return 0;
	}
node82:
	b = randbool();
	if (b) {
		input[0] |= (1 << 0);
		goto node6312;
	} else {
		input[0] &= ~(1 << 0);
		goto node2184;
	}
node5415:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node4399;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node8142:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node7259;
	} else {
		input[3] &= ~(1 << 4);
		goto node1229;
	}
node8123:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node3886;
	} else {
		input[3] &= ~(1 << 3);
		goto node2801;
	}
node8688:
	b = randbool();
	if (b) {
		input[1] |= (1 << 3);
		goto node6666;
	} else {
		input[1] &= ~(1 << 3);
		goto node3436;
	}
node3067:
	b = false;
	if (b) {
		input[2] |= (1 << 7);
		return 0;
	} else {
		input[2] &= ~(1 << 7);
		goto node5813;
	}
node9059:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node6144;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node8516:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node1445;
	} else {
		input[3] &= ~(1 << 2);
		goto node137;
	}
node2705:
	b = false;
	if (b) {
		input[1] |= (1 << 5);
		return 0;
	} else {
		input[1] &= ~(1 << 5);
		goto node4686;
	}
node4446:
	b = false;
	if (b) {
		input[1] |= (1 << 4);
		return 0;
	} else {
		input[1] &= ~(1 << 4);
		goto node800;
	}
node6199:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		goto node3799;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node2818:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node4203;
	}
node8295:
	b = randbool();
	if (b) {
		input[4] |= (1 << 5);
		goto node1690;
	} else {
		input[4] &= ~(1 << 5);
		goto node2925;
	}
node8669:
	b = false;
	if (b) {
		input[1] |= (1 << 4);
		return 0;
	} else {
		input[1] &= ~(1 << 4);
		goto node8642;
	}
node3205:
	b = randbool();
	if (b) {
		input[1] |= (1 << 4);
		goto node3436;
	} else {
		input[1] &= ~(1 << 4);
		goto node8688;
	}
node7584:
	b = false;
	if (b) {
		input[2] |= (1 << 7);
		return 0;
	} else {
		input[2] &= ~(1 << 7);
		goto node7476;
	}
node48:
	b = randbool();
	if (b) {
		input[4] |= (1 << 3);
		goto node7711;
	} else {
		input[4] &= ~(1 << 3);
		goto node5370;
	}
node676:
	b = false;
	if (b) {
		input[1] |= (1 << 1);
		return 0;
	} else {
		input[1] &= ~(1 << 1);
		goto node7850;
	}
node1405:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node7032;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node3273:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node369;
	}
node848:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node7581;
	}
node8510:
	b = randbool();
	if (b) {
		input[1] |= (1 << 6);
		goto node2423;
	} else {
		input[1] &= ~(1 << 6);
		goto node1569;
	}
node453:
	b = false;
	if (b) {
		input[1] |= (1 << 2);
		return 0;
	} else {
		input[1] &= ~(1 << 2);
		goto node965;
	}
node9202:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node4438;
	} else {
		input[2] &= ~(1 << 6);
		goto node8727;
	}
node5825:
	b = true;
	if (b) {
		input[3] |= (1 << 7);
		goto node2699;
	} else {
		input[3] &= ~(1 << 7);
		return 0;
	}
node5888:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node6462;
	} else {
		input[3] &= ~(1 << 3);
		goto node7648;
	}
node8931:
	b = false;
	if (b) {
		input[2] |= (1 << 3);
		return 0;
	} else {
		input[2] &= ~(1 << 3);
		goto node2838;
	}
node8430:
	b = false;
	if (b) {
		input[3] |= (1 << 7);
		return 0;
	} else {
		input[3] &= ~(1 << 7);
		goto node5692;
	}
node15:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node8972;
	} else {
		input[3] &= ~(1 << 4);
		goto node8950;
	}
node5779:
	b = true;
	if (b) {
		input[3] |= (1 << 1);
		goto node3033;
	} else {
		input[3] &= ~(1 << 1);
		return 0;
	}
node1397:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node2292;
	} else {
		input[3] &= ~(1 << 4);
		goto node4598;
	}
node7477:
	b = false;
	if (b) {
		input[4] |= (1 << 3);
		return 0;
	} else {
		input[4] &= ~(1 << 3);
		return 6;
	}
node5351:
	b = false;
	if (b) {
		input[2] |= (1 << 6);
		return 0;
	} else {
		input[2] &= ~(1 << 6);
		goto node304;
	}
node7990:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node8726;
	} else {
		input[2] &= ~(1 << 5);
		goto node7285;
	}
node7493:
	b = false;
	if (b) {
		input[2] |= (1 << 3);
		return 0;
	} else {
		input[2] &= ~(1 << 3);
		goto node4751;
	}
node2166:
	b = false;
	if (b) {
		input[2] |= (1 << 0);
		return 0;
	} else {
		input[2] &= ~(1 << 0);
		goto node8871;
	}
node6870:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node6098;
	} else {
		input[3] &= ~(1 << 7);
		goto node9225;
	}
node4566:
	b = false;
	if (b) {
		input[3] |= (1 << 7);
		return 0;
	} else {
		input[3] &= ~(1 << 7);
		goto node3953;
	}
node6639:
	b = false;
	if (b) {
		input[4] |= (1 << 2);
		return 0;
	} else {
		input[4] &= ~(1 << 2);
		goto node4464;
	}
node7773:
	b = randbool();
	if (b) {
		input[0] |= (1 << 1);
		goto node630;
	} else {
		input[0] &= ~(1 << 1);
		goto node7681;
	}
node2380:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node2676;
	} else {
		input[2] &= ~(1 << 3);
		goto node7450;
	}
node5713:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node104;
	} else {
		input[2] &= ~(1 << 1);
		goto node6712;
	}
node5283:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node6343;
	} else {
		input[3] &= ~(1 << 4);
		goto node7632;
	}
node2221:
	b = randbool();
	if (b) {
		input[3] |= (1 << 0);
		goto node3520;
	} else {
		input[3] &= ~(1 << 0);
		goto node6220;
	}
node1812:
	b = true;
	if (b) {
		input[1] |= (1 << 5);
		goto node6641;
	} else {
		input[1] &= ~(1 << 5);
		return 0;
	}
node6226:
	b = false;
	if (b) {
		input[3] |= (1 << 7);
		return 0;
	} else {
		input[3] &= ~(1 << 7);
		goto node9105;
	}
node6916:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node7412;
	} else {
		input[3] &= ~(1 << 4);
		goto node4255;
	}
node7157:
	b = true;
	if (b) {
		input[5] |= (1 << 5);
		goto node6156;
	} else {
		input[5] &= ~(1 << 5);
		return 0;
	}
node5734:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node4709;
	} else {
		input[2] &= ~(1 << 2);
		goto node939;
	}
node7495:
	b = false;
	if (b) {
		input[3] |= (1 << 6);
		return 0;
	} else {
		input[3] &= ~(1 << 6);
		goto node6381;
	}
node5556:
	b = false;
	if (b) {
		input[3] |= (1 << 6);
		return 0;
	} else {
		input[3] &= ~(1 << 6);
		goto node950;
	}
node3815:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node9397;
	}
node1481:
	b = true;
	if (b) {
		input[3] |= (1 << 0);
		goto node852;
	} else {
		input[3] &= ~(1 << 0);
		return 0;
	}
node2787:
	b = false;
	if (b) {
		input[4] |= (1 << 3);
		return 0;
	} else {
		input[4] &= ~(1 << 3);
		goto node3213;
	}
node4254:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node8843;
	} else {
		input[3] &= ~(1 << 6);
		goto node8679;
	}
node388:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node8646;
	} else {
		input[3] &= ~(1 << 6);
		goto node2520;
	}
node3881:
	b = false;
	if (b) {
		input[3] |= (1 << 0);
		return 0;
	} else {
		input[3] &= ~(1 << 0);
		return 4;
	}
node3401:
	b = randbool();
	if (b) {
		input[4] |= (1 << 6);
		goto node9343;
	} else {
		input[4] &= ~(1 << 6);
		goto node3845;
	}
node6533:
	b = randbool();
	if (b) {
		input[1] |= (1 << 3);
		goto node2325;
	} else {
		input[1] &= ~(1 << 3);
		goto node5070;
	}
node1421:
	b = true;
	if (b) {
		input[3] |= (1 << 7);
		goto node730;
	} else {
		input[3] &= ~(1 << 7);
		return 0;
	}
node5838:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node3132;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node4029:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node137;
	} else {
		input[3] &= ~(1 << 3);
		goto node5777;
	}
node312:
	b = false;
	if (b) {
		input[3] |= (1 << 2);
		return 0;
	} else {
		input[3] &= ~(1 << 2);
		goto node1524;
	}
node7309:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node6220;
	} else {
		input[3] &= ~(1 << 2);
		goto node6541;
	}
node4262:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node53;
	} else {
		input[2] &= ~(1 << 5);
		goto node8660;
	}
node5013:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node7217;
	}
node2025:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node2152;
	}
node7836:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node6297;
	} else {
		input[3] &= ~(1 << 2);
		goto node6682;
	}
node6678:
	b = randbool();
	if (b) {
		input[3] |= (1 << 1);
		return 8;
	} else {
		input[3] &= ~(1 << 1);
		goto node8601;
	}
node8474:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node142;
	} else {
		input[2] &= ~(1 << 3);
		goto node5476;
	}
node6025:
	b = false;
	if (b) {
		input[4] |= (1 << 4);
		return 0;
	} else {
		input[4] &= ~(1 << 4);
		goto node7041;
	}
node936:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node543;
	} else {
		input[2] &= ~(1 << 6);
		goto node1554;
	}
node3284:
	b = false;
	if (b) {
		input[2] |= (1 << 5);
		return 0;
	} else {
		input[2] &= ~(1 << 5);
		goto node208;
	}
node386:
	b = true;
	if (b) {
		input[2] |= (1 << 3);
		goto node4211;
	} else {
		input[2] &= ~(1 << 3);
		return 0;
	}
node1128:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node7545;
	} else {
		input[3] &= ~(1 << 6);
		goto node3188;
	}
node1072:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node3174;
	} else {
		input[3] &= ~(1 << 5);
		goto node474;
	}
node1126:
	b = true;
	if (b) {
		input[3] |= (1 << 1);
		goto node3050;
	} else {
		input[3] &= ~(1 << 1);
		return 0;
	}
node3024:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node769;
	} else {
		input[2] &= ~(1 << 6);
		goto node4321;
	}
node110:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node8187;
	} else {
		input[2] &= ~(1 << 3);
		goto node3114;
	}
node9313:
	b = false;
	if (b) {
		input[4] |= (1 << 2);
		return 0;
	} else {
		input[4] &= ~(1 << 2);
		goto node8555;
	}
node6057:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node7614;
	} else {
		input[3] &= ~(1 << 5);
		goto node3925;
	}
node2589:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node16;
	} else {
		input[3] &= ~(1 << 4);
		goto node6284;
	}
node499:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node8210;
	} else {
		input[2] &= ~(1 << 3);
		goto node4802;
	}
node4729:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node8683;
	} else {
		input[2] &= ~(1 << 2);
		goto node6371;
	}
node617:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node3582;
	} else {
		input[2] &= ~(1 << 2);
		goto node7510;
	}
node9421:
	b = true;
	if (b) {
		input[3] |= (1 << 7);
		goto node6833;
	} else {
		input[3] &= ~(1 << 7);
		return 0;
	}
node4274:
	b = randbool();
	if (b) {
		input[1] |= (1 << 4);
		goto node8677;
	} else {
		input[1] &= ~(1 << 4);
		goto node7013;
	}
node185:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node1597;
	} else {
		input[2] &= ~(1 << 5);
		goto node7180;
	}
node7209:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node6082;
	} else {
		input[3] &= ~(1 << 3);
		goto node3132;
	}
node9008:
	b = true;
	if (b) {
		input[4] |= (1 << 7);
		goto node5019;
	} else {
		input[4] &= ~(1 << 7);
		return 0;
	}
node3267:
	b = false;
	if (b) {
		input[5] |= (1 << 0);
		return 0;
	} else {
		input[5] &= ~(1 << 0);
		goto node6261;
	}
node5952:
	b = randbool();
	if (b) {
		input[1] |= (1 << 1);
		return 3;
	} else {
		input[1] &= ~(1 << 1);
		goto node7704;
	}
node5710:
	b = true;
	if (b) {
		input[2] |= (1 << 5);
		goto node5905;
	} else {
		input[2] &= ~(1 << 5);
		return 0;
	}
node7409:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		return 3;
	} else {
		input[2] &= ~(1 << 3);
		goto node4779;
	}
node3704:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node672;
	} else {
		input[2] &= ~(1 << 2);
		goto node2076;
	}
node2135:
	b = false;
	if (b) {
		input[2] |= (1 << 1);
		return 0;
	} else {
		input[2] &= ~(1 << 1);
		goto node4738;
	}
node1257:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node2236;
	} else {
		input[3] &= ~(1 << 2);
		goto node8007;
	}
node8318:
	b = randbool();
	if (b) {
		input[1] |= (1 << 0);
		goto node6255;
	} else {
		input[1] &= ~(1 << 0);
		goto node4427;
	}
node9418:
	b = false;
	if (b) {
		input[2] |= (1 << 5);
		return 0;
	} else {
		input[2] &= ~(1 << 5);
		goto node6050;
	}
node6871:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node6440;
	} else {
		input[3] &= ~(1 << 6);
		goto node3622;
	}
node2873:
	b = false;
	if (b) {
		input[3] |= (1 << 1);
		return 0;
	} else {
		input[3] &= ~(1 << 1);
		goto node8874;
	}
node8622:
	b = false;
	if (b) {
		input[4] |= (1 << 2);
		return 0;
	} else {
		input[4] &= ~(1 << 2);
		goto node702;
	}
node1625:
	b = false;
	if (b) {
		input[4] |= (1 << 1);
		return 0;
	} else {
		input[4] &= ~(1 << 1);
		goto node4858;
	}
node1391:
	b = true;
	if (b) {
		input[3] |= (1 << 1);
		goto node7600;
	} else {
		input[3] &= ~(1 << 1);
		return 0;
	}
node7714:
	b = true;
	if (b) {
		input[4] |= (1 << 4);
		goto node6236;
	} else {
		input[4] &= ~(1 << 4);
		return 0;
	}
node833:
	b = randbool();
	if (b) {
		input[0] |= (1 << 3);
		goto node4319;
	} else {
		input[0] &= ~(1 << 3);
		goto node9462;
	}
node3633:
	b = randbool();
	if (b) {
		input[1] |= (1 << 0);
		goto node4090;
	} else {
		input[1] &= ~(1 << 0);
		goto node4001;
	}
node6255:
	b = randbool();
	if (b) {
		input[2] |= (1 << 7);
		goto node7755;
	} else {
		input[2] &= ~(1 << 7);
		goto node4520;
	}
node853:
	b = true;
	if (b) {
		input[2] |= (1 << 6);
		goto node8274;
	} else {
		input[2] &= ~(1 << 6);
		return 0;
	}
node993:
	b = true;
	if (b) {
		input[2] |= (1 << 4);
		goto node2890;
	} else {
		input[2] &= ~(1 << 4);
		return 0;
	}
node8376:
	b = true;
	if (b) {
		input[2] |= (1 << 4);
		goto node499;
	} else {
		input[2] &= ~(1 << 4);
		return 0;
	}
node5518:
	b = randbool();
	if (b) {
		input[1] |= (1 << 5);
		goto node1553;
	} else {
		input[1] &= ~(1 << 5);
		goto node7086;
	}
node7988:
	b = randbool();
	if (b) {
		input[2] |= (1 << 7);
		goto node8419;
	} else {
		input[2] &= ~(1 << 7);
		goto node8582;
	}
node4334:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node2830;
	} else {
		input[2] &= ~(1 << 6);
		goto node8272;
	}
node914:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node3740;
	} else {
		input[3] &= ~(1 << 6);
		goto node444;
	}
node8954:
	b = true;
	if (b) {
		input[3] |= (1 << 0);
		goto node3334;
	} else {
		input[3] &= ~(1 << 0);
		return 0;
	}
node3022:
	b = true;
	if (b) {
		input[2] |= (1 << 2);
		goto node6355;
	} else {
		input[2] &= ~(1 << 2);
		return 0;
	}
node8933:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node8106;
	}
node8444:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node1579;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node5882:
	b = false;
	if (b) {
		input[3] |= (1 << 1);
		return 0;
	} else {
		input[3] &= ~(1 << 1);
		goto node4357;
	}
node3085:
	b = false;
	if (b) {
		input[1] |= (1 << 5);
		return 0;
	} else {
		input[1] &= ~(1 << 5);
		goto node3060;
	}
node5176:
	b = false;
	if (b) {
		input[1] |= (1 << 0);
		return 0;
	} else {
		input[1] &= ~(1 << 0);
		goto node4252;
	}
node2386:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node9174;
	} else {
		input[2] &= ~(1 << 4);
		goto node3304;
	}
node7756:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node332;
	} else {
		input[2] &= ~(1 << 2);
		goto node7633;
	}
node6197:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node1686;
	} else {
		input[2] &= ~(1 << 1);
		goto node8323;
	}
node3942:
	b = randbool();
	if (b) {
		input[4] |= (1 << 2);
		goto node7110;
	} else {
		input[4] &= ~(1 << 2);
		goto node1564;
	}
node8349:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node7345;
	} else {
		input[3] &= ~(1 << 2);
		goto node1281;
	}
node7248:
	b = randbool();
	if (b) {
		input[5] |= (1 << 4);
		goto node1753;
	} else {
		input[5] &= ~(1 << 4);
		goto node6486;
	}
node3817:
	b = randbool();
	if (b) {
		input[2] |= (1 << 7);
		goto node1037;
	} else {
		input[2] &= ~(1 << 7);
		goto node7186;
	}
node3526:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node8790;
	}
node6907:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node4292;
	} else {
		input[2] &= ~(1 << 1);
		goto node2967;
	}
node4640:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node9007;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node1579:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node4490;
	} else {
		input[3] &= ~(1 << 3);
		goto node3718;
	}
node7805:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		goto node3287;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node770:
	b = false;
	if (b) {
		input[3] |= (1 << 6);
		return 0;
	} else {
		input[3] &= ~(1 << 6);
		goto node5285;
	}
node1655:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node3762;
	} else {
		input[3] &= ~(1 << 3);
		goto node5276;
	}
node3408:
	b = false;
	if (b) {
		input[4] |= (1 << 2);
		return 0;
	} else {
		input[4] &= ~(1 << 2);
		goto node6972;
	}
node2874:
	b = randbool();
	if (b) {
		input[1] |= (1 << 1);
		goto node7645;
	} else {
		input[1] &= ~(1 << 1);
		goto node1652;
	}
node7940:
	b = true;
	if (b) {
		input[2] |= (1 << 2);
		goto node1322;
	} else {
		input[2] &= ~(1 << 2);
		return 0;
	}
node5143:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		goto node2057;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node2519:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node1262;
	} else {
		input[3] &= ~(1 << 5);
		goto node8930;
	}
node8028:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node5527;
	} else {
		input[3] &= ~(1 << 4);
		goto node5663;
	}
node8361:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node6692;
	} else {
		input[3] &= ~(1 << 2);
		goto node6778;
	}
node6083:
	b = randbool();
	if (b) {
		input[1] |= (1 << 0);
		goto node6489;
	} else {
		input[1] &= ~(1 << 0);
		goto node1932;
	}
node8343:
	b = false;
	if (b) {
		input[2] |= (1 << 6);
		return 0;
	} else {
		input[2] &= ~(1 << 6);
		goto node4855;
	}
node3864:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node1408;
	} else {
		input[2] &= ~(1 << 1);
		goto node169;
	}
node7306:
	b = randbool();
	if (b) {
		input[2] |= (1 << 0);
		goto node3885;
	} else {
		input[2] &= ~(1 << 0);
		goto node7024;
	}
node6962:
	b = randbool();
	if (b) {
		input[4] |= (1 << 5);
		goto node6515;
	} else {
		input[4] &= ~(1 << 5);
		goto node5729;
	}
node6443:
	b = true;
	if (b) {
		input[4] |= (1 << 5);
		goto node5236;
	} else {
		input[4] &= ~(1 << 5);
		return 0;
	}
node4289:
	b = randbool();
	if (b) {
		input[4] |= (1 << 2);
		goto node6509;
	} else {
		input[4] &= ~(1 << 2);
		goto node9390;
	}
node3016:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node6098;
	} else {
		input[3] &= ~(1 << 7);
		goto node4811;
	}
node7737:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node7815;
	}
node73:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node6835;
	}
node4459:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node3520;
	} else {
		input[3] &= ~(1 << 2);
		goto node8550;
	}
node2746:
	b = false;
	if (b) {
		input[3] |= (1 << 2);
		return 0;
	} else {
		input[3] &= ~(1 << 2);
		goto node3631;
	}
node8401:
	b = false;
	if (b) {
		input[4] |= (1 << 5);
		return 0;
	} else {
		input[4] &= ~(1 << 5);
		goto node713;
	}
node7617:
	b = true;
	if (b) {
		input[4] |= (1 << 2);
		goto node3555;
	} else {
		input[4] &= ~(1 << 2);
		return 0;
	}
node6361:
	b = true;
	if (b) {
		input[2] |= (1 << 3);
		goto node4026;
	} else {
		input[2] &= ~(1 << 3);
		return 0;
	}
node2359:
	b = true;
	if (b) {
		input[4] |= (1 << 4);
		goto node513;
	} else {
		input[4] &= ~(1 << 4);
		return 0;
	}
node4975:
	b = randbool();
	if (b) {
		input[1] |= (1 << 4);
		goto node3436;
	} else {
		input[1] &= ~(1 << 4);
		goto node5868;
	}
node2062:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node4302;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node8197:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node9360;
	} else {
		input[3] &= ~(1 << 2);
		goto node5054;
	}
node2432:
	b = true;
	if (b) {
		input[4] |= (1 << 4);
		goto node4699;
	} else {
		input[4] &= ~(1 << 4);
		return 0;
	}
node1357:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node6867;
	} else {
		input[2] &= ~(1 << 6);
		goto node8023;
	}
node1543:
	b = true;
	if (b) {
		input[3] |= (1 << 1);
		goto node320;
	} else {
		input[3] &= ~(1 << 1);
		return 0;
	}
node3182:
	b = true;
	if (b) {
		input[3] |= (1 << 1);
		goto node484;
	} else {
		input[3] &= ~(1 << 1);
		return 0;
	}
node874:
	b = true;
	if (b) {
		input[4] |= (1 << 5);
		goto node4630;
	} else {
		input[4] &= ~(1 << 5);
		return 0;
	}
node4079:
	b = true;
	if (b) {
		input[4] |= (1 << 1);
		goto node756;
	} else {
		input[4] &= ~(1 << 1);
		return 0;
	}
node4980:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node4101;
	} else {
		input[2] &= ~(1 << 6);
		goto node3301;
	}
node5324:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node1597;
	} else {
		input[2] &= ~(1 << 5);
		goto node1318;
	}
node8388:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node6851;
	} else {
		input[2] &= ~(1 << 4);
		goto node6669;
	}
node1577:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node6371;
	} else {
		input[2] &= ~(1 << 2);
		goto node917;
	}
node1434:
	b = randbool();
	if (b) {
		input[4] |= (1 << 3);
		goto node6753;
	} else {
		input[4] &= ~(1 << 3);
		goto node5909;
	}
node3499:
	b = true;
	if (b) {
		input[4] |= (1 << 1);
		goto node4053;
	} else {
		input[4] &= ~(1 << 1);
		return 0;
	}
node7966:
	b = randbool();
	if (b) {
		input[0] |= (1 << 0);
		goto node2653;
	} else {
		input[0] &= ~(1 << 0);
		goto node4149;
	}
node4540:
	b = true;
	if (b) {
		input[1] |= (1 << 0);
		goto node1414;
	} else {
		input[1] &= ~(1 << 0);
		return 0;
	}
node8451:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node959;
	} else {
		input[3] &= ~(1 << 2);
		goto node8686;
	}
node4941:
	b = randbool();
	if (b) {
		input[3] |= (1 << 1);
		goto node6382;
	} else {
		input[3] &= ~(1 << 1);
		goto node8934;
	}
node1970:
	b = randbool();
	if (b) {
		input[6] |= (1 << 7);
		goto node9303;
	} else {
		input[6] &= ~(1 << 7);
		goto node9102;
	}
node5260:
	b = true;
	if (b) {
		input[4] |= (1 << 4);
		goto node4873;
	} else {
		input[4] &= ~(1 << 4);
		return 0;
	}
node7140:
	b = randbool();
	if (b) {
		input[2] |= (1 << 7);
		goto node3921;
	} else {
		input[2] &= ~(1 << 7);
		goto node2765;
	}
node4848:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node2677;
	} else {
		input[2] &= ~(1 << 2);
		goto node9395;
	}
node8154:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node5718;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node8885:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node5415;
	} else {
		input[3] &= ~(1 << 5);
		goto node5147;
	}
node4204:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node6541;
	} else {
		input[3] &= ~(1 << 2);
		goto node3520;
	}
node1788:
	b = false;
	if (b) {
		input[3] |= (1 << 1);
		return 0;
	} else {
		input[3] &= ~(1 << 1);
		goto node4235;
	}
node6390:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node7801;
	} else {
		input[2] &= ~(1 << 6);
		goto node6699;
	}
node7713:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		goto node5707;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node8585:
	b = randbool();
	if (b) {
		input[2] |= (1 << 0);
		goto node7887;
	} else {
		input[2] &= ~(1 << 0);
		goto node667;
	}
node9392:
	b = true;
	if (b) {
		input[3] |= (1 << 7);
		goto node8492;
	} else {
		input[3] &= ~(1 << 7);
		return 0;
	}
node7165:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node4350;
	}
node4470:
	b = false;
	if (b) {
		input[1] |= (1 << 1);
		return 0;
	} else {
		input[1] &= ~(1 << 1);
		goto node2389;
	}
node4214:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node5637;
	} else {
		input[2] &= ~(1 << 1);
		goto node4780;
	}
node5370:
	b = true;
	if (b) {
		input[4] |= (1 << 2);
		goto node6509;
	} else {
		input[4] &= ~(1 << 2);
		return 0;
	}
node4003:
	b = true;
	if (b) {
		input[2] |= (1 << 5);
		goto node8584;
	} else {
		input[2] &= ~(1 << 5);
		return 0;
	}
node5906:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node3966;
	} else {
		input[3] &= ~(1 << 7);
		goto node4242;
	}
node6857:
	b = true;
	if (b) {
		input[4] |= (1 << 4);
		goto node4631;
	} else {
		input[4] &= ~(1 << 4);
		return 0;
	}
node4328:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node6287;
	} else {
		input[2] &= ~(1 << 6);
		goto node5853;
	}
node5063:
	b = false;
	if (b) {
		input[2] |= (1 << 3);
		return 0;
	} else {
		input[2] &= ~(1 << 3);
		goto node6481;
	}
node8219:
	b = true;
	if (b) {
		input[2] |= (1 << 2);
		goto node3398;
	} else {
		input[2] &= ~(1 << 2);
		return 0;
	}
node9130:
	b = false;
	if (b) {
		input[2] |= (1 << 2);
		return 0;
	} else {
		input[2] &= ~(1 << 2);
		goto node9000;
	}
node5701:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node3766;
	} else {
		input[3] &= ~(1 << 2);
		goto node948;
	}
node6222:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node412;
	} else {
		input[2] &= ~(1 << 6);
		goto node5722;
	}
node6110:
	b = false;
	if (b) {
		input[3] |= (1 << 7);
		return 0;
	} else {
		input[3] &= ~(1 << 7);
		goto node387;
	}
node4788:
	b = false;
	if (b) {
		input[3] |= (1 << 6);
		return 0;
	} else {
		input[3] &= ~(1 << 6);
		goto node1145;
	}
node4197:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node3174;
	}
node3762:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node3631;
	} else {
		input[3] &= ~(1 << 2);
		goto node1475;
	}
node2360:
	b = false;
	if (b) {
		input[4] |= (1 << 1);
		return 0;
	} else {
		input[4] &= ~(1 << 1);
		goto node5436;
	}
node1683:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node6469;
	} else {
		input[2] &= ~(1 << 5);
		goto node3713;
	}
node7118:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		goto node738;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node6645:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		goto node233;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node1842:
	b = true;
	if (b) {
		input[5] |= (1 << 2);
		goto node5919;
	} else {
		input[5] &= ~(1 << 2);
		return 0;
	}
node8421:
	b = false;
	if (b) {
		input[3] |= (1 << 7);
		return 0;
	} else {
		input[3] &= ~(1 << 7);
		goto node5850;
	}
node9160:
	b = randbool();
	if (b) {
		input[1] |= (1 << 1);
		goto node8906;
	} else {
		input[1] &= ~(1 << 1);
		goto node6808;
	}
node7466:
	b = false;
	if (b) {
		input[2] |= (1 << 6);
		return 0;
	} else {
		input[2] &= ~(1 << 6);
		goto node5093;
	}
node1790:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node5768;
	} else {
		input[2] &= ~(1 << 5);
		goto node7089;
	}
node8842:
	b = false;
	if (b) {
		input[2] |= (1 << 3);
		return 0;
	} else {
		input[2] &= ~(1 << 3);
		goto node3537;
	}
node728:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		goto node3587;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node9384:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node6799;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node5616:
	b = randbool();
	if (b) {
		input[1] |= (1 << 6);
		goto node5625;
	} else {
		input[1] &= ~(1 << 6);
		goto node6247;
	}
node487:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node3759;
	} else {
		input[2] &= ~(1 << 6);
		goto node8237;
	}
node1439:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node1809;
	} else {
		input[2] &= ~(1 << 4);
		goto node2675;
	}
node4390:
	b = false;
	if (b) {
		input[2] |= (1 << 2);
		return 0;
	} else {
		input[2] &= ~(1 << 2);
		goto node8730;
	}
node3675:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node1277;
	} else {
		input[3] &= ~(1 << 7);
		goto node2795;
	}
node7251:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node4316;
	} else {
		input[3] &= ~(1 << 2);
		goto node1994;
	}
node8949:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node2152;
	} else {
		input[3] &= ~(1 << 5);
		goto node6064;
	}
node5146:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node7366;
	} else {
		input[3] &= ~(1 << 4);
		goto node9232;
	}
node4380:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node6488;
	} else {
		input[3] &= ~(1 << 3);
		goto node409;
	}
node5769:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node940;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node888:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node5511;
	} else {
		input[3] &= ~(1 << 3);
		goto node3727;
	}
node3697:
	b = false;
	if (b) {
		input[2] |= (1 << 7);
		return 0;
	} else {
		input[2] &= ~(1 << 7);
		goto node5594;
	}
node2130:
	b = true;
	if (b) {
		input[2] |= (1 << 2);
		goto node4687;
	} else {
		input[2] &= ~(1 << 2);
		return 0;
	}
node6796:
	b = true;
	if (b) {
		input[3] |= (1 << 2);
		goto node6462;
	} else {
		input[3] &= ~(1 << 2);
		return 0;
	}
node2842:
	b = true;
	if (b) {
		input[4] |= (1 << 4);
		goto node3158;
	} else {
		input[4] &= ~(1 << 4);
		return 0;
	}
node5929:
	b = randbool();
	if (b) {
		input[1] |= (1 << 1);
		goto node7862;
	} else {
		input[1] &= ~(1 << 1);
		goto node6991;
	}
node9435:
	b = randbool();
	if (b) {
		input[2] |= (1 << 7);
		goto node5168;
	} else {
		input[2] &= ~(1 << 7);
		goto node2888;
	}
node296:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node738;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node4808:
	b = true;
	if (b) {
		input[3] |= (1 << 0);
		goto node100;
	} else {
		input[3] &= ~(1 << 0);
		return 0;
	}
node1821:
	b = randbool();
	if (b) {
		input[1] |= (1 << 1);
		goto node7645;
	} else {
		input[1] &= ~(1 << 1);
		goto node2927;
	}
node1484:
	b = false;
	if (b) {
		input[2] |= (1 << 2);
		return 0;
	} else {
		input[2] &= ~(1 << 2);
		goto node4259;
	}
node9029:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node4571;
	} else {
		input[3] &= ~(1 << 6);
		goto node4674;
	}
node7601:
	b = false;
	if (b) {
		input[4] |= (1 << 0);
		return 0;
	} else {
		input[4] &= ~(1 << 0);
		goto node9230;
	}
node2097:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node1412;
	} else {
		input[3] &= ~(1 << 5);
		goto node6527;
	}
node8255:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node6992;
	}
node5326:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node7259;
	}
node8920:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node5679;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node9341:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node6462;
	} else {
		input[3] &= ~(1 << 2);
		goto node9475;
	}
node2508:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node310;
	} else {
		input[3] &= ~(1 << 2);
		goto node9360;
	}
node9323:
	b = true;
	if (b) {
		input[1] |= (1 << 1);
		goto node3696;
	} else {
		input[1] &= ~(1 << 1);
		return 0;
	}
node9419:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node3709;
	}
node6355:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		return 3;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node2726:
	b = true;
	if (b) {
		input[3] |= (1 << 2);
		goto node4981;
	} else {
		input[3] &= ~(1 << 2);
		return 0;
	}
node7889:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node4139;
	} else {
		input[3] &= ~(1 << 2);
		goto node7632;
	}
node7804:
	b = randbool();
	if (b) {
		input[4] |= (1 << 1);
		goto node6914;
	} else {
		input[4] &= ~(1 << 1);
		goto node5417;
	}
node2275:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node1313;
	} else {
		input[2] &= ~(1 << 5);
		goto node8211;
	}
node6032:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node9383;
	} else {
		input[2] &= ~(1 << 4);
		goto node3799;
	}
node5538:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node1497;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node7609:
	b = true;
	if (b) {
		input[4] |= (1 << 5);
		goto node7818;
	} else {
		input[4] &= ~(1 << 5);
		return 0;
	}
node6287:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node8789;
	} else {
		input[2] &= ~(1 << 5);
		goto node8708;
	}
node7969:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node3322;
	} else {
		input[3] &= ~(1 << 4);
		goto node3520;
	}
node6478:
	b = randbool();
	if (b) {
		input[5] |= (1 << 4);
		goto node3239;
	} else {
		input[5] &= ~(1 << 4);
		goto node941;
	}
node7155:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		return 5;
	}
node1918:
	b = false;
	if (b) {
		input[3] |= (1 << 2);
		return 0;
	} else {
		input[3] &= ~(1 << 2);
		goto node4139;
	}
node5168:
	b = true;
	if (b) {
		input[2] |= (1 << 6);
		goto node38;
	} else {
		input[2] &= ~(1 << 6);
		return 0;
	}
node4768:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node1479;
	} else {
		input[2] &= ~(1 << 5);
		goto node2822;
	}
node3211:
	b = false;
	if (b) {
		input[2] |= (1 << 2);
		return 0;
	} else {
		input[2] &= ~(1 << 2);
		goto node2553;
	}
node5125:
	b = false;
	if (b) {
		input[3] |= (1 << 7);
		return 0;
	} else {
		input[3] &= ~(1 << 7);
		goto node4226;
	}
node7763:
	b = true;
	if (b) {
		input[3] |= (1 << 6);
		goto node8588;
	} else {
		input[3] &= ~(1 << 6);
		return 0;
	}
node3322:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node8634;
	} else {
		input[3] &= ~(1 << 3);
		goto node1126;
	}
node1199:
	b = randbool();
	if (b) {
		input[1] |= (1 << 2);
		goto node7645;
	} else {
		input[1] &= ~(1 << 2);
		goto node1821;
	}
node5232:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node8817;
	} else {
		input[2] &= ~(1 << 4);
		goto node1806;
	}
node6731:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node5374;
	} else {
		input[3] &= ~(1 << 5);
		goto node15;
	}
node4105:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node9292;
	}
node9221:
	b = true;
	if (b) {
		input[4] |= (1 << 1);
		goto node7349;
	} else {
		input[4] &= ~(1 << 1);
		return 0;
	}
node8320:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node631;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node9388:
	b = false;
	if (b) {
		input[3] |= (1 << 1);
		return 0;
	} else {
		input[3] &= ~(1 << 1);
		goto node6220;
	}
node5161:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node1073;
	} else {
		input[3] &= ~(1 << 4);
		goto node5989;
	}
node502:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node2646;
	} else {
		input[3] &= ~(1 << 3);
		goto node693;
	}
node219:
	b = true;
	if (b) {
		input[3] |= (1 << 0);
		goto node1634;
	} else {
		input[3] &= ~(1 << 0);
		return 0;
	}
node8179:
	b = true;
	if (b) {
		input[4] |= (1 << 4);
		goto node7254;
	} else {
		input[4] &= ~(1 << 4);
		return 0;
	}
node1877:
	b = true;
	if (b) {
		input[2] |= (1 << 7);
		goto node1961;
	} else {
		input[2] &= ~(1 << 7);
		return 0;
	}
node168:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node7165;
	} else {
		input[3] &= ~(1 << 5);
		goto node1195;
	}
node5314:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node7821;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node2951:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node6835;
	} else {
		input[3] &= ~(1 << 3);
		goto node7632;
	}
node2946:
	b = randbool();
	if (b) {
		input[4] |= (1 << 7);
		goto node477;
	} else {
		input[4] &= ~(1 << 7);
		goto node4623;
	}
node8108:
	b = randbool();
	if (b) {
		input[4] |= (1 << 1);
		goto node8656;
	} else {
		input[4] &= ~(1 << 1);
		goto node4412;
	}
node7577:
	b = randbool();
	if (b) {
		input[1] |= (1 << 3);
		goto node3396;
	} else {
		input[1] &= ~(1 << 3);
		goto node5487;
	}
node7715:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node6719;
	} else {
		input[2] &= ~(1 << 6);
		goto node1328;
	}
node8293:
	b = false;
	if (b) {
		input[3] |= (1 << 7);
		return 0;
	} else {
		input[3] &= ~(1 << 7);
		goto node1221;
	}
node9369:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node204;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node712:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node7790;
	} else {
		input[3] &= ~(1 << 2);
		goto node6778;
	}
node2652:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node5422;
	} else {
		input[3] &= ~(1 << 2);
		goto node8801;
	}
node1360:
	b = true;
	if (b) {
		input[2] |= (1 << 6);
		goto node109;
	} else {
		input[2] &= ~(1 << 6);
		return 0;
	}
node5884:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node2286;
	} else {
		input[2] &= ~(1 << 3);
		goto node7470;
	}
node2293:
	b = false;
	if (b) {
		input[2] |= (1 << 2);
		return 0;
	} else {
		input[2] &= ~(1 << 2);
		goto node6683;
	}
node1855:
	b = true;
	if (b) {
		input[2] |= (1 << 2);
		goto node4626;
	} else {
		input[2] &= ~(1 << 2);
		return 0;
	}
node4878:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node3088;
	} else {
		input[3] &= ~(1 << 2);
		goto node9360;
	}
node6425:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node4626;
	} else {
		input[2] &= ~(1 << 2);
		goto node8879;
	}
node3352:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node3735;
	} else {
		input[2] &= ~(1 << 2);
		goto node6257;
	}
node5865:
	b = randbool();
	if (b) {
		input[2] |= (1 << 7);
		goto node6418;
	} else {
		input[2] &= ~(1 << 7);
		goto node1092;
	}
node1473:
	b = true;
	if (b) {
		input[2] |= (1 << 2);
		goto node4606;
	} else {
		input[2] &= ~(1 << 2);
		return 0;
	}
node2817:
	b = true;
	if (b) {
		input[3] |= (1 << 7);
		goto node9087;
	} else {
		input[3] &= ~(1 << 7);
		return 0;
	}
node6911:
	b = true;
	if (b) {
		input[3] |= (1 << 6);
		goto node4553;
	} else {
		input[3] &= ~(1 << 6);
		return 0;
	}
node8732:
	b = randbool();
	if (b) {
		input[3] |= (1 << 0);
		goto node7632;
	} else {
		input[3] &= ~(1 << 0);
		goto node6818;
	}
node3673:
	b = randbool();
	if (b) {
		input[4] |= (1 << 4);
		goto node5540;
	} else {
		input[4] &= ~(1 << 4);
		goto node7113;
	}
node399:
	b = false;
	if (b) {
		input[3] |= (1 << 0);
		return 0;
	} else {
		input[3] &= ~(1 << 0);
		goto node7803;
	}
node1495:
	b = true;
	if (b) {
		input[2] |= (1 << 7);
		goto node1778;
	} else {
		input[2] &= ~(1 << 7);
		return 0;
	}
node5708:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node6122;
	} else {
		input[3] &= ~(1 << 7);
		goto node943;
	}
node8624:
	b = false;
	if (b) {
		input[3] |= (1 << 6);
		return 0;
	} else {
		input[3] &= ~(1 << 6);
		goto node7992;
	}
node4647:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node4300;
	}
node22:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node4167;
	} else {
		input[3] &= ~(1 << 4);
		goto node334;
	}
node2957:
	b = false;
	if (b) {
		input[3] |= (1 << 2);
		return 0;
	} else {
		input[3] &= ~(1 << 2);
		goto node470;
	}
node272:
	b = true;
	if (b) {
		input[1] |= (1 << 0);
		goto node7342;
	} else {
		input[1] &= ~(1 << 0);
		return 0;
	}
node6094:
	b = true;
	if (b) {
		input[1] |= (1 << 0);
		goto node8056;
	} else {
		input[1] &= ~(1 << 0);
		return 0;
	}
node8204:
	b = true;
	if (b) {
		input[2] |= (1 << 7);
		goto node3503;
	} else {
		input[2] &= ~(1 << 7);
		return 0;
	}
node7872:
	b = false;
	if (b) {
		input[3] |= (1 << 7);
		return 0;
	} else {
		input[3] &= ~(1 << 7);
		goto node7964;
	}
node3047:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node8341;
	} else {
		input[3] &= ~(1 << 6);
		goto node211;
	}
node2637:
	b = randbool();
	if (b) {
		input[3] |= (1 << 1);
		goto node8080;
	} else {
		input[3] &= ~(1 << 1);
		goto node3520;
	}
node8351:
	b = false;
	if (b) {
		input[3] |= (1 << 0);
		return 0;
	} else {
		input[3] &= ~(1 << 0);
		goto node1258;
	}
node8245:
	b = true;
	if (b) {
		input[2] |= (1 << 2);
		goto node6645;
	} else {
		input[2] &= ~(1 << 2);
		return 0;
	}
node2655:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node7257;
	} else {
		input[3] &= ~(1 << 7);
		goto node698;
	}
node4307:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node6528;
	} else {
		input[3] &= ~(1 << 5);
		goto node6691;
	}
node1680:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node1086;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node7765:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node9057;
	} else {
		input[3] &= ~(1 << 3);
		goto node6194;
	}
node5963:
	b = true;
	if (b) {
		input[3] |= (1 << 1);
		goto node4675;
	} else {
		input[3] &= ~(1 << 1);
		return 0;
	}
node1546:
	b = true;
	if (b) {
		input[2] |= (1 << 3);
		goto node3145;
	} else {
		input[2] &= ~(1 << 3);
		return 0;
	}
node2392:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node2087;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node9076:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node5091;
	} else {
		input[3] &= ~(1 << 2);
		goto node1742;
	}
node4317:
	b = false;
	if (b) {
		input[4] |= (1 << 6);
		return 0;
	} else {
		input[4] &= ~(1 << 6);
		goto node4815;
	}
node5037:
	b = randbool();
	if (b) {
		input[4] |= (1 << 4);
		goto node3990;
	} else {
		input[4] &= ~(1 << 4);
		goto node7938;
	}
node1286:
	b = randbool();
	if (b) {
		input[1] |= (1 << 0);
		goto node1495;
	} else {
		input[1] &= ~(1 << 0);
		goto node1695;
	}
node4791:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node730;
	} else {
		input[3] &= ~(1 << 7);
		goto node8881;
	}
node4489:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node3520;
	} else {
		input[3] &= ~(1 << 3);
		goto node1048;
	}
node2469:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node2605;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node1308:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node7632;
	} else {
		input[3] &= ~(1 << 2);
		goto node1742;
	}
node4360:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node8157;
	} else {
		input[3] &= ~(1 << 2);
		goto node4694;
	}
node7553:
	b = randbool();
	if (b) {
		input[0] |= (1 << 2);
		return 1;
	} else {
		input[0] &= ~(1 << 2);
		goto node1820;
	}
node1932:
	b = false;
	if (b) {
		input[2] |= (1 << 7);
		return 0;
	} else {
		input[2] &= ~(1 << 7);
		goto node27;
	}
node3405:
	b = randbool();
	if (b) {
		input[2] |= (1 << 0);
		goto node7887;
	} else {
		input[2] &= ~(1 << 0);
		goto node6428;
	}
node3940:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node2292;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node2969:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node8044;
	} else {
		input[3] &= ~(1 << 5);
		goto node4107;
	}
node7053:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node3507;
	} else {
		input[3] &= ~(1 << 3);
		goto node1011;
	}
node8554:
	b = true;
	if (b) {
		input[4] |= (1 << 5);
		goto node6659;
	} else {
		input[4] &= ~(1 << 5);
		return 0;
	}
node1119:
	b = true;
	if (b) {
		input[2] |= (1 << 2);
		goto node7385;
	} else {
		input[2] &= ~(1 << 2);
		return 0;
	}
node8702:
	b = false;
	if (b) {
		input[2] |= (1 << 2);
		return 0;
	} else {
		input[2] &= ~(1 << 2);
		goto node6455;
	}
node225:
	b = randbool();
	if (b) {
		input[2] |= (1 << 0);
		goto node5470;
	} else {
		input[2] &= ~(1 << 0);
		goto node7968;
	}
node1325:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node6897;
	} else {
		input[3] &= ~(1 << 5);
		goto node7141;
	}
node9181:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node7524;
	} else {
		input[3] &= ~(1 << 4);
		goto node5989;
	}
node3249:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node7087;
	} else {
		input[2] &= ~(1 << 2);
		return 7;
	}
node4067:
	b = false;
	if (b) {
		input[3] |= (1 << 7);
		return 0;
	} else {
		input[3] &= ~(1 << 7);
		goto node8821;
	}
node3338:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node1780;
	}
node4920:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node6606;
	} else {
		input[3] &= ~(1 << 4);
		goto node3520;
	}
node672:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node1547;
	} else {
		input[2] &= ~(1 << 1);
		goto node8091;
	}
node8965:
	b = randbool();
	if (b) {
		input[4] |= (1 << 2);
		goto node5757;
	} else {
		input[4] &= ~(1 << 2);
		goto node8305;
	}
node3072:
	b = false;
	if (b) {
		input[1] |= (1 << 5);
		return 0;
	} else {
		input[1] &= ~(1 << 5);
		goto node4880;
	}
node6643:
	b = randbool();
	if (b) {
		input[1] |= (1 << 2);
		goto node2731;
	} else {
		input[1] &= ~(1 << 2);
		goto node2674;
	}
node974:
	b = randbool();
	if (b) {
		input[1] |= (1 << 1);
		goto node5217;
	} else {
		input[1] &= ~(1 << 1);
		goto node1184;
	}
node3307:
	b = false;
	if (b) {
		input[2] |= (1 << 3);
		return 0;
	} else {
		input[2] &= ~(1 << 3);
		goto node3249;
	}
node3248:
	b = false;
	if (b) {
		input[2] |= (1 << 3);
		return 0;
	} else {
		input[2] &= ~(1 << 3);
		goto node1226;
	}
node4733:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		goto node4481;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node2872:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node2525;
	} else {
		input[3] &= ~(1 << 4);
		goto node4648;
	}
node2373:
	b = false;
	if (b) {
		input[4] |= (1 << 7);
		return 0;
	} else {
		input[4] &= ~(1 << 7);
		goto node3645;
	}
node3215:
	b = true;
	if (b) {
		input[1] |= (1 << 1);
		goto node9391;
	} else {
		input[1] &= ~(1 << 1);
		return 0;
	}
node4526:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node8162;
	} else {
		input[2] &= ~(1 << 6);
		goto node7636;
	}
node8559:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node3448;
	} else {
		input[2] &= ~(1 << 4);
		goto node6772;
	}
node7040:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node8051;
	} else {
		input[2] &= ~(1 << 1);
		goto node2523;
	}
node4259:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		goto node7887;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node6427:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node1578;
	} else {
		input[3] &= ~(1 << 7);
		goto node5581;
	}
node756:
	b = true;
	if (b) {
		input[4] |= (1 << 0);
		goto node7203;
	} else {
		input[4] &= ~(1 << 0);
		return 0;
	}
node2608:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node3155;
	} else {
		input[3] &= ~(1 << 6);
		goto node7764;
	}
node4384:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node3959;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node1514:
	b = randbool();
	if (b) {
		input[4] |= (1 << 5);
		goto node4906;
	} else {
		input[4] &= ~(1 << 5);
		goto node2359;
	}
node5388:
	b = false;
	if (b) {
		input[2] |= (1 << 7);
		return 0;
	} else {
		input[2] &= ~(1 << 7);
		goto node9286;
	}
node3663:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node981;
	} else {
		input[2] &= ~(1 << 5);
		goto node6323;
	}
node6012:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node6506;
	} else {
		input[3] &= ~(1 << 5);
		goto node3174;
	}
node5893:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node4961;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node3480:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node7632;
	} else {
		input[3] &= ~(1 << 3);
		goto node2610;
	}
node4794:
	b = false;
	if (b) {
		input[3] |= (1 << 1);
		return 0;
	} else {
		input[3] &= ~(1 << 1);
		goto node7794;
	}
node2567:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node6073;
	} else {
		input[2] &= ~(1 << 3);
		goto node2187;
	}
node8880:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node3379;
	} else {
		input[3] &= ~(1 << 7);
		goto node7892;
	}
node637:
	b = false;
	if (b) {
		input[4] |= (1 << 5);
		return 0;
	} else {
		input[4] &= ~(1 << 5);
		goto node4131;
	}
node7232:
	b = randbool();
	if (b) {
		input[6] |= (1 << 1);
		return 7;
	} else {
		input[6] &= ~(1 << 1);
		goto node2501;
	}
node8446:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node5201;
	} else {
		input[2] &= ~(1 << 5);
		goto node5737;
	}
node4692:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node4359;
	} else {
		input[3] &= ~(1 << 6);
		goto node7619;
	}
node7574:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node3520;
	} else {
		input[3] &= ~(1 << 3);
		goto node3478;
	}
node4215:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node6717;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node679:
	b = true;
	if (b) {
		input[4] |= (1 << 1);
		goto node5760;
	} else {
		input[4] &= ~(1 << 1);
		return 0;
	}
node7428:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node9416;
	}
node5831:
	b = true;
	if (b) {
		input[1] |= (1 << 2);
		goto node83;
	} else {
		input[1] &= ~(1 << 2);
		return 0;
	}
node815:
	b = false;
	if (b) {
		input[2] |= (1 << 6);
		return 0;
	} else {
		input[2] &= ~(1 << 6);
		goto node2902;
	}
node4362:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node7535;
	} else {
		input[2] &= ~(1 << 4);
		goto node8945;
	}
node2784:
	b = true;
	if (b) {
		input[2] |= (1 << 3);
		goto node1473;
	} else {
		input[2] &= ~(1 << 3);
		return 0;
	}
node2580:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node4655;
	} else {
		input[2] &= ~(1 << 2);
		goto node420;
	}
node9409:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node6920;
	} else {
		input[3] &= ~(1 << 7);
		goto node421;
	}
node9036:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node7271;
	} else {
		input[3] &= ~(1 << 5);
		goto node754;
	}
node6479:
	b = randbool();
	if (b) {
		input[1] |= (1 << 2);
		goto node2273;
	} else {
		input[1] &= ~(1 << 2);
		goto node716;
	}
node1751:
	b = false;
	if (b) {
		input[2] |= (1 << 1);
		return 0;
	} else {
		input[2] &= ~(1 << 1);
		goto node3123;
	}
node4790:
	b = randbool();
	if (b) {
		input[2] |= (1 << 0);
		goto node7031;
	} else {
		input[2] &= ~(1 << 0);
		goto node7154;
	}
node3226:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node2209;
	} else {
		input[3] &= ~(1 << 6);
		goto node9151;
	}
node8532:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node7893;
	} else {
		input[3] &= ~(1 << 4);
		goto node873;
	}
node4915:
	b = false;
	if (b) {
		input[3] |= (1 << 2);
		return 0;
	} else {
		input[3] &= ~(1 << 2);
		goto node7345;
	}
node5543:
	b = randbool();
	if (b) {
		input[1] |= (1 << 1);
		goto node1785;
	} else {
		input[1] &= ~(1 << 1);
		goto node1813;
	}
node5662:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node7428;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node2243:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node8533;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node2984:
	b = randbool();
	if (b) {
		input[4] |= (1 << 3);
		goto node8259;
	} else {
		input[4] &= ~(1 << 3);
		goto node3213;
	}
node1146:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node803;
	} else {
		input[3] &= ~(1 << 4);
		goto node1382;
	}
node606:
	b = true;
	if (b) {
		input[3] |= (1 << 0);
		goto node3727;
	} else {
		input[3] &= ~(1 << 0);
		return 0;
	}
node3019:
	b = false;
	if (b) {
		input[5] |= (1 << 7);
		return 0;
	} else {
		input[5] &= ~(1 << 7);
		goto node7468;
	}
node2054:
	b = randbool();
	if (b) {
		input[4] |= (1 << 6);
		goto node7752;
	} else {
		input[4] &= ~(1 << 6);
		goto node2780;
	}
node4560:
	b = randbool();
	if (b) {
		input[2] |= (1 << 0);
		goto node1687;
	} else {
		input[2] &= ~(1 << 0);
		goto node7202;
	}
node2656:
	b = true;
	if (b) {
		input[3] |= (1 << 7);
		goto node6325;
	} else {
		input[3] &= ~(1 << 7);
		return 0;
	}
node6856:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node9449;
	}
node7675:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node9021;
	}
node7647:
	b = false;
	if (b) {
		input[3] |= (1 << 2);
		return 0;
	} else {
		input[3] &= ~(1 << 2);
		goto node3638;
	}
node6675:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node4139;
	} else {
		input[3] &= ~(1 << 2);
		goto node5686;
	}
node9165:
	b = randbool();
	if (b) {
		input[1] |= (1 << 3);
		goto node824;
	} else {
		input[1] &= ~(1 << 3);
		goto node7754;
	}
node6622:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node7245;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node4318:
	b = randbool();
	if (b) {
		input[1] |= (1 << 3);
		goto node4612;
	} else {
		input[1] &= ~(1 << 3);
		goto node3656;
	}
node688:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node2827;
	}
node7528:
	b = true;
	if (b) {
		input[2] |= (1 << 2);
		goto node7118;
	} else {
		input[2] &= ~(1 << 2);
		return 0;
	}
node2614:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node2969;
	} else {
		input[3] &= ~(1 << 6);
		goto node8043;
	}
node3678:
	b = true;
	if (b) {
		input[3] |= (1 << 2);
		goto node6875;
	} else {
		input[3] &= ~(1 << 2);
		return 0;
	}
node7501:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node418;
	} else {
		input[3] &= ~(1 << 2);
		goto node3552;
	}
node7151:
	b = false;
	if (b) {
		input[1] |= (1 << 3);
		return 0;
	} else {
		input[1] &= ~(1 << 3);
		goto node8261;
	}
node6230:
	b = true;
	if (b) {
		input[1] |= (1 << 2);
		goto node5674;
	} else {
		input[1] &= ~(1 << 2);
		return 0;
	}
node5599:
	b = randbool();
	if (b) {
		input[1] |= (1 << 0);
		goto node6365;
	} else {
		input[1] &= ~(1 << 0);
		goto node2706;
	}
node356:
	b = false;
	if (b) {
		input[2] |= (1 << 3);
		return 0;
	} else {
		input[2] &= ~(1 << 3);
		goto node6573;
	}
node2208:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node2627;
	} else {
		input[3] &= ~(1 << 6);
		goto node8799;
	}
node4107:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node2521;
	} else {
		input[3] &= ~(1 << 4);
		goto node3520;
	}
node50:
	b = false;
	if (b) {
		input[1] |= (1 << 2);
		return 0;
	} else {
		input[1] &= ~(1 << 2);
		goto node5005;
	}
node8699:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node3738;
	} else {
		input[2] &= ~(1 << 6);
		goto node4112;
	}
node5705:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node1576;
	} else {
		input[2] &= ~(1 << 5);
		goto node1226;
	}
node6223:
	b = true;
	if (b) {
		input[2] |= (1 << 4);
		goto node364;
	} else {
		input[2] &= ~(1 << 4);
		return 0;
	}
node1547:
	b = randbool();
	if (b) {
		input[2] |= (1 << 0);
		goto node1373;
	} else {
		input[2] &= ~(1 << 0);
		goto node7569;
	}
node2730:
	b = randbool();
	if (b) {
		input[1] |= (1 << 7);
		goto node2172;
	} else {
		input[1] &= ~(1 << 7);
		goto node7273;
	}
node9026:
	b = randbool();
	if (b) {
		input[1] |= (1 << 1);
		goto node880;
	} else {
		input[1] &= ~(1 << 1);
		return 2;
	}
node9296:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node389;
	} else {
		input[3] &= ~(1 << 6);
		goto node4376;
	}
node7538:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node575;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node5358:
	b = randbool();
	if (b) {
		input[1] |= (1 << 2);
		goto node9400;
	} else {
		input[1] &= ~(1 << 2);
		goto node7277;
	}
node3296:
	b = randbool();
	if (b) {
		input[1] |= (1 << 1);
		goto node327;
	} else {
		input[1] &= ~(1 << 1);
		goto node4089;
	}
node6447:
	b = false;
	if (b) {
		input[3] |= (1 << 6);
		return 0;
	} else {
		input[3] &= ~(1 << 6);
		goto node2988;
	}
node335:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node7920;
	} else {
		input[3] &= ~(1 << 2);
		goto node4074;
	}
node2160:
	b = true;
	if (b) {
		input[1] |= (1 << 4);
		goto node1659;
	} else {
		input[1] &= ~(1 << 4);
		return 0;
	}
node727:
	b = randbool();
	if (b) {
		input[1] |= (1 << 3);
		goto node5549;
	} else {
		input[1] &= ~(1 << 3);
		goto node4423;
	}
node9094:
	b = false;
	if (b) {
		input[2] |= (1 << 7);
		return 0;
	} else {
		input[2] &= ~(1 << 7);
		goto node5936;
	}
node4363:
	b = randbool();
	if (b) {
		input[2] |= (1 << 0);
		goto node6428;
	} else {
		input[2] &= ~(1 << 0);
		goto node355;
	}
node1280:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node1590;
	} else {
		input[3] &= ~(1 << 3);
		goto node1011;
	}
node3336:
	b = true;
	if (b) {
		input[1] |= (1 << 1);
		goto node5515;
	} else {
		input[1] &= ~(1 << 1);
		return 0;
	}
node2918:
	b = true;
	if (b) {
		input[1] |= (1 << 0);
		goto node2564;
	} else {
		input[1] &= ~(1 << 0);
		return 0;
	}
node7801:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node8132;
	} else {
		input[2] &= ~(1 << 5);
		goto node2130;
	}
node6096:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node8958;
	} else {
		input[2] &= ~(1 << 3);
		goto node6193;
	}
node1761:
	b = true;
	if (b) {
		input[4] |= (1 << 3);
		goto node6858;
	} else {
		input[4] &= ~(1 << 3);
		return 0;
	}
node4233:
	b = randbool();
	if (b) {
		input[1] |= (1 << 5);
		goto node7867;
	} else {
		input[1] &= ~(1 << 5);
		goto node5340;
	}
node4443:
	b = true;
	if (b) {
		input[2] |= (1 << 5);
		goto node7182;
	} else {
		input[2] &= ~(1 << 5);
		return 0;
	}
node2616:
	b = true;
	if (b) {
		input[2] |= (1 << 2);
		goto node130;
	} else {
		input[2] &= ~(1 << 2);
		return 0;
	}
node9126:
	b = randbool();
	if (b) {
		input[2] |= (1 << 0);
		goto node9145;
	} else {
		input[2] &= ~(1 << 0);
		goto node2738;
	}
node6512:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node9302;
	} else {
		input[3] &= ~(1 << 6);
		goto node5455;
	}
node7903:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node891;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node6794:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node502;
	} else {
		input[3] &= ~(1 << 4);
		goto node2635;
	}
node5795:
	b = true;
	if (b) {
		input[1] |= (1 << 1);
		goto node5666;
	} else {
		input[1] &= ~(1 << 1);
		return 0;
	}
node3862:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node1586;
	} else {
		input[2] &= ~(1 << 3);
		goto node2187;
	}
node5247:
	b = false;
	if (b) {
		input[2] |= (1 << 3);
		return 0;
	} else {
		input[2] &= ~(1 << 3);
		goto node2130;
	}
node5921:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node7887;
	} else {
		input[2] &= ~(1 << 2);
		goto node6453;
	}
node855:
	b = false;
	if (b) {
		input[2] |= (1 << 2);
		return 0;
	} else {
		input[2] &= ~(1 << 2);
		goto node6199;
	}
node2693:
	b = false;
	if (b) {
		input[3] |= (1 << 6);
		return 0;
	} else {
		input[3] &= ~(1 << 6);
		goto node294;
	}
node8938:
	b = false;
	if (b) {
		input[2] |= (1 << 0);
		return 0;
	} else {
		input[2] &= ~(1 << 0);
		goto node131;
	}
node8838:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node6628;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node5958:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node5326;
	}
node1985:
	b = false;
	if (b) {
		input[4] |= (1 << 1);
		return 0;
	} else {
		input[4] &= ~(1 << 1);
		goto node6146;
	}
node7313:
	b = randbool();
	if (b) {
		input[4] |= (1 << 0);
		return 11;
	} else {
		input[4] &= ~(1 << 0);
		return 7;
	}
node4475:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node3088;
	} else {
		input[3] &= ~(1 << 2);
		goto node5337;
	}
node852:
	b = false;
	if (b) {
		input[4] |= (1 << 7);
		return 0;
	} else {
		input[4] &= ~(1 << 7);
		goto node8074;
	}
node4974:
	b = randbool();
	if (b) {
		input[7] |= (1 << 7);
		goto node624;
	} else {
		input[7] &= ~(1 << 7);
		goto node7950;
	}
node3699:
	b = false;
	if (b) {
		input[2] |= (1 << 0);
		return 0;
	} else {
		input[2] &= ~(1 << 0);
		goto node2372;
	}
node7065:
	b = true;
	if (b) {
		input[3] |= (1 << 1);
		goto node9262;
	} else {
		input[3] &= ~(1 << 1);
		return 0;
	}
node4333:
	b = randbool();
	if (b) {
		input[1] |= (1 << 6);
		goto node1944;
	} else {
		input[1] &= ~(1 << 6);
		goto node7086;
	}
node2893:
	b = randbool();
	if (b) {
		input[1] |= (1 << 3);
		goto node5626;
	} else {
		input[1] &= ~(1 << 3);
		goto node9013;
	}
node7514:
	b = randbool();
	if (b) {
		input[1] |= (1 << 0);
		goto node546;
	} else {
		input[1] &= ~(1 << 0);
		goto node6460;
	}
node7948:
	b = false;
	if (b) {
		input[2] |= (1 << 7);
		return 0;
	} else {
		input[2] &= ~(1 << 7);
		goto node3432;
	}
node3390:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node5135;
	} else {
		input[2] &= ~(1 << 6);
		goto node1715;
	}
node2446:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node4417;
	} else {
		input[2] &= ~(1 << 3);
		goto node3358;
	}
node2384:
	b = randbool();
	if (b) {
		input[3] |= (1 << 1);
		goto node7893;
	} else {
		input[3] &= ~(1 << 1);
		goto node8835;
	}
node7391:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node5872;
	}
node1633:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node2923;
	} else {
		input[3] &= ~(1 << 3);
		goto node9076;
	}
node1874:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node9266;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node720:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node4913;
	} else {
		input[3] &= ~(1 << 5);
		goto node86;
	}
node1743:
	b = randbool();
	if (b) {
		input[1] |= (1 << 1);
		return 6;
	} else {
		input[1] &= ~(1 << 1);
		goto node2927;
	}
node5930:
	b = true;
	if (b) {
		input[2] |= (1 << 6);
		goto node6017;
	} else {
		input[2] &= ~(1 << 6);
		return 0;
	}
node5362:
	b = true;
	if (b) {
		input[2] |= (1 << 2);
		goto node7805;
	} else {
		input[2] &= ~(1 << 2);
		return 0;
	}
node3527:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		goto node2045;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node1831:
	b = false;
	if (b) {
		input[2] |= (1 << 2);
		return 0;
	} else {
		input[2] &= ~(1 << 2);
		goto node266;
	}
node1268:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node2750;
	} else {
		input[3] &= ~(1 << 4);
		goto node892;
	}
node1954:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node2277;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node7515:
	b = true;
	if (b) {
		input[2] |= (1 << 5);
		goto node1226;
	} else {
		input[2] &= ~(1 << 5);
		return 0;
	}
node5285:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node5662;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node1525:
	b = false;
	if (b) {
		input[4] |= (1 << 5);
		return 0;
	} else {
		input[4] &= ~(1 << 5);
		goto node5226;
	}
node6310:
	b = false;
	if (b) {
		input[4] |= (1 << 5);
		return 0;
	} else {
		input[4] &= ~(1 << 5);
		goto node4491;
	}
node8736:
	b = true;
	if (b) {
		input[4] |= (1 << 4);
		goto node4996;
	} else {
		input[4] &= ~(1 << 4);
		return 0;
	}
node3469:
	b = false;
	if (b) {
		input[2] |= (1 << 5);
		return 0;
	} else {
		input[2] &= ~(1 << 5);
		goto node5013;
	}
node5959:
	b = true;
	if (b) {
		input[3] |= (1 << 2);
		goto node5808;
	} else {
		input[3] &= ~(1 << 2);
		return 0;
	}
node8414:
	b = true;
	if (b) {
		input[2] |= (1 << 4);
		goto node2824;
	} else {
		input[2] &= ~(1 << 4);
		return 0;
	}
node7222:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node2803;
	} else {
		input[3] &= ~(1 << 2);
		goto node9360;
	}
node3220:
	b = randbool();
	if (b) {
		input[3] |= (1 << 1);
		goto node4093;
	} else {
		input[3] &= ~(1 << 1);
		goto node524;
	}
node2213:
	b = false;
	if (b) {
		input[2] |= (1 << 7);
		return 0;
	} else {
		input[2] &= ~(1 << 7);
		goto node9424;
	}
node4810:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node2187;
	} else {
		input[2] &= ~(1 << 3);
		goto node4239;
	}
node8903:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node4640;
	} else {
		input[3] &= ~(1 << 6);
		goto node4375;
	}
node3530:
	b = false;
	if (b) {
		input[4] |= (1 << 7);
		return 0;
	} else {
		input[4] &= ~(1 << 7);
		goto node4982;
	}
node5192:
	b = false;
	if (b) {
		input[3] |= (1 << 2);
		return 0;
	} else {
		input[3] &= ~(1 << 2);
		goto node3237;
	}
node9284:
	b = true;
	if (b) {
		input[3] |= (1 << 0);
		goto node4498;
	} else {
		input[3] &= ~(1 << 0);
		return 0;
	}
node3204:
	b = randbool();
	if (b) {
		input[1] |= (1 << 4);
		goto node3973;
	} else {
		input[1] &= ~(1 << 4);
		goto node1559;
	}
node935:
	b = true;
	if (b) {
		input[1] |= (1 << 3);
		goto node4111;
	} else {
		input[1] &= ~(1 << 3);
		return 0;
	}
node1583:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node8537;
	} else {
		input[3] &= ~(1 << 7);
		goto node7623;
	}
node268:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node5001;
	} else {
		input[3] &= ~(1 << 4);
		goto node2408;
	}
node9158:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node2121;
	}
node1628:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node6462;
	} else {
		input[3] &= ~(1 << 2);
		goto node7156;
	}
node6623:
	b = true;
	if (b) {
		input[4] |= (1 << 4);
		goto node5560;
	} else {
		input[4] &= ~(1 << 4);
		return 0;
	}
node1837:
	b = false;
	if (b) {
		input[4] |= (1 << 4);
		return 0;
	} else {
		input[4] &= ~(1 << 4);
		goto node1387;
	}
node6143:
	b = randbool();
	if (b) {
		input[1] |= (1 << 2);
		goto node1585;
	} else {
		input[1] &= ~(1 << 2);
		goto node2674;
	}
node585:
	b = true;
	if (b) {
		input[2] |= (1 << 2);
		goto node4366;
	} else {
		input[2] &= ~(1 << 2);
		return 0;
	}
node8050:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node7269;
	} else {
		input[2] &= ~(1 << 2);
		goto node2180;
	}
node5900:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node8086;
	} else {
		input[3] &= ~(1 << 6);
		goto node830;
	}
node2615:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node1628;
	} else {
		input[3] &= ~(1 << 3);
		goto node7266;
	}
node1632:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node8273;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node2022:
	b = true;
	if (b) {
		input[1] |= (1 << 0);
		goto node5780;
	} else {
		input[1] &= ~(1 << 0);
		return 0;
	}
node614:
	b = true;
	if (b) {
		input[2] |= (1 << 7);
		goto node2207;
	} else {
		input[2] &= ~(1 << 7);
		return 0;
	}
node8861:
	b = true;
	if (b) {
		input[2] |= (1 << 4);
		goto node3217;
	} else {
		input[2] &= ~(1 << 4);
		return 0;
	}
node1858:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node6323;
	}
node1684:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node5886;
	} else {
		input[2] &= ~(1 << 4);
		goto node6553;
	}
node5499:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node4138;
	} else {
		input[2] &= ~(1 << 3);
		goto node7072;
	}
node1725:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node3981;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node3110:
	b = false;
	if (b) {
		input[2] |= (1 << 0);
		return 0;
	} else {
		input[2] &= ~(1 << 0);
		goto node9254;
	}
node9123:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node4332;
	} else {
		input[3] &= ~(1 << 4);
		goto node6993;
	}
node6022:
	b = false;
	if (b) {
		input[4] |= (1 << 1);
		return 0;
	} else {
		input[4] &= ~(1 << 1);
		goto node8514;
	}
node4967:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node8136;
	} else {
		input[2] &= ~(1 << 5);
		goto node6342;
	}
node9006:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node6331;
	} else {
		input[3] &= ~(1 << 5);
		goto node657;
	}
node723:
	b = true;
	if (b) {
		input[1] |= (1 << 4);
		goto node8184;
	} else {
		input[1] &= ~(1 << 4);
		return 0;
	}
node8372:
	b = randbool();
	if (b) {
		input[2] |= (1 << 7);
		goto node853;
	} else {
		input[2] &= ~(1 << 7);
		goto node8535;
	}
node2302:
	b = randbool();
	if (b) {
		input[2] |= (1 << 0);
		goto node7909;
	} else {
		input[2] &= ~(1 << 0);
		goto node7301;
	}
node6979:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node1993;
	} else {
		input[3] &= ~(1 << 5);
		goto node1390;
	}
node1845:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node6420;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node7666:
	b = false;
	if (b) {
		input[3] |= (1 << 0);
		return 0;
	} else {
		input[3] &= ~(1 << 0);
		goto node6980;
	}
node4492:
	b = randbool();
	if (b) {
		input[1] |= (1 << 0);
		goto node3871;
	} else {
		input[1] &= ~(1 << 0);
		goto node2511;
	}
node7147:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node7861;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node6265:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node8968;
	}
node1635:
	b = true;
	if (b) {
		input[4] |= (1 << 6);
		goto node4724;
	} else {
		input[4] &= ~(1 << 6);
		return 0;
	}
node6061:
	b = randbool();
	if (b) {
		input[1] |= (1 << 5);
		goto node9025;
	} else {
		input[1] &= ~(1 << 5);
		goto node495;
	}
node7610:
	b = randbool();
	if (b) {
		input[1] |= (1 << 3);
		goto node5164;
	} else {
		input[1] &= ~(1 << 3);
		goto node4841;
	}
node1106:
	b = randbool();
	if (b) {
		input[1] |= (1 << 0);
		goto node4649;
	} else {
		input[1] &= ~(1 << 0);
		goto node9278;
	}
node1300:
	b = false;
	if (b) {
		input[2] |= (1 << 7);
		return 0;
	} else {
		input[2] &= ~(1 << 7);
		goto node44;
	}
node7593:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		goto node7579;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node1950:
	b = true;
	if (b) {
		input[4] |= (1 << 0);
		return 7;
	} else {
		input[4] &= ~(1 << 0);
		return 0;
	}
node7650:
	b = false;
	if (b) {
		input[1] |= (1 << 4);
		return 0;
	} else {
		input[1] &= ~(1 << 4);
		goto node8643;
	}
node967:
	b = true;
	if (b) {
		input[2] |= (1 << 5);
		goto node4291;
	} else {
		input[2] &= ~(1 << 5);
		return 0;
	}
node5726:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node7912;
	} else {
		input[3] &= ~(1 << 5);
		goto node9377;
	}
node3552:
	b = randbool();
	if (b) {
		input[3] |= (1 << 1);
		goto node418;
	} else {
		input[3] &= ~(1 << 1);
		goto node7659;
	}
node8065:
	b = true;
	if (b) {
		input[3] |= (1 << 0);
		goto node5199;
	} else {
		input[3] &= ~(1 << 0);
		return 0;
	}
node872:
	b = true;
	if (b) {
		input[4] |= (1 << 3);
		goto node3531;
	} else {
		input[4] &= ~(1 << 3);
		return 0;
	}
node5253:
	b = randbool();
	if (b) {
		input[1] |= (1 << 7);
		goto node1149;
	} else {
		input[1] &= ~(1 << 7);
		goto node9133;
	}
node2177:
	b = true;
	if (b) {
		input[1] |= (1 << 4);
		goto node7786;
	} else {
		input[1] &= ~(1 << 4);
		return 0;
	}
node7158:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node5312;
	}
node2694:
	b = true;
	if (b) {
		input[3] |= (1 << 1);
		goto node8982;
	} else {
		input[3] &= ~(1 << 1);
		return 0;
	}
node3547:
	b = randbool();
	if (b) {
		input[4] |= (1 << 4);
		goto node4927;
	} else {
		input[4] &= ~(1 << 4);
		goto node5609;
	}
node8203:
	b = randbool();
	if (b) {
		input[1] |= (1 << 7);
		goto node9285;
	} else {
		input[1] &= ~(1 << 7);
		goto node7393;
	}
node2173:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node8607;
	}
node6556:
	b = true;
	if (b) {
		input[3] |= (1 << 6);
		goto node5785;
	} else {
		input[3] &= ~(1 << 6);
		return 0;
	}
node3481:
	b = randbool();
	if (b) {
		input[3] |= (1 << 0);
		goto node2395;
	} else {
		input[3] &= ~(1 << 0);
		goto node3520;
	}
node1634:
	b = false;
	if (b) {
		input[4] |= (1 << 7);
		return 0;
	} else {
		input[4] &= ~(1 << 7);
		goto node2163;
	}
node8429:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node6715;
	} else {
		input[2] &= ~(1 << 3);
		goto node1175;
	}
node2473:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		return 5;
	} else {
		input[2] &= ~(1 << 2);
		goto node5829;
	}
node7196:
	b = true;
	if (b) {
		input[4] |= (1 << 5);
		goto node8614;
	} else {
		input[4] &= ~(1 << 5);
		return 0;
	}
node2657:
	b = randbool();
	if (b) {
		input[4] |= (1 << 2);
		goto node439;
	} else {
		input[4] &= ~(1 << 2);
		goto node8469;
	}
node5550:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node7694;
	} else {
		input[2] &= ~(1 << 5);
		goto node164;
	}
node9312:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node8190;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node7934:
	b = randbool();
	if (b) {
		input[5] |= (1 << 3);
		goto node9230;
	} else {
		input[5] &= ~(1 << 3);
		goto node6422;
	}
node7200:
	b = randbool();
	if (b) {
		input[1] |= (1 << 0);
		goto node3292;
	} else {
		input[1] &= ~(1 << 0);
		goto node5964;
	}
node3432:
	b = false;
	if (b) {
		input[2] |= (1 << 6);
		return 0;
	} else {
		input[2] &= ~(1 << 6);
		goto node975;
	}
node5044:
	b = true;
	if (b) {
		input[2] |= (1 << 2);
		goto node8650;
	} else {
		input[2] &= ~(1 << 2);
		return 0;
	}
node802:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node5814;
	} else {
		input[3] &= ~(1 << 5);
		goto node780;
	}
node4681:
	b = false;
	if (b) {
		input[3] |= (1 << 0);
		return 0;
	} else {
		input[3] &= ~(1 << 0);
		goto node5729;
	}
node8892:
	b = randbool();
	if (b) {
		input[4] |= (1 << 4);
		goto node2197;
	} else {
		input[4] &= ~(1 << 4);
		goto node8506;
	}
node9287:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node1703;
	} else {
		input[2] &= ~(1 << 5);
		goto node3302;
	}
node4981:
	b = randbool();
	if (b) {
		input[3] |= (1 << 1);
		goto node3345;
	} else {
		input[3] &= ~(1 << 1);
		goto node3520;
	}
node8789:
	b = true;
	if (b) {
		input[2] |= (1 << 4);
		goto node4277;
	} else {
		input[2] &= ~(1 << 4);
		return 0;
	}
node8925:
	b = false;
	if (b) {
		input[3] |= (1 << 6);
		return 0;
	} else {
		input[3] &= ~(1 << 6);
		goto node4371;
	}
node8769:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node759;
	}
node8045:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node2651;
	} else {
		input[3] &= ~(1 << 3);
		goto node2374;
	}
node1049:
	b = false;
	if (b) {
		input[3] |= (1 << 1);
		return 0;
	} else {
		input[3] &= ~(1 << 1);
		goto node1130;
	}
node8550:
	b = randbool();
	if (b) {
		input[3] |= (1 << 1);
		goto node2924;
	} else {
		input[3] &= ~(1 << 1);
		goto node3050;
	}
node3577:
	b = false;
	if (b) {
		input[1] |= (1 << 6);
		return 0;
	} else {
		input[1] &= ~(1 << 6);
		goto node3085;
	}
node6609:
	b = true;
	if (b) {
		input[1] |= (1 << 2);
		goto node1582;
	} else {
		input[1] &= ~(1 << 2);
		return 0;
	}
node8459:
	b = randbool();
	if (b) {
		input[1] |= (1 << 0);
		goto node1327;
	} else {
		input[1] &= ~(1 << 0);
		goto node3524;
	}
node4086:
	b = true;
	if (b) {
		input[2] |= (1 << 4);
		goto node8999;
	} else {
		input[2] &= ~(1 << 4);
		return 0;
	}
node5425:
	b = randbool();
	if (b) {
		input[3] |= (1 << 0);
		goto node6816;
	} else {
		input[3] &= ~(1 << 0);
		goto node2989;
	}
node6666:
	b = randbool();
	if (b) {
		input[1] |= (1 << 2);
		goto node9053;
	} else {
		input[1] &= ~(1 << 2);
		goto node716;
	}
node4080:
	b = randbool();
	if (b) {
		input[2] |= (1 << 7);
		goto node2985;
	} else {
		input[2] &= ~(1 << 7);
		goto node4514;
	}
node428:
	b = randbool();
	if (b) {
		input[2] |= (1 << 7);
		goto node5930;
	} else {
		input[2] &= ~(1 << 7);
		goto node8699;
	}
node7483:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node1522;
	}
node31:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node5579;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node5174:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node3529;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node8397:
	b = true;
	if (b) {
		input[3] |= (1 << 7);
		goto node2570;
	} else {
		input[3] &= ~(1 << 7);
		return 0;
	}
node5224:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node6801;
	}
node52:
	b = true;
	if (b) {
		input[2] |= (1 << 4);
		goto node1157;
	} else {
		input[2] &= ~(1 << 4);
		return 0;
	}
node1981:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node677;
	} else {
		input[2] &= ~(1 << 4);
		goto node3492;
	}
node7870:
	b = false;
	if (b) {
		input[2] |= (1 << 1);
		return 0;
	} else {
		input[2] &= ~(1 << 1);
		goto node7784;
	}
node3599:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node1085;
	} else {
		input[3] &= ~(1 << 6);
		goto node2214;
	}
node3156:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node8654;
	} else {
		input[3] &= ~(1 << 3);
		goto node339;
	}
node5603:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node530;
	} else {
		input[3] &= ~(1 << 2);
		goto node7128;
	}
node3427:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node9296;
	} else {
		input[3] &= ~(1 << 7);
		goto node8819;
	}
node6488:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node7043;
	} else {
		input[3] &= ~(1 << 2);
		goto node1788;
	}
node2477:
	b = false;
	if (b) {
		input[4] |= (1 << 5);
		return 0;
	} else {
		input[4] &= ~(1 << 5);
		goto node1008;
	}
node3160:
	b = randbool();
	if (b) {
		input[1] |= (1 << 6);
		goto node4501;
	} else {
		input[1] &= ~(1 << 6);
		goto node6373;
	}
node1844:
	b = false;
	if (b) {
		input[2] |= (1 << 7);
		return 0;
	} else {
		input[2] &= ~(1 << 7);
		goto node4045;
	}
node397:
	b = true;
	if (b) {
		input[2] |= (1 << 3);
		goto node5330;
	} else {
		input[2] &= ~(1 << 3);
		return 0;
	}
node3716:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node5789;
	} else {
		input[3] &= ~(1 << 4);
		goto node8561;
	}
node4567:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node9238;
	} else {
		input[3] &= ~(1 << 4);
		goto node2083;
	}
node6285:
	b = false;
	if (b) {
		input[3] |= (1 << 1);
		return 0;
	} else {
		input[3] &= ~(1 << 1);
		goto node371;
	}
node44:
	b = false;
	if (b) {
		input[2] |= (1 << 6);
		return 0;
	} else {
		input[2] &= ~(1 << 6);
		goto node9037;
	}
node2207:
	b = true;
	if (b) {
		input[2] |= (1 << 6);
		goto node4261;
	} else {
		input[2] &= ~(1 << 6);
		return 0;
	}
node4884:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node7538;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node9450:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node5880;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node3781:
	b = false;
	if (b) {
		input[4] |= (1 << 6);
		return 0;
	} else {
		input[4] &= ~(1 << 6);
		goto node7304;
	}
node4121:
	b = randbool();
	if (b) {
		input[1] |= (1 << 6);
		goto node3468;
	} else {
		input[1] &= ~(1 << 6);
		goto node8802;
	}
node2343:
	b = randbool();
	if (b) {
		input[1] |= (1 << 1);
		goto node6316;
	} else {
		input[1] &= ~(1 << 1);
		goto node1014;
	}
node3150:
	b = false;
	if (b) {
		input[2] |= (1 << 5);
		return 0;
	} else {
		input[2] &= ~(1 << 5);
		goto node9242;
	}
node2910:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node252;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node6333:
	b = true;
	if (b) {
		input[1] |= (1 << 6);
		goto node2751;
	} else {
		input[1] &= ~(1 << 6);
		return 0;
	}
node6469:
	b = true;
	if (b) {
		input[2] |= (1 << 4);
		goto node3750;
	} else {
		input[2] &= ~(1 << 4);
		return 0;
	}
node6674:
	b = false;
	if (b) {
		input[3] |= (1 << 7);
		return 0;
	} else {
		input[3] &= ~(1 << 7);
		goto node7270;
	}
node5131:
	b = false;
	if (b) {
		input[4] |= (1 << 7);
		return 0;
	} else {
		input[4] &= ~(1 << 7);
		goto node1942;
	}
node4441:
	b = false;
	if (b) {
		input[4] |= (1 << 6);
		return 0;
	} else {
		input[4] &= ~(1 << 6);
		goto node4140;
	}
node3784:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node2634;
	} else {
		input[3] &= ~(1 << 6);
		goto node3775;
	}
node211:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node903;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node86:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node2525;
	} else {
		input[3] &= ~(1 << 4);
		goto node4764;
	}
node832:
	b = false;
	if (b) {
		input[3] |= (1 << 1);
		return 0;
	} else {
		input[3] &= ~(1 << 1);
		goto node8009;
	}
node484:
	b = true;
	if (b) {
		input[3] |= (1 << 0);
		goto node1600;
	} else {
		input[3] &= ~(1 << 0);
		return 0;
	}
node1658:
	b = false;
	if (b) {
		input[4] |= (1 << 0);
		return 0;
	} else {
		input[4] &= ~(1 << 0);
		goto node3615;
	}
node5229:
	b = true;
	if (b) {
		input[1] |= (1 << 6);
		goto node9448;
	} else {
		input[1] &= ~(1 << 6);
		return 0;
	}
node666:
	b = true;
	if (b) {
		input[2] |= (1 << 6);
		goto node2545;
	} else {
		input[2] &= ~(1 << 6);
		return 0;
	}
node2708:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node106;
	} else {
		input[3] &= ~(1 << 7);
		goto node55;
	}
node5956:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node4481;
	} else {
		input[2] &= ~(1 << 1);
		goto node4082;
	}
node318:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node9364;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node2156:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node1280;
	} else {
		input[3] &= ~(1 << 4);
		goto node8467;
	}
node3132:
	b = false;
	if (b) {
		input[3] |= (1 << 2);
		return 0;
	} else {
		input[3] &= ~(1 << 2);
		goto node9153;
	}
node8148:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node6337;
	} else {
		input[2] &= ~(1 << 6);
		goto node3895;
	}
node690:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node970;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node4934:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node6767;
	} else {
		input[3] &= ~(1 << 5);
		goto node559;
	}
node9091:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node2517;
	}
node2238:
	b = true;
	if (b) {
		input[5] |= (1 << 0);
		goto node1197;
	} else {
		input[5] &= ~(1 << 0);
		return 0;
	}
node1773:
	b = randbool();
	if (b) {
		input[1] |= (1 << 3);
		goto node340;
	} else {
		input[1] &= ~(1 << 3);
		goto node3707;
	}
node5911:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node6136;
	} else {
		input[2] &= ~(1 << 5);
		goto node9174;
	}
node4782:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		goto node1752;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node5441:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node4139;
	} else {
		input[3] &= ~(1 << 3);
		goto node9109;
	}
node2030:
	b = randbool();
	if (b) {
		input[4] |= (1 << 6);
		goto node652;
	} else {
		input[4] &= ~(1 << 6);
		goto node4183;
	}
node4221:
	b = false;
	if (b) {
		input[1] |= (1 << 2);
		return 0;
	} else {
		input[1] &= ~(1 << 2);
		goto node504;
	}
node5071:
	b = false;
	if (b) {
		input[1] |= (1 << 0);
		return 0;
	} else {
		input[1] &= ~(1 << 0);
		goto node25;
	}
node7568:
	b = true;
	if (b) {
		input[2] |= (1 << 3);
		goto node8306;
	} else {
		input[2] &= ~(1 << 3);
		return 0;
	}
node3854:
	b = true;
	if (b) {
		input[2] |= (1 << 2);
		goto node6939;
	} else {
		input[2] &= ~(1 << 2);
		return 0;
	}
node3600:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node7462;
	} else {
		input[3] &= ~(1 << 3);
		goto node3520;
	}
node624:
	b = randbool();
	if (b) {
		input[7] |= (1 << 5);
		goto node4260;
	} else {
		input[7] &= ~(1 << 5);
		goto node973;
	}
node8152:
	b = false;
	if (b) {
		input[1] |= (1 << 2);
		return 0;
	} else {
		input[1] &= ~(1 << 2);
		goto node4157;
	}
node1175:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node8248;
	} else {
		input[2] &= ~(1 << 2);
		goto node8852;
	}
node8680:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node3802;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node7041:
	b = false;
	if (b) {
		input[4] |= (1 << 3);
		return 0;
	} else {
		input[4] &= ~(1 << 3);
		return 7;
	}
node8829:
	b = randbool();
	if (b) {
		input[5] |= (1 << 0);
		return 10;
	} else {
		input[5] &= ~(1 << 0);
		goto node1970;
	}
node6728:
	b = true;
	if (b) {
		input[1] |= (1 << 1);
		goto node6895;
	} else {
		input[1] &= ~(1 << 1);
		return 0;
	}
node5391:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node2448;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node7135:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node2958;
	} else {
		input[3] &= ~(1 << 2);
		goto node7345;
	}
node8232:
	b = randbool();
	if (b) {
		input[0] |= (1 << 1);
		goto node6981;
	} else {
		input[0] &= ~(1 << 1);
		goto node2410;
	}
node1351:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node5395;
	} else {
		input[2] &= ~(1 << 3);
		goto node5975;
	}
node3744:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node7726;
	} else {
		input[3] &= ~(1 << 5);
		goto node9307;
	}
node1148:
	b = true;
	if (b) {
		input[4] |= (1 << 4);
		goto node5024;
	} else {
		input[4] &= ~(1 << 4);
		return 0;
	}
node1880:
	b = true;
	if (b) {
		input[4] |= (1 << 2);
		goto node1510;
	} else {
		input[4] &= ~(1 << 2);
		return 0;
	}
node3932:
	b = false;
	if (b) {
		input[2] |= (1 << 5);
		return 0;
	} else {
		input[2] &= ~(1 << 5);
		goto node6346;
	}
node128:
	b = randbool();
	if (b) {
		input[4] |= (1 << 5);
		goto node3553;
	} else {
		input[4] &= ~(1 << 5);
		goto node875;
	}
node2206:
	b = true;
	if (b) {
		input[4] |= (1 << 1);
		goto node8463;
	} else {
		input[4] &= ~(1 << 1);
		return 0;
	}
node515:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node4181;
	} else {
		input[2] &= ~(1 << 3);
		goto node5899;
	}
node9445:
	b = false;
	if (b) {
		input[3] |= (1 << 7);
		return 0;
	} else {
		input[3] &= ~(1 << 7);
		goto node5450;
	}
node6471:
	b = true;
	if (b) {
		input[3] |= (1 << 6);
		goto node7855;
	} else {
		input[3] &= ~(1 << 6);
		return 0;
	}
node7488:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node1728;
	} else {
		input[3] &= ~(1 << 3);
		goto node1591;
	}
node4311:
	b = false;
	if (b) {
		input[3] |= (1 << 1);
		return 0;
	} else {
		input[3] &= ~(1 << 1);
		goto node3881;
	}
node1785:
	b = false;
	if (b) {
		input[1] |= (1 << 0);
		return 0;
	} else {
		input[1] &= ~(1 << 0);
		goto node5430;
	}
node1677:
	b = false;
	if (b) {
		input[2] |= (1 << 7);
		return 0;
	} else {
		input[2] &= ~(1 << 7);
		goto node2905;
	}
node14:
	b = false;
	if (b) {
		input[2] |= (1 << 1);
		return 0;
	} else {
		input[2] &= ~(1 << 1);
		goto node3342;
	}
node4586:
	b = false;
	if (b) {
		input[3] |= (1 << 1);
		return 0;
	} else {
		input[3] &= ~(1 << 1);
		goto node2016;
	}
node542:
	b = randbool();
	if (b) {
		input[2] |= (1 << 7);
		goto node4161;
	} else {
		input[2] &= ~(1 << 7);
		goto node6157;
	}
node5813:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node8446;
	} else {
		input[2] &= ~(1 << 6);
		goto node2947;
	}
node1006:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node506;
	} else {
		input[2] &= ~(1 << 4);
		goto node1097;
	}
node4016:
	b = true;
	if (b) {
		input[3] |= (1 << 2);
		goto node5337;
	} else {
		input[3] &= ~(1 << 2);
		return 0;
	}
node7114:
	b = true;
	if (b) {
		input[4] |= (1 << 3);
		goto node875;
	} else {
		input[4] &= ~(1 << 3);
		return 0;
	}
node5005:
	b = randbool();
	if (b) {
		input[1] |= (1 << 1);
		goto node1898;
	} else {
		input[1] &= ~(1 << 1);
		goto node6186;
	}
node8479:
	b = false;
	if (b) {
		input[2] |= (1 << 2);
		return 0;
	} else {
		input[2] &= ~(1 << 2);
		goto node2762;
	}
node3915:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node1422;
	} else {
		input[3] &= ~(1 << 6);
		goto node8466;
	}
node1870:
	b = false;
	if (b) {
		input[4] |= (1 << 6);
		return 0;
	} else {
		input[4] &= ~(1 << 6);
		goto node6718;
	}
node1154:
	b = randbool();
	if (b) {
		input[1] |= (1 << 5);
		goto node3436;
	} else {
		input[1] &= ~(1 << 5);
		goto node4975;
	}
node5312:
	b = true;
	if (b) {
		input[2] |= (1 << 3);
		goto node7189;
	} else {
		input[2] &= ~(1 << 3);
		return 0;
	}
node6677:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node1541;
	} else {
		input[3] &= ~(1 << 6);
		goto node353;
	}
node5042:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node7501;
	} else {
		input[3] &= ~(1 << 4);
		goto node2651;
	}
node7437:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node1316;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node4916:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node4139;
	} else {
		input[3] &= ~(1 << 2);
		goto node6950;
	}
node1166:
	b = false;
	if (b) {
		input[4] |= (1 << 0);
		return 0;
	} else {
		input[4] &= ~(1 << 0);
		goto node8857;
	}
node3698:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node8543;
	} else {
		input[2] &= ~(1 << 5);
		goto node3444;
	}
node6772:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node969;
	} else {
		input[2] &= ~(1 << 3);
		goto node4502;
	}
node3837:
	b = true;
	if (b) {
		input[3] |= (1 << 6);
		goto node4759;
	} else {
		input[3] &= ~(1 << 6);
		return 0;
	}
node4896:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node8676;
	}
node4828:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node5107;
	} else {
		input[3] &= ~(1 << 4);
		goto node4215;
	}
node7272:
	b = randbool();
	if (b) {
		input[4] |= (1 << 3);
		goto node7777;
	} else {
		input[4] &= ~(1 << 3);
		goto node2297;
	}
node2164:
	b = randbool();
	if (b) {
		input[1] |= (1 << 4);
		goto node4559;
	} else {
		input[1] &= ~(1 << 4);
		goto node5363;
	}
node9231:
	b = true;
	if (b) {
		input[1] |= (1 << 1);
		goto node3328;
	} else {
		input[1] &= ~(1 << 1);
		return 0;
	}
node659:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node4268;
	}
node8137:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node5283;
	} else {
		input[3] &= ~(1 << 5);
		goto node2089;
	}
node1820:
	b = false;
	if (b) {
		input[0] |= (1 << 1);
		return 0;
	} else {
		input[0] &= ~(1 << 1);
		return 5;
	}
node1808:
	b = randbool();
	if (b) {
		input[1] |= (1 << 1);
		goto node5350;
	} else {
		input[1] &= ~(1 << 1);
		goto node4842;
	}
node9208:
	b = true;
	if (b) {
		input[2] |= (1 << 5);
		goto node8096;
	} else {
		input[2] &= ~(1 << 5);
		return 0;
	}
node6939:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		goto node9370;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node1372:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node87;
	} else {
		input[3] &= ~(1 << 7);
		goto node67;
	}
node6904:
	b = randbool();
	if (b) {
		input[7] |= (1 << 4);
		goto node6368;
	} else {
		input[7] &= ~(1 << 4);
		goto node2309;
	}
node3237:
	b = false;
	if (b) {
		input[3] |= (1 << 1);
		return 0;
	} else {
		input[3] &= ~(1 << 1);
		goto node6037;
	}
node1997:
	b = true;
	if (b) {
		input[4] |= (1 << 2);
		goto node1625;
	} else {
		input[4] &= ~(1 << 2);
		return 0;
	}
node3810:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node202;
	} else {
		input[2] &= ~(1 << 5);
		goto node4751;
	}
node8851:
	b = true;
	if (b) {
		input[2] |= (1 << 5);
		goto node1220;
	} else {
		input[2] &= ~(1 << 5);
		return 0;
	}
node9191:
	b = true;
	if (b) {
		input[2] |= (1 << 4);
		goto node515;
	} else {
		input[2] &= ~(1 << 4);
		return 0;
	}
node830:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node1869;
	} else {
		input[3] &= ~(1 << 5);
		goto node5744;
	}
node4835:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node4255;
	} else {
		input[3] &= ~(1 << 4);
		goto node289;
	}
node8468:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node8750;
	} else {
		input[3] &= ~(1 << 2);
		goto node4316;
	}
node2819:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node4069;
	} else {
		input[3] &= ~(1 << 5);
		goto node2026;
	}
node8193:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node8772;
	} else {
		input[3] &= ~(1 << 4);
		goto node1807;
	}
node979:
	b = randbool();
	if (b) {
		input[4] |= (1 << 6);
		goto node6013;
	} else {
		input[4] &= ~(1 << 6);
		goto node113;
	}
node4053:
	b = true;
	if (b) {
		input[4] |= (1 << 0);
		goto node6326;
	} else {
		input[4] &= ~(1 << 0);
		return 0;
	}
node1931:
	b = true;
	if (b) {
		input[1] |= (1 << 1);
		goto node2022;
	} else {
		input[1] &= ~(1 << 1);
		return 0;
	}
node406:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		goto node7225;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node7348:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node1532;
	} else {
		input[3] &= ~(1 << 3);
		goto node2492;
	}
node9067:
	b = false;
	if (b) {
		input[7] |= (1 << 1);
		return 0;
	} else {
		input[7] &= ~(1 << 1);
		goto node2815;
	}
node6860:
	b = randbool();
	if (b) {
		input[1] |= (1 << 3);
		goto node5320;
	} else {
		input[1] &= ~(1 << 3);
		goto node5910;
	}
node7727:
	b = false;
	if (b) {
		input[2] |= (1 << 7);
		return 0;
	} else {
		input[2] &= ~(1 << 7);
		goto node1331;
	}
node4066:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node2784;
	}
node4483:
	b = true;
	if (b) {
		input[3] |= (1 << 7);
		goto node5380;
	} else {
		input[3] &= ~(1 << 7);
		return 0;
	}
node863:
	b = true;
	if (b) {
		input[3] |= (1 << 6);
		goto node199;
	} else {
		input[3] &= ~(1 << 6);
		return 0;
	}
node811:
	b = false;
	if (b) {
		input[5] |= (1 << 1);
		return 0;
	} else {
		input[5] &= ~(1 << 1);
		goto node3267;
	}
node7809:
	b = true;
	if (b) {
		input[4] |= (1 << 1);
		goto node2367;
	} else {
		input[4] &= ~(1 << 1);
		return 0;
	}
node1022:
	b = randbool();
	if (b) {
		input[0] |= (1 << 3);
		goto node3276;
	} else {
		input[0] &= ~(1 << 3);
		goto node5464;
	}
node7405:
	b = randbool();
	if (b) {
		input[1] |= (1 << 3);
		goto node8984;
	} else {
		input[1] &= ~(1 << 3);
		goto node4432;
	}
node8379:
	b = true;
	if (b) {
		input[3] |= (1 << 2);
		goto node7976;
	} else {
		input[3] &= ~(1 << 2);
		return 0;
	}
node5548:
	b = true;
	if (b) {
		input[3] |= (1 << 2);
		goto node6211;
	} else {
		input[3] &= ~(1 << 2);
		return 0;
	}
node5669:
	b = true;
	if (b) {
		input[4] |= (1 << 6);
		goto node5513;
	} else {
		input[4] &= ~(1 << 6);
		return 0;
	}
node3213:
	b = false;
	if (b) {
		input[4] |= (1 << 2);
		return 0;
	} else {
		input[4] &= ~(1 << 2);
		goto node7110;
	}
node3274:
	b = true;
	if (b) {
		input[3] |= (1 << 2);
		goto node2158;
	} else {
		input[3] &= ~(1 << 2);
		return 0;
	}
node410:
	b = randbool();
	if (b) {
		input[4] |= (1 << 6);
		goto node5449;
	} else {
		input[4] &= ~(1 << 6);
		goto node1096;
	}
node1738:
	b = randbool();
	if (b) {
		input[1] |= (1 << 7);
		goto node7890;
	} else {
		input[1] &= ~(1 << 7);
		goto node785;
	}
node3834:
	b = true;
	if (b) {
		input[1] |= (1 << 0);
		goto node9178;
	} else {
		input[1] &= ~(1 << 0);
		return 0;
	}
node3912:
	b = false;
	if (b) {
		input[2] |= (1 << 2);
		return 0;
	} else {
		input[2] &= ~(1 << 2);
		goto node8664;
	}
node1034:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node381;
	} else {
		input[3] &= ~(1 << 6);
		goto node150;
	}
node4744:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node528;
	} else {
		input[3] &= ~(1 << 5);
		goto node5333;
	}
node6485:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node1457;
	}
node3180:
	b = false;
	if (b) {
		input[2] |= (1 << 6);
		return 0;
	} else {
		input[2] &= ~(1 << 6);
		goto node232;
	}
node4544:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node1981;
	} else {
		input[2] &= ~(1 << 5);
		goto node552;
	}
node866:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node3097;
	} else {
		input[2] &= ~(1 << 4);
		goto node1756;
	}
node4613:
	b = false;
	if (b) {
		input[2] |= (1 << 3);
		return 0;
	} else {
		input[2] &= ~(1 << 3);
		goto node5215;
	}
node1207:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node9217;
	} else {
		input[2] &= ~(1 << 2);
		goto node4214;
	}
node3806:
	b = false;
	if (b) {
		input[2] |= (1 << 2);
		return 0;
	} else {
		input[2] &= ~(1 << 2);
		goto node1986;
	}
node8583:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node8697;
	} else {
		input[2] &= ~(1 << 5);
		goto node337;
	}
node2972:
	b = false;
	if (b) {
		input[2] |= (1 << 5);
		return 0;
	} else {
		input[2] &= ~(1 << 5);
		goto node6535;
	}
node7687:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node1774;
	}
node2594:
	b = randbool();
	if (b) {
		input[3] |= (1 << 1);
		goto node3727;
	} else {
		input[3] &= ~(1 << 1);
		goto node6414;
	}
node5127:
	b = randbool();
	if (b) {
		input[4] |= (1 << 6);
		goto node2005;
	} else {
		input[4] &= ~(1 << 6);
		goto node5858;
	}
node3268:
	b = false;
	if (b) {
		input[1] |= (1 << 4);
		return 0;
	} else {
		input[1] &= ~(1 << 4);
		goto node2893;
	}
node2856:
	b = false;
	if (b) {
		input[2] |= (1 << 2);
		return 0;
	} else {
		input[2] &= ~(1 << 2);
		goto node2442;
	}
node5223:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node6656;
	} else {
		input[3] &= ~(1 << 7);
		goto node2208;
	}
node7289:
	b = false;
	if (b) {
		input[1] |= (1 << 2);
		return 0;
	} else {
		input[1] &= ~(1 << 2);
		goto node1354;
	}
node4353:
	b = false;
	if (b) {
		input[2] |= (1 << 5);
		return 0;
	} else {
		input[2] &= ~(1 << 5);
		goto node6192;
	}
node85:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		goto node1995;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node6494:
	b = false;
	if (b) {
		input[2] |= (1 << 1);
		return 0;
	} else {
		input[2] &= ~(1 << 1);
		goto node4129;
	}
node6947:
	b = false;
	if (b) {
		input[2] |= (1 << 0);
		return 0;
	} else {
		input[2] &= ~(1 << 0);
		goto node6225;
	}
node6201:
	b = false;
	if (b) {
		input[4] |= (1 << 4);
		return 0;
	} else {
		input[4] &= ~(1 << 4);
		goto node3474;
	}
node6520:
	b = randbool();
	if (b) {
		input[1] |= (1 << 3);
		return 2;
	} else {
		input[1] &= ~(1 << 3);
		goto node9246;
	}
node8160:
	b = randbool();
	if (b) {
		input[2] |= (1 << 7);
		goto node5245;
	} else {
		input[2] &= ~(1 << 7);
		goto node6047;
	}
node5578:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node3838;
	} else {
		input[3] &= ~(1 << 6);
		goto node6444;
	}
node4711:
	b = true;
	if (b) {
		input[3] |= (1 << 2);
		goto node4139;
	} else {
		input[3] &= ~(1 << 2);
		return 0;
	}
node5991:
	b = true;
	if (b) {
		input[4] |= (1 << 1);
		goto node2352;
	} else {
		input[4] &= ~(1 << 1);
		return 0;
	}
node8243:
	b = false;
	if (b) {
		input[4] |= (1 << 0);
		return 0;
	} else {
		input[4] &= ~(1 << 0);
		goto node6960;
	}
node1921:
	b = randbool();
	if (b) {
		input[2] |= (1 << 7);
		goto node3438;
	} else {
		input[2] &= ~(1 << 7);
		goto node8710;
	}
node4004:
	b = true;
	if (b) {
		input[2] |= (1 << 2);
		goto node8947;
	} else {
		input[2] &= ~(1 << 2);
		return 0;
	}
node87:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node4862;
	} else {
		input[3] &= ~(1 << 6);
		goto node4078;
	}
node2060:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node143;
	}
node4244:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node4749;
	} else {
		input[3] &= ~(1 << 3);
		goto node4093;
	}
node1222:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node6539;
	}
node2049:
	b = false;
	if (b) {
		input[2] |= (1 << 3);
		return 0;
	} else {
		input[2] &= ~(1 << 3);
		goto node1744;
	}
node6131:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		goto node7239;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node1294:
	b = true;
	if (b) {
		input[3] |= (1 << 7);
		goto node5220;
	} else {
		input[3] &= ~(1 << 7);
		return 0;
	}
node5096:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node6162;
	} else {
		input[3] &= ~(1 << 4);
		goto node3434;
	}
node2245:
	b = true;
	if (b) {
		input[4] |= (1 << 2);
		goto node8469;
	} else {
		input[4] &= ~(1 << 2);
		return 0;
	}
node7819:
	b = randbool();
	if (b) {
		input[6] |= (1 << 4);
		goto node629;
	} else {
		input[6] &= ~(1 << 4);
		goto node2572;
	}
node7811:
	b = randbool();
	if (b) {
		input[2] |= (1 << 7);
		goto node5939;
	} else {
		input[2] &= ~(1 << 7);
		goto node3747;
	}
node6239:
	b = false;
	if (b) {
		input[2] |= (1 << 1);
		return 0;
	} else {
		input[2] &= ~(1 << 1);
		goto node2776;
	}
node4357:
	b = randbool();
	if (b) {
		input[3] |= (1 << 0);
		goto node3520;
	} else {
		input[3] &= ~(1 << 0);
		goto node2395;
	}
node9308:
	b = randbool();
	if (b) {
		input[4] |= (1 << 6);
		goto node3842;
	} else {
		input[4] &= ~(1 << 6);
		goto node3652;
	}
node5878:
	b = false;
	if (b) {
		input[4] |= (1 << 4);
		return 0;
	} else {
		input[4] &= ~(1 << 4);
		goto node8490;
	}
node726:
	b = false;
	if (b) {
		input[2] |= (1 << 3);
		return 0;
	} else {
		input[2] &= ~(1 << 3);
		goto node5915;
	}
node3361:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node1144;
	} else {
		input[3] &= ~(1 << 6);
		goto node4591;
	}
node6362:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node5224;
	}
node6884:
	b = false;
	if (b) {
		input[4] |= (1 << 3);
		return 0;
	} else {
		input[4] &= ~(1 << 3);
		goto node6560;
	}
node3623:
	b = randbool();
	if (b) {
		input[6] |= (1 << 3);
		goto node6261;
	} else {
		input[6] &= ~(1 << 3);
		goto node7284;
	}
node1866:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node6088;
	} else {
		input[2] &= ~(1 << 5);
		goto node4472;
	}
node1463:
	b = false;
	if (b) {
		input[2] |= (1 << 3);
		return 0;
	} else {
		input[2] &= ~(1 << 3);
		goto node752;
	}
node7526:
	b = true;
	if (b) {
		input[4] |= (1 << 2);
		goto node3310;
	} else {
		input[4] &= ~(1 << 2);
		return 0;
	}
node7231:
	b = randbool();
	if (b) {
		input[5] |= (1 << 1);
		return 7;
	} else {
		input[5] &= ~(1 << 1);
		goto node7895;
	}
node2273:
	b = true;
	if (b) {
		input[1] |= (1 << 1);
		goto node3117;
	} else {
		input[1] &= ~(1 << 1);
		return 0;
	}
node3860:
	b = randbool();
	if (b) {
		input[1] |= (1 << 0);
		return 2;
	} else {
		input[1] &= ~(1 << 0);
		return 4;
	}
node5797:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node4848;
	} else {
		input[2] &= ~(1 << 3);
		goto node7859;
	}
node8576:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node1088;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node787:
	b = true;
	if (b) {
		input[3] |= (1 << 6);
		goto node8565;
	} else {
		input[3] &= ~(1 << 6);
		return 0;
	}
node6768:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node3780;
	}
node3646:
	b = false;
	if (b) {
		input[6] |= (1 << 7);
		return 0;
	} else {
		input[6] &= ~(1 << 7);
		goto node2788;
	}
node6935:
	b = randbool();
	if (b) {
		input[6] |= (1 << 0);
		return 12;
	} else {
		input[6] &= ~(1 << 0);
		return 8;
	}
node6599:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node2306;
	}
node508:
	b = true;
	if (b) {
		input[3] |= (1 << 2);
		goto node2236;
	} else {
		input[3] &= ~(1 << 2);
		return 0;
	}
node5873:
	b = randbool();
	if (b) {
		input[4] |= (1 << 6);
		goto node3910;
	} else {
		input[4] &= ~(1 << 6);
		goto node8554;
	}
node8758:
	b = false;
	if (b) {
		input[4] |= (1 << 0);
		return 0;
	} else {
		input[4] &= ~(1 << 0);
		goto node2122;
	}
node2078:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node7598;
	}
node6570:
	b = true;
	if (b) {
		input[4] |= (1 << 5);
		goto node5934;
	} else {
		input[4] &= ~(1 << 5);
		return 0;
	}
node4935:
	b = randbool();
	if (b) {
		input[4] |= (1 << 4);
		goto node5280;
	} else {
		input[4] &= ~(1 << 4);
		goto node7913;
	}
node7595:
	b = false;
	if (b) {
		input[4] |= (1 << 3);
		return 0;
	} else {
		input[4] &= ~(1 << 3);
		goto node7164;
	}
node8477:
	b = false;
	if (b) {
		input[5] |= (1 << 7);
		return 0;
	} else {
		input[5] &= ~(1 << 7);
		goto node4207;
	}
node8740:
	b = randbool();
	if (b) {
		input[2] |= (1 << 7);
		goto node1360;
	} else {
		input[2] &= ~(1 << 7);
		goto node2539;
	}
node8147:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node1442;
	} else {
		input[2] &= ~(1 << 1);
		goto node117;
	}
node6356:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node2168;
	} else {
		input[3] &= ~(1 << 6);
		goto node3998;
	}
node8121:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node814;
	}
node5366:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node8899;
	}
node2851:
	b = false;
	if (b) {
		input[3] |= (1 << 0);
		return 0;
	} else {
		input[3] &= ~(1 << 0);
		goto node7848;
	}
node1989:
	b = randbool();
	if (b) {
		input[1] |= (1 << 3);
		goto node496;
	} else {
		input[1] &= ~(1 << 3);
		goto node6186;
	}
node2639:
	b = true;
	if (b) {
		input[2] |= (1 << 6);
		goto node3608;
	} else {
		input[2] &= ~(1 << 6);
		return 0;
	}
node2557:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node4753;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node2839:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node8793;
	} else {
		input[3] &= ~(1 << 7);
		goto node6512;
	}
node3959:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node7327;
	}
node897:
	b = true;
	if (b) {
		input[5] |= (1 << 3);
		goto node96;
	} else {
		input[5] &= ~(1 << 3);
		return 0;
	}
node5993:
	b = false;
	if (b) {
		input[1] |= (1 << 3);
		return 0;
	} else {
		input[1] &= ~(1 << 3);
		goto node3468;
	}
node2363:
	b = randbool();
	if (b) {
		input[1] |= (1 << 0);
		goto node9206;
	} else {
		input[1] &= ~(1 << 0);
		goto node2602;
	}
node5612:
	b = false;
	if (b) {
		input[2] |= (1 << 5);
		return 0;
	} else {
		input[2] &= ~(1 << 5);
		goto node2719;
	}
node140:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node5195;
	}
node3723:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node1418;
	} else {
		input[3] &= ~(1 << 4);
		goto node2438;
	}
node3291:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node8772;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node6253:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node3606;
	} else {
		input[3] &= ~(1 << 7);
		goto node4665;
	}
node7516:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node9107;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node1213:
	b = true;
	if (b) {
		input[0] |= (1 << 1);
		goto node2416;
	} else {
		input[0] &= ~(1 << 1);
		return 0;
	}
node5766:
	b = randbool();
	if (b) {
		input[1] |= (1 << 1);
		goto node1137;
	} else {
		input[1] &= ~(1 << 1);
		goto node1339;
	}
node8131:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node8841;
	} else {
		input[2] &= ~(1 << 4);
		goto node5855;
	}
node7630:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node556;
	} else {
		input[2] &= ~(1 << 4);
		goto node4882;
	}
node3509:
	b = false;
	if (b) {
		input[2] |= (1 << 3);
		return 0;
	} else {
		input[2] &= ~(1 << 3);
		goto node158;
	}
node1120:
	b = randbool();
	if (b) {
		input[2] |= (1 << 0);
		goto node7511;
	} else {
		input[2] &= ~(1 << 0);
		goto node8717;
	}
node9343:
	b = false;
	if (b) {
		input[4] |= (1 << 5);
		return 0;
	} else {
		input[4] &= ~(1 << 5);
		goto node8423;
	}
node7152:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node5892;
	} else {
		input[2] &= ~(1 << 2);
		goto node8465;
	}
node1787:
	b = false;
	if (b) {
		input[3] |= (1 << 6);
		return 0;
	} else {
		input[3] &= ~(1 << 6);
		goto node211;
	}
node2670:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node788;
	}
node4609:
	b = false;
	if (b) {
		input[2] |= (1 << 1);
		return 0;
	} else {
		input[2] &= ~(1 << 1);
		goto node3972;
	}
node4738:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node2799;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node6933:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node4692;
	} else {
		input[3] &= ~(1 << 7);
		goto node6538;
	}
node4103:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node8138;
	} else {
		input[3] &= ~(1 << 5);
		goto node3333;
	}
node1699:
	b = randbool();
	if (b) {
		input[4] |= (1 << 6);
		goto node4058;
	} else {
		input[4] &= ~(1 << 6);
		goto node8223;
	}
node1615:
	b = true;
	if (b) {
		input[5] |= (1 << 5);
		goto node7621;
	} else {
		input[5] &= ~(1 << 5);
		return 0;
	}
node2123:
	b = randbool();
	if (b) {
		input[1] |= (1 << 2);
		goto node1053;
	} else {
		input[1] &= ~(1 << 2);
		goto node3061;
	}
node1270:
	b = false;
	if (b) {
		input[2] |= (1 << 7);
		return 0;
	} else {
		input[2] &= ~(1 << 7);
		goto node7424;
	}
node8666:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node4946;
	} else {
		input[3] &= ~(1 << 5);
		goto node9254;
	}
node4706:
	b = true;
	if (b) {
		input[4] |= (1 << 5);
		goto node1291;
	} else {
		input[4] &= ~(1 << 5);
		return 0;
	}
node7180:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node1597;
	} else {
		input[2] &= ~(1 << 4);
		goto node2281;
	}
node5737:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node2130;
	} else {
		input[2] &= ~(1 << 4);
		goto node5247;
	}
node6136:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node9174;
	} else {
		input[2] &= ~(1 << 4);
		goto node4196;
	}
node8517:
	b = false;
	if (b) {
		input[2] |= (1 << 0);
		return 0;
	} else {
		input[2] &= ~(1 << 0);
		goto node7228;
	}
node7481:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node3294;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node3908:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node1848;
	}
node4060:
	b = true;
	if (b) {
		input[1] |= (1 << 0);
		goto node4468;
	} else {
		input[1] &= ~(1 << 0);
		return 0;
	}
node861:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node7005;
	} else {
		input[2] &= ~(1 << 4);
		goto node3509;
	}
node7656:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node6744;
	}
node5107:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node424;
	} else {
		input[3] &= ~(1 << 3);
		goto node3083;
	}
node5858:
	b = randbool();
	if (b) {
		input[4] |= (1 << 5);
		goto node653;
	} else {
		input[4] &= ~(1 << 5);
		goto node8706;
	}
node5075:
	b = randbool();
	if (b) {
		input[5] |= (1 << 7);
		goto node7849;
	} else {
		input[5] &= ~(1 << 7);
		goto node3970;
	}
node9109:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node3055;
	} else {
		input[3] &= ~(1 << 2);
		goto node1742;
	}
node276:
	b = true;
	if (b) {
		input[3] |= (1 << 1);
		goto node9261;
	} else {
		input[3] &= ~(1 << 1);
		return 0;
	}
node4325:
	b = false;
	if (b) {
		input[1] |= (1 << 6);
		return 0;
	} else {
		input[1] &= ~(1 << 6);
		goto node4455;
	}
node8419:
	b = false;
	if (b) {
		input[2] |= (1 << 6);
		return 0;
	} else {
		input[2] &= ~(1 << 6);
		goto node1922;
	}
node2715:
	b = true;
	if (b) {
		input[2] |= (1 << 2);
		goto node5143;
	} else {
		input[2] &= ~(1 << 2);
		return 0;
	}
node2070:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node1679;
	} else {
		input[2] &= ~(1 << 1);
		goto node7244;
	}
node4134:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node6447;
	} else {
		input[3] &= ~(1 << 7);
		goto node3218;
	}
node3433:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node7721;
	} else {
		input[3] &= ~(1 << 4);
		goto node2408;
	}
node5623:
	b = true;
	if (b) {
		input[4] |= (1 << 6);
		goto node6570;
	} else {
		input[4] &= ~(1 << 6);
		return 0;
	}
node7698:
	b = true;
	if (b) {
		input[4] |= (1 << 3);
		goto node4517;
	} else {
		input[4] &= ~(1 << 3);
		return 0;
	}
node3990:
	b = true;
	if (b) {
		input[4] |= (1 << 2);
		goto node9255;
	} else {
		input[4] &= ~(1 << 2);
		return 0;
	}
node3066:
	b = randbool();
	if (b) {
		input[1] |= (1 << 2);
		goto node2593;
	} else {
		input[1] &= ~(1 << 2);
		goto node7334;
	}
node1036:
	b = randbool();
	if (b) {
		input[1] |= (1 << 0);
		goto node7277;
	} else {
		input[1] &= ~(1 << 0);
		goto node7746;
	}
node2240:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node6735;
	} else {
		input[2] &= ~(1 << 6);
		goto node8775;
	}
node7790:
	b = randbool();
	if (b) {
		input[3] |= (1 << 1);
		goto node6194;
	} else {
		input[3] &= ~(1 << 1);
		goto node896;
	}
node5528:
	b = randbool();
	if (b) {
		input[3] |= (1 << 0);
		return 9;
	} else {
		input[3] &= ~(1 << 0);
		return 5;
	}
node8566:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node8599;
	} else {
		input[3] &= ~(1 << 3);
		goto node465;
	}
node2090:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node4735;
	} else {
		input[3] &= ~(1 << 2);
		goto node8279;
	}
node9417:
	b = randbool();
	if (b) {
		input[1] |= (1 << 1);
		goto node9366;
	} else {
		input[1] &= ~(1 << 1);
		goto node4966;
	}
node341:
	b = randbool();
	if (b) {
		input[1] |= (1 << 0);
		goto node3242;
	} else {
		input[1] &= ~(1 << 0);
		goto node3277;
	}
node6047:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node5949;
	} else {
		input[2] &= ~(1 << 6);
		goto node4428;
	}
node507:
	b = true;
	if (b) {
		input[3] |= (1 << 6);
		goto node2305;
	} else {
		input[3] &= ~(1 << 6);
		return 0;
	}
node926:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node159;
	} else {
		input[3] &= ~(1 << 4);
		goto node8546;
	}
node2053:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node3083;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node6311:
	b = randbool();
	if (b) {
		input[0] |= (1 << 1);
		goto node82;
	} else {
		input[0] &= ~(1 << 1);
		goto node2184;
	}
node8694:
	b = randbool();
	if (b) {
		input[1] |= (1 << 0);
		goto node4830;
	} else {
		input[1] &= ~(1 << 0);
		goto node9236;
	}
node9203:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node172;
	}
node2966:
	b = true;
	if (b) {
		input[2] |= (1 << 3);
		goto node7980;
	} else {
		input[2] &= ~(1 << 3);
		return 0;
	}
node9288:
	b = false;
	if (b) {
		input[3] |= (1 << 2);
		return 0;
	} else {
		input[3] &= ~(1 << 2);
		goto node6927;
	}
node3472:
	b = true;
	if (b) {
		input[3] |= (1 << 2);
		goto node244;
	} else {
		input[3] &= ~(1 << 2);
		return 0;
	}
node5245:
	b = false;
	if (b) {
		input[2] |= (1 << 6);
		return 0;
	} else {
		input[2] &= ~(1 << 6);
		goto node8460;
	}
node5034:
	b = randbool();
	if (b) {
		input[2] |= (1 << 0);
		goto node3799;
	} else {
		input[2] &= ~(1 << 0);
		goto node5345;
	}
node691:
	b = false;
	if (b) {
		input[3] |= (1 << 6);
		return 0;
	} else {
		input[3] &= ~(1 << 6);
		goto node8735;
	}
node1032:
	b = randbool();
	if (b) {
		input[2] |= (1 << 0);
		goto node3799;
	} else {
		input[2] &= ~(1 << 0);
		goto node5992;
	}
node6587:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node668;
	} else {
		input[3] &= ~(1 << 7);
		goto node6646;
	}
node200:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node7048;
	} else {
		input[3] &= ~(1 << 7);
		goto node3837;
	}
node4597:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node3063;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node5273:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node36;
	} else {
		input[3] &= ~(1 << 3);
		goto node871;
	}
node4887:
	b = false;
	if (b) {
		input[4] |= (1 << 7);
		return 0;
	} else {
		input[4] &= ~(1 << 7);
		goto node3482;
	}
node880:
	b = randbool();
	if (b) {
		input[1] |= (1 << 0);
		goto node6186;
	} else {
		input[1] &= ~(1 << 0);
		return 2;
	}
node5994:
	b = true;
	if (b) {
		input[2] |= (1 << 6);
		goto node1672;
	} else {
		input[2] &= ~(1 << 6);
		return 0;
	}
node1456:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node4626;
	} else {
		input[2] &= ~(1 << 2);
		goto node248;
	}
node7144:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		goto node1685;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node7472:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node3841;
	}
node2480:
	b = randbool();
	if (b) {
		input[3] |= (1 << 1);
		goto node6671;
	} else {
		input[3] &= ~(1 << 1);
		goto node8380;
	}
node6955:
	b = false;
	if (b) {
		input[2] |= (1 << 3);
		return 0;
	} else {
		input[2] &= ~(1 << 3);
		goto node5526;
	}
node8835:
	b = true;
	if (b) {
		input[3] |= (1 << 0);
		goto node7893;
	} else {
		input[3] &= ~(1 << 0);
		return 0;
	}
node2673:
	b = randbool();
	if (b) {
		input[5] |= (1 << 5);
		goto node2235;
	} else {
		input[5] &= ~(1 << 5);
		goto node5645;
	}
node9222:
	b = randbool();
	if (b) {
		input[1] |= (1 << 6);
		goto node5274;
	} else {
		input[1] &= ~(1 << 6);
		goto node3659;
	}
node3618:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node6082;
	} else {
		input[3] &= ~(1 << 3);
		goto node264;
	}
node4533:
	b = false;
	if (b) {
		input[4] |= (1 << 3);
		return 0;
	} else {
		input[4] &= ~(1 << 3);
		goto node1019;
	}
node7547:
	b = true;
	if (b) {
		input[4] |= (1 << 3);
		goto node8463;
	} else {
		input[4] &= ~(1 << 3);
		return 0;
	}
node5909:
	b = true;
	if (b) {
		input[4] |= (1 << 2);
		goto node8481;
	} else {
		input[4] &= ~(1 << 2);
		return 0;
	}
node5438:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node4970;
	} else {
		input[2] &= ~(1 << 4);
		goto node5976;
	}
node5678:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node6626;
	} else {
		input[2] &= ~(1 << 3);
		goto node4642;
	}
node1757:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node1084;
	} else {
		input[2] &= ~(1 << 2);
		goto node4733;
	}
node817:
	b = true;
	if (b) {
		input[2] |= (1 << 2);
		goto node621;
	} else {
		input[2] &= ~(1 << 2);
		return 0;
	}
node7026:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node6180;
	}
node311:
	b = randbool();
	if (b) {
		input[5] |= (1 << 6);
		goto node9327;
	} else {
		input[5] &= ~(1 << 6);
		goto node6640;
	}
node6453:
	b = false;
	if (b) {
		input[2] |= (1 << 1);
		return 0;
	} else {
		input[2] &= ~(1 << 1);
		goto node8585;
	}
node6957:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node1386;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node5583:
	b = true;
	if (b) {
		input[3] |= (1 << 2);
		goto node2600;
	} else {
		input[3] &= ~(1 << 2);
		return 0;
	}
node4605:
	b = randbool();
	if (b) {
		input[3] |= (1 << 1);
		goto node5983;
	} else {
		input[3] &= ~(1 << 1);
		goto node3050;
	}
node2348:
	b = randbool();
	if (b) {
		input[1] |= (1 << 3);
		goto node8639;
	} else {
		input[1] &= ~(1 << 3);
		goto node4742;
	}
node8176:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node5214;
	} else {
		input[2] &= ~(1 << 5);
		goto node8355;
	}
node9159:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node3237;
	} else {
		input[3] &= ~(1 << 2);
		goto node2600;
	}
node1803:
	b = randbool();
	if (b) {
		input[1] |= (1 << 0);
		goto node8752;
	} else {
		input[1] &= ~(1 << 0);
		goto node9104;
	}
node3113:
	b = true;
	if (b) {
		input[2] |= (1 << 7);
		goto node6614;
	} else {
		input[2] &= ~(1 << 7);
		return 0;
	}
node615:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node7908;
	} else {
		input[2] &= ~(1 << 5);
		goto node2130;
	}
node6790:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node2650;
	}
node226:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node8933;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node6569:
	b = false;
	if (b) {
		input[3] |= (1 << 2);
		return 0;
	} else {
		input[3] &= ~(1 << 2);
		goto node5506;
	}
node6689:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node4761;
	} else {
		input[2] &= ~(1 << 3);
		goto node6553;
	}
node3355:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node4697;
	} else {
		input[3] &= ~(1 << 3);
		goto node6382;
	}
node4153:
	b = randbool();
	if (b) {
		input[4] |= (1 << 4);
		goto node875;
	} else {
		input[4] &= ~(1 << 4);
		goto node8440;
	}
node7913:
	b = true;
	if (b) {
		input[4] |= (1 << 3);
		goto node9313;
	} else {
		input[4] &= ~(1 << 3);
		return 0;
	}
node8332:
	b = randbool();
	if (b) {
		input[4] |= (1 << 0);
		goto node7203;
	} else {
		input[4] &= ~(1 << 0);
		goto node2279;
	}
node162:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node4879;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node6228:
	b = randbool();
	if (b) {
		input[4] |= (1 << 4);
		goto node3728;
	} else {
		input[4] &= ~(1 << 4);
		goto node3604;
	}
node7469:
	b = randbool();
	if (b) {
		input[0] |= (1 << 2);
		return 1;
	} else {
		input[0] &= ~(1 << 2);
		goto node1117;
	}
node2953:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node9338;
	} else {
		input[2] &= ~(1 << 6);
		goto node4638;
	}
node3797:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node429;
	} else {
		input[2] &= ~(1 << 5);
		goto node6223;
	}
node8930:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node1180;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node348:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node4557;
	} else {
		input[3] &= ~(1 << 3);
		goto node6210;
	}
node9452:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node5011;
	}
node3805:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node5659;
	} else {
		input[2] &= ~(1 << 4);
		goto node8999;
	}
node1840:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node7608;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node6786:
	b = randbool();
	if (b) {
		input[1] |= (1 << 6);
		goto node2047;
	} else {
		input[1] &= ~(1 << 6);
		goto node7001;
	}
node5969:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node3533;
	} else {
		input[2] &= ~(1 << 6);
		goto node2080;
	}
node1406:
	b = true;
	if (b) {
		input[3] |= (1 << 1);
		goto node1656;
	} else {
		input[3] &= ~(1 << 1);
		return 0;
	}
node4482:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node4596;
	} else {
		input[3] &= ~(1 << 7);
		goto node4590;
	}
node1740:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node4777;
	} else {
		input[3] &= ~(1 << 5);
		return 5;
	}
node2005:
	b = randbool();
	if (b) {
		input[4] |= (1 << 5);
		goto node6687;
	} else {
		input[4] &= ~(1 << 5);
		goto node1863;
	}
node3966:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node8371;
	} else {
		input[3] &= ~(1 << 6);
		goto node261;
	}
node2794:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node8646;
	} else {
		input[3] &= ~(1 << 6);
		goto node791;
	}
node2470:
	b = randbool();
	if (b) {
		input[3] |= (1 << 1);
		goto node871;
	} else {
		input[3] &= ~(1 << 1);
		goto node3887;
	}
node5880:
	b = true;
	if (b) {
		input[3] |= (1 << 2);
		goto node2147;
	} else {
		input[3] &= ~(1 << 2);
		return 0;
	}
node647:
	b = false;
	if (b) {
		input[6] |= (1 << 0);
		return 0;
	} else {
		input[6] &= ~(1 << 0);
		goto node6205;
	}
node7001:
	b = randbool();
	if (b) {
		input[1] |= (1 << 5);
		goto node1650;
	} else {
		input[1] &= ~(1 << 5);
		goto node2892;
	}
node5691:
	b = false;
	if (b) {
		input[2] |= (1 << 3);
		return 0;
	} else {
		input[2] &= ~(1 << 3);
		goto node557;
	}
node7505:
	b = true;
	if (b) {
		input[2] |= (1 << 2);
		goto node6233;
	} else {
		input[2] &= ~(1 << 2);
		return 0;
	}
node5450:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node2225;
	} else {
		input[3] &= ~(1 << 6);
		goto node1041;
	}
node7865:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node5366;
	} else {
		input[3] &= ~(1 << 6);
		goto node6599;
	}
node5917:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node4921;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node5515:
	b = randbool();
	if (b) {
		input[1] |= (1 << 0);
		goto node7323;
	} else {
		input[1] &= ~(1 << 0);
		goto node5213;
	}
node2074:
	b = false;
	if (b) {
		input[2] |= (1 << 6);
		return 0;
	} else {
		input[2] &= ~(1 << 6);
		goto node19;
	}
node7761:
	b = true;
	if (b) {
		input[2] |= (1 << 2);
		goto node3735;
	} else {
		input[2] &= ~(1 << 2);
		return 0;
	}
node4752:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node6434;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node5470:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node4692;
	} else {
		input[3] &= ~(1 << 7);
		goto node6502;
	}
node6913:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node7156;
	} else {
		input[3] &= ~(1 << 2);
		goto node2694;
	}
node9347:
	b = false;
	if (b) {
		input[3] |= (1 << 2);
		return 0;
	} else {
		input[3] &= ~(1 << 2);
		goto node7098;
	}
node6998:
	b = true;
	if (b) {
		input[3] |= (1 << 6);
		goto node8915;
	} else {
		input[3] &= ~(1 << 6);
		return 0;
	}
node8373:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node6749;
	} else {
		input[3] &= ~(1 << 5);
		goto node8653;
	}
node3930:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node5621;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node5297:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node5774;
	}
node5196:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node8268;
	}
node3035:
	b = true;
	if (b) {
		input[2] |= (1 << 4);
		goto node7615;
	} else {
		input[2] &= ~(1 << 4);
		return 0;
	}
node4728:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node4396;
	} else {
		input[2] &= ~(1 << 3);
		goto node717;
	}
node4263:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node8339;
	} else {
		input[3] &= ~(1 << 7);
		goto node925;
	}
node5637:
	b = randbool();
	if (b) {
		input[2] |= (1 << 0);
		goto node6084;
	} else {
		input[2] &= ~(1 << 0);
		goto node1204;
	}
node4474:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node2720;
	} else {
		input[3] &= ~(1 << 7);
		goto node7370;
	}
node261:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node2358;
	} else {
		input[3] &= ~(1 << 5);
		goto node1424;
	}
node5048:
	b = true;
	if (b) {
		input[4] |= (1 << 3);
		goto node8224;
	} else {
		input[4] &= ~(1 << 3);
		return 0;
	}
node8735:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node4827;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node7141:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node2521;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node8107:
	b = randbool();
	if (b) {
		input[3] |= (1 << 1);
		goto node5029;
	} else {
		input[3] &= ~(1 << 1);
		goto node8439;
	}
node4423:
	b = randbool();
	if (b) {
		input[1] |= (1 << 2);
		goto node1931;
	} else {
		input[1] &= ~(1 << 2);
		goto node8682;
	}
node7455:
	b = false;
	if (b) {
		input[2] |= (1 << 7);
		return 0;
	} else {
		input[2] &= ~(1 << 7);
		goto node4737;
	}
node7004:
	b = true;
	if (b) {
		input[2] |= (1 << 3);
		goto node7509;
	} else {
		input[2] &= ~(1 << 3);
		return 0;
	}
node2263:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		goto node7522;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node8325:
	b = true;
	if (b) {
		input[3] |= (1 << 6);
		goto node4911;
	} else {
		input[3] &= ~(1 << 6);
		return 0;
	}
node3077:
	b = false;
	if (b) {
		input[3] |= (1 << 0);
		return 0;
	} else {
		input[3] &= ~(1 << 0);
		goto node5535;
	}
node5496:
	b = true;
	if (b) {
		input[4] |= (1 << 6);
		goto node7772;
	} else {
		input[4] &= ~(1 << 6);
		return 0;
	}
node2344:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node4086;
	} else {
		input[2] &= ~(1 << 5);
		goto node1303;
	}
node5874:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node8937;
	} else {
		input[2] &= ~(1 << 5);
		goto node8103;
	}
node9258:
	b = true;
	if (b) {
		input[3] |= (1 << 6);
		goto node2419;
	} else {
		input[3] &= ~(1 << 6);
		return 0;
	}
node1941:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node2458;
	} else {
		input[3] &= ~(1 << 4);
		goto node2358;
	}
node9185:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node8006;
	}
node1746:
	b = randbool();
	if (b) {
		input[3] |= (1 << 1);
		goto node3808;
	} else {
		input[3] &= ~(1 << 1);
		goto node3520;
	}
node9045:
	b = true;
	if (b) {
		input[1] |= (1 << 0);
		goto node8902;
	} else {
		input[1] &= ~(1 << 0);
		return 0;
	}
node5763:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node2641;
	}
node6357:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node3546;
	} else {
		input[3] &= ~(1 << 4);
		goto node5826;
	}
node240:
	b = randbool();
	if (b) {
		input[1] |= (1 << 3);
		goto node3688;
	} else {
		input[1] &= ~(1 << 3);
		goto node5910;
	}
node7820:
	b = true;
	if (b) {
		input[2] |= (1 << 5);
		goto node7120;
	} else {
		input[2] &= ~(1 << 5);
		return 0;
	}
node3853:
	b = true;
	if (b) {
		input[2] |= (1 << 3);
		goto node585;
	} else {
		input[2] &= ~(1 << 3);
		return 0;
	}
node2000:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node2392;
	} else {
		input[3] &= ~(1 << 5);
		goto node7697;
	}
node942:
	b = false;
	if (b) {
		input[2] |= (1 << 5);
		return 0;
	} else {
		input[2] &= ~(1 << 5);
		goto node3961;
	}
node6411:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node4211;
	} else {
		input[2] &= ~(1 << 3);
		goto node6553;
	}
node1817:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node7873;
	} else {
		input[3] &= ~(1 << 7);
		goto node9472;
	}
node3925:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node9385;
	} else {
		input[3] &= ~(1 << 4);
		goto node6284;
	}
node4906:
	b = false;
	if (b) {
		input[4] |= (1 << 4);
		return 0;
	} else {
		input[4] &= ~(1 << 4);
		goto node1920;
	}
node5924:
	b = false;
	if (b) {
		input[1] |= (1 << 3);
		return 0;
	} else {
		input[1] &= ~(1 << 3);
		return 2;
	}
node6885:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node8017;
	}
node149:
	b = true;
	if (b) {
		input[2] |= (1 << 4);
		goto node8931;
	} else {
		input[2] &= ~(1 << 4);
		return 0;
	}
node6098:
	b = true;
	if (b) {
		input[3] |= (1 << 6);
		goto node1279;
	} else {
		input[3] &= ~(1 << 6);
		return 0;
	}
node250:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node7538;
	} else {
		input[3] &= ~(1 << 5);
		goto node7539;
	}
node8416:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node3593;
	} else {
		input[3] &= ~(1 << 4);
		goto node2420;
	}
node3348:
	b = randbool();
	if (b) {
		input[1] |= (1 << 4);
		goto node1802;
	} else {
		input[1] &= ~(1 << 4);
		goto node7927;
	}
node5152:
	b = false;
	if (b) {
		input[2] |= (1 << 6);
		return 0;
	} else {
		input[2] &= ~(1 << 6);
		goto node2990;
	}
node2223:
	b = true;
	if (b) {
		input[2] |= (1 << 5);
		goto node9374;
	} else {
		input[2] &= ~(1 << 5);
		return 0;
	}
node7093:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node196;
	} else {
		input[3] &= ~(1 << 5);
		goto node3779;
	}
node6805:
	b = true;
	if (b) {
		input[3] |= (1 << 1);
		goto node7884;
	} else {
		input[3] &= ~(1 << 1);
		return 0;
	}
node8020:
	b = false;
	if (b) {
		input[1] |= (1 << 2);
		return 0;
	} else {
		input[1] &= ~(1 << 2);
		goto node4983;
	}
node3184:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node6471;
	} else {
		input[3] &= ~(1 << 7);
		goto node8287;
	}
node4551:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node5155;
	} else {
		input[3] &= ~(1 << 6);
		goto node3317;
	}
node2437:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node4877;
	}
node5318:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		return 4;
	} else {
		input[3] &= ~(1 << 4);
		goto node5877;
	}
node6195:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node4374;
	} else {
		input[2] &= ~(1 << 6);
		goto node2412;
	}
node1562:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node1342;
	} else {
		input[3] &= ~(1 << 6);
		goto node8532;
	}
node3406:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node4130;
	}
node8580:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node4164;
	} else {
		input[3] &= ~(1 << 2);
		goto node9475;
	}
node6752:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node3660;
	} else {
		input[3] &= ~(1 << 2);
		goto node1126;
	}
node1643:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node165;
	}
node1492:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node535;
	} else {
		input[2] &= ~(1 << 1);
		goto node3051;
	}
node4063:
	b = false;
	if (b) {
		input[3] |= (1 << 6);
		return 0;
	} else {
		input[3] &= ~(1 << 6);
		goto node6116;
	}
node1582:
	b = true;
	if (b) {
		input[1] |= (1 << 1);
		goto node4540;
	} else {
		input[1] &= ~(1 << 1);
		return 0;
	}
node4701:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node3574;
	}
node6806:
	b = randbool();
	if (b) {
		input[4] |= (1 << 6);
		goto node34;
	} else {
		input[4] &= ~(1 << 6);
		goto node3368;
	}
node255:
	b = randbool();
	if (b) {
		input[3] |= (1 << 0);
		return 10;
	} else {
		input[3] &= ~(1 << 0);
		return 6;
	}
node697:
	b = false;
	if (b) {
		input[4] |= (1 << 1);
		return 0;
	} else {
		input[4] &= ~(1 << 1);
		goto node280;
	}
node3234:
	b = randbool();
	if (b) {
		input[0] |= (1 << 2);
		goto node2455;
	} else {
		input[0] &= ~(1 << 2);
		return 1;
	}
node8470:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node5462;
	} else {
		input[2] &= ~(1 << 5);
		goto node6032;
	}
node8947:
	b = false;
	if (b) {
		input[2] |= (1 << 1);
		return 0;
	} else {
		input[2] &= ~(1 << 1);
		goto node4807;
	}
node595:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node2427;
	} else {
		input[3] &= ~(1 << 4);
		goto node9467;
	}
node1329:
	b = true;
	if (b) {
		input[1] |= (1 << 6);
		goto node8662;
	} else {
		input[1] &= ~(1 << 6);
		return 0;
	}
node4690:
	b = true;
	if (b) {
		input[1] |= (1 << 6);
		return 2;
	} else {
		input[1] &= ~(1 << 6);
		return 0;
	}
node7298:
	b = false;
	if (b) {
		input[1] |= (1 << 3);
		return 0;
	} else {
		input[1] &= ~(1 << 3);
		goto node3066;
	}
node2307:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node6670;
	} else {
		input[2] &= ~(1 << 2);
		goto node847;
	}
node8783:
	b = false;
	if (b) {
		input[3] |= (1 << 1);
		return 0;
	} else {
		input[3] &= ~(1 << 1);
		goto node382;
	}
node9454:
	b = true;
	if (b) {
		input[4] |= (1 << 5);
		goto node4922;
	} else {
		input[4] &= ~(1 << 5);
		return 0;
	}
node3789:
	b = randbool();
	if (b) {
		input[1] |= (1 << 6);
		goto node201;
	} else {
		input[1] &= ~(1 << 6);
		goto node2971;
	}
node6319:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node6462;
	} else {
		input[3] &= ~(1 << 3);
		goto node3498;
	}
node3711:
	b = randbool();
	if (b) {
		input[4] |= (1 << 6);
		goto node3990;
	} else {
		input[4] &= ~(1 << 6);
		goto node467;
	}
node2805:
	b = true;
	if (b) {
		input[2] |= (1 << 2);
		goto node5183;
	} else {
		input[2] &= ~(1 << 2);
		return 0;
	}
node4913:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node3293;
	} else {
		input[3] &= ~(1 << 4);
		goto node2635;
	}
node4445:
	b = false;
	if (b) {
		input[3] |= (1 << 0);
		return 0;
	} else {
		input[3] &= ~(1 << 0);
		return 5;
	}
node6446:
	b = false;
	if (b) {
		input[1] |= (1 << 1);
		return 0;
	} else {
		input[1] &= ~(1 << 1);
		goto node1898;
	}
node5465:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node3311;
	} else {
		input[3] &= ~(1 << 6);
		goto node2381;
	}
node3986:
	b = false;
	if (b) {
		input[3] |= (1 << 2);
		return 0;
	} else {
		input[3] &= ~(1 << 2);
		goto node3977;
	}
node6241:
	b = false;
	if (b) {
		input[2] |= (1 << 5);
		return 0;
	} else {
		input[2] &= ~(1 << 5);
		goto node2607;
	}
node8584:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node2446;
	} else {
		input[2] &= ~(1 << 4);
		goto node5797;
	}
node8394:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node863;
	} else {
		input[3] &= ~(1 << 7);
		goto node5652;
	}
node4056:
	b = true;
	if (b) {
		input[4] |= (1 << 6);
		goto node3407;
	} else {
		input[4] &= ~(1 << 6);
		return 0;
	}
node8964:
	b = randbool();
	if (b) {
		input[4] |= (1 << 5);
		goto node8667;
	} else {
		input[4] &= ~(1 << 5);
		goto node7213;
	}
node8087:
	b = false;
	if (b) {
		input[4] |= (1 << 2);
		return 0;
	} else {
		input[4] &= ~(1 << 2);
		goto node81;
	}
node783:
	b = randbool();
	if (b) {
		input[1] |= (1 << 4);
		goto node5070;
	} else {
		input[1] &= ~(1 << 4);
		goto node6533;
	}
node7973:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		goto node6187;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node3766:
	b = randbool();
	if (b) {
		input[3] |= (1 << 1);
		goto node6220;
	} else {
		input[3] &= ~(1 << 1);
		goto node3520;
	}
node8022:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node942;
	} else {
		input[2] &= ~(1 << 6);
		goto node4353;
	}
node2283:
	b = true;
	if (b) {
		input[3] |= (1 << 7);
		goto node6112;
	} else {
		input[3] &= ~(1 << 7);
		return 0;
	}
node2988:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node6362;
	}
node8899:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node2507;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node7462:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node4316;
	} else {
		input[3] &= ~(1 << 2);
		goto node3520;
	}
node6348:
	b = false;
	if (b) {
		input[4] |= (1 << 2);
		return 0;
	} else {
		input[4] &= ~(1 << 2);
		goto node8305;
	}
node8873:
	b = false;
	if (b) {
		input[3] |= (1 << 2);
		return 0;
	} else {
		input[3] &= ~(1 << 2);
		goto node9360;
	}
node9273:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node2203;
	} else {
		input[3] &= ~(1 << 5);
		goto node8871;
	}
node9056:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node2121;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node3346:
	b = false;
	if (b) {
		input[4] |= (1 << 3);
		return 0;
	} else {
		input[4] &= ~(1 << 3);
		goto node8359;
	}
node8183:
	b = randbool();
	if (b) {
		input[1] |= (1 << 4);
		goto node5924;
	} else {
		input[1] &= ~(1 << 4);
		goto node7577;
	}
node5843:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node6595;
	} else {
		input[2] &= ~(1 << 4);
		goto node7887;
	}
node748:
	b = randbool();
	if (b) {
		input[2] |= (1 << 0);
		goto node8834;
	} else {
		input[2] &= ~(1 << 0);
		goto node1323;
	}
node9136:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node214;
	} else {
		input[3] &= ~(1 << 5);
		goto node780;
	}
node8134:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node5107;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node532:
	b = true;
	if (b) {
		input[3] |= (1 << 0);
		goto node6504;
	} else {
		input[3] &= ~(1 << 0);
		return 0;
	}
node2215:
	b = false;
	if (b) {
		input[4] |= (1 << 2);
		return 0;
	} else {
		input[4] &= ~(1 << 2);
		goto node8082;
	}
node3632:
	b = randbool();
	if (b) {
		input[1] |= (1 << 3);
		goto node5771;
	} else {
		input[1] &= ~(1 << 3);
		goto node5113;
	}
node7812:
	b = randbool();
	if (b) {
		input[2] |= (1 << 7);
		goto node3790;
	} else {
		input[2] &= ~(1 << 7);
		goto node2691;
	}
node6861:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node7255;
	} else {
		input[2] &= ~(1 << 4);
		goto node3521;
	}
node8275:
	b = true;
	if (b) {
		input[2] |= (1 << 2);
		goto node117;
	} else {
		input[2] &= ~(1 << 2);
		return 0;
	}
node2467:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node5494;
	} else {
		input[3] &= ~(1 << 5);
		goto node3550;
	}
node4547:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node5745;
	} else {
		input[3] &= ~(1 << 5);
		goto node1623;
	}
node2331:
	b = false;
	if (b) {
		input[3] |= (1 << 1);
		return 0;
	} else {
		input[3] &= ~(1 << 1);
		goto node927;
	}
node7346:
	b = randbool();
	if (b) {
		input[1] |= (1 << 1);
		goto node5827;
	} else {
		input[1] &= ~(1 << 1);
		goto node8048;
	}
node4382:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node6480;
	} else {
		input[2] &= ~(1 << 3);
		goto node3629;
	}
node5687:
	b = false;
	if (b) {
		input[2] |= (1 << 0);
		return 0;
	} else {
		input[2] &= ~(1 << 0);
		goto node8597;
	}
node3951:
	b = false;
	if (b) {
		input[3] |= (1 << 6);
		return 0;
	} else {
		input[3] &= ~(1 << 6);
		goto node4331;
	}
node3146:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node2243;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node2448:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node7632;
	} else {
		input[3] &= ~(1 << 3);
		goto node7362;
	}
node1636:
	b = randbool();
	if (b) {
		input[6] |= (1 << 1);
		return 7;
	} else {
		input[6] &= ~(1 << 1);
		goto node8125;
	}
node8990:
	b = randbool();
	if (b) {
		input[0] |= (1 << 2);
		return 1;
	} else {
		input[0] &= ~(1 << 2);
		goto node1242;
	}
node7355:
	b = true;
	if (b) {
		input[1] |= (1 << 1);
		goto node7267;
	} else {
		input[1] &= ~(1 << 1);
		return 0;
	}
node4421:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node7742;
	} else {
		input[2] &= ~(1 << 6);
		goto node4137;
	}
node5136:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node3617;
	} else {
		input[2] &= ~(1 << 4);
		goto node9130;
	}
node4904:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node2185;
	}
node2937:
	b = true;
	if (b) {
		input[3] |= (1 << 0);
		goto node8846;
	} else {
		input[3] &= ~(1 << 0);
		return 0;
	}
node648:
	b = randbool();
	if (b) {
		input[1] |= (1 << 1);
		goto node7514;
	} else {
		input[1] &= ~(1 << 1);
		goto node341;
	}
node3447:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node66;
	} else {
		input[2] &= ~(1 << 4);
		goto node7611;
	}
node7440:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		goto node2732;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node1645:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node451;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node6392:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node3486;
	} else {
		input[3] &= ~(1 << 3);
		goto node712;
	}
node254:
	b = false;
	if (b) {
		input[3] |= (1 << 2);
		return 0;
	} else {
		input[3] &= ~(1 << 2);
		goto node7825;
	}
node7470:
	b = false;
	if (b) {
		input[2] |= (1 << 2);
		return 0;
	} else {
		input[2] &= ~(1 << 2);
		goto node808;
	}
node8799:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node4244;
	}
node5862:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node5016;
	} else {
		input[3] &= ~(1 << 4);
		goto node1018;
	}
node711:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node3294;
	}
node6918:
	b = false;
	if (b) {
		input[4] |= (1 << 4);
		return 0;
	} else {
		input[4] &= ~(1 << 4);
		goto node841;
	}
node8490:
	b = false;
	if (b) {
		input[4] |= (1 << 3);
		return 0;
	} else {
		input[4] &= ~(1 << 3);
		goto node6903;
	}
node4923:
	b = randbool();
	if (b) {
		input[2] |= (1 << 0);
		goto node2282;
	} else {
		input[2] &= ~(1 << 0);
		goto node6246;
	}
node35:
	b = true;
	if (b) {
		input[3] |= (1 << 7);
		goto node1836;
	} else {
		input[3] &= ~(1 << 7);
		return 0;
	}
node4206:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node9406;
	} else {
		input[3] &= ~(1 << 7);
		goto node650;
	}
node2155:
	b = true;
	if (b) {
		input[3] |= (1 << 6);
		goto node5304;
	} else {
		input[3] &= ~(1 << 6);
		return 0;
	}
node8466:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node809;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node5904:
	b = randbool();
	if (b) {
		input[4] |= (1 << 4);
		goto node1748;
	} else {
		input[4] &= ~(1 << 4);
		goto node7547;
	}
node8364:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node4487;
	}
node3130:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node9376;
	}
node4302:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node2104;
	}
node4921:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node137;
	} else {
		input[3] &= ~(1 << 2);
		goto node5337;
	}
node7489:
	b = true;
	if (b) {
		input[4] |= (1 << 5);
		goto node1713;
	} else {
		input[4] &= ~(1 << 5);
		return 0;
	}
node946:
	b = randbool();
	if (b) {
		input[1] |= (1 << 1);
		goto node7341;
	} else {
		input[1] &= ~(1 << 1);
		goto node6186;
	}
node500:
	b = false;
	if (b) {
		input[2] |= (1 << 2);
		return 0;
	} else {
		input[2] &= ~(1 << 2);
		goto node6454;
	}
node7657:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node771;
	} else {
		input[3] &= ~(1 << 4);
		goto node5812;
	}
node4052:
	b = false;
	if (b) {
		input[4] |= (1 << 7);
		return 0;
	} else {
		input[4] &= ~(1 << 7);
		goto node6442;
	}
node4341:
	b = randbool();
	if (b) {
		input[4] |= (1 << 6);
		goto node6013;
	} else {
		input[4] &= ~(1 << 6);
		goto node2736;
	}
node2250:
	b = randbool();
	if (b) {
		input[6] |= (1 << 5);
		goto node1852;
	} else {
		input[6] &= ~(1 << 5);
		goto node8202;
	}
node7088:
	b = randbool();
	if (b) {
		input[4] |= (1 << 5);
		goto node2514;
	} else {
		input[4] &= ~(1 << 5);
		goto node4645;
	}
node4657:
	b = randbool();
	if (b) {
		input[1] |= (1 << 2);
		goto node9323;
	} else {
		input[1] &= ~(1 << 2);
		goto node676;
	}
node41:
	b = randbool();
	if (b) {
		input[1] |= (1 << 1);
		goto node8616;
	} else {
		input[1] &= ~(1 << 1);
		goto node6468;
	}
node7793:
	b = randbool();
	if (b) {
		input[1] |= (1 << 0);
		goto node103;
	} else {
		input[1] &= ~(1 << 0);
		goto node1270;
	}
node7844:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node2023;
	} else {
		input[2] &= ~(1 << 5);
		goto node6323;
	}
node3756:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node5988;
	} else {
		input[3] &= ~(1 << 5);
		goto node7412;
	}
node646:
	b = randbool();
	if (b) {
		input[4] |= (1 << 7);
		goto node2050;
	} else {
		input[4] &= ~(1 << 7);
		goto node2611;
	}
node5086:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node2139;
	}
node8530:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node3581;
	} else {
		input[2] &= ~(1 << 3);
		goto node7612;
	}
node5377:
	b = true;
	if (b) {
		input[4] |= (1 << 3);
		goto node742;
	} else {
		input[4] &= ~(1 << 3);
		return 0;
	}
node1292:
	b = false;
	if (b) {
		input[4] |= (1 << 2);
		return 0;
	} else {
		input[4] &= ~(1 << 2);
		goto node2027;
	}
node2034:
	b = true;
	if (b) {
		input[2] |= (1 << 2);
		goto node1751;
	} else {
		input[2] &= ~(1 << 2);
		return 0;
	}
node3174:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node780;
	}
node1139:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node1727;
	}
node6124:
	b = true;
	if (b) {
		input[4] |= (1 << 7);
		goto node6093;
	} else {
		input[4] &= ~(1 << 7);
		return 0;
	}
node5055:
	b = true;
	if (b) {
		input[4] |= (1 << 0);
		goto node9168;
	} else {
		input[4] &= ~(1 << 0);
		return 0;
	}
node1140:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node5747;
	} else {
		input[2] &= ~(1 << 5);
		goto node6632;
	}
node6557:
	b = false;
	if (b) {
		input[2] |= (1 << 3);
		return 0;
	} else {
		input[2] &= ~(1 << 3);
		goto node8702;
	}
node8302:
	b = randbool();
	if (b) {
		input[2] |= (1 << 0);
		return 4;
	} else {
		input[2] &= ~(1 << 0);
		goto node9432;
	}
node20:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node2107;
	} else {
		input[3] &= ~(1 << 6);
		goto node1875;
	}
node7624:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node1333;
	}
node4961:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node7632;
	} else {
		input[3] &= ~(1 << 3);
		goto node3755;
	}
node3246:
	b = randbool();
	if (b) {
		input[1] |= (1 << 1);
		goto node8418;
	} else {
		input[1] &= ~(1 << 1);
		goto node3484;
	}
node3100:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node2188;
	} else {
		input[2] &= ~(1 << 3);
		goto node8702;
	}
node3558:
	b = randbool();
	if (b) {
		input[2] |= (1 << 0);
		goto node1294;
	} else {
		input[2] &= ~(1 << 0);
		goto node3988;
	}
node6128:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node2739;
	}
node6268:
	b = randbool();
	if (b) {
		input[3] |= (1 << 0);
		return 7;
	} else {
		input[3] &= ~(1 << 0);
		goto node7843;
	}
node2376:
	b = randbool();
	if (b) {
		input[4] |= (1 << 3);
		goto node7777;
	} else {
		input[4] &= ~(1 << 3);
		goto node1794;
	}
node6624:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node356;
	}
node5573:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node5491;
	}
node1718:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node6508;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node7525:
	b = true;
	if (b) {
		input[3] |= (1 << 0);
		goto node9008;
	} else {
		input[3] &= ~(1 << 0);
		return 0;
	}
node3823:
	b = randbool();
	if (b) {
		input[4] |= (1 << 2);
		goto node8528;
	} else {
		input[4] &= ~(1 << 2);
		goto node5757;
	}
node694:
	b = false;
	if (b) {
		input[4] |= (1 << 1);
		return 0;
	} else {
		input[4] &= ~(1 << 1);
		goto node7203;
	}
node2395:
	b = true;
	if (b) {
		input[4] |= (1 << 7);
		goto node2727;
	} else {
		input[4] &= ~(1 << 7);
		return 0;
	}
node256:
	b = true;
	if (b) {
		input[4] |= (1 << 6);
		goto node1587;
	} else {
		input[4] &= ~(1 << 6);
		return 0;
	}
node1971:
	b = randbool();
	if (b) {
		input[1] |= (1 << 0);
		return 4;
	} else {
		input[1] &= ~(1 << 0);
		goto node4831;
	}
node4889:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node66;
	} else {
		input[2] &= ~(1 << 4);
		goto node7278;
	}
node9383:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node3799;
	} else {
		input[2] &= ~(1 << 3);
		goto node8171;
	}
node9446:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node3004;
	} else {
		input[3] &= ~(1 << 4);
		goto node1530;
	}
node264:
	b = true;
	if (b) {
		input[3] |= (1 << 2);
		goto node8157;
	} else {
		input[3] &= ~(1 << 2);
		return 0;
	}
node2236:
	b = false;
	if (b) {
		input[3] |= (1 << 1);
		return 0;
	} else {
		input[3] &= ~(1 << 1);
		goto node5100;
	}
node4525:
	b = false;
	if (b) {
		input[2] |= (1 << 6);
		return 0;
	} else {
		input[2] &= ~(1 << 6);
		goto node5612;
	}
node5912:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node93;
	} else {
		input[2] &= ~(1 << 4);
		goto node9018;
	}
node1465:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node3398;
	} else {
		input[2] &= ~(1 << 2);
		goto node190;
	}
node2418:
	b = randbool();
	if (b) {
		input[2] |= (1 << 0);
		goto node4283;
	} else {
		input[2] &= ~(1 << 0);
		goto node6908;
	}
node4411:
	b = false;
	if (b) {
		input[3] |= (1 << 2);
		return 0;
	} else {
		input[3] &= ~(1 << 2);
		goto node6303;
	}
node2085:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node2584;
	} else {
		input[3] &= ~(1 << 2);
		goto node2821;
	}
node7758:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node1627;
	} else {
		input[3] &= ~(1 << 5);
		goto node1146;
	}
node3495:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node4581;
	}
node183:
	b = randbool();
	if (b) {
		input[1] |= (1 << 7);
		goto node3789;
	} else {
		input[1] &= ~(1 << 7);
		goto node8352;
	}
node4205:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node889;
	} else {
		input[2] &= ~(1 << 6);
		goto node822;
	}
node4653:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node6301;
	} else {
		input[2] &= ~(1 << 6);
		goto node1368;
	}
node7755:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node8000;
	} else {
		input[2] &= ~(1 << 6);
		goto node6534;
	}
node4762:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		goto node8214;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node586:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node548;
	} else {
		input[3] &= ~(1 << 6);
		goto node7412;
	}
node8044:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node4380;
	} else {
		input[3] &= ~(1 << 4);
		goto node3520;
	}
node72:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node3255;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node7287:
	b = false;
	if (b) {
		input[3] |= (1 << 2);
		return 0;
	} else {
		input[3] &= ~(1 << 2);
		goto node8750;
	}
node3186:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node3727;
	} else {
		input[3] &= ~(1 << 2);
		goto node4044;
	}
node3446:
	b = true;
	if (b) {
		input[5] |= (1 << 3);
		goto node9230;
	} else {
		input[5] &= ~(1 << 3);
		return 0;
	}
node197:
	b = randbool();
	if (b) {
		input[1] |= (1 << 5);
		goto node9155;
	} else {
		input[1] &= ~(1 << 5);
		return 2;
	}
node4624:
	b = randbool();
	if (b) {
		input[1] |= (1 << 2);
		goto node7277;
	} else {
		input[1] &= ~(1 << 2);
		goto node9412;
	}
node84:
	b = true;
	if (b) {
		input[1] |= (1 << 0);
		goto node7395;
	} else {
		input[1] &= ~(1 << 0);
		return 0;
	}
node2973:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node534;
	} else {
		input[2] &= ~(1 << 3);
		goto node3863;
	}
node1537:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node1941;
	} else {
		input[3] &= ~(1 << 5);
		goto node1424;
	}
node8387:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node8776;
	} else {
		input[3] &= ~(1 << 5);
		goto node8101;
	}
node5076:
	b = false;
	if (b) {
		input[6] |= (1 << 1);
		return 0;
	} else {
		input[6] &= ~(1 << 1);
		goto node4019;
	}
node5166:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node137;
	} else {
		input[3] &= ~(1 << 3);
		goto node3091;
	}
node8828:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node5970;
	} else {
		input[3] &= ~(1 << 3);
		goto node873;
	}
node4149:
	b = randbool();
	if (b) {
		input[1] |= (1 << 7);
		goto node5730;
	} else {
		input[1] &= ~(1 << 7);
		goto node2018;
	}
node5428:
	b = true;
	if (b) {
		input[1] |= (1 << 2);
		goto node7704;
	} else {
		input[1] &= ~(1 << 2);
		return 0;
	}
node9085:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node3721;
	} else {
		input[2] &= ~(1 << 3);
		goto node2838;
	}
node4999:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node1631;
	} else {
		input[2] &= ~(1 << 2);
		goto node3378;
	}
node4772:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node7227;
	} else {
		input[2] &= ~(1 << 1);
		goto node3648;
	}
node7835:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node940;
	} else {
		input[3] &= ~(1 << 4);
		goto node5769;
	}
node5895:
	b = true;
	if (b) {
		input[4] |= (1 << 4);
		goto node990;
	} else {
		input[4] &= ~(1 << 4);
		return 0;
	}
node7839:
	b = false;
	if (b) {
		input[2] |= (1 << 7);
		return 0;
	} else {
		input[2] &= ~(1 << 7);
		goto node1671;
	}
node4721:
	b = randbool();
	if (b) {
		input[2] |= (1 << 7);
		goto node1357;
	} else {
		input[2] &= ~(1 << 7);
		goto node610;
	}
node6604:
	b = false;
	if (b) {
		input[2] |= (1 << 3);
		return 0;
	} else {
		input[2] &= ~(1 << 3);
		goto node3957;
	}
node2214:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node398;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node8507:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node9090;
	}
node8285:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node3391;
	} else {
		input[2] &= ~(1 << 2);
		goto node2187;
	}
node3753:
	b = false;
	if (b) {
		input[2] |= (1 << 2);
		return 0;
	} else {
		input[2] &= ~(1 << 2);
		goto node9425;
	}
node803:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node7105;
	} else {
		input[3] &= ~(1 << 3);
		goto node5022;
	}
node4085:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node5237;
	} else {
		input[2] &= ~(1 << 6);
		goto node9120;
	}
node6652:
	b = true;
	if (b) {
		input[2] |= (1 << 4);
		goto node4613;
	} else {
		input[2] &= ~(1 << 4);
		return 0;
	}
node6814:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node1847;
	} else {
		input[2] &= ~(1 << 1);
		goto node5787;
	}
node3705:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node3297;
	} else {
		input[2] &= ~(1 << 1);
		goto node7207;
	}
node464:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node4484;
	} else {
		input[3] &= ~(1 << 4);
		goto node334;
	}
node3593:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node9010;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node1247:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node8937;
	} else {
		input[2] &= ~(1 << 5);
		goto node5620;
	}
node1306:
	b = true;
	if (b) {
		input[4] |= (1 << 5);
		goto node5966;
	} else {
		input[4] &= ~(1 << 5);
		return 0;
	}
node295:
	b = false;
	if (b) {
		input[1] |= (1 << 3);
		return 0;
	} else {
		input[1] &= ~(1 << 3);
		goto node4795;
	}
node5002:
	b = false;
	if (b) {
		input[3] |= (1 << 2);
		return 0;
	} else {
		input[3] &= ~(1 << 2);
		goto node952;
	}
node9372:
	b = false;
	if (b) {
		input[3] |= (1 << 1);
		return 0;
	} else {
		input[3] &= ~(1 << 1);
		goto node5212;
	}
node2051:
	b = true;
	if (b) {
		input[4] |= (1 << 4);
		return 5;
	} else {
		input[4] &= ~(1 << 4);
		return 0;
	}
node9379:
	b = randbool();
	if (b) {
		input[5] |= (1 << 3);
		goto node2463;
	} else {
		input[5] &= ~(1 << 3);
		goto node1705;
	}
node8178:
	b = true;
	if (b) {
		input[4] |= (1 << 4);
		goto node2847;
	} else {
		input[4] &= ~(1 << 4);
		return 0;
	}
node3537:
	b = true;
	if (b) {
		input[2] |= (1 << 2);
		goto node6239;
	} else {
		input[2] &= ~(1 << 2);
		return 0;
	}
node3872:
	b = false;
	if (b) {
		input[2] |= (1 << 0);
		return 0;
	} else {
		input[2] &= ~(1 << 0);
		goto node6253;
	}
node6630:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node2711;
	} else {
		input[3] &= ~(1 << 4);
		goto node7970;
	}
node8522:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node6219;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node5643:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node8750;
	} else {
		input[3] &= ~(1 << 2);
		goto node1994;
	}
node4484:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node4960;
	} else {
		input[3] &= ~(1 << 3);
		goto node4864;
	}
node3879:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node7184;
	} else {
		input[3] &= ~(1 << 2);
		goto node3143;
	}
node6305:
	b = randbool();
	if (b) {
		input[1] |= (1 << 2);
		goto node1275;
	} else {
		input[1] &= ~(1 << 2);
		return 6;
	}
node8036:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node8446;
	} else {
		input[2] &= ~(1 << 6);
		goto node491;
	}
node3984:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node4091;
	}
node8355:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node1834;
	} else {
		input[2] &= ~(1 << 4);
		goto node6966;
	}
node1573:
	b = true;
	if (b) {
		input[2] |= (1 << 2);
		goto node3586;
	} else {
		input[2] &= ~(1 << 2);
		return 0;
	}
node3235:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node2722;
	} else {
		input[3] &= ~(1 << 3);
		goto node5668;
	}
node2802:
	b = randbool();
	if (b) {
		input[1] |= (1 << 4);
		goto node1132;
	} else {
		input[1] &= ~(1 << 4);
		goto node9198;
	}
node4463:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		goto node1968;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node8720:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node5188;
	} else {
		input[3] &= ~(1 << 5);
		goto node2330;
	}
node6086:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node2175;
	} else {
		input[3] &= ~(1 << 5);
		goto node3049;
	}
node3194:
	b = true;
	if (b) {
		input[4] |= (1 << 5);
		goto node4670;
	} else {
		input[4] &= ~(1 << 5);
		return 0;
	}
node5342:
	b = true;
	if (b) {
		input[6] |= (1 << 2);
		goto node8402;
	} else {
		input[6] &= ~(1 << 2);
		return 0;
	}
node1560:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node7543;
	} else {
		input[2] &= ~(1 << 4);
		goto node3544;
	}
node1297:
	b = false;
	if (b) {
		input[2] |= (1 << 0);
		return 0;
	} else {
		input[2] &= ~(1 << 0);
		goto node5434;
	}
node4516:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node2915;
	}
node8114:
	b = false;
	if (b) {
		input[3] |= (1 << 2);
		return 0;
	} else {
		input[3] &= ~(1 << 2);
		goto node3088;
	}
node1952:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node3833;
	} else {
		input[3] &= ~(1 << 6);
		goto node9055;
	}
node678:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node7375;
	} else {
		input[3] &= ~(1 << 5);
		goto node4760;
	}
node3018:
	b = true;
	if (b) {
		input[4] |= (1 << 5);
		goto node6329;
	} else {
		input[4] &= ~(1 << 5);
		return 0;
	}
node2031:
	b = true;
	if (b) {
		input[1] |= (1 << 0);
		goto node5696;
	} else {
		input[1] &= ~(1 << 0);
		return 0;
	}
node5204:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node8105;
	} else {
		input[3] &= ~(1 << 7);
		goto node8308;
	}
node4141:
	b = randbool();
	if (b) {
		input[1] |= (1 << 3);
		goto node5358;
	} else {
		input[1] &= ~(1 << 3);
		goto node592;
	}
node2068:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node8209;
	}
node1464:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node907;
	} else {
		input[2] &= ~(1 << 2);
		goto node266;
	}
node5276:
	b = true;
	if (b) {
		input[3] |= (1 << 2);
		goto node9469;
	} else {
		input[3] &= ~(1 << 2);
		return 0;
	}
node4077:
	b = randbool();
	if (b) {
		input[2] |= (1 << 0);
		goto node6501;
	} else {
		input[2] &= ~(1 << 0);
		goto node2190;
	}
node4119:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node4916;
	}
node8782:
	b = false;
	if (b) {
		input[3] |= (1 << 2);
		return 0;
	} else {
		input[3] &= ~(1 << 2);
		goto node765;
	}
node9469:
	b = true;
	if (b) {
		input[3] |= (1 << 1);
		goto node4444;
	} else {
		input[3] &= ~(1 << 1);
		return 0;
	}
node7047:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node3370;
	} else {
		input[2] &= ~(1 << 4);
		goto node3825;
	}
node829:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node5109;
	} else {
		input[3] &= ~(1 << 6);
		goto node5501;
	}
node3477:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node1542;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node4265:
	b = true;
	if (b) {
		input[3] |= (1 << 2);
		goto node2530;
	} else {
		input[3] &= ~(1 << 2);
		return 0;
	}
node371:
	b = false;
	if (b) {
		input[3] |= (1 << 0);
		return 0;
	} else {
		input[3] &= ~(1 << 0);
		goto node1819;
	}
node8326:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node7893;
	} else {
		input[3] &= ~(1 << 4);
		goto node8828;
	}
node618:
	b = false;
	if (b) {
		input[3] |= (1 << 0);
		return 0;
	} else {
		input[3] &= ~(1 << 0);
		goto node4732;
	}
node3221:
	b = true;
	if (b) {
		input[4] |= (1 << 3);
		goto node8375;
	} else {
		input[4] &= ~(1 << 3);
		return 0;
	}
node7204:
	b = false;
	if (b) {
		input[1] |= (1 << 4);
		return 0;
	} else {
		input[1] &= ~(1 << 4);
		goto node7610;
	}
node2641:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node2469;
	}
node8661:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node2289;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node4238:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node9209;
	} else {
		input[2] &= ~(1 << 5);
		goto node736;
	}
node3749:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node1448;
	} else {
		input[2] &= ~(1 << 4);
		goto node7409;
	}
node1686:
	b = false;
	if (b) {
		input[2] |= (1 << 0);
		return 0;
	} else {
		input[2] &= ~(1 << 0);
		goto node6887;
	}
node2850:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node6098;
	} else {
		input[3] &= ~(1 << 7);
		goto node6685;
	}
node8014:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node1122;
	}
node1767:
	b = true;
	if (b) {
		input[5] |= (1 << 5);
		goto node6163;
	} else {
		input[5] &= ~(1 << 5);
		return 0;
	}
node4152:
	b = true;
	if (b) {
		input[3] |= (1 << 2);
		goto node2522;
	} else {
		input[3] &= ~(1 << 2);
		return 0;
	}
node3591:
	b = false;
	if (b) {
		input[1] |= (1 << 2);
		return 0;
	} else {
		input[1] &= ~(1 << 2);
		goto node4035;
	}
node1944:
	b = true;
	if (b) {
		input[1] |= (1 << 2);
		goto node2901;
	} else {
		input[1] &= ~(1 << 2);
		return 0;
	}
node5526:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node85;
	} else {
		input[2] &= ~(1 << 2);
		goto node7440;
	}
node7244:
	b = randbool();
	if (b) {
		input[2] |= (1 << 0);
		goto node3812;
	} else {
		input[2] &= ~(1 << 0);
		goto node6111;
	}
node1901:
	b = false;
	if (b) {
		input[2] |= (1 << 0);
		return 0;
	} else {
		input[2] &= ~(1 << 0);
		goto node5345;
	}
node8297:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node5698;
	} else {
		input[3] &= ~(1 << 7);
		goto node8112;
	}
node9257:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node6374;
	}
node8768:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node728;
	} else {
		input[2] &= ~(1 << 2);
		goto node8946;
	}
node6187:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node2659;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node8494:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node6006;
	}
node2014:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node3266;
	} else {
		input[3] &= ~(1 << 2);
		goto node948;
	}
node257:
	b = randbool();
	if (b) {
		input[1] |= (1 << 6);
		goto node1545;
	} else {
		input[1] &= ~(1 << 6);
		goto node7051;
	}
node6286:
	b = false;
	if (b) {
		input[1] |= (1 << 5);
		return 0;
	} else {
		input[1] &= ~(1 << 5);
		goto node964;
	}
node2680:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node2583;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node873:
	b = true;
	if (b) {
		input[4] |= (1 << 7);
		goto node1153;
	} else {
		input[4] &= ~(1 << 7);
		return 0;
	}
node4616:
	b = randbool();
	if (b) {
		input[5] |= (1 << 5);
		goto node4198;
	} else {
		input[5] &= ~(1 << 5);
		goto node2463;
	}
node1242:
	b = true;
	if (b) {
		input[0] |= (1 << 1);
		goto node9348;
	} else {
		input[0] &= ~(1 << 1);
		return 0;
	}
node2312:
	b = false;
	if (b) {
		input[2] |= (1 << 5);
		return 0;
	} else {
		input[2] &= ~(1 << 5);
		goto node8432;
	}
node3928:
	b = false;
	if (b) {
		input[2] |= (1 << 3);
		return 0;
	} else {
		input[2] &= ~(1 << 3);
		goto node7201;
	}
node6900:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node1442;
	} else {
		input[2] &= ~(1 << 1);
		goto node851;
	}
node6313:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node994;
	} else {
		input[3] &= ~(1 << 7);
		goto node5900;
	}
node391:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node1190;
	}
node2251:
	b = randbool();
	if (b) {
		input[1] |= (1 << 6);
		goto node3782;
	} else {
		input[1] &= ~(1 << 6);
		goto node8668;
	}
node8869:
	b = randbool();
	if (b) {
		input[1] |= (1 << 0);
		goto node8734;
	} else {
		input[1] &= ~(1 << 0);
		goto node2515;
	}
node6349:
	b = true;
	if (b) {
		input[2] |= (1 << 6);
		goto node1403;
	} else {
		input[2] &= ~(1 << 6);
		return 0;
	}
node6161:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node7339;
	} else {
		input[3] &= ~(1 << 4);
		goto node2952;
	}
node8996:
	b = randbool();
	if (b) {
		input[4] |= (1 << 7);
		goto node3006;
	} else {
		input[4] &= ~(1 << 7);
		goto node5127;
	}
node139:
	b = true;
	if (b) {
		input[4] |= (1 << 3);
		goto node7983;
	} else {
		input[4] &= ~(1 << 3);
		return 0;
	}
node6169:
	b = randbool();
	if (b) {
		input[1] |= (1 << 1);
		goto node6186;
	} else {
		input[1] &= ~(1 << 1);
		goto node1898;
	}
node1483:
	b = false;
	if (b) {
		input[2] |= (1 << 3);
		return 0;
	} else {
		input[2] &= ~(1 << 3);
		goto node3937;
	}
node7825:
	b = randbool();
	if (b) {
		input[3] |= (1 << 1);
		goto node5492;
	} else {
		input[3] &= ~(1 << 1);
		goto node4453;
	}
node2163:
	b = randbool();
	if (b) {
		input[4] |= (1 << 6);
		goto node8327;
	} else {
		input[4] &= ~(1 << 6);
		goto node998;
	}
node4101:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node5747;
	} else {
		input[2] &= ~(1 << 5);
		goto node5762;
	}
node5798:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node3388;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node5047:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node7259;
	} else {
		input[3] &= ~(1 << 4);
		goto node9364;
	}
node3031:
	b = randbool();
	if (b) {
		input[6] |= (1 << 0);
		return 8;
	} else {
		input[6] &= ~(1 << 0);
		goto node8116;
	}
node9246:
	b = false;
	if (b) {
		input[1] |= (1 << 2);
		return 0;
	} else {
		input[1] &= ~(1 << 2);
		goto node724;
	}
node4497:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node6889;
	} else {
		input[3] &= ~(1 << 6);
		goto node9268;
	}
node5225:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node8873;
	} else {
		input[3] &= ~(1 << 3);
		goto node1688;
	}
node2876:
	b = false;
	if (b) {
		input[3] |= (1 << 0);
		return 0;
	} else {
		input[3] &= ~(1 << 0);
		goto node3873;
	}
node7662:
	b = true;
	if (b) {
		input[4] |= (1 << 6);
		goto node4798;
	} else {
		input[4] &= ~(1 << 6);
		return 0;
	}
node7926:
	b = false;
	if (b) {
		input[1] |= (1 << 4);
		return 0;
	} else {
		input[1] &= ~(1 << 4);
		goto node4110;
	}
node3430:
	b = false;
	if (b) {
		input[2] |= (1 << 2);
		return 0;
	} else {
		input[2] &= ~(1 << 2);
		goto node3331;
	}
node5248:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		goto node4286;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node3116:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node3558;
	} else {
		input[2] &= ~(1 << 1);
		goto node5613;
	}
node5392:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node6327;
	} else {
		input[3] &= ~(1 << 3);
		goto node5022;
	}
node2757:
	b = true;
	if (b) {
		input[3] |= (1 << 0);
		goto node2395;
	} else {
		input[3] &= ~(1 << 0);
		return 0;
	}
node1570:
	b = true;
	if (b) {
		input[1] |= (1 << 4);
		goto node1080;
	} else {
		input[1] &= ~(1 << 4);
		return 0;
	}
node51:
	b = true;
	if (b) {
		input[2] |= (1 << 6);
		goto node1866;
	} else {
		input[2] &= ~(1 << 6);
		return 0;
	}
node4845:
	b = randbool();
	if (b) {
		input[3] |= (1 << 1);
		goto node3345;
	} else {
		input[3] &= ~(1 << 1);
		goto node6220;
	}
node7480:
	b = false;
	if (b) {
		input[3] |= (1 << 6);
		return 0;
	} else {
		input[3] &= ~(1 << 6);
		goto node4272;
	}
node4007:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node8609;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node6054:
	b = true;
	if (b) {
		input[3] |= (1 << 2);
		goto node2903;
	} else {
		input[3] &= ~(1 << 2);
		return 0;
	}
node5833:
	b = false;
	if (b) {
		input[3] |= (1 << 1);
		return 0;
	} else {
		input[3] &= ~(1 << 1);
		goto node3050;
	}
node4035:
	b = false;
	if (b) {
		input[1] |= (1 << 1);
		return 0;
	} else {
		input[1] &= ~(1 << 1);
		goto node3437;
	}
node1239:
	b = false;
	if (b) {
		input[3] |= (1 << 6);
		return 0;
	} else {
		input[3] &= ~(1 << 6);
		goto node8502;
	}
node4336:
	b = false;
	if (b) {
		input[3] |= (1 << 0);
		return 0;
	} else {
		input[3] &= ~(1 << 0);
		goto node5411;
	}
node616:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node6073;
	} else {
		input[2] &= ~(1 << 3);
		goto node4239;
	}
node7508:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node7017;
	} else {
		input[2] &= ~(1 << 2);
		goto node2180;
	}
node4870:
	b = false;
	if (b) {
		input[2] |= (1 << 1);
		return 0;
	} else {
		input[2] &= ~(1 << 1);
		goto node273;
	}
node5992:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node8509;
	} else {
		input[3] &= ~(1 << 7);
		goto node3903;
	}
node3883:
	b = false;
	if (b) {
		input[4] |= (1 << 5);
		return 0;
	} else {
		input[4] &= ~(1 << 5);
		goto node6516;
	}
node1979:
	b = randbool();
	if (b) {
		input[1] |= (1 << 1);
		goto node8837;
	} else {
		input[1] &= ~(1 << 1);
		goto node6186;
	}
node6088:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node7261;
	} else {
		input[2] &= ~(1 << 4);
		goto node4258;
	}
node1666:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node3108;
	} else {
		input[2] &= ~(1 << 2);
		goto node9300;
	}
node6929:
	b = true;
	if (b) {
		input[4] |= (1 << 2);
		goto node4840;
	} else {
		input[4] &= ~(1 << 2);
		return 0;
	}
node5288:
	b = randbool();
	if (b) {
		input[1] |= (1 << 4);
		return 2;
	} else {
		input[1] &= ~(1 << 4);
		goto node3177;
	}
node7743:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node7887;
	} else {
		input[2] &= ~(1 << 3);
		goto node5899;
	}
node8027:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node3010;
	} else {
		input[3] &= ~(1 << 4);
		goto node686;
	}
node2836:
	b = false;
	if (b) {
		input[4] |= (1 << 2);
		return 0;
	} else {
		input[4] &= ~(1 << 2);
		goto node8955;
	}
node7000:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node4539;
	} else {
		input[3] &= ~(1 << 4);
		goto node9312;
	}
node2728:
	b = true;
	if (b) {
		input[4] |= (1 << 3);
		goto node6930;
	} else {
		input[4] &= ~(1 << 3);
		return 0;
	}
node1466:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node1269;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node2462:
	b = true;
	if (b) {
		input[4] |= (1 << 7);
		goto node306;
	} else {
		input[4] &= ~(1 << 7);
		return 0;
	}
node5419:
	b = false;
	if (b) {
		input[1] |= (1 << 5);
		return 0;
	} else {
		input[1] &= ~(1 << 5);
		goto node1755;
	}
node1061:
	b = randbool();
	if (b) {
		input[1] |= (1 << 5);
		goto node8385;
	} else {
		input[1] &= ~(1 << 5);
		goto node7496;
	}
node4114:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node4096;
	} else {
		input[2] &= ~(1 << 2);
		goto node4763;
	}
node3571:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node5268;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node6748:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node4635;
	} else {
		input[3] &= ~(1 << 7);
		goto node2914;
	}
node5851:
	b = true;
	if (b) {
		input[3] |= (1 << 6);
		goto node720;
	} else {
		input[3] &= ~(1 << 6);
		return 0;
	}
node6636:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node9210;
	}
node4472:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node1448;
	} else {
		input[2] &= ~(1 << 4);
		goto node5063;
	}
node3414:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node672;
	} else {
		input[2] &= ~(1 << 2);
		goto node2070;
	}
node5509:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node3028;
	} else {
		input[3] &= ~(1 << 7);
		goto node7696;
	}
node5871:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node2435;
	} else {
		input[3] &= ~(1 << 5);
		goto node9259;
	}
node3170:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node8873;
	} else {
		input[3] &= ~(1 << 3);
		goto node7833;
	}
node4327:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node5836;
	} else {
		input[2] &= ~(1 << 6);
		goto node8344;
	}
node6734:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node5605;
	} else {
		input[2] &= ~(1 << 6);
		goto node3198;
	}
node2174:
	b = false;
	if (b) {
		input[2] |= (1 << 3);
		return 0;
	} else {
		input[2] &= ~(1 << 3);
		goto node3806;
	}
node2920:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node6707;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node7688:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node7414;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node7736:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node5210;
	} else {
		input[3] &= ~(1 << 4);
		goto node2951;
	}
node5384:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node2319;
	} else {
		input[3] &= ~(1 << 5);
		goto node1469;
	}
node5688:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node8963;
	} else {
		input[3] &= ~(1 << 5);
		goto node4994;
	}
node8902:
	b = randbool();
	if (b) {
		input[2] |= (1 << 7);
		goto node5128;
	} else {
		input[2] &= ~(1 << 7);
		goto node4550;
	}
node8280:
	b = false;
	if (b) {
		input[2] |= (1 << 6);
		return 0;
	} else {
		input[2] &= ~(1 << 6);
		goto node4968;
	}
node1556:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node7974;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node9474:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node6637;
	} else {
		input[3] &= ~(1 << 2);
		goto node2600;
	}
node6462:
	b = randbool();
	if (b) {
		input[4] |= (1 << 7);
		goto node2727;
	} else {
		input[4] &= ~(1 << 7);
		goto node178;
	}
node1654:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node8444;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node596:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node6529;
	}
node2094:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node4407;
	} else {
		input[3] &= ~(1 << 7);
		goto node2443;
	}
node1480:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node8692;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node1326:
	b = false;
	if (b) {
		input[4] |= (1 << 4);
		return 0;
	} else {
		input[4] &= ~(1 << 4);
		goto node5158;
	}
node6895:
	b = true;
	if (b) {
		input[1] |= (1 << 0);
		goto node510;
	} else {
		input[1] &= ~(1 << 0);
		return 0;
	}
node2909:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node548;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node3033:
	b = false;
	if (b) {
		input[3] |= (1 << 0);
		return 0;
	} else {
		input[3] &= ~(1 << 0);
		goto node9077;
	}
node5242:
	b = true;
	if (b) {
		input[4] |= (1 << 4);
		goto node2409;
	} else {
		input[4] &= ~(1 << 4);
		return 0;
	}
node166:
	b = true;
	if (b) {
		input[2] |= (1 << 2);
		goto node4607;
	} else {
		input[2] &= ~(1 << 2);
		return 0;
	}
node8544:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node7265;
	}
node8784:
	b = randbool();
	if (b) {
		input[3] |= (1 << 1);
		goto node6504;
	} else {
		input[3] &= ~(1 << 1);
		goto node532;
	}
node7894:
	b = false;
	if (b) {
		input[4] |= (1 << 1);
		return 0;
	} else {
		input[4] &= ~(1 << 1);
		goto node2027;
	}
node3402:
	b = randbool();
	if (b) {
		input[2] |= (1 << 7);
		goto node3020;
	} else {
		input[2] &= ~(1 << 7);
		goto node8815;
	}
node5430:
	b = false;
	if (b) {
		input[2] |= (1 << 7);
		return 0;
	} else {
		input[2] &= ~(1 << 7);
		goto node1527;
	}
node9432:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node414;
	} else {
		input[3] &= ~(1 << 5);
		goto node2450;
	}
node3328:
	b = true;
	if (b) {
		input[1] |= (1 << 0);
		goto node9435;
	} else {
		input[1] &= ~(1 << 0);
		return 0;
	}
node4984:
	b = randbool();
	if (b) {
		input[2] |= (1 << 7);
		goto node2326;
	} else {
		input[2] &= ~(1 << 7);
		goto node9207;
	}
node6702:
	b = false;
	if (b) {
		input[3] |= (1 << 2);
		return 0;
	} else {
		input[3] &= ~(1 << 2);
		goto node7790;
	}
node7397:
	b = randbool();
	if (b) {
		input[3] |= (1 << 1);
		goto node6504;
	} else {
		input[3] &= ~(1 << 1);
		goto node441;
	}
node3131:
	b = true;
	if (b) {
		input[3] |= (1 << 2);
		goto node3088;
	} else {
		input[3] &= ~(1 << 2);
		return 0;
	}
node7799:
	b = false;
	if (b) {
		input[3] |= (1 << 2);
		return 0;
	} else {
		input[3] &= ~(1 << 2);
		goto node6940;
	}
node933:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node5458;
	} else {
		input[2] &= ~(1 << 4);
		goto node9018;
	}
node8367:
	b = randbool();
	if (b) {
		input[3] |= (1 << 0);
		goto node2171;
	} else {
		input[3] &= ~(1 << 0);
		goto node6037;
	}
node5473:
	b = true;
	if (b) {
		input[4] |= (1 << 5);
		goto node912;
	} else {
		input[4] &= ~(1 << 5);
		return 0;
	}
node4765:
	b = true;
	if (b) {
		input[3] |= (1 << 1);
		goto node108;
	} else {
		input[3] &= ~(1 << 1);
		return 0;
	}
node8223:
	b = randbool();
	if (b) {
		input[4] |= (1 << 5);
		goto node3865;
	} else {
		input[4] &= ~(1 << 5);
		goto node6941;
	}
node5194:
	b = true;
	if (b) {
		input[4] |= (1 << 3);
		goto node2782;
	} else {
		input[4] &= ~(1 << 3);
		return 0;
	}
node5387:
	b = randbool();
	if (b) {
		input[4] |= (1 << 2);
		goto node6185;
	} else {
		input[4] &= ~(1 << 2);
		goto node915;
	}
node4588:
	b = false;
	if (b) {
		input[1] |= (1 << 6);
		return 0;
	} else {
		input[1] &= ~(1 << 6);
		goto node2755;
	}
node3719:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node171;
	} else {
		input[2] &= ~(1 << 6);
		goto node1247;
	}
node7623:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node2777;
	} else {
		input[3] &= ~(1 << 6);
		goto node9097;
	}
node8192:
	b = true;
	if (b) {
		input[3] |= (1 << 6);
		goto node971;
	} else {
		input[3] &= ~(1 << 6);
		return 0;
	}
node4953:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node2589;
	} else {
		input[3] &= ~(1 << 5);
		goto node8899;
	}
node6352:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node2958;
	} else {
		input[3] &= ~(1 << 2);
		goto node1176;
	}
node5939:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node4768;
	} else {
		input[2] &= ~(1 << 6);
		goto node4443;
	}
node5234:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node8348;
	} else {
		input[3] &= ~(1 << 4);
		goto node1530;
	}
node9252:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node3886;
	} else {
		input[3] &= ~(1 << 3);
		goto node409;
	}
node6458:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node8599;
	} else {
		input[3] &= ~(1 << 3);
		goto node5983;
	}
node2584:
	b = false;
	if (b) {
		input[4] |= (1 << 7);
		return 0;
	} else {
		input[4] &= ~(1 << 7);
		goto node178;
	}
node6613:
	b = randbool();
	if (b) {
		input[1] |= (1 << 0);
		goto node42;
	} else {
		input[1] &= ~(1 << 0);
		goto node7277;
	}
node5167:
	b = randbool();
	if (b) {
		input[2] |= (1 << 7);
		goto node4275;
	} else {
		input[2] &= ~(1 << 7);
		goto node7989;
	}
node6441:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node7230;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node1705:
	b = true;
	if (b) {
		input[5] |= (1 << 2);
		goto node8110;
	} else {
		input[5] &= ~(1 << 2);
		return 0;
	}
node8319:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node6208;
	} else {
		input[2] &= ~(1 << 2);
		goto node9395;
	}
node4997:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node3419;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node7863:
	b = true;
	if (b) {
		input[3] |= (1 << 7);
		goto node9141;
	} else {
		input[3] &= ~(1 << 7);
		return 0;
	}
node3371:
	b = false;
	if (b) {
		input[3] |= (1 << 0);
		return 0;
	} else {
		input[3] &= ~(1 << 0);
		goto node3635;
	}
node8291:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node3674;
	} else {
		input[2] &= ~(1 << 5);
		goto node8978;
	}
node1534:
	b = false;
	if (b) {
		input[2] |= (1 << 2);
		return 0;
	} else {
		input[2] &= ~(1 << 2);
		goto node3964;
	}
node3518:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node1311;
	}
node1824:
	b = true;
	if (b) {
		input[3] |= (1 << 2);
		goto node4765;
	} else {
		input[3] &= ~(1 << 2);
		return 0;
	}
node774:
	b = randbool();
	if (b) {
		input[4] |= (1 << 3);
		goto node1720;
	} else {
		input[4] &= ~(1 << 3);
		goto node842;
	}
node7871:
	b = randbool();
	if (b) {
		input[2] |= (1 << 0);
		goto node8383;
	} else {
		input[2] &= ~(1 << 0);
		goto node6109;
	}
node2337:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node6467;
	} else {
		input[3] &= ~(1 << 4);
		goto node3485;
	}
node8794:
	b = randbool();
	if (b) {
		input[3] |= (1 << 1);
		goto node235;
	} else {
		input[3] &= ~(1 << 1);
		goto node8877;
	}
node3709:
	b = true;
	if (b) {
		input[2] |= (1 << 3);
		goto node5329;
	} else {
		input[2] &= ~(1 << 3);
		return 0;
	}
node4283:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node9035;
	} else {
		input[3] &= ~(1 << 7);
		goto node5278;
	}
node8832:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node1277;
	} else {
		input[3] &= ~(1 << 7);
		goto node2914;
	}
node1452:
	b = randbool();
	if (b) {
		input[1] |= (1 << 5);
		return 2;
	} else {
		input[1] &= ~(1 << 5);
		goto node206;
	}
node4036:
	b = randbool();
	if (b) {
		input[1] |= (1 << 0);
		goto node8102;
	} else {
		input[1] &= ~(1 << 0);
		goto node5102;
	}
node6507:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node6372;
	} else {
		input[3] &= ~(1 << 3);
		goto node5777;
	}
node7946:
	b = true;
	if (b) {
		input[3] |= (1 << 2);
		goto node1742;
	} else {
		input[3] &= ~(1 << 2);
		return 0;
	}
node1926:
	b = randbool();
	if (b) {
		input[1] |= (1 << 1);
		goto node8689;
	} else {
		input[1] &= ~(1 << 1);
		return 2;
	}
node8937:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node6079;
	} else {
		input[2] &= ~(1 << 4);
		goto node7470;
	}
node1724:
	b = true;
	if (b) {
		input[2] |= (1 << 3);
		return 4;
	} else {
		input[2] &= ~(1 << 3);
		return 0;
	}
node6722:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node3939;
	} else {
		input[2] &= ~(1 << 1);
		goto node8378;
	}
node1847:
	b = randbool();
	if (b) {
		input[2] |= (1 << 0);
		goto node6553;
	} else {
		input[2] &= ~(1 << 0);
		goto node695;
	}
node7944:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node6046;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node2377:
	b = false;
	if (b) {
		input[2] |= (1 << 1);
		return 0;
	} else {
		input[2] &= ~(1 << 1);
		goto node3110;
	}
node7187:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node8951;
	} else {
		input[3] &= ~(1 << 4);
		goto node5989;
	}
node8827:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node7658;
	}
node2220:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node137;
	} else {
		input[3] &= ~(1 << 3);
		goto node2672;
	}
node9460:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node4761;
	} else {
		input[2] &= ~(1 << 3);
		goto node7643;
	}
node2195:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node466;
	} else {
		input[3] &= ~(1 << 2);
		goto node3038;
	}
node6303:
	b = true;
	if (b) {
		input[3] |= (1 << 1);
		goto node7112;
	} else {
		input[3] &= ~(1 << 1);
		return 0;
	}
node7034:
	b = randbool();
	if (b) {
		input[5] |= (1 << 4);
		goto node5645;
	} else {
		input[5] &= ~(1 << 4);
		goto node5353;
	}
node114:
	b = randbool();
	if (b) {
		input[1] |= (1 << 3);
		goto node9277;
	} else {
		input[1] &= ~(1 << 3);
		goto node6660;
	}
node6906:
	b = randbool();
	if (b) {
		input[2] |= (1 << 7);
		goto node1999;
	} else {
		input[2] &= ~(1 << 7);
		goto node6231;
	}
node8825:
	b = false;
	if (b) {
		input[3] |= (1 << 7);
		return 0;
	} else {
		input[3] &= ~(1 << 7);
		goto node3129;
	}
node2883:
	b = true;
	if (b) {
		input[3] |= (1 << 6);
		goto node8137;
	} else {
		input[3] &= ~(1 << 6);
		return 0;
	}
node3682:
	b = false;
	if (b) {
		input[3] |= (1 << 2);
		return 0;
	} else {
		input[3] &= ~(1 << 2);
		goto node8231;
	}
node4671:
	b = true;
	if (b) {
		input[4] |= (1 << 2);
		goto node1967;
	} else {
		input[4] &= ~(1 << 2);
		return 0;
	}
node5049:
	b = true;
	if (b) {
		input[4] |= (1 << 2);
		goto node239;
	} else {
		input[4] &= ~(1 << 2);
		return 0;
	}
node2405:
	b = true;
	if (b) {
		input[2] |= (1 << 3);
		goto node8211;
	} else {
		input[2] &= ~(1 << 3);
		return 0;
	}
node6115:
	b = false;
	if (b) {
		input[2] |= (1 << 3);
		return 0;
	} else {
		input[2] &= ~(1 << 3);
		goto node6586;
	}
node7705:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node7607;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node2942:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node8872;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node8235:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node58;
	} else {
		input[3] &= ~(1 << 2);
		goto node1399;
	}
node485:
	b = true;
	if (b) {
		input[4] |= (1 << 3);
		goto node3658;
	} else {
		input[4] &= ~(1 << 3);
		return 0;
	}
node7792:
	b = randbool();
	if (b) {
		input[1] |= (1 << 1);
		goto node5599;
	} else {
		input[1] &= ~(1 << 1);
		goto node4524;
	}
node1471:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node4086;
	} else {
		input[2] &= ~(1 << 5);
		goto node3996;
	}
node7530:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node3743;
	} else {
		input[3] &= ~(1 << 6);
		goto node601;
	}
node765:
	b = false;
	if (b) {
		input[3] |= (1 << 1);
		return 0;
	} else {
		input[3] &= ~(1 << 1);
		goto node6703;
	}
node8836:
	b = false;
	if (b) {
		input[4] |= (1 << 3);
		return 0;
	} else {
		input[4] &= ~(1 << 3);
		goto node3515;
	}
node2451:
	b = false;
	if (b) {
		input[1] |= (1 << 4);
		return 0;
	} else {
		input[1] &= ~(1 << 4);
		goto node7151;
	}
node3713:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node8741;
	} else {
		input[2] &= ~(1 << 4);
		goto node8170;
	}
node7263:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node4883;
	} else {
		input[2] &= ~(1 << 1);
		goto node1995;
	}
node433:
	b = randbool();
	if (b) {
		input[2] |= (1 << 0);
		goto node6706;
	} else {
		input[2] &= ~(1 << 0);
		goto node3731;
	}
node8755:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node7473;
	}
node7866:
	b = randbool();
	if (b) {
		input[1] |= (1 << 4);
		return 2;
	} else {
		input[1] &= ~(1 << 4);
		goto node5924;
	}
node1227:
	b = false;
	if (b) {
		input[2] |= (1 << 1);
		return 0;
	} else {
		input[2] &= ~(1 << 1);
		goto node7374;
	}
node9125:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node6553;
	} else {
		input[2] &= ~(1 << 1);
		goto node1134;
	}
node4023:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node611;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node1519:
	b = true;
	if (b) {
		input[5] |= (1 << 7);
		goto node8169;
	} else {
		input[5] &= ~(1 << 7);
		return 0;
	}
node9327:
	b = randbool();
	if (b) {
		input[5] |= (1 << 5);
		goto node411;
	} else {
		input[5] &= ~(1 << 5);
		goto node9230;
	}
node4658:
	b = randbool();
	if (b) {
		input[6] |= (1 << 4);
		goto node6261;
	} else {
		input[6] &= ~(1 << 4);
		goto node3623;
	}
node3445:
	b = false;
	if (b) {
		input[2] |= (1 << 2);
		return 0;
	} else {
		input[2] &= ~(1 << 2);
		goto node2456;
	}
node8509:
	b = true;
	if (b) {
		input[3] |= (1 << 6);
		goto node6567;
	} else {
		input[3] &= ~(1 << 6);
		return 0;
	}
node2709:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node1093;
	} else {
		input[3] &= ~(1 << 6);
		goto node284;
	}
node780:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node2907;
	} else {
		input[3] &= ~(1 << 2);
		return 4;
	}
node359:
	b = true;
	if (b) {
		input[3] |= (1 << 2);
		goto node8475;
	} else {
		input[3] &= ~(1 << 2);
		return 0;
	}
node8982:
	b = randbool();
	if (b) {
		input[3] |= (1 << 0);
		goto node1224;
	} else {
		input[3] &= ~(1 << 0);
		goto node6462;
	}
node7115:
	b = randbool();
	if (b) {
		input[1] |= (1 << 2);
		goto node3602;
	} else {
		input[1] &= ~(1 << 2);
		goto node5523;
	}
node7746:
	b = false;
	if (b) {
		input[2] |= (1 << 7);
		return 0;
	} else {
		input[2] &= ~(1 << 7);
		goto node3166;
	}
node2717:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node143;
	} else {
		input[3] &= ~(1 << 5);
		goto node1311;
	}
node7912:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node2115;
	} else {
		input[3] &= ~(1 << 4);
		goto node4314;
	}
node6400:
	b = false;
	if (b) {
		input[4] |= (1 << 2);
		return 0;
	} else {
		input[4] &= ~(1 << 2);
		goto node3148;
	}
node8448:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node6403;
	}
node2211:
	b = randbool();
	if (b) {
		input[3] |= (1 << 1);
		goto node3345;
	} else {
		input[3] &= ~(1 << 1);
		goto node8380;
	}
node3819:
	b = randbool();
	if (b) {
		input[3] |= (1 << 1);
		goto node2757;
	} else {
		input[3] &= ~(1 << 1);
		goto node3520;
	}
node7008:
	b = false;
	if (b) {
		input[2] |= (1 << 5);
		return 0;
	} else {
		input[2] &= ~(1 << 5);
		goto node2032;
	}
node1510:
	b = true;
	if (b) {
		input[4] |= (1 << 1);
		goto node8382;
	} else {
		input[4] &= ~(1 << 1);
		return 0;
	}
node9382:
	b = true;
	if (b) {
		input[1] |= (1 << 0);
		goto node2781;
	} else {
		input[1] &= ~(1 << 0);
		return 0;
	}
node6342:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node8841;
	} else {
		input[2] &= ~(1 << 4);
		return 3;
	}
node1244:
	b = true;
	if (b) {
		input[2] |= (1 << 3);
		goto node1816;
	} else {
		input[2] &= ~(1 << 3);
		return 0;
	}
node9279:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node432;
	} else {
		input[2] &= ~(1 << 2);
		goto node9466;
	}
node4315:
	b = false;
	if (b) {
		input[3] |= (1 << 2);
		return 0;
	} else {
		input[3] &= ~(1 << 2);
		goto node5833;
	}
node8913:
	b = true;
	if (b) {
		input[1] |= (1 << 5);
		goto node7829;
	} else {
		input[1] &= ~(1 << 5);
		return 0;
	}
node8283:
	b = false;
	if (b) {
		input[1] |= (1 << 3);
		return 0;
	} else {
		input[1] &= ~(1 << 3);
		goto node4100;
	}
node7869:
	b = false;
	if (b) {
		input[2] |= (1 << 3);
		return 0;
	} else {
		input[2] &= ~(1 << 3);
		goto node8797;
	}
node8177:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node1996;
	} else {
		input[2] &= ~(1 << 1);
		goto node4545;
	}
node5010:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node573;
	} else {
		input[3] &= ~(1 << 5);
		goto node305;
	}
node2453:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node4323;
	}
node3065:
	b = randbool();
	if (b) {
		input[1] |= (1 << 7);
		goto node1070;
	} else {
		input[1] &= ~(1 << 7);
		goto node3523;
	}
node4933:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node4843;
	}
node2607:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node9216;
	}
node7096:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node4708;
	} else {
		input[2] &= ~(1 << 3);
		goto node4585;
	}
node191:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node6128;
	}
node5908:
	b = false;
	if (b) {
		input[3] |= (1 << 0);
		return 0;
	} else {
		input[3] &= ~(1 << 0);
		goto node5101;
	}
node1446:
	b = true;
	if (b) {
		input[5] |= (1 << 2);
		goto node6672;
	} else {
		input[5] &= ~(1 << 2);
		return 0;
	}
node8639:
	b = true;
	if (b) {
		input[1] |= (1 << 2);
		goto node9231;
	} else {
		input[1] &= ~(1 << 2);
		return 0;
	}
node1087:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node1639;
	} else {
		input[3] &= ~(1 << 7);
		goto node1951;
	}
node5971:
	b = randbool();
	if (b) {
		input[5] |= (1 << 6);
		goto node1767;
	} else {
		input[5] &= ~(1 << 6);
		goto node430;
	}
node7177:
	b = randbool();
	if (b) {
		input[5] |= (1 << 1);
		return 6;
	} else {
		input[5] &= ~(1 << 1);
		goto node1079;
	}
node6260:
	b = true;
	if (b) {
		input[6] |= (1 << 2);
		goto node7667;
	} else {
		input[6] &= ~(1 << 2);
		return 0;
	}
node7080:
	b = randbool();
	if (b) {
		input[2] |= (1 << 7);
		goto node1378;
	} else {
		input[2] &= ~(1 << 7);
		goto node899;
	}
node2024:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node2655;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node3089:
	b = false;
	if (b) {
		input[3] |= (1 << 0);
		return 0;
	} else {
		input[3] &= ~(1 << 0);
		goto node8523;
	}
node2366:
	b = true;
	if (b) {
		input[4] |= (1 << 3);
		goto node7526;
	} else {
		input[4] &= ~(1 << 3);
		return 0;
	}
node4174:
	b = true;
	if (b) {
		input[4] |= (1 << 1);
		goto node1550;
	} else {
		input[4] &= ~(1 << 1);
		return 0;
	}
node4789:
	b = randbool();
	if (b) {
		input[4] |= (1 << 0);
		goto node9168;
	} else {
		input[4] &= ~(1 << 0);
		goto node439;
	}
node3894:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node6474;
	} else {
		input[2] &= ~(1 << 6);
		goto node1683;
	}
node7031:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node8553;
	} else {
		input[3] &= ~(1 << 7);
		goto node9074;
	}
node5686:
	b = randbool();
	if (b) {
		input[3] |= (1 << 1);
		goto node7632;
	} else {
		input[3] &= ~(1 << 1);
		goto node5492;
	}
node9161:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node2130;
	} else {
		input[2] &= ~(1 << 6);
		goto node6323;
	}
node113:
	b = false;
	if (b) {
		input[4] |= (1 << 5);
		return 0;
	} else {
		input[4] &= ~(1 << 5);
		goto node2804;
	}
node3288:
	b = false;
	if (b) {
		input[4] |= (1 << 2);
		return 0;
	} else {
		input[4] &= ~(1 << 2);
		goto node2754;
	}
node9278:
	b = randbool();
	if (b) {
		input[2] |= (1 << 7);
		goto node3770;
	} else {
		input[2] &= ~(1 << 7);
		goto node2613;
	}
node7201:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node3398;
	} else {
		input[2] &= ~(1 << 2);
		goto node2008;
	}
node4891:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node718;
	} else {
		input[2] &= ~(1 << 2);
		goto node3864;
	}
node1626:
	b = true;
	if (b) {
		input[2] |= (1 << 2);
		goto node4569;
	} else {
		input[2] &= ~(1 << 2);
		return 0;
	}
node1234:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node3359;
	} else {
		input[2] &= ~(1 << 1);
		goto node3901;
	}
node5672:
	b = false;
	if (b) {
		input[4] |= (1 << 4);
		return 0;
	} else {
		input[4] &= ~(1 << 4);
		goto node3346;
	}
node7100:
	b = true;
	if (b) {
		input[4] |= (1 << 1);
		goto node5842;
	} else {
		input[4] &= ~(1 << 1);
		return 0;
	}
node3201:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node47;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node1927:
	b = randbool();
	if (b) {
		input[1] |= (1 << 0);
		goto node6644;
	} else {
		input[1] &= ~(1 << 0);
		goto node363;
	}
node9402:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node1233;
	} else {
		input[2] &= ~(1 << 5);
		goto node1630;
	}
node6270:
	b = true;
	if (b) {
		input[2] |= (1 << 3);
		goto node8603;
	} else {
		input[2] &= ~(1 << 3);
		return 0;
	}
node6323:
	b = true;
	if (b) {
		input[2] |= (1 << 2);
		goto node9027;
	} else {
		input[2] &= ~(1 << 2);
		return 0;
	}
node6288:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node5642;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node3998:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node4227;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node6256:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node8888;
	} else {
		input[2] &= ~(1 << 6);
		goto node8262;
	}
node6087:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node3629;
	} else {
		input[2] &= ~(1 << 4);
		goto node4382;
	}
node8653:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node3366;
	} else {
		input[3] &= ~(1 << 4);
		goto node9260;
	}
node4278:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node6682;
	} else {
		input[3] &= ~(1 << 2);
		goto node4098;
	}
node182:
	b = randbool();
	if (b) {
		input[1] |= (1 << 7);
		goto node9169;
	} else {
		input[1] &= ~(1 << 7);
		goto node6108;
	}
node8611:
	b = true;
	if (b) {
		input[1] |= (1 << 1);
		goto node665;
	} else {
		input[1] &= ~(1 << 1);
		return 0;
	}
node6338:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node5232;
	} else {
		input[2] &= ~(1 << 5);
		goto node5854;
	}
node2105:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node6428;
	} else {
		input[2] &= ~(1 << 1);
		goto node851;
	}
node4538:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node9351;
	}
node721:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node5130;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node4903:
	b = false;
	if (b) {
		input[2] |= (1 << 6);
		return 0;
	} else {
		input[2] &= ~(1 << 6);
		goto node4471;
	}
node4068:
	b = false;
	if (b) {
		input[3] |= (1 << 6);
		return 0;
	} else {
		input[3] &= ~(1 << 6);
		goto node4050;
	}
node5088:
	b = false;
	if (b) {
		input[2] |= (1 << 1);
		return 0;
	} else {
		input[2] &= ~(1 << 1);
		goto node2785;
	}
node5369:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node2236;
	} else {
		input[3] &= ~(1 << 2);
		goto node470;
	}
node9110:
	b = true;
	if (b) {
		input[3] |= (1 << 1);
		goto node2512;
	} else {
		input[3] &= ~(1 << 1);
		return 0;
	}
node224:
	b = false;
	if (b) {
		input[5] |= (1 << 0);
		return 0;
	} else {
		input[5] &= ~(1 << 0);
		goto node8714;
	}
node5889:
	b = randbool();
	if (b) {
		input[7] |= (1 << 1);
		return 8;
	} else {
		input[7] &= ~(1 << 1);
		goto node7453;
	}
node5149:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node5337;
	} else {
		input[3] &= ~(1 << 2);
		goto node137;
	}
node3899:
	b = true;
	if (b) {
		input[4] |= (1 << 4);
		goto node4120;
	} else {
		input[4] &= ~(1 << 4);
		return 0;
	}
node8055:
	b = true;
	if (b) {
		input[1] |= (1 << 5);
		goto node2048;
	} else {
		input[1] &= ~(1 << 5);
		return 0;
	}
node1763:
	b = randbool();
	if (b) {
		input[1] |= (1 << 3);
		goto node7838;
	} else {
		input[1] &= ~(1 << 3);
		goto node1650;
	}
node1231:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node1805;
	} else {
		input[2] &= ~(1 << 5);
		goto node6175;
	}
node1108:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node7403;
	} else {
		input[2] &= ~(1 << 2);
		goto node6661;
	}
node4346:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node9404;
	} else {
		input[2] &= ~(1 << 2);
		goto node5222;
	}
node964:
	b = false;
	if (b) {
		input[1] |= (1 << 4);
		return 0;
	} else {
		input[1] &= ~(1 << 4);
		goto node4850;
	}
node3136:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node1817;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node5709:
	b = false;
	if (b) {
		input[3] |= (1 << 0);
		return 0;
	} else {
		input[3] &= ~(1 << 0);
		goto node6858;
	}
node9344:
	b = false;
	if (b) {
		input[4] |= (1 << 4);
		return 0;
	} else {
		input[4] &= ~(1 << 4);
		goto node576;
	}
node5195:
	b = true;
	if (b) {
		input[2] |= (1 << 3);
		goto node9329;
	} else {
		input[2] &= ~(1 << 3);
		return 0;
	}
node6854:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node4424;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node5249:
	b = false;
	if (b) {
		input[3] |= (1 << 6);
		return 0;
	} else {
		input[3] &= ~(1 << 6);
		goto node909;
	}
node6589:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node23;
	} else {
		input[3] &= ~(1 << 2);
		goto node1126;
	}
node3508:
	b = true;
	if (b) {
		input[4] |= (1 << 7);
		goto node9308;
	} else {
		input[4] &= ~(1 << 7);
		return 0;
	}
node9204:
	b = true;
	if (b) {
		input[4] |= (1 << 5);
		goto node2422;
	} else {
		input[4] &= ~(1 << 5);
		return 0;
	}
node3848:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node6464;
	} else {
		input[2] &= ~(1 << 6);
		goto node456;
	}
node1046:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node867;
	}
node7739:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		goto node6497;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node3611:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node988;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node730:
	b = true;
	if (b) {
		input[3] |= (1 << 6);
		goto node7472;
	} else {
		input[3] &= ~(1 << 6);
		return 0;
	}
node7671:
	b = false;
	if (b) {
		input[3] |= (1 << 2);
		return 0;
	} else {
		input[3] &= ~(1 << 2);
		goto node7789;
	}
node4861:
	b = false;
	if (b) {
		input[2] |= (1 << 0);
		return 0;
	} else {
		input[2] &= ~(1 << 0);
		goto node3799;
	}
node5400:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node4953;
	} else {
		input[3] &= ~(1 << 6);
		goto node6599;
	}
node4163:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node7209;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node1611:
	b = randbool();
	if (b) {
		input[4] |= (1 << 2);
		goto node7769;
	} else {
		input[4] &= ~(1 << 2);
		return 5;
	}
node1438:
	b = false;
	if (b) {
		input[2] |= (1 << 6);
		return 0;
	} else {
		input[2] &= ~(1 << 6);
		goto node4386;
	}
node2269:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node5187;
	} else {
		input[2] &= ~(1 << 2);
		goto node8307;
	}
node8495:
	b = true;
	if (b) {
		input[3] |= (1 << 0);
		goto node3999;
	} else {
		input[3] &= ~(1 << 0);
		return 0;
	}
node7277:
	b = false;
	if (b) {
		input[2] |= (1 << 7);
		return 0;
	} else {
		input[2] &= ~(1 << 7);
		goto node9161;
	}
node9115:
	b = false;
	if (b) {
		input[2] |= (1 << 7);
		return 0;
	} else {
		input[2] &= ~(1 << 7);
		goto node8944;
	}
node4952:
	b = false;
	if (b) {
		input[2] |= (1 << 5);
		return 0;
	} else {
		input[2] &= ~(1 << 5);
		goto node140;
	}
node186:
	b = true;
	if (b) {
		input[3] |= (1 << 7);
		goto node1340;
	} else {
		input[3] &= ~(1 << 7);
		return 0;
	}
node5608:
	b = true;
	if (b) {
		input[4] |= (1 << 5);
		goto node1611;
	} else {
		input[4] &= ~(1 << 5);
		return 0;
	}
node3413:
	b = randbool();
	if (b) {
		input[1] |= (1 << 3);
		goto node303;
	} else {
		input[1] &= ~(1 << 3);
		goto node7249;
	}
node4268:
	b = false;
	if (b) {
		input[2] |= (1 << 3);
		return 0;
	} else {
		input[2] &= ~(1 << 3);
		goto node6792;
	}
node1109:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node9163;
	} else {
		input[3] &= ~(1 << 7);
		goto node6295;
	}
node4120:
	b = randbool();
	if (b) {
		input[4] |= (1 << 3);
		goto node7777;
	} else {
		input[4] &= ~(1 << 3);
		goto node8271;
	}
node2076:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node4186;
	} else {
		input[2] &= ~(1 << 1);
		goto node8370;
	}
node4555:
	b = false;
	if (b) {
		input[3] |= (1 << 6);
		return 0;
	} else {
		input[3] &= ~(1 << 6);
		goto node6091;
	}
node3528:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node6794;
	} else {
		input[3] &= ~(1 << 5);
		goto node3540;
	}
node7412:
	b = true;
	if (b) {
		input[3] |= (1 << 2);
		goto node4335;
	} else {
		input[3] &= ~(1 << 2);
		return 0;
	}
node8934:
	b = true;
	if (b) {
		input[3] |= (1 << 0);
		goto node6382;
	} else {
		input[3] &= ~(1 << 0);
		return 0;
	}
node561:
	b = randbool();
	if (b) {
		input[1] |= (1 << 1);
		goto node2816;
	} else {
		input[1] &= ~(1 << 1);
		goto node4054;
	}
node5187:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node1694;
	} else {
		input[2] &= ~(1 << 1);
		goto node3972;
	}
node8539:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node8266;
	} else {
		input[3] &= ~(1 << 4);
		goto node2132;
	}
node5694:
	b = false;
	if (b) {
		input[3] |= (1 << 2);
		return 0;
	} else {
		input[3] &= ~(1 << 2);
		goto node5587;
	}
node4109:
	b = true;
	if (b) {
		input[3] |= (1 << 0);
		goto node3686;
	} else {
		input[3] &= ~(1 << 0);
		return 0;
	}
node9398:
	b = randbool();
	if (b) {
		input[4] |= (1 << 6);
		goto node6962;
	} else {
		input[4] &= ~(1 << 6);
		goto node6328;
	}
node3377:
	b = false;
	if (b) {
		input[3] |= (1 << 1);
		return 0;
	} else {
		input[3] &= ~(1 << 1);
		goto node6836;
	}
node8330:
	b = false;
	if (b) {
		input[4] |= (1 << 6);
		return 0;
	} else {
		input[4] &= ~(1 << 6);
		goto node7489;
	}
node7541:
	b = false;
	if (b) {
		input[2] |= (1 << 5);
		return 0;
	} else {
		input[2] &= ~(1 << 5);
		goto node4248;
	}
node825:
	b = false;
	if (b) {
		input[2] |= (1 << 1);
		return 0;
	} else {
		input[2] &= ~(1 << 1);
		goto node4373;
	}
node4050:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node5459;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node5239:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node544;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node9167:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node5221;
	} else {
		input[3] &= ~(1 << 5);
		goto node3228;
	}
node5028:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node6890;
	}
node6205:
	b = randbool();
	if (b) {
		input[7] |= (1 << 7);
		goto node3133;
	} else {
		input[7] &= ~(1 << 7);
		goto node5038;
	}
node626:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node4347;
	} else {
		input[2] &= ~(1 << 1);
		goto node6039;
	}
node9200:
	b = randbool();
	if (b) {
		input[3] |= (1 << 0);
		goto node8081;
	} else {
		input[3] &= ~(1 << 0);
		goto node6037;
	}
node9455:
	b = randbool();
	if (b) {
		input[4] |= (1 << 5);
		goto node7012;
	} else {
		input[4] &= ~(1 << 5);
		goto node6659;
	}
node9255:
	b = false;
	if (b) {
		input[4] |= (1 << 1);
		return 0;
	} else {
		input[4] &= ~(1 << 1);
		goto node6363;
	}
node2490:
	b = false;
	if (b) {
		input[0] |= (1 << 1);
		return 0;
	} else {
		input[0] &= ~(1 << 1);
		goto node3059;
	}
node2930:
	b = true;
	if (b) {
		input[2] |= (1 << 4);
		goto node2966;
	} else {
		input[2] &= ~(1 << 4);
		return 0;
	}
node4531:
	b = false;
	if (b) {
		input[3] |= (1 << 6);
		return 0;
	} else {
		input[3] &= ~(1 << 6);
		goto node3722;
	}
node2350:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		return 5;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node163:
	b = true;
	if (b) {
		input[3] |= (1 << 0);
		goto node2989;
	} else {
		input[3] &= ~(1 << 0);
		return 0;
	}
node9082:
	b = false;
	if (b) {
		input[5] |= (1 << 0);
		return 0;
	} else {
		input[5] &= ~(1 << 0);
		goto node5265;
	}
node521:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node7285;
	} else {
		input[2] &= ~(1 << 5);
		goto node1597;
	}
node9112:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node1957;
	} else {
		input[3] &= ~(1 << 5);
		goto node2413;
	}
node5666:
	b = false;
	if (b) {
		input[1] |= (1 << 0);
		return 0;
	} else {
		input[1] &= ~(1 << 0);
		goto node3014;
	}
node5114:
	b = false;
	if (b) {
		input[2] |= (1 << 1);
		return 0;
	} else {
		input[2] &= ~(1 << 1);
		goto node3309;
	}
node5615:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node4411;
	} else {
		input[3] &= ~(1 << 3);
		goto node5483;
	}
node3294:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node3710;
	} else {
		input[3] &= ~(1 << 2);
		return 4;
	}
node8940:
	b = false;
	if (b) {
		input[3] |= (1 << 1);
		return 0;
	} else {
		input[3] &= ~(1 << 1);
		goto node1904;
	}
node4074:
	b = false;
	if (b) {
		input[3] |= (1 << 1);
		return 0;
	} else {
		input[3] &= ~(1 << 1);
		goto node4444;
	}
node5901:
	b = randbool();
	if (b) {
		input[3] |= (1 << 1);
		goto node9453;
	} else {
		input[3] &= ~(1 << 1);
		goto node219;
	}
node2562:
	b = false;
	if (b) {
		input[4] |= (1 << 5);
		return 0;
	} else {
		input[4] &= ~(1 << 5);
		goto node1201;
	}
node8657:
	b = randbool();
	if (b) {
		input[1] |= (1 << 2);
		goto node3758;
	} else {
		input[1] &= ~(1 << 2);
		goto node9417;
	}
node3511:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		goto node8645;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node6068:
	b = false;
	if (b) {
		input[2] |= (1 << 1);
		return 0;
	} else {
		input[2] &= ~(1 << 1);
		goto node6355;
	}
node6829:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node4914;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node2218:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node780;
	}
node5442:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node137;
	}
node3302:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node9085;
	} else {
		input[2] &= ~(1 << 4);
		goto node9471;
	}
node5203:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node5209;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node4731:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node3677;
	}
node7597:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node6462;
	} else {
		input[3] &= ~(1 << 3);
		goto node9442;
	}
node8313:
	b = true;
	if (b) {
		input[3] |= (1 << 0);
		goto node3400;
	} else {
		input[3] &= ~(1 << 0);
		return 0;
	}
node6750:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node5782;
	} else {
		input[2] &= ~(1 << 6);
		goto node2256;
	}
node4408:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node6577;
	} else {
		input[3] &= ~(1 << 5);
		goto node8028;
	}
node539:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node3520;
	} else {
		input[3] &= ~(1 << 2);
		goto node8157;
	}
node2016:
	b = true;
	if (b) {
		input[3] |= (1 << 0);
		goto node6037;
	} else {
		input[3] &= ~(1 << 0);
		return 0;
	}
node5277:
	b = false;
	if (b) {
		input[4] |= (1 << 5);
		return 0;
	} else {
		input[4] &= ~(1 << 5);
		goto node5896;
	}
node724:
	b = true;
	if (b) {
		input[1] |= (1 << 1);
		return 2;
	} else {
		input[1] &= ~(1 << 1);
		return 0;
	}
node6103:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node1421;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node7025:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node3739;
	} else {
		input[3] &= ~(1 << 6);
		goto node2670;
	}
node3604:
	b = true;
	if (b) {
		input[4] |= (1 << 3);
		goto node3728;
	} else {
		input[4] &= ~(1 << 3);
		return 0;
	}
node327:
	b = randbool();
	if (b) {
		input[1] |= (1 << 0);
		goto node4480;
	} else {
		input[1] &= ~(1 << 0);
		goto node812;
	}
node5216:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node2753;
	} else {
		input[3] &= ~(1 << 6);
		goto node7134;
	}
node6502:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node2891;
	} else {
		input[3] &= ~(1 << 6);
		goto node844;
	}
node2499:
	b = true;
	if (b) {
		input[4] |= (1 << 2);
		goto node8463;
	} else {
		input[4] &= ~(1 << 2);
		return 0;
	}
node6340:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node1597;
	} else {
		input[2] &= ~(1 << 5);
		goto node1692;
	}
node461:
	b = false;
	if (b) {
		input[3] |= (1 << 2);
		return 0;
	} else {
		input[3] &= ~(1 << 2);
		goto node7947;
	}
node894:
	b = true;
	if (b) {
		input[4] |= (1 << 6);
		return 6;
	} else {
		input[4] &= ~(1 << 6);
		return 0;
	}
node6140:
	b = false;
	if (b) {
		input[2] |= (1 << 7);
		return 0;
	} else {
		input[2] &= ~(1 << 7);
		goto node7467;
	}
node8186:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node4486;
	}
node5458:
	b = true;
	if (b) {
		input[2] |= (1 << 3);
		goto node9018;
	} else {
		input[2] &= ~(1 << 3);
		return 0;
	}
node5810:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		goto node1442;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node7282:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node5015;
	} else {
		input[3] &= ~(1 << 5);
		goto node4863;
	}
node8596:
	b = false;
	if (b) {
		input[1] |= (1 << 3);
		return 0;
	} else {
		input[1] &= ~(1 << 3);
		goto node7641;
	}
node7742:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node1597;
	} else {
		input[2] &= ~(1 << 5);
		goto node7408;
	}
node895:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node119;
	} else {
		input[3] &= ~(1 << 3);
		goto node1281;
	}
node2605:
	b = true;
	if (b) {
		input[3] |= (1 << 2);
		goto node2958;
	} else {
		input[3] &= ~(1 << 2);
		return 0;
	}
node495:
	b = false;
	if (b) {
		input[1] |= (1 << 4);
		return 0;
	} else {
		input[1] &= ~(1 << 4);
		goto node9025;
	}
node4433:
	b = false;
	if (b) {
		input[2] |= (1 << 6);
		return 0;
	} else {
		input[2] &= ~(1 << 6);
		goto node8606;
	}
node8221:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node2061;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node3869:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node3032;
	} else {
		input[3] &= ~(1 << 5);
		goto node2156;
	}
node7606:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node3243;
	} else {
		input[3] &= ~(1 << 7);
		goto node6429;
	}
node4156:
	b = false;
	if (b) {
		input[1] |= (1 << 4);
		return 0;
	} else {
		input[1] &= ~(1 << 4);
		goto node609;
	}
node2233:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node7766;
	} else {
		input[3] &= ~(1 << 6);
		goto node3294;
	}
node2993:
	b = true;
	if (b) {
		input[4] |= (1 << 4);
		goto node612;
	} else {
		input[4] &= ~(1 << 4);
		return 0;
	}
node8229:
	b = true;
	if (b) {
		input[4] |= (1 << 3);
		goto node1230;
	} else {
		input[4] &= ~(1 << 3);
		return 0;
	}
node1540:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node4781;
	} else {
		input[2] &= ~(1 << 5);
		goto node993;
	}
node5740:
	b = true;
	if (b) {
		input[2] |= (1 << 2);
		goto node2263;
	} else {
		input[2] &= ~(1 << 2);
		return 0;
	}
node5533:
	b = randbool();
	if (b) {
		input[2] |= (1 << 0);
		goto node667;
	} else {
		input[2] &= ~(1 << 0);
		goto node6428;
	}
node1557:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node4284;
	} else {
		input[3] &= ~(1 << 5);
		goto node9307;
	}
node3071:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node5096;
	} else {
		input[3] &= ~(1 << 5);
		goto node2733;
	}
node2170:
	b = true;
	if (b) {
		input[3] |= (1 << 0);
		goto node2171;
	} else {
		input[3] &= ~(1 << 0);
		return 0;
	}
node331:
	b = true;
	if (b) {
		input[2] |= (1 << 2);
		goto node9263;
	} else {
		input[2] &= ~(1 << 2);
		return 0;
	}
node9404:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node3042;
	} else {
		input[2] &= ~(1 << 1);
		goto node7887;
	}
node1796:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node4092;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node5601:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node6770;
	} else {
		input[3] &= ~(1 << 4);
		goto node996;
	}
node4044:
	b = randbool();
	if (b) {
		input[3] |= (1 << 1);
		goto node3727;
	} else {
		input[3] &= ~(1 << 1);
		goto node606;
	}
node1895:
	b = false;
	if (b) {
		input[3] |= (1 << 1);
		return 0;
	} else {
		input[3] &= ~(1 << 1);
		goto node3522;
	}
node4814:
	b = true;
	if (b) {
		input[3] |= (1 << 6);
		goto node217;
	} else {
		input[3] &= ~(1 << 6);
		return 0;
	}
node705:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node8450;
	} else {
		input[3] &= ~(1 << 5);
		goto node7141;
	}
node8007:
	b = true;
	if (b) {
		input[3] |= (1 << 1);
		goto node5759;
	} else {
		input[3] &= ~(1 << 1);
		return 0;
	}
node9357:
	b = false;
	if (b) {
		input[5] |= (1 << 5);
		return 0;
	} else {
		input[5] &= ~(1 << 5);
		goto node8182;
	}
node8593:
	b = false;
	if (b) {
		input[2] |= (1 << 0);
		return 0;
	} else {
		input[2] &= ~(1 << 0);
		goto node6553;
	}
node6684:
	b = randbool();
	if (b) {
		input[2] |= (1 << 0);
		goto node5275;
	} else {
		input[2] &= ~(1 << 0);
		goto node2095;
	}
node1558:
	b = true;
	if (b) {
		input[4] |= (1 << 6);
		goto node8681;
	} else {
		input[4] &= ~(1 << 6);
		return 0;
	}
node1401:
	b = false;
	if (b) {
		input[4] |= (1 << 0);
		return 0;
	} else {
		input[4] &= ~(1 << 0);
		goto node3239;
	}
node3616:
	b = true;
	if (b) {
		input[2] |= (1 << 3);
		goto node3045;
	} else {
		input[2] &= ~(1 << 3);
		return 0;
	}
node2496:
	b = false;
	if (b) {
		input[2] |= (1 << 3);
		return 0;
	} else {
		input[2] &= ~(1 << 3);
		goto node9279;
	}
node3979:
	b = false;
	if (b) {
		input[4] |= (1 << 5);
		return 0;
	} else {
		input[4] &= ~(1 << 5);
		goto node8733;
	}
node2412:
	b = false;
	if (b) {
		input[2] |= (1 << 5);
		return 0;
	} else {
		input[2] &= ~(1 << 5);
		goto node5086;
	}
node3802:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node9408;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node9259:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node3600;
	}
node8215:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node2957;
	}
node741:
	b = randbool();
	if (b) {
		input[4] |= (1 << 5);
		goto node2842;
	} else {
		input[4] &= ~(1 << 5);
		goto node3176;
	}
node2736:
	b = false;
	if (b) {
		input[4] |= (1 << 5);
		return 0;
	} else {
		input[4] &= ~(1 << 5);
		goto node181;
	}
node673:
	b = true;
	if (b) {
		input[3] |= (1 << 1);
		goto node2807;
	} else {
		input[3] &= ~(1 << 1);
		return 0;
	}
node6893:
	b = randbool();
	if (b) {
		input[4] |= (1 << 3);
		goto node6348;
	} else {
		input[4] &= ~(1 << 3);
		goto node8965;
	}
node8088:
	b = randbool();
	if (b) {
		input[1] |= (1 << 4);
		goto node4535;
	} else {
		input[1] &= ~(1 << 4);
		goto node4859;
	}
node931:
	b = true;
	if (b) {
		input[1] |= (1 << 2);
		goto node1616;
	} else {
		input[1] &= ~(1 << 2);
		return 0;
	}
node7886:
	b = randbool();
	if (b) {
		input[2] |= (1 << 7);
		goto node3390;
	} else {
		input[2] &= ~(1 << 7);
		goto node1438;
	}
node9037:
	b = false;
	if (b) {
		input[2] |= (1 << 5);
		return 0;
	} else {
		input[2] &= ~(1 << 5);
		goto node9419;
	}
node6246:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node9066;
	} else {
		input[3] &= ~(1 << 7);
		goto node5278;
	}
node4994:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node7410;
	} else {
		input[3] &= ~(1 << 4);
		goto node8494;
	}
node9303:
	b = randbool();
	if (b) {
		input[6] |= (1 << 5);
		goto node7834;
	} else {
		input[6] &= ~(1 << 5);
		goto node2042;
	}
node1210:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node850;
	} else {
		input[2] &= ~(1 << 2);
		goto node1084;
	}
node553:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node6946;
	} else {
		input[2] &= ~(1 << 2);
		goto node5057;
	}
node9069:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node1960;
	} else {
		input[2] &= ~(1 << 5);
		return 3;
	}
node7925:
	b = false;
	if (b) {
		input[5] |= (1 << 3);
		return 0;
	} else {
		input[5] &= ~(1 << 3);
		goto node2912;
	}
node1187:
	b = false;
	if (b) {
		input[2] |= (1 << 3);
		return 0;
	} else {
		input[2] &= ~(1 << 3);
		goto node7508;
	}
node8487:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node5123;
	} else {
		input[2] &= ~(1 << 3);
		goto node5791;
	}
node516:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node4417;
	} else {
		input[2] &= ~(1 << 3);
		goto node7450;
	}
node3814:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node983;
	}
node425:
	b = false;
	if (b) {
		input[3] |= (1 << 2);
		return 0;
	} else {
		input[3] &= ~(1 << 2);
		goto node3345;
	}
node1069:
	b = randbool();
	if (b) {
		input[5] |= (1 << 1);
		return 7;
	} else {
		input[5] &= ~(1 << 1);
		goto node7407;
	}
node1805:
	b = true;
	if (b) {
		input[2] |= (1 << 4);
		goto node397;
	} else {
		input[2] &= ~(1 << 4);
		return 0;
	}
node661:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node3081;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node1195:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node4954;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node2017:
	b = false;
	if (b) {
		input[4] |= (1 << 4);
		return 0;
	} else {
		input[4] &= ~(1 << 4);
		goto node2351;
	}
node3778:
	b = false;
	if (b) {
		input[2] |= (1 << 3);
		return 0;
	} else {
		input[2] &= ~(1 << 3);
		goto node5172;
	}
node6404:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node1359;
	} else {
		input[2] &= ~(1 << 2);
		goto node6074;
	}
node2075:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node748;
	} else {
		input[2] &= ~(1 << 1);
		goto node8396;
	}
node2027:
	b = true;
	if (b) {
		input[4] |= (1 << 0);
		goto node8305;
	} else {
		input[4] &= ~(1 << 0);
		return 0;
	}
node4223:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node8859;
	} else {
		input[2] &= ~(1 << 6);
		goto node924;
	}
node3364:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node6550;
	}
node1951:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node4028;
	} else {
		input[3] &= ~(1 << 6);
		goto node8252;
	}
node4106:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node3227;
	}
node629:
	b = randbool();
	if (b) {
		input[6] |= (1 << 2);
		goto node1636;
	} else {
		input[6] &= ~(1 << 2);
		return 7;
	}
node9234:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node4051;
	}
node3482:
	b = randbool();
	if (b) {
		input[4] |= (1 << 6);
		goto node7937;
	} else {
		input[4] &= ~(1 << 6);
		goto node5180;
	}
node6013:
	b = false;
	if (b) {
		input[4] |= (1 << 5);
		return 0;
	} else {
		input[4] &= ~(1 << 5);
		goto node2422;
	}
node6359:
	b = randbool();
	if (b) {
		input[1] |= (1 << 3);
		goto node5119;
	} else {
		input[1] &= ~(1 << 3);
		goto node1142;
	}
node7127:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node8345;
	} else {
		input[2] &= ~(1 << 6);
		goto node1827;
	}
node6788:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node3098;
	} else {
		input[2] &= ~(1 << 2);
		goto node7300;
	}
node9411:
	b = randbool();
	if (b) {
		input[6] |= (1 << 1);
		return 8;
	} else {
		input[6] &= ~(1 << 1);
		goto node6935;
	}
node3934:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node6462;
	} else {
		input[3] &= ~(1 << 3);
		goto node2264;
	}
node4340:
	b = false;
	if (b) {
		input[4] |= (1 << 7);
		return 0;
	} else {
		input[4] &= ~(1 << 7);
		goto node435;
	}
node9456:
	b = false;
	if (b) {
		input[4] |= (1 << 1);
		return 0;
	} else {
		input[4] &= ~(1 << 1);
		goto node675;
	}
node6314:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node4444;
	} else {
		input[3] &= ~(1 << 3);
		goto node5603;
	}
node840:
	b = true;
	if (b) {
		input[4] |= (1 << 4);
		goto node1691;
	} else {
		input[4] &= ~(1 << 4);
		return 0;
	}
node1864:
	b = randbool();
	if (b) {
		input[1] |= (1 << 5);
		goto node3268;
	} else {
		input[1] &= ~(1 << 5);
		goto node7967;
	}
node4833:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node5317;
	} else {
		input[2] &= ~(1 << 2);
		return 7;
	}
node881:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node343;
	} else {
		input[2] &= ~(1 << 2);
		goto node6182;
	}
node6733:
	b = false;
	if (b) {
		input[4] |= (1 << 2);
		return 0;
	} else {
		input[4] &= ~(1 << 2);
		goto node9221;
	}
node6972:
	b = true;
	if (b) {
		input[4] |= (1 << 1);
		goto node6914;
	} else {
		input[4] &= ~(1 << 1);
		return 0;
	}
node4930:
	b = true;
	if (b) {
		input[2] |= (1 << 2);
		goto node9248;
	} else {
		input[2] &= ~(1 << 2);
		return 0;
	}
node9368:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node6318;
	}
node275:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node2157;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node911:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node2085;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node3451:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node4838;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node5118:
	b = randbool();
	if (b) {
		input[5] |= (1 << 4);
		goto node2463;
	} else {
		input[5] &= ~(1 << 4);
		goto node9379;
	}
node4151:
	b = false;
	if (b) {
		input[2] |= (1 << 0);
		return 0;
	} else {
		input[2] &= ~(1 << 0);
		goto node2095;
	}
node8100:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node2436;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node5717:
	b = true;
	if (b) {
		input[3] |= (1 << 2);
		goto node6956;
	} else {
		input[3] &= ~(1 << 2);
		return 0;
	}
node1602:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node1561;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node2052:
	b = false;
	if (b) {
		input[3] |= (1 << 7);
		return 0;
	} else {
		input[3] &= ~(1 << 7);
		goto node4555;
	}
node8404:
	b = true;
	if (b) {
		input[3] |= (1 << 6);
		goto node321;
	} else {
		input[3] &= ~(1 << 6);
		return 0;
	}
node9291:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node884;
	} else {
		input[3] &= ~(1 << 5);
		goto node9320;
	}
node6713:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node8566;
	}
node6634:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node3386;
	} else {
		input[3] &= ~(1 << 6);
		goto node9136;
	}
node4522:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node1135;
	} else {
		input[3] &= ~(1 << 6);
		goto node3260;
	}
node4766:
	b = randbool();
	if (b) {
		input[0] |= (1 << 1);
		goto node5108;
	} else {
		input[0] &= ~(1 << 1);
		return 1;
	}
node29:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node5723;
	} else {
		input[2] &= ~(1 << 5);
		goto node1684;
	}
node7494:
	b = true;
	if (b) {
		input[2] |= (1 << 2);
		goto node7145;
	} else {
		input[2] &= ~(1 << 2);
		return 0;
	}
node7325:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node6907;
	} else {
		input[2] &= ~(1 << 2);
		goto node7350;
	}
node5317:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		return 7;
	} else {
		input[2] &= ~(1 << 1);
		goto node8938;
	}
node7762:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node3989;
	} else {
		input[3] &= ~(1 << 7);
		goto node4754;
	}
node7818:
	b = true;
	if (b) {
		input[4] |= (1 << 4);
		goto node2079;
	} else {
		input[4] &= ~(1 << 4);
		return 0;
	}
node2912:
	b = false;
	if (b) {
		input[5] |= (1 << 2);
		return 0;
	} else {
		input[5] &= ~(1 << 2);
		goto node6000;
	}
node8608:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node3630;
	} else {
		input[3] &= ~(1 << 4);
		goto node5668;
	}
node8381:
	b = randbool();
	if (b) {
		input[4] |= (1 << 1);
		return 7;
	} else {
		input[4] &= ~(1 << 1);
		goto node7313;
	}
node7203:
	b = false;
	if (b) {
		input[5] |= (1 << 7);
		return 0;
	} else {
		input[5] &= ~(1 << 7);
		goto node3203;
	}
node8603:
	b = true;
	if (b) {
		input[2] |= (1 << 2);
		goto node8389;
	} else {
		input[2] &= ~(1 << 2);
		return 0;
	}
node3596:
	b = randbool();
	if (b) {
		input[4] |= (1 << 6);
		goto node6215;
	} else {
		input[4] &= ~(1 << 6);
		goto node9154;
	}
node1748:
	b = false;
	if (b) {
		input[4] |= (1 << 3);
		return 0;
	} else {
		input[4] &= ~(1 << 3);
		goto node2499;
	}
node7694:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node3720;
	} else {
		input[2] &= ~(1 << 4);
		goto node1472;
	}
node5077:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node1167;
	} else {
		input[2] &= ~(1 << 3);
		goto node1786;
	}
node1489:
	b = true;
	if (b) {
		input[4] |= (1 << 6);
		goto node4160;
	} else {
		input[4] &= ~(1 << 6);
		return 0;
	}
node5074:
	b = false;
	if (b) {
		input[4] |= (1 << 5);
		return 0;
	} else {
		input[4] &= ~(1 << 5);
		goto node4352;
	}
node4813:
	b = false;
	if (b) {
		input[4] |= (1 << 1);
		return 0;
	} else {
		input[4] &= ~(1 << 1);
		goto node2352;
	}
node6694:
	b = randbool();
	if (b) {
		input[6] |= (1 << 4);
		goto node2042;
	} else {
		input[6] &= ~(1 << 4);
		goto node5485;
	}
node3196:
	b = false;
	if (b) {
		input[2] |= (1 << 3);
		return 0;
	} else {
		input[2] &= ~(1 << 3);
		goto node6545;
	}
node9268:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node7165;
	} else {
		input[3] &= ~(1 << 5);
		goto node6800;
	}
node6020:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node2437;
	}
node4179:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node1182;
	}
node418:
	b = true;
	if (b) {
		input[4] |= (1 << 7);
		goto node6514;
	} else {
		input[4] &= ~(1 << 7);
		return 0;
	}
node885:
	b = false;
	if (b) {
		input[5] |= (1 << 0);
		return 0;
	} else {
		input[5] &= ~(1 << 0);
		return 6;
	}
node9408:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node3718;
	}
node7554:
	b = randbool();
	if (b) {
		input[1] |= (1 << 2);
		goto node1808;
	} else {
		input[1] &= ~(1 << 2);
		goto node2311;
	}
node1650:
	b = false;
	if (b) {
		input[1] |= (1 << 2);
		return 0;
	} else {
		input[1] &= ~(1 << 2);
		goto node4726;
	}
node4133:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node5160;
	} else {
		input[2] &= ~(1 << 3);
		goto node1806;
	}
node8238:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node8154;
	} else {
		input[2] &= ~(1 << 1);
		goto node3111;
	}
node8492:
	b = true;
	if (b) {
		input[3] |= (1 << 6);
		goto node6730;
	} else {
		input[3] &= ~(1 << 6);
		return 0;
	}
node3119:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node4718;
	} else {
		input[3] &= ~(1 << 5);
		goto node8777;
	}
node5364:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node4713;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node5638:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node730;
	} else {
		input[3] &= ~(1 << 7);
		goto node622;
	}
node5634:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node5240;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node8244:
	b = randbool();
	if (b) {
		input[1] |= (1 << 0);
		goto node775;
	} else {
		input[1] &= ~(1 << 0);
		goto node1063;
	}
node4949:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node8226;
	} else {
		input[2] &= ~(1 << 5);
		goto node1226;
	}
node3440:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node3701;
	} else {
		input[3] &= ~(1 << 5);
		goto node5352;
	}
node4020:
	b = false;
	if (b) {
		input[1] |= (1 << 6);
		return 0;
	} else {
		input[1] &= ~(1 << 6);
		goto node8055;
	}
node258:
	b = randbool();
	if (b) {
		input[2] |= (1 << 7);
		goto node6360;
	} else {
		input[2] &= ~(1 << 7);
		goto node932;
	}
node4291:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node6689;
	} else {
		input[2] &= ~(1 << 4);
		goto node8820;
	}
node6849:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node1442;
	} else {
		input[2] &= ~(1 << 1);
		goto node7887;
	}
node5661:
	b = true;
	if (b) {
		input[3] |= (1 << 6);
		goto node218;
	} else {
		input[3] &= ~(1 << 6);
		return 0;
	}
node5344:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node6099;
	} else {
		input[3] &= ~(1 << 7);
		goto node5278;
	}
node7460:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node6880;
	}
node4827:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node4608;
	} else {
		input[3] &= ~(1 << 4);
		goto node2012;
	}
node3541:
	b = true;
	if (b) {
		input[3] |= (1 << 1);
		goto node658;
	} else {
		input[3] &= ~(1 << 1);
		return 0;
	}
node5466:
	b = false;
	if (b) {
		input[3] |= (1 << 0);
		return 0;
	} else {
		input[3] &= ~(1 << 0);
		goto node5484;
	}
node6026:
	b = true;
	if (b) {
		input[5] |= (1 << 2);
		goto node3169;
	} else {
		input[5] &= ~(1 << 2);
		return 0;
	}
node7603:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node3704;
	} else {
		input[2] &= ~(1 << 3);
		goto node553;
	}
node3045:
	b = true;
	if (b) {
		input[2] |= (1 << 2);
		goto node2553;
	} else {
		input[2] &= ~(1 << 2);
		return 0;
	}
node2297:
	b = false;
	if (b) {
		input[4] |= (1 << 2);
		return 0;
	} else {
		input[4] &= ~(1 << 2);
		goto node8569;
	}
node2917:
	b = randbool();
	if (b) {
		input[0] |= (1 << 1);
		goto node6608;
	} else {
		input[0] &= ~(1 << 1);
		goto node2184;
	}
node6119:
	b = randbool();
	if (b) {
		input[4] |= (1 << 6);
		goto node3367;
	} else {
		input[4] &= ~(1 << 6);
		goto node446;
	}
node9298:
	b = randbool();
	if (b) {
		input[4] |= (1 << 2);
		goto node7791;
	} else {
		input[4] &= ~(1 << 2);
		goto node7203;
	}
node4462:
	b = randbool();
	if (b) {
		input[1] |= (1 << 4);
		goto node5255;
	} else {
		input[1] &= ~(1 << 4);
		goto node1773;
	}
node890:
	b = true;
	if (b) {
		input[3] |= (1 << 6);
		return 6;
	} else {
		input[3] &= ~(1 << 6);
		return 0;
	}
node6307:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node5064;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node2751:
	b = false;
	if (b) {
		input[1] |= (1 << 5);
		return 0;
	} else {
		input[1] &= ~(1 << 5);
		goto node836;
	}
node8171:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node3799;
	} else {
		input[2] &= ~(1 << 2);
		goto node7995;
	}
node9007:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node5927;
	} else {
		input[3] &= ~(1 << 4);
		goto node6220;
	}
node2944:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node4294;
	} else {
		input[3] &= ~(1 << 4);
		goto node6307;
	}
node9317:
	b = false;
	if (b) {
		input[3] |= (1 << 2);
		return 0;
	} else {
		input[3] &= ~(1 << 2);
		goto node2211;
	}
node441:
	b = randbool();
	if (b) {
		input[3] |= (1 << 0);
		goto node6504;
	} else {
		input[3] &= ~(1 << 0);
		goto node509;
	}
node9403:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node7144;
	} else {
		input[2] &= ~(1 << 2);
		goto node8730;
	}
node1639:
	b = true;
	if (b) {
		input[3] |= (1 << 6);
		goto node3833;
	} else {
		input[3] &= ~(1 << 6);
		return 0;
	}
node6091:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node370;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node437:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node6830;
	}
node39:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node3120;
	}
node9177:
	b = randbool();
	if (b) {
		input[3] |= (1 << 1);
		return 4;
	} else {
		input[3] &= ~(1 << 1);
		goto node3522;
	}
node7126:
	b = false;
	if (b) {
		input[2] |= (1 << 6);
		return 0;
	} else {
		input[2] &= ~(1 << 6);
		goto node1427;
	}
node5098:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node2009;
	} else {
		input[2] &= ~(1 << 2);
		goto node3426;
	}
node2309:
	b = randbool();
	if (b) {
		input[7] |= (1 << 3);
		goto node6368;
	} else {
		input[7] &= ~(1 << 3);
		goto node5227;
	}
node3832:
	b = randbool();
	if (b) {
		input[1] |= (1 << 2);
		goto node6787;
	} else {
		input[1] &= ~(1 << 2);
		goto node716;
	}
node7542:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node747;
	} else {
		input[2] &= ~(1 << 3);
		goto node3753;
	}
node8890:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node7216;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node6749:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node3366;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node9265:
	b = false;
	if (b) {
		input[2] |= (1 << 5);
		return 0;
	} else {
		input[2] &= ~(1 << 5);
		goto node6885;
	}
node9426:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node5668;
	} else {
		input[3] &= ~(1 << 4);
		goto node5568;
	}
node3717:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node7632;
	} else {
		input[3] &= ~(1 << 3);
		goto node6559;
	}
node1432:
	b = randbool();
	if (b) {
		input[4] |= (1 << 2);
		goto node7576;
	} else {
		input[4] &= ~(1 << 2);
		goto node1493;
	}
node5323:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node1528;
	} else {
		input[2] &= ~(1 << 6);
		goto node4541;
	}
node7072:
	b = false;
	if (b) {
		input[2] |= (1 << 2);
		return 0;
	} else {
		input[2] &= ~(1 << 2);
		goto node4660;
	}
node2187:
	b = false;
	if (b) {
		input[3] |= (1 << 7);
		return 0;
	} else {
		input[3] &= ~(1 << 7);
		goto node3209;
	}
node633:
	b = true;
	if (b) {
		input[3] |= (1 << 2);
		goto node6297;
	} else {
		input[3] &= ~(1 << 2);
		return 0;
	}
node5990:
	b = randbool();
	if (b) {
		input[4] |= (1 << 3);
		goto node151;
	} else {
		input[4] &= ~(1 << 3);
		goto node2215;
	}
node1852:
	b = randbool();
	if (b) {
		input[6] |= (1 << 4);
		goto node8202;
	} else {
		input[6] &= ~(1 << 4);
		goto node7085;
	}
node1410:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node2756;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node2834:
	b = false;
	if (b) {
		input[3] |= (1 << 1);
		return 0;
	} else {
		input[3] &= ~(1 << 1);
		goto node3880;
	}
node1545:
	b = true;
	if (b) {
		input[1] |= (1 << 5);
		goto node821;
	} else {
		input[1] &= ~(1 << 5);
		return 0;
	}
node4273:
	b = true;
	if (b) {
		input[1] |= (1 << 5);
		goto node8810;
	} else {
		input[1] &= ~(1 << 5);
		return 0;
	}
node4900:
	b = randbool();
	if (b) {
		input[1] |= (1 << 3);
		goto node7979;
	} else {
		input[1] &= ~(1 << 3);
		goto node4246;
	}
node1468:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node3681;
	} else {
		input[2] &= ~(1 << 3);
		goto node6669;
	}
node7655:
	b = false;
	if (b) {
		input[2] |= (1 << 3);
		return 0;
	} else {
		input[2] &= ~(1 << 3);
		goto node6878;
	}
node7690:
	b = false;
	if (b) {
		input[3] |= (1 << 7);
		return 0;
	} else {
		input[3] &= ~(1 << 7);
		goto node6901;
	}
node8857:
	b = false;
	if (b) {
		input[5] |= (1 << 7);
		return 0;
	} else {
		input[5] &= ~(1 << 7);
		goto node9138;
	}
node6783:
	b = true;
	if (b) {
		input[1] |= (1 << 0);
		goto node5388;
	} else {
		input[1] &= ~(1 << 0);
		return 0;
	}
node3351:
	b = false;
	if (b) {
		input[2] |= (1 << 5);
		return 0;
	} else {
		input[2] &= ~(1 << 5);
		goto node4875;
	}
node2857:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node3425;
	} else {
		input[2] &= ~(1 << 2);
		goto node8433;
	}
node2897:
	b = false;
	if (b) {
		input[3] |= (1 << 7);
		return 0;
	} else {
		input[3] &= ~(1 << 7);
		goto node5036;
	}
node8339:
	b = true;
	if (b) {
		input[3] |= (1 << 6);
		goto node4507;
	} else {
		input[3] &= ~(1 << 6);
		return 0;
	}
node2898:
	b = false;
	if (b) {
		input[5] |= (1 << 7);
		return 0;
	} else {
		input[5] &= ~(1 << 7);
		goto node1905;
	}
node1569:
	b = randbool();
	if (b) {
		input[1] |= (1 << 5);
		goto node1978;
	} else {
		input[1] &= ~(1 << 5);
		goto node1428;
	}
node2318:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node7153;
	} else {
		input[2] &= ~(1 << 3);
		goto node752;
	}
node3691:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node7627;
	} else {
		input[3] &= ~(1 << 6);
		goto node4688;
	}
node8009:
	b = false;
	if (b) {
		input[3] |= (1 << 0);
		return 0;
	} else {
		input[3] &= ~(1 << 0);
		goto node2701;
	}
node8004:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node6507;
	} else {
		input[3] &= ~(1 << 4);
		goto node1718;
	}
node4100:
	b = false;
	if (b) {
		input[1] |= (1 << 2);
		return 0;
	} else {
		input[1] &= ~(1 << 2);
		goto node3215;
	}
node1177:
	b = true;
	if (b) {
		input[1] |= (1 << 1);
		goto node6139;
	} else {
		input[1] &= ~(1 << 1);
		return 0;
	}
node9207:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node1186;
	} else {
		input[2] &= ~(1 << 6);
		goto node1369;
	}
node1572:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node4889;
	} else {
		input[2] &= ~(1 << 5);
		goto node66;
	}
node3021:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node1244;
	}
node4537:
	b = true;
	if (b) {
		input[3] |= (1 << 7);
		goto node3226;
	} else {
		input[3] &= ~(1 << 7);
		return 0;
	}
node4172:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node6161;
	} else {
		input[3] &= ~(1 << 5);
		goto node7246;
	}
node1099:
	b = true;
	if (b) {
		input[3] |= (1 << 2);
		goto node2697;
	} else {
		input[3] &= ~(1 << 2);
		return 0;
	}
node4661:
	b = randbool();
	if (b) {
		input[3] |= (1 << 1);
		goto node270;
	} else {
		input[3] &= ~(1 << 1);
		goto node7020;
	}
node4175:
	b = false;
	if (b) {
		input[1] |= (1 << 3);
		return 0;
	} else {
		input[1] &= ~(1 << 3);
		goto node2239;
	}
node6043:
	b = false;
	if (b) {
		input[2] |= (1 << 1);
		return 0;
	} else {
		input[2] &= ~(1 << 1);
		goto node1193;
	}
node3082:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node6462;
	} else {
		input[3] &= ~(1 << 4);
		goto node9048;
	}
node2506:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node6796;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node1339:
	b = true;
	if (b) {
		input[1] |= (1 << 0);
		goto node2019;
	} else {
		input[1] &= ~(1 << 0);
		return 0;
	}
node1158:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node6258;
	} else {
		input[3] &= ~(1 << 7);
		goto node3691;
	}
node7658:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node1223;
	} else {
		input[3] &= ~(1 << 2);
		goto node1896;
	}
node2647:
	b = randbool();
	if (b) {
		input[4] |= (1 << 4);
		goto node6291;
	} else {
		input[4] &= ~(1 << 4);
		goto node7015;
	}
node8261:
	b = true;
	if (b) {
		input[1] |= (1 << 2);
		goto node7316;
	} else {
		input[1] &= ~(1 << 2);
		return 0;
	}
node4820:
	b = randbool();
	if (b) {
		input[4] |= (1 << 6);
		goto node447;
	} else {
		input[4] &= ~(1 << 6);
		goto node2943;
	}
node2402:
	b = randbool();
	if (b) {
		input[0] |= (1 << 0);
		return 1;
	} else {
		input[0] &= ~(1 << 0);
		return 3;
	}
node9054:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node117;
	} else {
		input[2] &= ~(1 << 1);
		goto node7887;
	}
node6405:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node274;
	} else {
		input[3] &= ~(1 << 7);
		goto node6004;
	}
node8287:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node2131;
	} else {
		input[3] &= ~(1 << 6);
		goto node2459;
	}
node3638:
	b = true;
	if (b) {
		input[3] |= (1 << 1);
		goto node3881;
	} else {
		input[3] &= ~(1 << 1);
		return 0;
	}
node3020:
	b = true;
	if (b) {
		input[2] |= (1 << 6);
		goto node1453;
	} else {
		input[2] &= ~(1 << 6);
		return 0;
	}
node7344:
	b = false;
	if (b) {
		input[2] |= (1 << 1);
		return 0;
	} else {
		input[2] &= ~(1 << 1);
		goto node8302;
	}
node392:
	b = false;
	if (b) {
		input[4] |= (1 << 1);
		return 0;
	} else {
		input[4] &= ~(1 << 1);
		goto node8758;
	}
node2449:
	b = true;
	if (b) {
		input[2] |= (1 << 2);
		goto node9395;
	} else {
		input[2] &= ~(1 << 2);
		return 0;
	}
node2603:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node4912;
	} else {
		input[3] &= ~(1 << 6);
		goto node6576;
	}
node8271:
	b = randbool();
	if (b) {
		input[4] |= (1 << 2);
		goto node4840;
	} else {
		input[4] &= ~(1 << 2);
		goto node694;
	}
node9046:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		return 3;
	} else {
		input[2] &= ~(1 << 4);
		goto node1887;
	}
node8454:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node8046;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node2636:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node6037;
	} else {
		input[3] &= ~(1 << 2);
		goto node3314;
	}
node7816:
	b = true;
	if (b) {
		input[3] |= (1 << 2);
		goto node124;
	} else {
		input[3] &= ~(1 << 2);
		return 0;
	}
node3595:
	b = true;
	if (b) {
		input[3] |= (1 << 2);
		goto node6922;
	} else {
		input[3] &= ~(1 << 2);
		return 0;
	}
node2227:
	b = randbool();
	if (b) {
		input[0] |= (1 << 3);
		goto node8701;
	} else {
		input[0] &= ~(1 << 3);
		goto node4218;
	}
node7958:
	b = randbool();
	if (b) {
		input[1] |= (1 << 0);
		goto node1843;
	} else {
		input[1] &= ~(1 << 0);
		goto node3259;
	}
node4519:
	b = randbool();
	if (b) {
		input[1] |= (1 << 4);
		return 2;
	} else {
		input[1] &= ~(1 << 4);
		goto node6704;
	}
node5897:
	b = false;
	if (b) {
		input[1] |= (1 << 4);
		return 0;
	} else {
		input[1] &= ~(1 << 4);
		goto node3847;
	}
node2624:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node8024;
	} else {
		input[2] &= ~(1 << 4);
		goto node5306;
	}
node3534:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		return 3;
	} else {
		input[2] &= ~(1 << 3);
		goto node9403;
	}
node4521:
	b = randbool();
	if (b) {
		input[2] |= (1 << 0);
		goto node9458;
	} else {
		input[2] &= ~(1 << 0);
		goto node9415;
	}
node8476:
	b = false;
	if (b) {
		input[3] |= (1 << 1);
		return 0;
	} else {
		input[3] &= ~(1 << 1);
		goto node5759;
	}
node9467:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node7647;
	} else {
		input[3] &= ~(1 << 3);
		goto node4510;
	}
node4018:
	b = false;
	if (b) {
		input[5] |= (1 << 1);
		return 0;
	} else {
		input[5] &= ~(1 << 1);
		goto node885;
	}
node2028:
	b = true;
	if (b) {
		input[1] |= (1 << 6);
		goto node6846;
	} else {
		input[1] &= ~(1 << 6);
		return 0;
	}
node9463:
	b = randbool();
	if (b) {
		input[1] |= (1 << 5);
		goto node4274;
	} else {
		input[1] &= ~(1 << 5);
		goto node24;
	}
node3099:
	b = true;
	if (b) {
		input[2] |= (1 << 6);
		goto node7712;
	} else {
		input[2] &= ~(1 << 6);
		return 0;
	}
node5480:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node6553;
	} else {
		input[2] &= ~(1 << 2);
		goto node1708;
	}
node7176:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node418;
	} else {
		input[3] &= ~(1 << 4);
		goto node2374;
	}
node1613:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node4145;
	}
node8770:
	b = false;
	if (b) {
		input[2] |= (1 << 6);
		return 0;
	} else {
		input[2] &= ~(1 << 6);
		goto node7541;
	}
node7578:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node2246;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node2507:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node9283;
	} else {
		input[3] &= ~(1 << 3);
		goto node2672;
	}
node9083:
	b = randbool();
	if (b) {
		input[6] |= (1 << 4);
		goto node629;
	} else {
		input[6] &= ~(1 << 4);
		goto node4637;
	}
node1366:
	b = false;
	if (b) {
		input[2] |= (1 << 3);
		return 0;
	} else {
		input[2] &= ~(1 << 3);
		goto node8050;
	}
node4473:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		goto node9131;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node2224:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node507;
	} else {
		input[3] &= ~(1 << 7);
		goto node3164;
	}
node3776:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node3926;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node4599:
	b = false;
	if (b) {
		input[4] |= (1 << 2);
		return 0;
	} else {
		input[4] &= ~(1 << 2);
		goto node5570;
	}
node1754:
	b = randbool();
	if (b) {
		input[5] |= (1 << 2);
		goto node8541;
	} else {
		input[5] &= ~(1 << 2);
		return 6;
	}
node5355:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node4608;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node1335:
	b = true;
	if (b) {
		input[3] |= (1 << 2);
		goto node3808;
	} else {
		input[3] &= ~(1 << 2);
		return 0;
	}
node8757:
	b = true;
	if (b) {
		input[4] |= (1 << 3);
		return 5;
	} else {
		input[4] &= ~(1 << 3);
		return 0;
	}
node7269:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		goto node4151;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node565:
	b = false;
	if (b) {
		input[3] |= (1 << 6);
		return 0;
	} else {
		input[3] &= ~(1 << 6);
		goto node6657;
	}
node2820:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node3076;
	}
node3277:
	b = randbool();
	if (b) {
		input[2] |= (1 << 7);
		goto node7181;
	} else {
		input[2] &= ~(1 << 7);
		goto node7343;
	}
node5173:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node5250;
	} else {
		input[3] &= ~(1 << 5);
		goto node4828;
	}
node6959:
	b = false;
	if (b) {
		input[4] |= (1 << 1);
		return 0;
	} else {
		input[4] &= ~(1 << 1);
		goto node1166;
	}
node8704:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node3449;
	} else {
		input[3] &= ~(1 << 7);
		goto node1562;
	}
node8762:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node7960;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node7551:
	b = false;
	if (b) {
		input[3] |= (1 << 1);
		return 0;
	} else {
		input[3] &= ~(1 << 1);
		goto node7112;
	}
node8092:
	b = randbool();
	if (b) {
		input[2] |= (1 << 0);
		goto node7461;
	} else {
		input[2] &= ~(1 << 0);
		goto node2896;
	}
node7032:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node8772;
	} else {
		input[3] &= ~(1 << 4);
		goto node5272;
	}
node2098:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node8777;
	} else {
		input[3] &= ~(1 << 4);
		goto node434;
	}
node1973:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node8197;
	}
node2048:
	b = false;
	if (b) {
		input[1] |= (1 << 4);
		return 0;
	} else {
		input[1] &= ~(1 << 4);
		goto node6688;
	}
node468:
	b = false;
	if (b) {
		input[2] |= (1 << 7);
		return 0;
	} else {
		input[2] &= ~(1 << 7);
		goto node2879;
	}
node8744:
	b = false;
	if (b) {
		input[2] |= (1 << 7);
		return 0;
	} else {
		input[2] &= ~(1 << 7);
		goto node2718;
	}
node1497:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node8721;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node6467:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node9341;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node2640:
	b = true;
	if (b) {
		input[2] |= (1 << 6);
		goto node2275;
	} else {
		input[2] &= ~(1 << 6);
		return 0;
	}
node6082:
	b = true;
	if (b) {
		input[3] |= (1 << 2);
		goto node4316;
	} else {
		input[3] &= ~(1 << 2);
		return 0;
	}
node2868:
	b = false;
	if (b) {
		input[3] |= (1 << 0);
		return 0;
	} else {
		input[3] &= ~(1 << 0);
		goto node3530;
	}
node3383:
	b = randbool();
	if (b) {
		input[4] |= (1 << 1);
		return 5;
	} else {
		input[4] &= ~(1 << 1);
		goto node1658;
	}
node5842:
	b = false;
	if (b) {
		input[4] |= (1 << 0);
		return 0;
	} else {
		input[4] &= ~(1 << 0);
		goto node6326;
	}
node3994:
	b = randbool();
	if (b) {
		input[5] |= (1 << 2);
		goto node9245;
	} else {
		input[5] &= ~(1 << 2);
		return 7;
	}
node5735:
	b = randbool();
	if (b) {
		input[1] |= (1 << 5);
		goto node4594;
	} else {
		input[1] &= ~(1 << 5);
		goto node930;
	}
node6690:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node1627;
	} else {
		input[3] &= ~(1 << 5);
		goto node731;
	}
node6723:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node8749;
	} else {
		input[3] &= ~(1 << 4);
		goto node2517;
	}
node8247:
	b = false;
	if (b) {
		input[4] |= (1 << 1);
		return 0;
	} else {
		input[4] &= ~(1 << 1);
		goto node3054;
	}
node779:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node5801;
	} else {
		input[2] &= ~(1 << 4);
		goto node5390;
	}
node6875:
	b = true;
	if (b) {
		input[3] |= (1 << 1);
		goto node8954;
	} else {
		input[3] &= ~(1 << 1);
		return 0;
	}
node4927:
	b = randbool();
	if (b) {
		input[4] |= (1 << 3);
		goto node6639;
	} else {
		input[4] &= ~(1 << 3);
		goto node5984;
	}
node1704:
	b = false;
	if (b) {
		input[3] |= (1 << 6);
		return 0;
	} else {
		input[3] &= ~(1 << 6);
		goto node2549;
	}
node4863:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node5490;
	} else {
		input[3] &= ~(1 << 4);
		goto node1200;
	}
node845:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node3456;
	} else {
		input[3] &= ~(1 << 4);
		goto node2629;
	}
node6005:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node8916;
	} else {
		input[3] &= ~(1 << 4);
		goto node6462;
	}
node3820:
	b = true;
	if (b) {
		input[4] |= (1 << 7);
		goto node3489;
	} else {
		input[4] &= ~(1 << 7);
		return 0;
	}
node3916:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node9433;
	} else {
		input[3] &= ~(1 << 3);
		goto node5668;
	}
node8886:
	b = false;
	if (b) {
		input[3] |= (1 << 1);
		return 0;
	} else {
		input[3] &= ~(1 << 1);
		goto node4168;
	}
node8562:
	b = randbool();
	if (b) {
		input[1] |= (1 << 3);
		goto node8369;
	} else {
		input[1] &= ~(1 << 3);
		goto node9013;
	}
node4084:
	b = true;
	if (b) {
		input[1] |= (1 << 0);
		goto node2544;
	} else {
		input[1] &= ~(1 << 0);
		return 0;
	}
node1815:
	b = false;
	if (b) {
		input[2] |= (1 << 2);
		return 0;
	} else {
		input[2] &= ~(1 << 2);
		goto node8895;
	}
node7030:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node6855;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node2088:
	b = false;
	if (b) {
		input[3] |= (1 << 6);
		return 0;
	} else {
		input[3] &= ~(1 << 6);
		goto node4783;
	}
node8365:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node8458;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node3757:
	b = true;
	if (b) {
		input[4] |= (1 << 5);
		goto node8736;
	} else {
		input[4] &= ~(1 << 5);
		return 0;
	}
node8412:
	b = randbool();
	if (b) {
		input[4] |= (1 << 4);
		goto node5729;
	} else {
		input[4] &= ~(1 << 4);
		goto node2186;
	}
node442:
	b = false;
	if (b) {
		input[5] |= (1 << 3);
		return 0;
	} else {
		input[5] &= ~(1 << 3);
		goto node1851;
	}
node8159:
	b = randbool();
	if (b) {
		input[1] |= (1 << 0);
		goto node6186;
	} else {
		input[1] &= ~(1 << 0);
		goto node4909;
	}
node2274:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node1140;
	} else {
		input[2] &= ~(1 << 6);
		goto node4770;
	}
node1816:
	b = true;
	if (b) {
		input[2] |= (1 << 2);
		goto node190;
	} else {
		input[2] &= ~(1 << 2);
		return 0;
	}
node4735:
	b = true;
	if (b) {
		input[3] |= (1 << 0);
		goto node137;
	} else {
		input[3] &= ~(1 << 0);
		return 0;
	}
node6844:
	b = false;
	if (b) {
		input[4] |= (1 << 4);
		return 0;
	} else {
		input[4] &= ~(1 << 4);
		goto node2127;
	}
node9022:
	b = false;
	if (b) {
		input[3] |= (1 << 2);
		return 0;
	} else {
		input[3] &= ~(1 << 2);
		goto node832;
	}
node1048:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node3266;
	} else {
		input[3] &= ~(1 << 2);
		goto node9388;
	}
node8616:
	b = randbool();
	if (b) {
		input[1] |= (1 << 0);
		goto node5429;
	} else {
		input[1] &= ~(1 << 0);
		goto node7046;
	}
node7980:
	b = false;
	if (b) {
		input[2] |= (1 << 2);
		return 0;
	} else {
		input[2] &= ~(1 << 2);
		goto node907;
	}
node9458:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node7075;
	} else {
		input[3] &= ~(1 << 7);
		goto node4710;
	}
node1627:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node8437;
	}
node7918:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node4893;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node4399:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node7780;
	}
node4672:
	b = true;
	if (b) {
		input[4] |= (1 << 2);
		goto node9256;
	} else {
		input[4] &= ~(1 << 2);
		return 0;
	}
node4185:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node1723;
	}
node8059:
	b = false;
	if (b) {
		input[2] |= (1 << 1);
		return 0;
	} else {
		input[2] &= ~(1 << 1);
		goto node7220;
	}
node8705:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node6296;
	} else {
		input[3] &= ~(1 << 4);
		goto node1018;
	}
node205:
	b = true;
	if (b) {
		input[4] |= (1 << 2);
		goto node1657;
	} else {
		input[4] &= ~(1 << 2);
		return 0;
	}
node6289:
	b = false;
	if (b) {
		input[4] |= (1 << 1);
		return 0;
	} else {
		input[4] &= ~(1 << 1);
		goto node7422;
	}
node6160:
	b = true;
	if (b) {
		input[3] |= (1 << 6);
		goto node8885;
	} else {
		input[3] &= ~(1 << 6);
		return 0;
	}
node6123:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node9044;
	}
node4614:
	b = true;
	if (b) {
		input[3] |= (1 << 2);
		goto node8007;
	} else {
		input[3] &= ~(1 << 2);
		return 0;
	}
node1253:
	b = true;
	if (b) {
		input[4] |= (1 << 2);
		goto node8259;
	} else {
		input[4] &= ~(1 << 2);
		return 0;
	}
node9390:
	b = false;
	if (b) {
		input[4] |= (1 << 1);
		return 0;
	} else {
		input[4] &= ~(1 << 1);
		goto node8656;
	}
node1264:
	b = true;
	if (b) {
		input[6] |= (1 << 2);
		goto node75;
	} else {
		input[6] &= ~(1 << 2);
		return 0;
	}
node991:
	b = randbool();
	if (b) {
		input[0] |= (1 << 2);
		return 1;
	} else {
		input[0] &= ~(1 << 2);
		return 9;
	}
node2849:
	b = true;
	if (b) {
		input[2] |= (1 << 3);
		goto node2856;
	} else {
		input[2] &= ~(1 << 3);
		return 0;
	}
node2683:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node4431;
	}
node1507:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node8143;
	} else {
		input[3] &= ~(1 << 3);
		goto node5846;
	}
node2612:
	b = randbool();
	if (b) {
		input[5] |= (1 << 2);
		goto node1069;
	} else {
		input[5] &= ~(1 << 2);
		return 7;
	}
node2001:
	b = randbool();
	if (b) {
		input[1] |= (1 << 2);
		goto node8206;
	} else {
		input[1] &= ~(1 << 2);
		goto node9026;
	}
node4155:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node1518;
	} else {
		input[3] &= ~(1 << 5);
		return 4;
	}
node685:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node4757;
	} else {
		input[3] &= ~(1 << 4);
		goto node7766;
	}
node3574:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node3452;
	}
node6782:
	b = randbool();
	if (b) {
		input[1] |= (1 << 5);
		goto node858;
	} else {
		input[1] &= ~(1 << 5);
		goto node583;
	}
node1312:
	b = randbool();
	if (b) {
		input[1] |= (1 << 4);
		goto node64;
	} else {
		input[1] &= ~(1 << 4);
		goto node9270;
	}
node3443:
	b = true;
	if (b) {
		input[1] |= (1 << 1);
		goto node3860;
	} else {
		input[1] &= ~(1 << 1);
		return 0;
	}
node1797:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node2372;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node443:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node9020;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node6767:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node721;
	} else {
		input[3] &= ~(1 << 4);
		goto node8122;
	}
node230:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node5472;
	} else {
		input[3] &= ~(1 << 4);
		goto node2745;
	}
node989:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node7135;
	}
node6757:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node2292;
	}
node3889:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node6270;
	}
node7735:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		return 3;
	} else {
		input[2] &= ~(1 << 3);
		goto node4746;
	}
node8156:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node4819;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node9186:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node5750;
	} else {
		input[3] &= ~(1 << 4);
		goto node4064;
	}
node7994:
	b = randbool();
	if (b) {
		input[4] |= (1 << 3);
		goto node6858;
	} else {
		input[4] &= ~(1 << 3);
		goto node1997;
	}
node4258:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node7887;
	} else {
		input[2] &= ~(1 << 3);
		goto node4577;
	}
node949:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		goto node2516;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node2739:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node3678;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node176:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node2296;
	}
node549:
	b = false;
	if (b) {
		input[4] |= (1 << 5);
		return 0;
	} else {
		input[4] &= ~(1 << 5);
		goto node5966;
	}
node4679:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node7801;
	} else {
		input[2] &= ~(1 << 6);
		goto node671;
	}
node907:
	b = false;
	if (b) {
		input[2] |= (1 << 1);
		return 0;
	} else {
		input[2] &= ~(1 << 1);
		goto node7887;
	}
node8116:
	b = randbool();
	if (b) {
		input[7] |= (1 << 5);
		goto node8117;
	} else {
		input[7] &= ~(1 << 5);
		goto node1376;
	}
node8224:
	b = true;
	if (b) {
		input[4] |= (1 << 2);
		goto node8108;
	} else {
		input[4] &= ~(1 << 2);
		return 0;
	}
node4045:
	b = true;
	if (b) {
		input[2] |= (1 << 2);
		goto node8346;
	} else {
		input[2] &= ~(1 << 2);
		return 0;
	}
node6817:
	b = false;
	if (b) {
		input[2] |= (1 << 2);
		return 0;
	} else {
		input[2] &= ~(1 << 2);
		goto node5810;
	}
node1708:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node5120;
	} else {
		input[2] &= ~(1 << 1);
		goto node847;
	}
node3783:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		goto node7361;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node7964:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node7099;
	} else {
		input[3] &= ~(1 << 6);
		goto node5439;
	}
node3473:
	b = false;
	if (b) {
		input[3] |= (1 << 2);
		return 0;
	} else {
		input[3] &= ~(1 << 2);
		goto node6007;
	}
node9299:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node2187;
	}
node7923:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node5302;
	} else {
		input[3] &= ~(1 << 7);
		goto node565;
	}
node649:
	b = true;
	if (b) {
		input[3] |= (1 << 6);
		goto node2259;
	} else {
		input[3] &= ~(1 << 6);
		return 0;
	}
node9041:
	b = true;
	if (b) {
		input[1] |= (1 << 1);
		goto node7290;
	} else {
		input[1] &= ~(1 << 1);
		return 0;
	}
node7507:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node516;
	} else {
		input[2] &= ~(1 << 4);
		goto node5797;
	}
node5633:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node6945;
	} else {
		input[3] &= ~(1 << 6);
		goto node1341;
	}
node1642:
	b = randbool();
	if (b) {
		input[3] |= (1 << 0);
		return 8;
	} else {
		input[3] &= ~(1 << 0);
		goto node7336;
	}
node2042:
	b = randbool();
	if (b) {
		input[6] |= (1 << 2);
		goto node7232;
	} else {
		input[6] &= ~(1 << 2);
		return 7;
	}
node973:
	b = randbool();
	if (b) {
		input[7] |= (1 << 2);
		goto node1552;
	} else {
		input[7] &= ~(1 << 2);
		return 8;
	}
node5563:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node5559;
	}
node5158:
	b = false;
	if (b) {
		input[4] |= (1 << 3);
		return 0;
	} else {
		input[4] &= ~(1 << 3);
		goto node6845;
	}
node4565:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node4463;
	} else {
		input[2] &= ~(1 << 2);
		goto node6455;
	}
node3197:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node1739;
	} else {
		input[2] &= ~(1 << 2);
		goto node4071;
	}
node3069:
	b = false;
	if (b) {
		input[2] |= (1 << 1);
		return 0;
	} else {
		input[2] &= ~(1 << 1);
		goto node3592;
	}
node2598:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node72;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node8865:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node4516;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node2015:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node857;
	} else {
		input[3] &= ~(1 << 2);
		goto node4074;
	}
node137:
	b = false;
	if (b) {
		input[4] |= (1 << 7);
		return 0;
	} else {
		input[4] &= ~(1 << 7);
		goto node3202;
	}
node2176:
	b = true;
	if (b) {
		input[4] |= (1 << 5);
		goto node7776;
	} else {
		input[4] &= ~(1 << 5);
		return 0;
	}
node3467:
	b = randbool();
	if (b) {
		input[1] |= (1 << 5);
		goto node1650;
	} else {
		input[1] &= ~(1 << 5);
		goto node625;
	}
node9025:
	b = randbool();
	if (b) {
		input[1] |= (1 << 2);
		return 2;
	} else {
		input[1] &= ~(1 << 2);
		goto node129;
	}
node6214:
	b = randbool();
	if (b) {
		input[2] |= (1 << 0);
		goto node2102;
	} else {
		input[2] &= ~(1 << 0);
		goto node9249;
	}
node9266:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node4027;
	} else {
		input[3] &= ~(1 << 7);
		goto node8404;
	}
node8462:
	b = randbool();
	if (b) {
		input[3] |= (1 << 1);
		goto node6462;
	} else {
		input[3] &= ~(1 << 1);
		goto node2584;
	}
node5535:
	b = randbool();
	if (b) {
		input[4] |= (1 << 7);
		goto node8228;
	} else {
		input[4] &= ~(1 << 7);
		goto node4820;
	}
node1057:
	b = true;
	if (b) {
		input[4] |= (1 << 3);
		goto node5049;
	} else {
		input[4] &= ~(1 << 3);
		return 0;
	}
node6973:
	b = false;
	if (b) {
		input[4] |= (1 << 0);
		return 0;
	} else {
		input[4] &= ~(1 << 0);
		goto node2898;
	}
node5396:
	b = false;
	if (b) {
		input[2] |= (1 << 0);
		return 0;
	} else {
		input[2] &= ~(1 << 0);
		goto node4566;
	}
node977:
	b = false;
	if (b) {
		input[3] |= (1 << 6);
		return 0;
	} else {
		input[3] &= ~(1 << 6);
		goto node1606;
	}
node2699:
	b = true;
	if (b) {
		input[3] |= (1 << 6);
		goto node2809;
	} else {
		input[3] &= ~(1 << 6);
		return 0;
	}
node7195:
	b = true;
	if (b) {
		input[3] |= (1 << 2);
		goto node4735;
	} else {
		input[3] &= ~(1 << 2);
		return 0;
	}
node4051:
	b = true;
	if (b) {
		input[3] |= (1 << 2);
		return 4;
	} else {
		input[3] &= ~(1 << 2);
		return 0;
	}
node8756:
	b = randbool();
	if (b) {
		input[3] |= (1 << 0);
		goto node1423;
	} else {
		input[3] &= ~(1 << 0);
		goto node137;
	}
node6384:
	b = randbool();
	if (b) {
		input[1] |= (1 << 4);
		goto node5097;
	} else {
		input[1] &= ~(1 << 4);
		goto node4928;
	}
node5378:
	b = randbool();
	if (b) {
		input[1] |= (1 << 2);
		goto node1585;
	} else {
		input[1] &= ~(1 << 2);
		goto node5766;
	}
node2965:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		return 3;
	} else {
		input[2] &= ~(1 << 4);
		goto node8841;
	}
node517:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node7887;
	} else {
		input[2] &= ~(1 << 2);
		goto node2241;
	}
node6437:
	b = false;
	if (b) {
		input[4] |= (1 << 0);
		return 0;
	} else {
		input[4] &= ~(1 << 0);
		goto node5864;
	}
node9250:
	b = true;
	if (b) {
		input[3] |= (1 << 7);
		goto node2096;
	} else {
		input[3] &= ~(1 << 7);
		return 0;
	}
node5918:
	b = true;
	if (b) {
		input[3] |= (1 << 0);
		goto node58;
	} else {
		input[3] &= ~(1 << 0);
		return 0;
	}
node1564:
	b = false;
	if (b) {
		input[4] |= (1 << 1);
		return 0;
	} else {
		input[4] &= ~(1 << 1);
		goto node2808;
	}
node2064:
	b = false;
	if (b) {
		input[3] |= (1 << 0);
		return 0;
	} else {
		input[3] &= ~(1 << 0);
		goto node5818;
	}
node4256:
	b = true;
	if (b) {
		input[4] |= (1 << 6);
		goto node4136;
	} else {
		input[4] &= ~(1 << 6);
		return 0;
	}
node3177:
	b = false;
	if (b) {
		input[1] |= (1 << 3);
		return 0;
	} else {
		input[1] &= ~(1 << 3);
		goto node8724;
	}
node9013:
	b = false;
	if (b) {
		input[1] |= (1 << 2);
		return 0;
	} else {
		input[1] &= ~(1 << 2);
		goto node6571;
	}
node3095:
	b = randbool();
	if (b) {
		input[2] |= (1 << 7);
		goto node5761;
	} else {
		input[2] &= ~(1 << 7);
		goto node1215;
	}
node4846:
	b = false;
	if (b) {
		input[2] |= (1 << 6);
		return 0;
	} else {
		input[2] &= ~(1 << 6);
		goto node961;
	}
node3533:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node2547;
	} else {
		input[2] &= ~(1 << 5);
		goto node2790;
	}
node1619:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node3009;
	} else {
		input[3] &= ~(1 << 7);
		goto node8112;
	}
node8956:
	b = false;
	if (b) {
		input[4] |= (1 << 1);
		return 0;
	} else {
		input[4] &= ~(1 << 1);
		goto node2638;
	}
node5689:
	b = randbool();
	if (b) {
		input[1] |= (1 << 7);
		goto node7565;
	} else {
		input[1] &= ~(1 << 7);
		goto node1925;
	}
node8501:
	b = randbool();
	if (b) {
		input[2] |= (1 << 0);
		goto node1121;
	} else {
		input[2] &= ~(1 << 0);
		goto node3184;
	}
node5303:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node7888;
	} else {
		input[3] &= ~(1 << 5);
		goto node5662;
	}
node227:
	b = true;
	if (b) {
		input[2] |= (1 << 5);
		goto node6426;
	} else {
		input[2] &= ~(1 << 5);
		return 0;
	}
node7183:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node6803;
	} else {
		input[3] &= ~(1 << 7);
		goto node1206;
	}
node4292:
	b = false;
	if (b) {
		input[3] |= (1 << 7);
		return 0;
	} else {
		input[3] &= ~(1 << 7);
		goto node5278;
	}
node8761:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node1413;
	} else {
		input[3] &= ~(1 << 5);
		goto node780;
	}
node5579:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node1800;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node4960:
	b = false;
	if (b) {
		input[3] |= (1 << 2);
		return 0;
	} else {
		input[3] &= ~(1 << 2);
		goto node1391;
	}
node2561:
	b = false;
	if (b) {
		input[1] |= (1 << 3);
		return 0;
	} else {
		input[1] &= ~(1 << 3);
		goto node2563;
	}
node3620:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node8487;
	} else {
		input[2] &= ~(1 << 4);
		goto node5791;
	}
node5850:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node2852;
	} else {
		input[3] &= ~(1 << 6);
		goto node5331;
	}
node1115:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node7632;
	} else {
		input[3] &= ~(1 << 2);
		goto node5492;
	}
node8236:
	b = true;
	if (b) {
		input[4] |= (1 << 6);
		goto node3459;
	} else {
		input[4] &= ~(1 << 6);
		return 0;
	}
node7828:
	b = randbool();
	if (b) {
		input[1] |= (1 << 5);
		goto node7086;
	} else {
		input[1] &= ~(1 << 5);
		goto node608;
	}
node7985:
	b = randbool();
	if (b) {
		input[1] |= (1 << 5);
		goto node4257;
	} else {
		input[1] &= ~(1 << 5);
		goto node7086;
	}
node8675:
	b = randbool();
	if (b) {
		input[1] |= (1 << 3);
		goto node8534;
	} else {
		input[1] &= ~(1 << 3);
		goto node1559;
	}
node6046:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node5701;
	}
node1674:
	b = false;
	if (b) {
		input[4] |= (1 << 1);
		return 0;
	} else {
		input[4] &= ~(1 << 1);
		goto node1401;
	}
node129:
	b = randbool();
	if (b) {
		input[1] |= (1 << 1);
		return 2;
	} else {
		input[1] &= ~(1 << 1);
		goto node7645;
	}
node3983:
	b = false;
	if (b) {
		input[2] |= (1 << 5);
		return 0;
	} else {
		input[2] &= ~(1 << 5);
		goto node6790;
	}
node210:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node6798;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node1472:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node8319;
	} else {
		input[2] &= ~(1 << 3);
		goto node7859;
	}
node1221:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node4271;
	} else {
		input[3] &= ~(1 << 6);
		goto node4187;
	}
node645:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node3520;
	} else {
		input[3] &= ~(1 << 3);
		goto node4204;
	}
node6315:
	b = false;
	if (b) {
		input[1] |= (1 << 3);
		return 0;
	} else {
		input[1] &= ~(1 << 3);
		goto node4221;
	}
node5217:
	b = false;
	if (b) {
		input[1] |= (1 << 0);
		return 0;
	} else {
		input[1] &= ~(1 << 0);
		goto node8225;
	}
node2059:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node9007;
	} else {
		input[3] &= ~(1 << 5);
		goto node2661;
	}
node7449:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node7622;
	} else {
		input[2] &= ~(1 << 3);
		goto node3957;
	}
node6154:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node4474;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node5374:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node2978;
	} else {
		input[3] &= ~(1 << 4);
		goto node2320;
	}
node4535:
	b = randbool();
	if (b) {
		input[1] |= (1 << 3);
		goto node6186;
	} else {
		input[1] &= ~(1 << 3);
		goto node6837;
	}
node924:
	b = true;
	if (b) {
		input[2] |= (1 << 5);
		goto node8559;
	} else {
		input[2] &= ~(1 << 5);
		return 0;
	}
node2230:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node1750;
	}
node8286:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node3124;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node8989:
	b = true;
	if (b) {
		input[4] |= (1 << 4);
		goto node7698;
	} else {
		input[4] &= ~(1 << 4);
		return 0;
	}
node6298:
	b = false;
	if (b) {
		input[1] |= (1 << 4);
		return 0;
	} else {
		input[1] &= ~(1 << 4);
		goto node980;
	}
node2321:
	b = randbool();
	if (b) {
		input[1] |= (1 << 6);
		goto node4273;
	} else {
		input[1] &= ~(1 << 6);
		goto node6965;
	}
node3747:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node9394;
	} else {
		input[2] &= ~(1 << 6);
		goto node1790;
	}
node7215:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node910;
	} else {
		input[3] &= ~(1 << 5);
		goto node6761;
	}
node996:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node6332;
	} else {
		input[3] &= ~(1 << 3);
		goto node8468;
	}
node4694:
	b = randbool();
	if (b) {
		input[3] |= (1 << 1);
		goto node4644;
	} else {
		input[3] &= ~(1 << 1);
		goto node1274;
	}
node7028:
	b = randbool();
	if (b) {
		input[2] |= (1 << 7);
		goto node9095;
	} else {
		input[2] &= ~(1 << 7);
		goto node3956;
	}
node2861:
	b = randbool();
	if (b) {
		input[2] |= (1 << 7);
		goto node7497;
	} else {
		input[2] &= ~(1 << 7);
		goto node2074;
	}
node4122:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node1540;
	} else {
		input[2] &= ~(1 << 6);
		goto node4262;
	}
node7482:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		return 3;
	} else {
		input[2] &= ~(1 << 5);
		goto node3036;
	}
node6536:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node2580;
	} else {
		input[2] &= ~(1 << 3);
		goto node7325;
	}
node656:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node1454;
	}
node8970:
	b = randbool();
	if (b) {
		input[1] |= (1 << 3);
		goto node7554;
	} else {
		input[1] &= ~(1 << 3);
		goto node8520;
	}
node5732:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node5690;
	} else {
		input[2] &= ~(1 << 5);
		goto node7700;
	}
node8971:
	b = false;
	if (b) {
		input[2] |= (1 << 3);
		return 0;
	} else {
		input[2] &= ~(1 << 3);
		goto node1449;
	}
node643:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node7657;
	} else {
		input[3] &= ~(1 << 5);
		goto node2226;
	}
node8633:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node1011;
	} else {
		input[3] &= ~(1 << 3);
		goto node137;
	}
node722:
	b = false;
	if (b) {
		input[3] |= (1 << 2);
		return 0;
	} else {
		input[3] &= ~(1 << 2);
		goto node2480;
	}
node8936:
	b = true;
	if (b) {
		input[1] |= (1 << 6);
		goto node1452;
	} else {
		input[1] &= ~(1 << 6);
		return 0;
	}
node1209:
	b = true;
	if (b) {
		input[1] |= (1 << 0);
		goto node282;
	} else {
		input[1] &= ~(1 << 0);
		return 0;
	}
node2420:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node1798;
	} else {
		input[3] &= ~(1 << 3);
		goto node9474;
	}
node8581:
	b = true;
	if (b) {
		input[1] |= (1 << 0);
		goto node5256;
	} else {
		input[1] &= ~(1 << 0);
		return 0;
	}
node1118:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node564;
	} else {
		input[2] &= ~(1 << 2);
		goto node5468;
	}
node1810:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node7864;
	} else {
		input[3] &= ~(1 << 7);
		goto node835;
	}
node5385:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node8357;
	} else {
		input[3] &= ~(1 << 5);
		goto node2292;
	}
node4118:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node8676;
	} else {
		input[3] &= ~(1 << 4);
		goto node5755;
	}
node9057:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node9355;
	} else {
		input[3] &= ~(1 << 2);
		goto node9387;
	}
node4178:
	b = true;
	if (b) {
		input[2] |= (1 << 2);
		goto node793;
	} else {
		input[2] &= ~(1 << 2);
		return 0;
	}
node3844:
	b = randbool();
	if (b) {
		input[4] |= (1 << 6);
		goto node7752;
	} else {
		input[4] &= ~(1 << 6);
		goto node874;
	}
node3794:
	b = randbool();
	if (b) {
		input[1] |= (1 << 1);
		goto node4222;
	} else {
		input[1] &= ~(1 << 1);
		goto node2019;
	}
node6387:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node4362;
	} else {
		input[2] &= ~(1 << 5);
		goto node8945;
	}
node2771:
	b = true;
	if (b) {
		input[3] |= (1 << 7);
		goto node5724;
	} else {
		input[3] &= ~(1 << 7);
		return 0;
	}
node2870:
	b = false;
	if (b) {
		input[3] |= (1 << 6);
		return 0;
	} else {
		input[3] &= ~(1 << 6);
		goto node1598;
	}
node7992:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node7726;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node1568:
	b = randbool();
	if (b) {
		input[4] |= (1 << 3);
		goto node3888;
	} else {
		input[4] &= ~(1 << 3);
		goto node1254;
	}
node3847:
	b = true;
	if (b) {
		input[1] |= (1 << 3);
		goto node5753;
	} else {
		input[1] &= ~(1 << 3);
		return 0;
	}
node8814:
	b = true;
	if (b) {
		input[3] |= (1 << 0);
		goto node7637;
	} else {
		input[3] &= ~(1 << 0);
		return 0;
	}
node5460:
	b = randbool();
	if (b) {
		input[4] |= (1 << 4);
		goto node5834;
	} else {
		input[4] &= ~(1 << 4);
		goto node3221;
	}
node8161:
	b = randbool();
	if (b) {
		input[2] |= (1 << 7);
		goto node2963;
	} else {
		input[2] &= ~(1 << 7);
		goto node6681;
	}
node8228:
	b = randbool();
	if (b) {
		input[4] |= (1 << 6);
		goto node9128;
	} else {
		input[4] &= ~(1 << 6);
		goto node3233;
	}
node4645:
	b = randbool();
	if (b) {
		input[4] |= (1 << 4);
		goto node635;
	} else {
		input[4] &= ~(1 << 4);
		goto node5517;
	}
node3610:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node1589;
	} else {
		input[2] &= ~(1 << 2);
		goto node4603;
	}
node1536:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node2475;
	} else {
		input[3] &= ~(1 << 5);
		goto node548;
	}
node7097:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node2218;
	} else {
		input[3] &= ~(1 << 4);
		goto node474;
	}
node3084:
	b = randbool();
	if (b) {
		input[4] |= (1 << 1);
		return 6;
	} else {
		input[4] &= ~(1 << 1);
		goto node3187;
	}
node8991:
	b = randbool();
	if (b) {
		input[1] |= (1 << 4);
		goto node5097;
	} else {
		input[1] &= ~(1 << 4);
		goto node8715;
	}
node65:
	b = randbool();
	if (b) {
		input[1] |= (1 << 1);
		goto node801;
	} else {
		input[1] &= ~(1 << 1);
		goto node1071;
	}
node1630:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node7668;
	} else {
		input[2] &= ~(1 << 4);
		goto node8737;
	}
node9395:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		goto node8457;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node8625:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node6273;
	} else {
		input[3] &= ~(1 << 4);
		goto node3389;
	}
node8384:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node8782;
	}
node7796:
	b = true;
	if (b) {
		input[1] |= (1 << 1);
		goto node8882;
	} else {
		input[1] &= ~(1 << 1);
		return 0;
	}
node6278:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node7668;
	} else {
		input[2] &= ~(1 << 5);
		goto node8737;
	}
node5987:
	b = true;
	if (b) {
		input[3] |= (1 << 6);
		goto node2934;
	} else {
		input[3] &= ~(1 << 6);
		return 0;
	}
node6888:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node7165;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node1149:
	b = true;
	if (b) {
		input[1] |= (1 << 6);
		goto node3982;
	} else {
		input[1] &= ~(1 << 6);
		return 0;
	}
node3163:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node5008;
	} else {
		input[3] &= ~(1 << 7);
		goto node8052;
	}
node9128:
	b = randbool();
	if (b) {
		input[4] |= (1 << 5);
		goto node5242;
	} else {
		input[4] &= ~(1 << 5);
		goto node8892;
	}
node8464:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node8016;
	} else {
		input[2] &= ~(1 << 6);
		goto node5067;
	}
node6821:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node1760;
	} else {
		input[3] &= ~(1 << 5);
		goto node2226;
	}
node3855:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node7982;
	}
node6456:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node7155;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node1363:
	b = true;
	if (b) {
		input[3] |= (1 << 0);
		goto node8081;
	} else {
		input[3] &= ~(1 << 0);
		return 0;
	}
node5300:
	b = randbool();
	if (b) {
		input[1] |= (1 << 7);
		goto node2704;
	} else {
		input[1] &= ~(1 << 7);
		goto node4823;
	}
node6233:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		goto node6355;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node2403:
	b = true;
	if (b) {
		input[3] |= (1 << 6);
		goto node6872;
	} else {
		input[3] &= ~(1 << 6);
		return 0;
	}
node5282:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node5147;
	}
node8658:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node8876;
	}
node4886:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node1918;
	} else {
		input[3] &= ~(1 << 3);
		goto node6835;
	}
node2423:
	b = randbool();
	if (b) {
		input[1] |= (1 << 5);
		goto node4908;
	} else {
		input[1] &= ~(1 << 5);
		goto node3980;
	}
node5329:
	b = true;
	if (b) {
		input[2] |= (1 << 2);
		goto node3263;
	} else {
		input[2] &= ~(1 << 2);
		return 0;
	}
node8106:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node3294;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node9213:
	b = true;
	if (b) {
		input[4] |= (1 << 6);
		goto node7817;
	} else {
		input[4] &= ~(1 << 6);
		return 0;
	}
node8674:
	b = randbool();
	if (b) {
		input[4] |= (1 << 2);
		goto node8305;
	} else {
		input[4] &= ~(1 << 2);
		goto node6022;
	}
node8999:
	b = true;
	if (b) {
		input[2] |= (1 << 3);
		goto node1379;
	} else {
		input[2] &= ~(1 << 3);
		return 0;
	}
node6089:
	b = true;
	if (b) {
		input[2] |= (1 << 3);
		goto node6817;
	} else {
		input[2] &= ~(1 << 3);
		return 0;
	}
node62:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node2865;
	} else {
		input[3] &= ~(1 << 7);
		goto node7846;
	}
node1828:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node5205;
	}
node6976:
	b = false;
	if (b) {
		input[4] |= (1 << 7);
		return 0;
	} else {
		input[4] &= ~(1 << 7);
		goto node1850;
	}
node6640:
	b = randbool();
	if (b) {
		input[5] |= (1 << 5);
		goto node2601;
	} else {
		input[5] &= ~(1 << 5);
		goto node9230;
	}
node599:
	b = false;
	if (b) {
		input[4] |= (1 << 2);
		return 0;
	} else {
		input[4] &= ~(1 << 2);
		goto node7583;
	}
node6202:
	b = randbool();
	if (b) {
		input[4] |= (1 << 1);
		goto node2027;
	} else {
		input[4] &= ~(1 << 1);
		goto node8305;
	}
node4943:
	b = randbool();
	if (b) {
		input[1] |= (1 << 4);
		goto node6771;
	} else {
		input[1] &= ~(1 << 4);
		goto node7086;
	}
node5925:
	b = randbool();
	if (b) {
		input[1] |= (1 << 1);
		goto node2690;
	} else {
		input[1] &= ~(1 << 1);
		goto node6186;
	}
node4320:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node5949;
	} else {
		input[2] &= ~(1 << 6);
		goto node1225;
	}
node7387:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node9406;
	} else {
		input[3] &= ~(1 << 7);
		goto node1128;
	}
node1963:
	b = false;
	if (b) {
		input[3] |= (1 << 7);
		return 0;
	} else {
		input[3] &= ~(1 << 7);
		goto node501;
	}
node8299:
	b = randbool();
	if (b) {
		input[4] |= (1 << 5);
		goto node70;
	} else {
		input[4] &= ~(1 << 5);
		goto node9187;
	}
node8594:
	b = randbool();
	if (b) {
		input[4] |= (1 << 1);
		goto node8966;
	} else {
		input[4] &= ~(1 << 1);
		goto node7417;
	}
node8932:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node7238;
	} else {
		input[2] &= ~(1 << 3);
		goto node7859;
	}
node6938:
	b = true;
	if (b) {
		input[2] |= (1 << 4);
		goto node8485;
	} else {
		input[2] &= ~(1 << 4);
		return 0;
	}
node3463:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		goto node1725;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node3836:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node2387;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node651:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node6777;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node124:
	b = false;
	if (b) {
		input[3] |= (1 << 1);
		return 0;
	} else {
		input[3] &= ~(1 << 1);
		goto node6547;
	}
node7732:
	b = randbool();
	if (b) {
		input[4] |= (1 << 1);
		return 5;
	} else {
		input[4] &= ~(1 << 1);
		goto node3684;
	}
node2635:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node3520;
	} else {
		input[3] &= ~(1 << 3);
		goto node5972;
	}
node5826:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node3682;
	}
node1070:
	b = false;
	if (b) {
		input[1] |= (1 << 6);
		return 0;
	} else {
		input[1] &= ~(1 << 6);
		goto node5867;
	}
node7383:
	b = false;
	if (b) {
		input[2] |= (1 << 7);
		return 0;
	} else {
		input[2] &= ~(1 << 7);
		goto node7126;
	}
node9242:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node4684;
	}
node8764:
	b = true;
	if (b) {
		input[2] |= (1 << 2);
		goto node8849;
	} else {
		input[2] &= ~(1 << 2);
		return 0;
	}
node1076:
	b = false;
	if (b) {
		input[2] |= (1 << 1);
		return 0;
	} else {
		input[2] &= ~(1 << 1);
		goto node2361;
	}
node4734:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node9359;
	}
node6934:
	b = randbool();
	if (b) {
		input[4] |= (1 << 5);
		goto node3339;
	} else {
		input[4] &= ~(1 << 5);
		goto node3888;
	}
node2804:
	b = true;
	if (b) {
		input[4] |= (1 << 4);
		goto node467;
	} else {
		input[4] &= ~(1 << 4);
		return 0;
	}
node1285:
	b = false;
	if (b) {
		input[1] |= (1 << 2);
		return 0;
	} else {
		input[1] &= ~(1 << 2);
		goto node6492;
	}
node3225:
	b = true;
	if (b) {
		input[2] |= (1 << 3);
		goto node4751;
	} else {
		input[2] &= ~(1 << 3);
		return 0;
	}
node6617:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node5492;
	} else {
		input[3] &= ~(1 << 2);
		goto node6950;
	}
node4038:
	b = true;
	if (b) {
		input[2] |= (1 << 6);
		goto node2649;
	} else {
		input[2] &= ~(1 << 6);
		return 0;
	}
node1960:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		return 3;
	}
node4527:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node2408;
	} else {
		input[3] &= ~(1 << 6);
		goto node5510;
	}
node3952:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node871;
	}
node8475:
	b = true;
	if (b) {
		input[3] |= (1 << 1);
		goto node5908;
	} else {
		input[3] &= ~(1 << 1);
		return 0;
	}
node8061:
	b = false;
	if (b) {
		input[3] |= (1 << 7);
		return 0;
	} else {
		input[3] &= ~(1 << 7);
		goto node3222;
	}
node5188:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node2053;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node7684:
	b = randbool();
	if (b) {
		input[3] |= (1 << 1);
		goto node4444;
	} else {
		input[3] &= ~(1 << 1);
		goto node2936;
	}
node7822:
	b = false;
	if (b) {
		input[4] |= (1 << 2);
		return 0;
	} else {
		input[4] &= ~(1 << 2);
		goto node7809;
	}
node7159:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node2406;
	} else {
		input[2] &= ~(1 << 3);
		goto node5975;
	}
node4704:
	b = false;
	if (b) {
		input[3] |= (1 << 7);
		return 0;
	} else {
		input[3] &= ~(1 << 7);
		goto node6655;
	}
node7670:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node6671;
	} else {
		input[3] &= ~(1 << 3);
		goto node1048;
	}
node5846:
	b = false;
	if (b) {
		input[3] |= (1 << 2);
		return 0;
	} else {
		input[3] &= ~(1 << 2);
		goto node7551;
	}
node2952:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node8776;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node4955:
	b = randbool();
	if (b) {
		input[1] |= (1 << 4);
		goto node5924;
	} else {
		input[1] &= ~(1 << 4);
		return 2;
	}
node1832:
	b = randbool();
	if (b) {
		input[1] |= (1 << 0);
		goto node7368;
	} else {
		input[1] &= ~(1 << 0);
		goto node9115;
	}
node3285:
	b = false;
	if (b) {
		input[2] |= (1 << 1);
		return 0;
	} else {
		input[2] &= ~(1 << 1);
		goto node1551;
	}
node8457:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node3799;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node4755:
	b = false;
	if (b) {
		input[3] |= (1 << 6);
		return 0;
	} else {
		input[3] &= ~(1 << 6);
		goto node710;
	}
node731:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node4836;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node8815:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node1186;
	} else {
		input[2] &= ~(1 << 6);
		goto node8788;
	}
node8746:
	b = true;
	if (b) {
		input[3] |= (1 << 6);
		goto node2404;
	} else {
		input[3] &= ~(1 << 6);
		return 0;
	}
node1739:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node1797;
	} else {
		input[2] &= ~(1 << 1);
		goto node3699;
	}
node8526:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node5153;
	} else {
		input[3] &= ~(1 << 3);
		goto node3595;
	}
node1653:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node1006;
	} else {
		input[2] &= ~(1 << 5);
		goto node1097;
	}
node4062:
	b = true;
	if (b) {
		input[2] |= (1 << 5);
		goto node3035;
	} else {
		input[2] &= ~(1 << 5);
		return 0;
	}
node8075:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node564;
	} else {
		input[2] &= ~(1 << 2);
		goto node8059;
	}
node1201:
	b = false;
	if (b) {
		input[4] |= (1 << 4);
		return 0;
	} else {
		input[4] &= ~(1 << 4);
		goto node4671;
	}
node4865:
	b = false;
	if (b) {
		input[4] |= (1 << 2);
		return 0;
	} else {
		input[4] &= ~(1 << 2);
		goto node6580;
	}
node3900:
	b = true;
	if (b) {
		input[1] |= (1 << 6);
		return 3;
	} else {
		input[1] &= ~(1 << 6);
		return 0;
	}
node7087:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		return 7;
	} else {
		input[2] &= ~(1 << 1);
		goto node1017;
	}
node262:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node4444;
	} else {
		input[3] &= ~(1 << 3);
		goto node4712;
	}
node8174:
	b = true;
	if (b) {
		input[3] |= (1 << 2);
		goto node1524;
	} else {
		input[3] &= ~(1 << 2);
		return 0;
	}
node5896:
	b = false;
	if (b) {
		input[4] |= (1 << 4);
		return 0;
	} else {
		input[4] &= ~(1 << 4);
		goto node3044;
	}
node6518:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node3957;
	} else {
		input[2] &= ~(1 << 4);
		goto node7449;
	}
node1732:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node847;
	} else {
		input[2] &= ~(1 << 1);
		goto node5787;
	}
node7677:
	b = false;
	if (b) {
		input[4] |= (1 << 7);
		return 0;
	} else {
		input[4] &= ~(1 << 7);
		goto node2300;
	}
node4898:
	b = randbool();
	if (b) {
		input[4] |= (1 << 4);
		goto node7337;
	} else {
		input[4] &= ~(1 << 4);
		goto node7983;
	}
node4816:
	b = randbool();
	if (b) {
		input[4] |= (1 << 4);
		goto node761;
	} else {
		input[4] &= ~(1 << 4);
		goto node8856;
	}
node8897:
	b = randbool();
	if (b) {
		input[6] |= (1 << 6);
		goto node3347;
	} else {
		input[6] &= ~(1 << 6);
		goto node5413;
	}
node867:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node3835;
	} else {
		input[2] &= ~(1 << 3);
		goto node1577;
	}
node2081:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node1631;
	} else {
		input[2] &= ~(1 << 2);
		goto node407;
	}
node3260:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node3545;
	} else {
		input[3] &= ~(1 << 5);
		goto node6490;
	}
node5405:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node1367;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node3367:
	b = false;
	if (b) {
		input[4] |= (1 << 5);
		return 0;
	} else {
		input[4] &= ~(1 << 5);
		goto node6190;
	}
node6250:
	b = randbool();
	if (b) {
		input[1] |= (1 << 1);
		goto node4800;
	} else {
		input[1] &= ~(1 << 1);
		goto node8590;
	}
node6813:
	b = randbool();
	if (b) {
		input[1] |= (1 << 0);
		return 7;
	} else {
		input[1] &= ~(1 << 0);
		goto node7891;
	}
node2488:
	b = false;
	if (b) {
		input[3] |= (1 << 1);
		return 0;
	} else {
		input[3] &= ~(1 << 1);
		goto node2757;
	}
node3256:
	b = true;
	if (b) {
		input[3] |= (1 << 0);
		goto node7677;
	} else {
		input[3] &= ~(1 << 0);
		return 0;
	}
node3366:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node7599;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node5960:
	b = false;
	if (b) {
		input[3] |= (1 << 0);
		return 0;
	} else {
		input[3] &= ~(1 << 0);
		goto node1689;
	}
node5402:
	b = false;
	if (b) {
		input[4] |= (1 << 4);
		return 0;
	} else {
		input[4] &= ~(1 << 4);
		goto node581;
	}
node4646:
	b = false;
	if (b) {
		input[2] |= (1 << 7);
		return 0;
	} else {
		input[2] &= ~(1 << 7);
		goto node7173;
	}
node1795:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node7255;
	} else {
		input[2] &= ~(1 << 4);
		goto node5600;
	}
node2113:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node1463;
	} else {
		input[2] &= ~(1 << 4);
		goto node752;
	}
node2040:
	b = true;
	if (b) {
		input[2] |= (1 << 3);
		goto node3444;
	} else {
		input[2] &= ~(1 << 3);
		return 0;
	}
node6551:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node1158;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node956:
	b = true;
	if (b) {
		input[3] |= (1 << 7);
		goto node8488;
	} else {
		input[3] &= ~(1 << 7);
		return 0;
	}
node6561:
	b = true;
	if (b) {
		input[1] |= (1 << 0);
		goto node6594;
	} else {
		input[1] &= ~(1 << 0);
		return 0;
	}
node7613:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node537;
	}
node8676:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node548;
	}
node4075:
	b = randbool();
	if (b) {
		input[6] |= (1 << 5);
		goto node7819;
	} else {
		input[6] &= ~(1 << 5);
		goto node629;
	}
node1720:
	b = false;
	if (b) {
		input[4] |= (1 << 1);
		return 0;
	} else {
		input[4] &= ~(1 << 1);
		goto node7485;
	}
node4966:
	b = false;
	if (b) {
		input[1] |= (1 << 0);
		return 0;
	} else {
		input[1] &= ~(1 << 0);
		goto node184;
	}
node3438:
	b = false;
	if (b) {
		input[2] |= (1 << 6);
		return 0;
	} else {
		input[2] &= ~(1 << 6);
		goto node3907;
	}
node943:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node6122;
	} else {
		input[3] &= ~(1 << 6);
		goto node6647;
	}
node7599:
	b = false;
	if (b) {
		input[3] |= (1 << 2);
		return 0;
	} else {
		input[3] &= ~(1 << 2);
		goto node2236;
	}
node7464:
	b = randbool();
	if (b) {
		input[3] |= (1 << 1);
		goto node1066;
	} else {
		input[3] &= ~(1 << 1);
		goto node6194;
	}
node4724:
	b = true;
	if (b) {
		input[4] |= (1 << 5);
		goto node1593;
	} else {
		input[4] &= ~(1 << 5);
		return 0;
	}
node2514:
	b = randbool();
	if (b) {
		input[4] |= (1 << 4);
		goto node795;
	} else {
		input[4] &= ~(1 << 4);
		goto node6893;
	}
node1730:
	b = randbool();
	if (b) {
		input[1] |= (1 << 0);
		goto node4405;
	} else {
		input[1] &= ~(1 << 0);
		goto node3767;
	}
node6791:
	b = true;
	if (b) {
		input[2] |= (1 << 3);
		goto node5976;
	} else {
		input[2] &= ~(1 << 3);
		return 0;
	}
node2188:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node6597;
	} else {
		input[2] &= ~(1 << 2);
		goto node6455;
	}
node3098:
	b = false;
	if (b) {
		input[2] |= (1 << 1);
		return 0;
	} else {
		input[2] &= ~(1 << 1);
		goto node4853;
	}
node7840:
	b = false;
	if (b) {
		input[2] |= (1 << 1);
		return 0;
	} else {
		input[2] &= ~(1 << 1);
		goto node6811;
	}
node6798:
	b = false;
	if (b) {
		input[3] |= (1 << 7);
		return 0;
	} else {
		input[3] &= ~(1 << 7);
		goto node7025;
	}
node7086:
	b = randbool();
	if (b) {
		input[1] |= (1 << 2);
		goto node1783;
	} else {
		input[1] &= ~(1 << 2);
		return 2;
	}
node3231:
	b = false;
	if (b) {
		input[2] |= (1 << 2);
		return 0;
	} else {
		input[2] &= ~(1 << 2);
		goto node1272;
	}
node523:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node1343;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node8029:
	b = true;
	if (b) {
		input[4] |= (1 << 5);
		goto node181;
	} else {
		input[4] &= ~(1 << 5);
		return 0;
	}
node652:
	b = false;
	if (b) {
		input[4] |= (1 << 5);
		return 0;
	} else {
		input[4] &= ~(1 << 5);
		goto node3431;
	}
node3013:
	b = true;
	if (b) {
		input[4] |= (1 << 2);
		goto node2863;
	} else {
		input[4] &= ~(1 << 2);
		return 0;
	}
node1310:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node8563;
	}
node130:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		goto node8430;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node6795:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node9467;
	}
node6577:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node3520;
	} else {
		input[3] &= ~(1 << 3);
		goto node4046;
	}
node7580:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node5149;
	} else {
		input[3] &= ~(1 << 3);
		goto node137;
	}
node2982:
	b = true;
	if (b) {
		input[4] |= (1 << 3);
		goto node151;
	} else {
		input[4] &= ~(1 << 3);
		return 0;
	}
node7003:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node1395;
	} else {
		input[2] &= ~(1 << 6);
		goto node5476;
	}
node1025:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		goto node7922;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node1928:
	b = false;
	if (b) {
		input[2] |= (1 << 0);
		return 0;
	} else {
		input[2] &= ~(1 << 0);
		goto node7887;
	}
node7009:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node9295;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node8586:
	b = false;
	if (b) {
		input[3] |= (1 << 7);
		return 0;
	} else {
		input[3] &= ~(1 << 7);
		goto node5699;
	}
node4580:
	b = false;
	if (b) {
		input[4] |= (1 << 7);
		return 0;
	} else {
		input[4] &= ~(1 << 7);
		goto node1165;
	}
node6206:
	b = true;
	if (b) {
		input[2] |= (1 << 5);
		goto node9116;
	} else {
		input[2] &= ~(1 << 5);
		return 0;
	}
node7425:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node3381;
	} else {
		input[3] &= ~(1 << 6);
		goto node3411;
	}
node2308:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node8123;
	} else {
		input[3] &= ~(1 << 4);
		goto node3520;
	}
node2300:
	b = randbool();
	if (b) {
		input[4] |= (1 << 6);
		goto node5151;
	} else {
		input[4] &= ~(1 << 6);
		goto node9012;
	}
node583:
	b = false;
	if (b) {
		input[1] |= (1 << 4);
		return 0;
	} else {
		input[1] &= ~(1 << 4);
		goto node479;
	}
node8830:
	b = false;
	if (b) {
		input[1] |= (1 << 1);
		return 0;
	} else {
		input[1] &= ~(1 << 1);
		goto node2690;
	}
node6397:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node6028;
	} else {
		input[2] &= ~(1 << 3);
		goto node3022;
	}
node8841:
	b = false;
	if (b) {
		input[2] |= (1 << 3);
		return 0;
	} else {
		input[2] &= ~(1 << 3);
		return 3;
	}
node4963:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node3506;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node3607:
	b = true;
	if (b) {
		input[4] |= (1 << 5);
		goto node2682;
	} else {
		input[4] &= ~(1 << 5);
		return 0;
	}
node4270:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node1654;
	} else {
		input[3] &= ~(1 << 6);
		goto node7377;
	}
node8311:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node8993;
	} else {
		input[3] &= ~(1 << 2);
		goto node8801;
	}
node2841:
	b = randbool();
	if (b) {
		input[4] |= (1 << 7);
		goto node5496;
	} else {
		input[4] &= ~(1 << 7);
		goto node7198;
	}
node7519:
	b = true;
	if (b) {
		input[2] |= (1 << 6);
		goto node9265;
	} else {
		input[2] &= ~(1 << 6);
		return 0;
	}
node5595:
	b = true;
	if (b) {
		input[2] |= (1 << 5);
		goto node342;
	} else {
		input[2] &= ~(1 << 5);
		return 0;
	}
node8095:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node7442;
	} else {
		input[2] &= ~(1 << 5);
		goto node6101;
	}
node8237:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node8737;
	} else {
		input[2] &= ~(1 << 5);
		goto node1814;
	}
node6296:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node1728;
	} else {
		input[3] &= ~(1 << 3);
		goto node425;
	}
node2133:
	b = false;
	if (b) {
		input[3] |= (1 << 2);
		return 0;
	} else {
		input[3] &= ~(1 << 2);
		goto node8476;
	}
node1185:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node9439;
	} else {
		input[2] &= ~(1 << 6);
		goto node5853;
	}
node8016:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node52;
	} else {
		input[2] &= ~(1 << 5);
		goto node1361;
	}
node3374:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node3225;
	}
node4426:
	b = true;
	if (b) {
		input[3] |= (1 << 2);
		goto node4586;
	} else {
		input[3] &= ~(1 << 2);
		return 0;
	}
node4743:
	b = randbool();
	if (b) {
		input[1] |= (1 << 0);
		return 6;
	} else {
		input[1] &= ~(1 << 0);
		goto node1990;
	}
node4576:
	b = true;
	if (b) {
		input[1] |= (1 << 0);
		goto node9124;
	} else {
		input[1] &= ~(1 << 0);
		return 0;
	}
node2137:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node7875;
	}
node6272:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node1977;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node1624:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node8114;
	}
node1559:
	b = false;
	if (b) {
		input[1] |= (1 << 2);
		return 0;
	} else {
		input[1] &= ~(1 << 2);
		goto node6446;
	}
node769:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node99;
	} else {
		input[2] &= ~(1 << 5);
		goto node1597;
	}
node66:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node8631;
	} else {
		input[2] &= ~(1 << 2);
		return 3;
	}
node6770:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node6177;
	} else {
		input[3] &= ~(1 << 3);
		goto node6890;
	}
node2128:
	b = false;
	if (b) {
		input[4] |= (1 << 1);
		return 0;
	} else {
		input[4] &= ~(1 << 1);
		goto node5842;
	}
node6102:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node9118;
	} else {
		input[2] &= ~(1 << 1);
		goto node4521;
	}
node7163:
	b = true;
	if (b) {
		input[4] |= (1 << 4);
		goto node5030;
	} else {
		input[4] &= ~(1 << 4);
		return 0;
	}
node271:
	b = true;
	if (b) {
		input[1] |= (1 << 2);
		goto node7277;
	} else {
		input[1] &= ~(1 << 2);
		return 0;
	}
node5525:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node4751;
	} else {
		input[2] &= ~(1 << 4);
		goto node356;
	}
node4071:
	b = false;
	if (b) {
		input[2] |= (1 << 1);
		return 0;
	} else {
		input[2] &= ~(1 << 1);
		goto node8517;
	}
node9135:
	b = true;
	if (b) {
		input[3] |= (1 << 6);
		goto node6385;
	} else {
		input[3] &= ~(1 << 6);
		return 0;
	}
node9449:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node5394;
	} else {
		input[3] &= ~(1 << 4);
		goto node8633;
	}
node4530:
	b = true;
	if (b) {
		input[4] |= (1 << 6);
		goto node6310;
	} else {
		input[4] &= ~(1 << 6);
		return 0;
	}
node7678:
	b = randbool();
	if (b) {
		input[4] |= (1 << 5);
		goto node3057;
	} else {
		input[4] &= ~(1 << 5);
		goto node4534;
	}
node3240:
	b = randbool();
	if (b) {
		input[0] |= (1 << 3);
		goto node3234;
	} else {
		input[0] &= ~(1 << 3);
		goto node8424;
	}
node5464:
	b = randbool();
	if (b) {
		input[0] |= (1 << 2);
		goto node6311;
	} else {
		input[0] &= ~(1 << 2);
		goto node4281;
	}
node4076:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node9325;
	} else {
		input[2] &= ~(1 << 1);
		goto node2885;
	}
node6204:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node5877;
	} else {
		input[3] &= ~(1 << 4);
		return 4;
	}
node5961:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node5686;
	} else {
		input[3] &= ~(1 << 2);
		goto node6682;
	}
node5815:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node1460;
	} else {
		input[3] &= ~(1 << 2);
		goto node6462;
	}
node4799:
	b = randbool();
	if (b) {
		input[1] |= (1 << 5);
		goto node5897;
	} else {
		input[1] &= ~(1 << 5);
		goto node59;
	}
node8403:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node5556;
	} else {
		input[3] &= ~(1 << 7);
		goto node2126;
	}
node9035:
	b = false;
	if (b) {
		input[3] |= (1 << 6);
		return 0;
	} else {
		input[3] &= ~(1 << 6);
		goto node444;
	}
node8225:
	b = randbool();
	if (b) {
		input[2] |= (1 << 7);
		goto node7951;
	} else {
		input[2] &= ~(1 << 7);
		goto node8343;
	}
node1956:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node4953;
	} else {
		input[3] &= ~(1 << 6);
		goto node8127;
	}
node1457:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node1348;
	}
node9322:
	b = randbool();
	if (b) {
		input[1] |= (1 << 6);
		goto node4303;
	} else {
		input[1] &= ~(1 << 6);
		goto node4342;
	}
node6135:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node7962;
	} else {
		input[2] &= ~(1 << 5);
		goto node563;
	}
node1567:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node746;
	}
node1644:
	b = false;
	if (b) {
		input[2] |= (1 << 0);
		return 0;
	} else {
		input[2] &= ~(1 << 0);
		goto node3572;
	}
node8362:
	b = true;
	if (b) {
		input[4] |= (1 << 5);
		goto node3828;
	} else {
		input[4] &= ~(1 << 5);
		return 0;
	}
node1713:
	b = true;
	if (b) {
		input[4] |= (1 << 4);
		goto node8917;
	} else {
		input[4] &= ~(1 << 4);
		return 0;
	}
node8534:
	b = randbool();
	if (b) {
		input[1] |= (1 << 2);
		goto node7796;
	} else {
		input[1] &= ~(1 << 2);
		goto node6446;
	}
node3290:
	b = true;
	if (b) {
		input[1] |= (1 << 1);
		goto node1339;
	} else {
		input[1] &= ~(1 << 1);
		return 0;
	}
node6700:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node5600;
	}
node4260:
	b = randbool();
	if (b) {
		input[7] |= (1 << 4);
		goto node973;
	} else {
		input[7] &= ~(1 << 4);
		goto node4230;
	}
node1354:
	b = randbool();
	if (b) {
		input[1] |= (1 << 1);
		goto node5654;
	} else {
		input[1] &= ~(1 << 1);
		goto node3484;
	}
node8939:
	b = true;
	if (b) {
		input[3] |= (1 << 6);
		goto node9363;
	} else {
		input[3] &= ~(1 << 6);
		return 0;
	}
node5814:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node474;
	} else {
		input[3] &= ~(1 << 4);
		goto node780;
	}
node623:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node2133;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node8172:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node7799;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node7680:
	b = true;
	if (b) {
		input[4] |= (1 << 2);
		goto node8687;
	} else {
		input[4] &= ~(1 << 2);
		return 0;
	}
node8194:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node8190;
	}
node5933:
	b = false;
	if (b) {
		input[4] |= (1 << 4);
		return 0;
	} else {
		input[4] &= ~(1 << 4);
		goto node9050;
	}
node3635:
	b = true;
	if (b) {
		input[4] |= (1 << 7);
		goto node2332;
	} else {
		input[4] &= ~(1 << 7);
		return 0;
	}
node7324:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node6340;
	} else {
		input[2] &= ~(1 << 6);
		goto node3216;
	}
node8498:
	b = true;
	if (b) {
		input[2] |= (1 << 3);
		return 3;
	} else {
		input[2] &= ~(1 << 3);
		return 0;
	}
node2747:
	b = true;
	if (b) {
		input[2] |= (1 << 3);
		goto node8245;
	} else {
		input[2] &= ~(1 << 3);
		return 0;
	}
node6997:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node1589;
	} else {
		input[2] &= ~(1 << 2);
		goto node4249;
	}
node4202:
	b = true;
	if (b) {
		input[2] |= (1 << 2);
		goto node6179;
	} else {
		input[2] &= ~(1 << 2);
		return 0;
	}
node4280:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node263;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node8064:
	b = false;
	if (b) {
		input[3] |= (1 << 1);
		return 0;
	} else {
		input[3] &= ~(1 << 1);
		goto node7156;
	}
node929:
	b = randbool();
	if (b) {
		input[4] |= (1 << 2);
		goto node3084;
	} else {
		input[4] &= ~(1 << 2);
		return 6;
	}
node8858:
	b = randbool();
	if (b) {
		input[1] |= (1 << 1);
		goto node3860;
	} else {
		input[1] &= ~(1 << 1);
		goto node155;
	}
node2690:
	b = true;
	if (b) {
		input[1] |= (1 << 0);
		goto node1898;
	} else {
		input[1] &= ~(1 << 0);
		return 0;
	}
node3654:
	b = false;
	if (b) {
		input[2] |= (1 << 6);
		return 0;
	} else {
		input[2] &= ~(1 << 6);
		goto node7672;
	}
node8185:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node6735;
	} else {
		input[2] &= ~(1 << 6);
		goto node330;
	}
node6028:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node6355;
	} else {
		input[2] &= ~(1 << 2);
		goto node6233;
	}
node6912:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node4387;
	} else {
		input[3] &= ~(1 << 4);
		goto node8691;
	}
node7777:
	b = false;
	if (b) {
		input[4] |= (1 << 1);
		return 0;
	} else {
		input[4] &= ~(1 << 1);
		goto node3327;
	}
node5818:
	b = false;
	if (b) {
		input[4] |= (1 << 7);
		return 0;
	} else {
		input[4] &= ~(1 << 7);
		goto node220;
	}
node6816:
	b = false;
	if (b) {
		input[4] |= (1 << 7);
		return 0;
	} else {
		input[4] &= ~(1 << 7);
		goto node2193;
	}
node8208:
	b = randbool();
	if (b) {
		input[2] |= (1 << 7);
		goto node9324;
	} else {
		input[2] &= ~(1 << 7);
		goto node7972;
	}
node6775:
	b = false;
	if (b) {
		input[2] |= (1 << 0);
		return 0;
	} else {
		input[2] &= ~(1 << 0);
		goto node2136;
	}
node1736:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node3185;
	} else {
		input[3] &= ~(1 << 7);
		goto node684;
	}
node6171:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node5685;
	}
node7721:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node2408;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node1169:
	b = true;
	if (b) {
		input[3] |= (1 << 2);
		goto node3055;
	} else {
		input[3] &= ~(1 << 2);
		return 0;
	}
node8305:
	b = false;
	if (b) {
		input[5] |= (1 << 7);
		return 0;
	} else {
		input[5] &= ~(1 << 7);
		goto node3970;
	}
node5486:
	b = randbool();
	if (b) {
		input[1] |= (1 << 3);
		goto node5885;
	} else {
		input[1] &= ~(1 << 3);
		goto node1650;
	}
node1225:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node8797;
	} else {
		input[2] &= ~(1 << 5);
		goto node5508;
	}
node3544:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node6907;
	} else {
		input[2] &= ~(1 << 2);
		goto node6102;
	}
node4225:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node3902;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node6873:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node3093;
	}
node5258:
	b = randbool();
	if (b) {
		input[3] |= (1 << 1);
		goto node2221;
	} else {
		input[3] &= ~(1 << 1);
		goto node3520;
	}
node5262:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node2103;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node6563:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node316;
	} else {
		input[3] &= ~(1 << 4);
		goto node3485;
	}
node3486:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node896;
	} else {
		input[3] &= ~(1 << 2);
		goto node6692;
	}
node4326:
	b = randbool();
	if (b) {
		input[2] |= (1 << 7);
		goto node7181;
	} else {
		input[2] &= ~(1 << 7);
		goto node5397;
	}
node966:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node2125;
	} else {
		input[2] &= ~(1 << 5);
		goto node8002;
	}
node4091:
	b = false;
	if (b) {
		input[2] |= (1 << 3);
		return 0;
	} else {
		input[2] &= ~(1 << 3);
		goto node558;
	}
node1806:
	b = false;
	if (b) {
		input[2] |= (1 << 2);
		return 0;
	} else {
		input[2] &= ~(1 << 2);
		goto node8879;
	}
node5793:
	b = false;
	if (b) {
		input[3] |= (1 << 6);
		return 0;
	} else {
		input[3] &= ~(1 << 6);
		goto node2818;
	}
node2962:
	b = randbool();
	if (b) {
		input[1] |= (1 << 3);
		goto node3189;
	} else {
		input[1] &= ~(1 << 3);
		goto node5869;
	}
node6697:
	b = randbool();
	if (b) {
		input[2] |= (1 << 0);
		goto node3624;
	} else {
		input[2] &= ~(1 << 0);
		goto node2850;
	}
node2968:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node2626;
	} else {
		input[3] &= ~(1 << 7);
		goto node5122;
	}
node7448:
	b = randbool();
	if (b) {
		input[4] |= (1 << 3);
		goto node8259;
	} else {
		input[4] &= ~(1 << 3);
		goto node5909;
	}
node7537:
	b = true;
	if (b) {
		input[2] |= (1 << 2);
		goto node847;
	} else {
		input[2] &= ~(1 << 2);
		return 0;
	}
node4811:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node681;
	} else {
		input[3] &= ~(1 << 6);
		goto node7434;
	}
node5741:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node5942;
	} else {
		input[3] &= ~(1 << 4);
		goto node3130;
	}
node325:
	b = false;
	if (b) {
		input[4] |= (1 << 1);
		return 0;
	} else {
		input[4] &= ~(1 << 1);
		goto node5305;
	}
node2542:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node2536;
	} else {
		input[3] &= ~(1 << 4);
		goto node848;
	}
node5872:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node8516;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node9275:
	b = randbool();
	if (b) {
		input[0] |= (1 << 2);
		goto node3839;
	} else {
		input[0] &= ~(1 << 2);
		goto node2917;
	}
node8206:
	b = randbool();
	if (b) {
		input[1] |= (1 << 1);
		goto node1998;
	} else {
		input[1] &= ~(1 << 1);
		goto node2229;
	}
node5738:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node7510;
	} else {
		input[2] &= ~(1 << 2);
		goto node8730;
	}
node6669:
	b = false;
	if (b) {
		input[2] |= (1 << 2);
		return 0;
	} else {
		input[2] &= ~(1 << 2);
		goto node7510;
	}
node9300:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node7660;
	} else {
		input[2] &= ~(1 << 1);
		goto node4664;
	}
node2108:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node3693;
	}
node8980:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node1590;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node8969:
	b = true;
	if (b) {
		input[4] |= (1 << 6);
		goto node6745;
	} else {
		input[4] &= ~(1 << 6);
		return 0;
	}
node9102:
	b = randbool();
	if (b) {
		input[6] |= (1 << 6);
		goto node9303;
	} else {
		input[6] &= ~(1 << 6);
		goto node3460;
	}
node2727:
	b = true;
	if (b) {
		input[4] |= (1 << 6);
		return 5;
	} else {
		input[4] &= ~(1 << 6);
		return 0;
	}
node5552:
	b = false;
	if (b) {
		input[2] |= (1 << 1);
		return 0;
	} else {
		input[2] &= ~(1 << 1);
		goto node7074;
	}
node4989:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		goto node4861;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node8340:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node3048;
	}
node4272:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node5147;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node1913:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node7750;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node7193:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node2989;
	} else {
		input[3] &= ~(1 << 2);
		goto node7947;
	}
node1091:
	b = false;
	if (b) {
		input[1] |= (1 << 2);
		return 0;
	} else {
		input[1] &= ~(1 << 2);
		goto node8111;
	}
node2606:
	b = randbool();
	if (b) {
		input[2] |= (1 << 7);
		goto node666;
	} else {
		input[2] &= ~(1 << 7);
		goto node1185;
	}
node1058:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node5480;
	} else {
		input[2] &= ~(1 << 3);
		goto node7643;
	}
node1204:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node2749;
	} else {
		input[3] &= ~(1 << 7);
		goto node7270;
	}
node4959:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node9167;
	} else {
		input[3] &= ~(1 << 6);
		goto node1888;
	}
node6881:
	b = randbool();
	if (b) {
		input[5] |= (1 << 5);
		goto node5118;
	} else {
		input[5] &= ~(1 << 5);
		goto node2463;
	}
node4313:
	b = true;
	if (b) {
		input[2] |= (1 << 3);
		goto node481;
	} else {
		input[2] &= ~(1 << 3);
		return 0;
	}
node6945:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node2743;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node5941:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node8747;
	} else {
		input[3] &= ~(1 << 5);
		goto node2447;
	}
node3733:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node6784;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node1521:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node3717;
	} else {
		input[3] &= ~(1 << 4);
		goto node777;
	}
node814:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node4749;
	}
node1281:
	b = true;
	if (b) {
		input[3] |= (1 << 1);
		goto node5029;
	} else {
		input[3] &= ~(1 << 1);
		return 0;
	}
node2875:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node3609;
	} else {
		input[2] &= ~(1 << 5);
		goto node4751;
	}
node8818:
	b = randbool();
	if (b) {
		input[2] |= (1 << 0);
		return 6;
	} else {
		input[2] &= ~(1 << 0);
		goto node1940;
	}
node6833:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node8063;
	} else {
		input[3] &= ~(1 << 6);
		goto node9151;
	}
node6657:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node2944;
	} else {
		input[3] &= ~(1 << 5);
		goto node559;
	}
node7524:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node7946;
	} else {
		input[3] &= ~(1 << 3);
		goto node7599;
	}
node1903:
	b = true;
	if (b) {
		input[3] |= (1 << 2);
		goto node1934;
	} else {
		input[3] &= ~(1 << 2);
		return 0;
	}
node2583:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node4608;
	} else {
		input[3] &= ~(1 << 4);
		goto node1954;
	}
node8400:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node4954;
	} else {
		input[3] &= ~(1 << 4);
		goto node5335;
	}
node9427:
	b = randbool();
	if (b) {
		input[1] |= (1 << 5);
		goto node40;
	} else {
		input[1] &= ~(1 << 5);
		goto node8088;
	}
node3758:
	b = true;
	if (b) {
		input[1] |= (1 << 1);
		goto node1898;
	} else {
		input[1] &= ~(1 << 1);
		return 0;
	}
node3403:
	b = true;
	if (b) {
		input[2] |= (1 << 4);
		goto node8032;
	} else {
		input[2] &= ~(1 << 4);
		return 0;
	}
node99:
	b = true;
	if (b) {
		input[2] |= (1 << 3);
		goto node1597;
	} else {
		input[2] &= ~(1 << 3);
		return 0;
	}
node7037:
	b = false;
	if (b) {
		input[3] |= (1 << 6);
		return 0;
	} else {
		input[3] &= ~(1 << 6);
		goto node6928;
	}
node7274:
	b = false;
	if (b) {
		input[5] |= (1 << 0);
		return 0;
	} else {
		input[5] &= ~(1 << 0);
		goto node629;
	}
node1605:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node7931;
	} else {
		input[2] &= ~(1 << 1);
		goto node6371;
	}
node9175:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node6911;
	} else {
		input[3] &= ~(1 << 7);
		goto node7846;
	}
node7695:
	b = true;
	if (b) {
		input[3] |= (1 << 7);
		goto node570;
	} else {
		input[3] &= ~(1 << 7);
		return 0;
	}
node3058:
	b = randbool();
	if (b) {
		input[7] |= (1 << 5);
		goto node6904;
	} else {
		input[7] &= ~(1 << 5);
		goto node6368;
	}
node986:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node9170;
	} else {
		input[2] &= ~(1 << 6);
		goto node1886;
	}
node7710:
	b = false;
	if (b) {
		input[4] |= (1 << 4);
		return 0;
	} else {
		input[4] &= ~(1 << 4);
		goto node7185;
	}
node2720:
	b = true;
	if (b) {
		input[3] |= (1 << 6);
		goto node3732;
	} else {
		input[3] &= ~(1 << 6);
		return 0;
	}
node459:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node6445;
	}
node6840:
	b = false;
	if (b) {
		input[4] |= (1 << 5);
		return 0;
	} else {
		input[4] &= ~(1 << 5);
		goto node8066;
	}
node206:
	b = randbool();
	if (b) {
		input[1] |= (1 << 4);
		goto node980;
	} else {
		input[1] &= ~(1 << 4);
		return 2;
	}
node7612:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node3876;
	} else {
		input[2] &= ~(1 << 2);
		goto node2105;
	}
node4231:
	b = true;
	if (b) {
		input[4] |= (1 << 7);
		goto node5512;
	} else {
		input[4] &= ~(1 << 7);
		return 0;
	}
node1544:
	b = false;
	if (b) {
		input[4] |= (1 << 5);
		return 0;
	} else {
		input[4] &= ~(1 << 5);
		goto node5163;
	}
node377:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node403;
	} else {
		input[2] &= ~(1 << 6);
		goto node5550;
	}
node969:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node2118;
	} else {
		input[2] &= ~(1 << 2);
		goto node8307;
	}
node1223:
	b = true;
	if (b) {
		input[3] |= (1 << 1);
		goto node3256;
	} else {
		input[3] &= ~(1 << 1);
		return 0;
	}
node3108:
	b = false;
	if (b) {
		input[2] |= (1 << 1);
		return 0;
	} else {
		input[2] &= ~(1 << 1);
		goto node2149;
	}
node1193:
	b = randbool();
	if (b) {
		input[2] |= (1 << 0);
		goto node3799;
	} else {
		input[2] &= ~(1 << 0);
		goto node2136;
	}
node6252:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node6556;
	} else {
		input[3] &= ~(1 << 7);
		goto node2505;
	}
node3692:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node68;
	}
node5857:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node1823;
	}
node5004:
	b = false;
	if (b) {
		input[4] |= (1 << 1);
		return 0;
	} else {
		input[4] &= ~(1 << 1);
		goto node4466;
	}
node5348:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node5251;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node5198:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node6617;
	}
node1423:
	b = false;
	if (b) {
		input[4] |= (1 << 7);
		return 0;
	} else {
		input[4] &= ~(1 << 7);
		goto node2431;
	}
node5935:
	b = false;
	if (b) {
		input[4] |= (1 << 3);
		return 0;
	} else {
		input[4] &= ~(1 << 3);
		goto node3408;
	}
node6595:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node7887;
	} else {
		input[2] &= ~(1 << 3);
		goto node517;
	}
node7220:
	b = false;
	if (b) {
		input[2] |= (1 << 0);
		return 0;
	} else {
		input[2] &= ~(1 << 0);
		goto node338;
	}
node3626:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node3765;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node2604:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node8610;
	} else {
		input[3] &= ~(1 << 4);
		goto node6392;
	}
node7124:
	b = false;
	if (b) {
		input[3] |= (1 << 1);
		return 0;
	} else {
		input[3] &= ~(1 << 1);
		goto node3089;
	}
node7502:
	b = randbool();
	if (b) {
		input[4] |= (1 << 2);
		goto node486;
	} else {
		input[4] &= ~(1 << 2);
		goto node1564;
	}
node2279:
	b = false;
	if (b) {
		input[5] |= (1 << 7);
		return 0;
	} else {
		input[5] &= ~(1 << 7);
		goto node4010;
	}
node6312:
	b = randbool();
	if (b) {
		input[1] |= (1 << 7);
		goto node147;
	} else {
		input[1] &= ~(1 << 7);
		goto node4333;
	}
node4099:
	b = false;
	if (b) {
		input[1] |= (1 << 2);
		return 0;
	} else {
		input[1] &= ~(1 << 2);
		goto node8010;
	}
node8300:
	b = randbool();
	if (b) {
		input[1] |= (1 << 2);
		goto node6186;
	} else {
		input[1] &= ~(1 << 2);
		goto node8040;
	}
node9459:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node2362;
	} else {
		input[3] &= ~(1 << 7);
		goto node6280;
	}
node8026:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node8626;
	} else {
		input[3] &= ~(1 << 5);
		goto node5111;
	}
node3887:
	b = randbool();
	if (b) {
		input[3] |= (1 << 0);
		goto node871;
	} else {
		input[3] &= ~(1 << 0);
		goto node509;
	}
node8955:
	b = false;
	if (b) {
		input[4] |= (1 << 1);
		return 0;
	} else {
		input[4] &= ~(1 << 1);
		goto node7532;
	}
node2416:
	b = false;
	if (b) {
		input[0] |= (1 << 0);
		return 0;
	} else {
		input[0] &= ~(1 << 0);
		goto node2854;
	}
node1202:
	b = randbool();
	if (b) {
		input[1] |= (1 << 5);
		goto node7086;
	} else {
		input[1] &= ~(1 << 5);
		goto node2268;
	}
node8943:
	b = false;
	if (b) {
		input[1] |= (1 << 3);
		return 0;
	} else {
		input[1] &= ~(1 << 3);
		goto node8657;
	}
node9034:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node1513;
	}
node6685:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node547;
	} else {
		input[3] &= ~(1 << 6);
		goto node8034;
	}
node7882:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node1480;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node8202:
	b = true;
	if (b) {
		input[6] |= (1 << 2);
		goto node3224;
	} else {
		input[6] &= ~(1 << 2);
		return 0;
	}
node1023:
	b = randbool();
	if (b) {
		input[0] |= (1 << 0);
		goto node8425;
	} else {
		input[0] &= ~(1 << 0);
		goto node1890;
	}
node2527:
	b = randbool();
	if (b) {
		input[1] |= (1 << 4);
		goto node5951;
	} else {
		input[1] &= ~(1 << 4);
		goto node4150;
	}
node8047:
	b = false;
	if (b) {
		input[1] |= (1 << 3);
		return 0;
	} else {
		input[1] &= ~(1 << 3);
		goto node9247;
	}
node6263:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node3991;
	} else {
		input[2] &= ~(1 << 6);
		goto node589;
	}
node7280:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node4166;
	} else {
		input[3] &= ~(1 << 7);
		goto node5581;
	}
node2733:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node3976;
	}
node1885:
	b = true;
	if (b) {
		input[2] |= (1 << 6);
		goto node2143;
	} else {
		input[2] &= ~(1 << 6);
		return 0;
	}
node4112:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node53;
	} else {
		input[2] &= ~(1 << 5);
		goto node149;
	}
node6549:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node2130;
	} else {
		input[2] &= ~(1 << 4);
		goto node6550;
	}
node8889:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node173;
	} else {
		input[2] &= ~(1 << 2);
		goto node8730;
	}
node9066:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node7307;
	} else {
		input[3] &= ~(1 << 6);
		goto node444;
	}
node3057:
	b = randbool();
	if (b) {
		input[4] |= (1 << 4);
		goto node4534;
	} else {
		input[4] &= ~(1 << 4);
		goto node6031;
	}
node2298:
	b = randbool();
	if (b) {
		input[1] |= (1 << 7);
		goto node7827;
	} else {
		input[1] &= ~(1 << 7);
		goto node2440;
	}
node7051:
	b = false;
	if (b) {
		input[1] |= (1 << 5);
		return 0;
	} else {
		input[1] &= ~(1 << 5);
		goto node7782;
	}
node5898:
	b = true;
	if (b) {
		input[1] |= (1 << 1);
		goto node2816;
	} else {
		input[1] &= ~(1 << 1);
		return 0;
	}
node9080:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node831;
	} else {
		input[3] &= ~(1 << 5);
		goto node7150;
	}
node9212:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node3507;
	}
node1445:
	b = false;
	if (b) {
		input[3] |= (1 << 1);
		return 0;
	} else {
		input[3] &= ~(1 << 1);
		goto node137;
	}
node9334:
	b = false;
	if (b) {
		input[4] |= (1 << 7);
		return 0;
	} else {
		input[4] &= ~(1 << 7);
		goto node627;
	}
node1004:
	b = randbool();
	if (b) {
		input[4] |= (1 << 6);
		goto node128;
	} else {
		input[4] &= ~(1 << 6);
		goto node4008;
	}
node4822:
	b = false;
	if (b) {
		input[7] |= (1 << 1);
		return 0;
	} else {
		input[7] &= ~(1 << 1);
		goto node2940;
	}
node7733:
	b = randbool();
	if (b) {
		input[1] |= (1 << 1);
		goto node600;
	} else {
		input[1] &= ~(1 << 1);
		goto node5142;
	}
node5201:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node2130;
	}
node2204:
	b = true;
	if (b) {
		input[3] |= (1 << 6);
		goto node4155;
	} else {
		input[3] &= ~(1 << 6);
		return 0;
	}
node2571:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node8826;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node4973:
	b = true;
	if (b) {
		input[5] |= (1 << 7);
		goto node4400;
	} else {
		input[5] &= ~(1 << 7);
		return 0;
	}
node7831:
	b = true;
	if (b) {
		input[1] |= (1 << 1);
		goto node4745;
	} else {
		input[1] &= ~(1 << 1);
		return 0;
	}
node7128:
	b = false;
	if (b) {
		input[3] |= (1 << 1);
		return 0;
	} else {
		input[3] &= ~(1 << 1);
		goto node2584;
	}
node3888:
	b = randbool();
	if (b) {
		input[4] |= (1 << 2);
		goto node7732;
	} else {
		input[4] &= ~(1 << 2);
		return 5;
	}
node486:
	b = randbool();
	if (b) {
		input[4] |= (1 << 1);
		goto node7422;
	} else {
		input[4] &= ~(1 << 1);
		goto node439;
	}
node1616:
	b = true;
	if (b) {
		input[1] |= (1 << 1);
		goto node7179;
	} else {
		input[1] &= ~(1 << 1);
		return 0;
	}
node2707:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node2194;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node7474:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node6448;
	}
node6789:
	b = false;
	if (b) {
		input[4] |= (1 << 5);
		return 0;
	} else {
		input[4] &= ~(1 << 5);
		goto node7767;
	}
node2960:
	b = randbool();
	if (b) {
		input[4] |= (1 << 1);
		return 5;
	} else {
		input[4] &= ~(1 << 1);
		goto node4858;
	}
node456:
	b = false;
	if (b) {
		input[2] |= (1 << 5);
		return 0;
	} else {
		input[2] &= ~(1 << 5);
		goto node6624;
	}
node5144:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		return 3;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node1134:
	b = randbool();
	if (b) {
		input[2] |= (1 << 0);
		goto node2295;
	} else {
		input[2] &= ~(1 << 0);
		goto node6003;
	}
node4403:
	b = false;
	if (b) {
		input[3] |= (1 << 0);
		return 0;
	} else {
		input[3] &= ~(1 << 0);
		goto node101;
	}
node544:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node4757;
	}
node1229:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node6341;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node5733:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node8804;
	}
node761:
	b = randbool();
	if (b) {
		input[4] |= (1 << 3);
		goto node7203;
	} else {
		input[4] &= ~(1 << 3);
		goto node9298;
	}
node3728:
	b = true;
	if (b) {
		input[4] |= (1 << 2);
		goto node8109;
	} else {
		input[4] &= ~(1 << 2);
		return 0;
	}
node2255:
	b = false;
	if (b) {
		input[2] |= (1 << 6);
		return 0;
	} else {
		input[2] &= ~(1 << 6);
		goto node198;
	}
node6711:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node6038;
	} else {
		input[2] &= ~(1 << 5);
		goto node6573;
	}
node2247:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node730;
	} else {
		input[3] &= ~(1 << 7);
		goto node4652;
	}
node452:
	b = false;
	if (b) {
		input[3] |= (1 << 2);
		return 0;
	} else {
		input[3] &= ~(1 << 2);
		goto node3175;
	}
node237:
	b = false;
	if (b) {
		input[4] |= (1 << 5);
		return 0;
	} else {
		input[4] &= ~(1 << 5);
		goto node6201;
	}
node1690:
	b = false;
	if (b) {
		input[4] |= (1 << 4);
		return 0;
	} else {
		input[4] &= ~(1 << 4);
		goto node3068;
	}
node2252:
	b = randbool();
	if (b) {
		input[1] |= (1 << 2);
		goto node6169;
	} else {
		input[1] &= ~(1 << 2);
		goto node1979;
	}
node9306:
	b = false;
	if (b) {
		input[2] |= (1 << 1);
		return 0;
	} else {
		input[2] &= ~(1 << 1);
		goto node7604;
	}
node1172:
	b = false;
	if (b) {
		input[2] |= (1 << 0);
		return 0;
	} else {
		input[2] &= ~(1 << 0);
		goto node4773;
	}
node4097:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node3254;
	} else {
		input[3] &= ~(1 << 7);
		goto node7570;
	}
node2077:
	b = false;
	if (b) {
		input[3] |= (1 << 6);
		return 0;
	} else {
		input[3] &= ~(1 << 6);
		goto node9055;
	}
node5624:
	b = true;
	if (b) {
		input[4] |= (1 << 5);
		goto node2900;
	} else {
		input[4] &= ~(1 << 5);
		return 0;
	}
node1052:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node4143;
	} else {
		input[3] &= ~(1 << 5);
		goto node5557;
	}
node3519:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node1849;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node4115:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node5558;
	}
node9320:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node4243;
	} else {
		input[3] &= ~(1 << 4);
		goto node5663;
	}
node1646:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node417;
	}
node7928:
	b = false;
	if (b) {
		input[2] |= (1 << 7);
		return 0;
	} else {
		input[2] &= ~(1 << 7);
		goto node8711;
	}
node5307:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node3414;
	} else {
		input[2] &= ~(1 << 3);
		goto node7700;
	}
node9133:
	b = randbool();
	if (b) {
		input[1] |= (1 << 6);
		goto node1061;
	} else {
		input[1] &= ~(1 << 6);
		goto node1044;
	}
node7902:
	b = true;
	if (b) {
		input[2] |= (1 << 4);
		goto node6791;
	} else {
		input[2] &= ~(1 << 4);
		return 0;
	}
node2914:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node5383;
	} else {
		input[3] &= ~(1 << 6);
		goto node7353;
	}
node1771:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node2778;
	} else {
		input[3] &= ~(1 << 6);
		goto node4173;
	}
node294:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node8608;
	} else {
		input[3] &= ~(1 << 5);
		goto node9426;
	}
node7019:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node819;
	} else {
		input[3] &= ~(1 << 4);
		goto node2358;
	}
node7724:
	b = randbool();
	if (b) {
		input[1] |= (1 << 2);
		goto node1826;
	} else {
		input[1] &= ~(1 << 2);
		goto node4625;
	}
node7214:
	b = true;
	if (b) {
		input[3] |= (1 << 6);
		goto node3855;
	} else {
		input[3] &= ~(1 << 6);
		return 0;
	}
node6416:
	b = randbool();
	if (b) {
		input[4] |= (1 << 2);
		goto node7203;
	} else {
		input[4] &= ~(1 << 2);
		goto node2415;
	}
node8945:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node5660;
	} else {
		input[2] &= ~(1 << 2);
		goto node3774;
	}
node8647:
	b = true;
	if (b) {
		input[3] |= (1 << 0);
		goto node5841;
	} else {
		input[3] &= ~(1 << 0);
		return 0;
	}
node8642:
	b = false;
	if (b) {
		input[1] |= (1 << 3);
		return 0;
	} else {
		input[1] &= ~(1 << 3);
		goto node9071;
	}
node3830:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node3778;
	}
node4126:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node5552;
	} else {
		input[2] &= ~(1 << 2);
		goto node5631;
	}
node127:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node4547;
	} else {
		input[3] &= ~(1 << 6);
		goto node796;
	}
node819:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node6462;
	} else {
		input[3] &= ~(1 << 3);
		goto node6796;
	}
node2712:
	b = randbool();
	if (b) {
		input[4] |= (1 << 4);
		goto node3421;
	} else {
		input[4] &= ~(1 << 4);
		goto node3282;
	}
node5673:
	b = randbool();
	if (b) {
		input[1] |= (1 << 7);
		goto node8575;
	} else {
		input[1] &= ~(1 << 7);
		goto node4325;
	}
node5427:
	b = true;
	if (b) {
		input[1] |= (1 << 4);
		goto node4900;
	} else {
		input[1] &= ~(1 << 4);
		return 0;
	}
node1156:
	b = false;
	if (b) {
		input[2] |= (1 << 5);
		return 0;
	} else {
		input[2] &= ~(1 << 5);
		goto node337;
	}
node6667:
	b = true;
	if (b) {
		input[3] |= (1 << 7);
		goto node4834;
	} else {
		input[3] &= ~(1 << 7);
		return 0;
	}
node7192:
	b = false;
	if (b) {
		input[3] |= (1 << 7);
		return 0;
	} else {
		input[3] &= ~(1 << 7);
		goto node3784;
	}
node1798:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node6037;
	} else {
		input[3] &= ~(1 << 2);
		goto node3237;
	}
node8551:
	b = true;
	if (b) {
		input[4] |= (1 << 7);
		goto node607;
	} else {
		input[4] &= ~(1 << 7);
		return 0;
	}
node8689:
	b = false;
	if (b) {
		input[1] |= (1 << 0);
		return 0;
	} else {
		input[1] &= ~(1 << 0);
		return 2;
	}
node3253:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node2224;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node7605:
	b = randbool();
	if (b) {
		input[2] |= (1 << 0);
		goto node6633;
	} else {
		input[2] &= ~(1 << 0);
		goto node6870;
	}
node7965:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node2036;
	} else {
		input[3] &= ~(1 << 6);
		goto node1015;
	}
node7219:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node175;
	} else {
		input[3] &= ~(1 << 5);
		goto node8776;
	}
node3539:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node711;
	}
node6950:
	b = true;
	if (b) {
		input[3] |= (1 << 1);
		goto node3650;
	} else {
		input[3] &= ~(1 << 1);
		return 0;
	}
node8396:
	b = randbool();
	if (b) {
		input[2] |= (1 << 0);
		goto node4134;
	} else {
		input[2] &= ~(1 << 0);
		goto node3103;
	}
node7874:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node5111;
	}
node93:
	b = false;
	if (b) {
		input[2] |= (1 << 3);
		return 0;
	} else {
		input[2] &= ~(1 << 3);
		goto node9018;
	}
node4117:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node7148;
	} else {
		input[3] &= ~(1 << 5);
		goto node2872;
	}
node7598:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node6352;
	} else {
		input[3] &= ~(1 << 3);
		goto node5029;
	}
node3476:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node6154;
	} else {
		input[2] &= ~(1 << 1);
		goto node3326;
	}
node451:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node4152;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node9433:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node3769;
	} else {
		input[3] &= ~(1 << 2);
		goto node4098;
	}
node477:
	b = randbool();
	if (b) {
		input[4] |= (1 << 6);
		goto node1336;
	} else {
		input[4] &= ~(1 << 6);
		goto node2494;
	}
node1493:
	b = true;
	if (b) {
		input[4] |= (1 << 1);
		goto node4987;
	} else {
		input[4] &= ~(1 << 1);
		return 0;
	}
node8424:
	b = randbool();
	if (b) {
		input[0] |= (1 << 2);
		goto node1520;
	} else {
		input[0] &= ~(1 << 2);
		goto node3008;
	}
node4773:
	b = true;
	if (b) {
		input[3] |= (1 << 7);
		goto node8824;
	} else {
		input[3] &= ~(1 << 7);
		return 0;
	}
node5590:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node4864;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node2550:
	b = true;
	if (b) {
		input[3] |= (1 << 2);
		goto node8886;
	} else {
		input[3] &= ~(1 << 2);
		return 0;
	}
node4732:
	b = true;
	if (b) {
		input[4] |= (1 << 7);
		goto node4785;
	} else {
		input[4] &= ~(1 << 7);
		return 0;
	}
node4217:
	b = randbool();
	if (b) {
		input[4] |= (1 << 4);
		goto node8124;
	} else {
		input[4] &= ~(1 << 4);
		goto node9205;
	}
node3895:
	b = true;
	if (b) {
		input[2] |= (1 << 5);
		goto node6869;
	} else {
		input[2] &= ~(1 << 5);
		return 0;
	}
node9150:
	b = false;
	if (b) {
		input[2] |= (1 << 5);
		return 0;
	} else {
		input[2] &= ~(1 << 5);
		goto node2464;
	}
node6521:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node3397;
	} else {
		input[2] &= ~(1 << 3);
		goto node8275;
	}
node2139:
	b = true;
	if (b) {
		input[2] |= (1 << 3);
		goto node5758;
	} else {
		input[2] &= ~(1 << 3);
		return 0;
	}
node8909:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node8988;
	} else {
		input[3] &= ~(1 << 2);
		goto node2488;
	}
node3559:
	b = false;
	if (b) {
		input[3] |= (1 << 0);
		return 0;
	} else {
		input[3] &= ~(1 << 0);
		goto node4534;
	}
node5854:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node1806;
	} else {
		input[2] &= ~(1 << 4);
		goto node4381;
	}
node7169:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node1109;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node668:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node5296;
	} else {
		input[3] &= ~(1 << 6);
		goto node211;
	}
node3560:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node1115;
	} else {
		input[3] &= ~(1 << 3);
		goto node3755;
	}
node6951:
	b = randbool();
	if (b) {
		input[4] |= (1 << 5);
		goto node3911;
	} else {
		input[4] &= ~(1 << 5);
		goto node1191;
	}
node7512:
	b = false;
	if (b) {
		input[4] |= (1 << 3);
		return 0;
	} else {
		input[4] &= ~(1 << 3);
		goto node1096;
	}
node6433:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node2344;
	} else {
		input[2] &= ~(1 << 6);
		goto node6016;
	}
node4641:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node4296;
	} else {
		input[2] &= ~(1 << 6);
		goto node2503;
	}
node7619:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node6793;
	} else {
		input[3] &= ~(1 << 5);
		goto node15;
	}
node5287:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node5504;
	}
node5644:
	b = randbool();
	if (b) {
		input[4] |= (1 << 0);
		goto node1550;
	} else {
		input[4] &= ~(1 << 0);
		goto node6326;
	}
node1476:
	b = true;
	if (b) {
		input[5] |= (1 << 3);
		goto node6651;
	} else {
		input[5] &= ~(1 << 3);
		return 0;
	}
node3946:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node110;
	} else {
		input[2] &= ~(1 << 4);
		goto node3114;
	}
node9305:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		return 3;
	} else {
		input[2] &= ~(1 << 4);
		goto node8498;
	}
node1160:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node7402;
	} else {
		input[2] &= ~(1 << 3);
		goto node6553;
	}
node5591:
	b = true;
	if (b) {
		input[3] |= (1 << 0);
		goto node7552;
	} else {
		input[3] &= ~(1 << 0);
		return 0;
	}
node3030:
	b = true;
	if (b) {
		input[4] |= (1 << 6);
		goto node8964;
	} else {
		input[4] &= ~(1 << 6);
		return 0;
	}
node4654:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node847;
	} else {
		input[2] &= ~(1 << 2);
		goto node6826;
	}
node6477:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node7918;
	} else {
		input[3] &= ~(1 << 4);
		goto node5061;
	}
node2334:
	b = false;
	if (b) {
		input[1] |= (1 << 3);
		return 0;
	} else {
		input[1] &= ~(1 << 3);
		goto node613;
	}
node715:
	b = randbool();
	if (b) {
		input[1] |= (1 << 1);
		goto node6316;
	} else {
		input[1] &= ~(1 << 1);
		goto node6760;
	}
node5572:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node8443;
	}
node8488:
	b = true;
	if (b) {
		input[3] |= (1 << 6);
		goto node7307;
	} else {
		input[3] &= ~(1 << 6);
		return 0;
	}
node7556:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node7628;
	} else {
		input[3] &= ~(1 << 6);
		goto node7631;
	}
node369:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node2218;
	}
node6137:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node7917;
	} else {
		input[2] &= ~(1 << 1);
		goto node8253;
	}
node3739:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node7737;
	}
node7253:
	b = true;
	if (b) {
		input[3] |= (1 << 0);
		goto node6727;
	} else {
		input[3] &= ~(1 << 0);
		return 0;
	}
node7076:
	b = false;
	if (b) {
		input[4] |= (1 << 7);
		return 0;
	} else {
		input[4] &= ~(1 << 7);
		goto node701;
	}
node4491:
	b = false;
	if (b) {
		input[4] |= (1 << 4);
		return 0;
	} else {
		input[4] &= ~(1 << 4);
		goto node2642;
	}
node7740:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node3382;
	} else {
		input[3] &= ~(1 << 4);
		goto node5750;
	}
node6118:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node6352;
	} else {
		input[3] &= ~(1 << 3);
		goto node7135;
	}
node5869:
	b = false;
	if (b) {
		input[1] |= (1 << 2);
		return 0;
	} else {
		input[1] &= ~(1 << 2);
		goto node7831;
	}
node6584:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node1618;
	}
node8262:
	b = false;
	if (b) {
		input[2] |= (1 << 2);
		return 0;
	} else {
		input[2] &= ~(1 << 2);
		goto node2864;
	}
node8537:
	b = true;
	if (b) {
		input[3] |= (1 << 6);
		goto node3106;
	} else {
		input[3] &= ~(1 << 6);
		return 0;
	}
node7807:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node7572;
	} else {
		input[3] &= ~(1 << 6);
		goto node9176;
	}
node2436:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node1348;
	} else {
		input[3] &= ~(1 << 4);
		goto node7632;
	}
node7751:
	b = true;
	if (b) {
		input[4] |= (1 << 7);
		goto node8969;
	} else {
		input[4] &= ~(1 << 7);
		return 0;
	}
node3645:
	b = randbool();
	if (b) {
		input[4] |= (1 << 6);
		goto node4809;
	} else {
		input[4] &= ~(1 << 6);
		goto node8567;
	}
node9335:
	b = true;
	if (b) {
		input[4] |= (1 << 4);
		goto node4670;
	} else {
		input[4] &= ~(1 << 4);
		return 0;
	}
node6389:
	b = true;
	if (b) {
		input[0] |= (1 << 1);
		goto node4404;
	} else {
		input[0] &= ~(1 << 1);
		return 0;
	}
node5357:
	b = randbool();
	if (b) {
		input[1] |= (1 << 5);
		goto node5910;
	} else {
		input[1] &= ~(1 << 5);
		goto node1801;
	}
node8630:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node3629;
	} else {
		input[2] &= ~(1 << 5);
		goto node6087;
	}
node2919:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node4259;
	} else {
		input[2] &= ~(1 << 2);
		goto node851;
	}
node5017:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node7920;
	} else {
		input[3] &= ~(1 << 2);
		goto node7007;
	}
node4750:
	b = true;
	if (b) {
		input[4] |= (1 << 7);
		goto node5946;
	} else {
		input[4] &= ~(1 << 7);
		return 0;
	}
node412:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node2832;
	} else {
		input[2] &= ~(1 << 5);
		goto node6032;
	}
node6277:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node6036;
	} else {
		input[3] &= ~(1 << 2);
		goto node2600;
	}
node6120:
	b = randbool();
	if (b) {
		input[5] |= (1 << 0);
		return 11;
	} else {
		input[5] &= ~(1 << 0);
		return 7;
	}
node6925:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node5360;
	}
node6419:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		return 4;
	}
node5789:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node2684;
	} else {
		input[3] &= ~(1 << 3);
		goto node6077;
	}
node525:
	b = randbool();
	if (b) {
		input[1] |= (1 << 2);
		goto node7454;
	} else {
		input[1] &= ~(1 << 2);
		goto node9026;
	}
node8005:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node8094;
	} else {
		input[3] &= ~(1 << 4);
		goto node7632;
	}
node59:
	b = false;
	if (b) {
		input[1] |= (1 << 4);
		return 0;
	} else {
		input[1] &= ~(1 << 4);
		goto node3662;
	}
node8525:
	b = false;
	if (b) {
		input[2] |= (1 << 5);
		return 0;
	} else {
		input[2] &= ~(1 << 5);
		goto node6279;
	}
node7496:
	b = randbool();
	if (b) {
		input[1] |= (1 << 4);
		goto node1944;
	} else {
		input[1] &= ~(1 << 4);
		goto node7800;
	}
node1092:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node923;
	} else {
		input[2] &= ~(1 << 6);
		goto node3544;
	}
node535:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node1963;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node5108:
	b = true;
	if (b) {
		input[0] |= (1 << 0);
		return 1;
	} else {
		input[0] &= ~(1 << 0);
		return 0;
	}
node2913:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node8808;
	}
node4758:
	b = false;
	if (b) {
		input[2] |= (1 << 0);
		return 0;
	} else {
		input[2] &= ~(1 << 0);
		goto node8884;
	}
node8824:
	b = true;
	if (b) {
		input[3] |= (1 << 6);
		goto node3706;
	} else {
		input[3] &= ~(1 << 6);
		return 0;
	}
node4829:
	b = randbool();
	if (b) {
		input[4] |= (1 << 5);
		goto node7021;
	} else {
		input[4] &= ~(1 << 5);
		goto node7392;
	}
node5021:
	b = randbool();
	if (b) {
		input[5] |= (1 << 5);
		goto node7033;
	} else {
		input[5] &= ~(1 << 5);
		goto node3239;
	}
node8256:
	b = randbool();
	if (b) {
		input[0] |= (1 << 1);
		goto node91;
	} else {
		input[0] &= ~(1 << 1);
		goto node7651;
	}
node6719:
	b = true;
	if (b) {
		input[2] |= (1 << 5);
		goto node4781;
	} else {
		input[2] &= ~(1 << 5);
		return 0;
	}
node5024:
	b = false;
	if (b) {
		input[4] |= (1 << 3);
		return 0;
	} else {
		input[4] &= ~(1 << 3);
		goto node1067;
	}
node9336:
	b = true;
	if (b) {
		input[4] |= (1 << 3);
		goto node3159;
	} else {
		input[4] &= ~(1 << 3);
		return 0;
	}
node2280:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node8737;
	} else {
		input[2] &= ~(1 << 4);
		goto node4684;
	}
node7413:
	b = false;
	if (b) {
		input[2] |= (1 << 3);
		return 0;
	} else {
		input[2] &= ~(1 << 3);
		goto node3352;
	}
node766:
	b = false;
	if (b) {
		input[4] |= (1 << 5);
		return 0;
	} else {
		input[4] &= ~(1 << 5);
		goto node8614;
	}
node3241:
	b = false;
	if (b) {
		input[1] |= (1 << 2);
		return 0;
	} else {
		input[1] &= ~(1 << 2);
		goto node6728;
	}
node2685:
	b = randbool();
	if (b) {
		input[2] |= (1 << 0);
		goto node2094;
	} else {
		input[2] &= ~(1 << 0);
		goto node5235;
	}
node8660:
	b = true;
	if (b) {
		input[2] |= (1 << 4);
		goto node2714;
	} else {
		input[2] &= ~(1 << 4);
		return 0;
	}
node9002:
	b = randbool();
	if (b) {
		input[3] |= (1 << 1);
		goto node6037;
	} else {
		input[3] &= ~(1 << 1);
		goto node9200;
	}
node3126:
	b = true;
	if (b) {
		input[4] |= (1 << 3);
		goto node8315;
	} else {
		input[4] &= ~(1 << 3);
		return 0;
	}
node9078:
	b = randbool();
	if (b) {
		input[4] |= (1 << 2);
		goto node3383;
	} else {
		input[4] &= ~(1 << 2);
		return 5;
	}
node9270:
	b = randbool();
	if (b) {
		input[1] |= (1 << 3);
		goto node4854;
	} else {
		input[1] &= ~(1 << 3);
		goto node3556;
	}
node2932:
	b = randbool();
	if (b) {
		input[1] |= (1 << 3);
		goto node859;
	} else {
		input[1] &= ~(1 << 3);
		goto node4594;
	}
node9237:
	b = false;
	if (b) {
		input[2] |= (1 << 6);
		return 0;
	} else {
		input[2] &= ~(1 << 6);
		goto node2575;
	}
node7981:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node5129;
	} else {
		input[2] &= ~(1 << 1);
		goto node6155;
	}
node4857:
	b = true;
	if (b) {
		input[3] |= (1 << 1);
		goto node5338;
	} else {
		input[3] &= ~(1 << 1);
		return 0;
	}
node5852:
	b = randbool();
	if (b) {
		input[1] |= (1 << 1);
		goto node6186;
	} else {
		input[1] &= ~(1 << 1);
		goto node8822;
	}
node982:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node8612;
	} else {
		input[2] &= ~(1 << 2);
		goto node2504;
	}
node1775:
	b = true;
	if (b) {
		input[3] |= (1 << 7);
		goto node5451;
	} else {
		input[3] &= ~(1 << 7);
		return 0;
	}
node1003:
	b = true;
	if (b) {
		input[2] |= (1 << 2);
		goto node2008;
	} else {
		input[2] &= ~(1 << 2);
		return 0;
	}
node1995:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node5345;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node9422:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node247;
	} else {
		input[3] &= ~(1 << 6);
		goto node802;
	}
node1967:
	b = false;
	if (b) {
		input[4] |= (1 << 1);
		return 0;
	} else {
		input[4] &= ~(1 << 1);
		goto node3168;
	}
node4207:
	b = randbool();
	if (b) {
		input[5] |= (1 << 6);
		goto node9357;
	} else {
		input[5] &= ~(1 << 6);
		goto node5985;
	}
node7875:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node4614;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node2631:
	b = randbool();
	if (b) {
		input[4] |= (1 << 5);
		goto node1533;
	} else {
		input[4] &= ~(1 << 5);
		goto node6858;
	}
node2674:
	b = randbool();
	if (b) {
		input[1] |= (1 << 1);
		goto node3242;
	} else {
		input[1] &= ~(1 << 1);
		goto node2019;
	}
node6299:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node2692;
	} else {
		input[2] &= ~(1 << 3);
		goto node6792;
	}
node3680:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node3621;
	} else {
		input[2] &= ~(1 << 3);
		goto node3211;
	}
node2354:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node617;
	} else {
		input[2] &= ~(1 << 3);
		goto node6669;
	}
node266:
	b = false;
	if (b) {
		input[2] |= (1 << 1);
		return 0;
	} else {
		input[2] &= ~(1 << 1);
		goto node1928;
	}
node667:
	b = true;
	if (b) {
		input[3] |= (1 << 7);
		goto node9061;
	} else {
		input[3] &= ~(1 << 7);
		return 0;
	}
node8872:
	b = false;
	if (b) {
		input[3] |= (1 << 2);
		return 0;
	} else {
		input[3] &= ~(1 << 2);
		goto node1964;
	}
node662:
	b = false;
	if (b) {
		input[3] |= (1 << 2);
		return 0;
	} else {
		input[3] &= ~(1 << 2);
		goto node2600;
	}
node4432:
	b = false;
	if (b) {
		input[1] |= (1 << 1);
		return 0;
	} else {
		input[1] &= ~(1 << 1);
		return 2;
	}
node1319:
	b = true;
	if (b) {
		input[2] |= (1 << 3);
		goto node2581;
	} else {
		input[2] &= ~(1 << 3);
		return 0;
	}
node6908:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node4068;
	} else {
		input[3] &= ~(1 << 7);
		goto node5725;
	}
node2840:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node2155;
	} else {
		input[3] &= ~(1 << 7);
		goto node680;
	}
node352:
	b = true;
	if (b) {
		input[3] |= (1 << 6);
		goto node6117;
	} else {
		input[3] &= ~(1 << 6);
		return 0;
	}
node7295:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node461;
	}
node9044:
	b = true;
	if (b) {
		input[3] |= (1 << 2);
		goto node4714;
	} else {
		input[3] &= ~(1 << 2);
		return 0;
	}
node7362:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node7632;
	} else {
		input[3] &= ~(1 << 2);
		goto node4098;
	}
node192:
	b = randbool();
	if (b) {
		input[1] |= (1 << 6);
		goto node6449;
	} else {
		input[1] &= ~(1 << 6);
		goto node5592;
	}
node3729:
	b = randbool();
	if (b) {
		input[1] |= (1 << 5);
		goto node2375;
	} else {
		input[1] &= ~(1 << 5);
		goto node7724;
	}
node2921:
	b = true;
	if (b) {
		input[3] |= (1 << 6);
		goto node6834;
	} else {
		input[3] &= ~(1 << 6);
		return 0;
	}
node4543:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node5153;
	} else {
		input[3] &= ~(1 << 4);
		goto node7027;
	}
node653:
	b = false;
	if (b) {
		input[4] |= (1 << 4);
		return 0;
	} else {
		input[4] &= ~(1 << 4);
		goto node8836;
	}
node7800:
	b = false;
	if (b) {
		input[1] |= (1 << 3);
		return 0;
	} else {
		input[1] &= ~(1 << 3);
		goto node1944;
	}
node3484:
	b = true;
	if (b) {
		input[1] |= (1 << 0);
		goto node8670;
	} else {
		input[1] &= ~(1 << 0);
		return 0;
	}
node1685:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node7183;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node7808:
	b = randbool();
	if (b) {
		input[3] |= (1 << 0);
		goto node137;
	} else {
		input[3] &= ~(1 << 0);
		goto node9334;
	}
node6292:
	b = randbool();
	if (b) {
		input[1] |= (1 << 0);
		goto node775;
	} else {
		input[1] &= ~(1 << 0);
		goto node5865;
	}
node7924:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node1879;
	}
node767:
	b = randbool();
	if (b) {
		input[5] |= (1 << 6);
		goto node1446;
	} else {
		input[5] &= ~(1 << 6);
		goto node96;
	}
node480:
	b = true;
	if (b) {
		input[1] |= (1 << 2);
		goto node7645;
	} else {
		input[1] &= ~(1 << 2);
		return 0;
	}
node7484:
	b = false;
	if (b) {
		input[4] |= (1 << 5);
		return 0;
	} else {
		input[4] &= ~(1 << 5);
		goto node9393;
	}
node2538:
	b = true;
	if (b) {
		input[5] |= (1 << 5);
		goto node4867;
	} else {
		input[5] &= ~(1 << 5);
		return 0;
	}
node2590:
	b = randbool();
	if (b) {
		input[0] |= (1 << 4);
		goto node833;
	} else {
		input[0] &= ~(1 << 4);
		goto node913;
	}
node6510:
	b = true;
	if (b) {
		input[1] |= (1 << 1);
		goto node4084;
	} else {
		input[1] &= ~(1 << 1);
		return 0;
	}
node1848:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node4308;
	}
node1477:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node2567;
	} else {
		input[2] &= ~(1 << 4);
		goto node1351;
	}
node1039:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node5821;
	}
node7573:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node502;
	} else {
		input[3] &= ~(1 << 4);
		goto node8749;
	}
node1735:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node6803;
	} else {
		input[3] &= ~(1 << 7);
		goto node2608;
	}
node2949:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node8325;
	} else {
		input[3] &= ~(1 << 7);
		goto node4497;
	}
node9380:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node5494;
	} else {
		input[3] &= ~(1 << 5);
		goto node8018;
	}
node4043:
	b = false;
	if (b) {
		input[3] |= (1 << 1);
		return 0;
	} else {
		input[3] &= ~(1 << 1);
		goto node5955;
	}
node6837:
	b = randbool();
	if (b) {
		input[1] |= (1 << 2);
		goto node1155;
	} else {
		input[1] &= ~(1 << 2);
		goto node1171;
	}
node9282:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node711;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node1506:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node5877;
	}
node7920:
	b = false;
	if (b) {
		input[3] |= (1 << 1);
		return 0;
	} else {
		input[3] &= ~(1 << 1);
		goto node6462;
	}
node7033:
	b = randbool();
	if (b) {
		input[5] |= (1 << 4);
		goto node3239;
	} else {
		input[5] &= ~(1 << 4);
		goto node3422;
	}
node9182:
	b = true;
	if (b) {
		input[2] |= (1 << 2);
		goto node8967;
	} else {
		input[2] &= ~(1 << 2);
		return 0;
	}
node4269:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node5533;
	} else {
		input[2] &= ~(1 << 1);
		goto node7887;
	}
node1317:
	b = randbool();
	if (b) {
		input[4] |= (1 << 1);
		goto node9168;
	} else {
		input[4] &= ~(1 << 1);
		goto node4789;
	}
node6590:
	b = randbool();
	if (b) {
		input[0] |= (1 << 2);
		goto node1213;
	} else {
		input[0] &= ~(1 << 2);
		goto node6859;
	}
node7996:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node1995;
	} else {
		input[2] &= ~(1 << 1);
		goto node5345;
	}
node9464:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node6544;
	} else {
		input[2] &= ~(1 << 4);
		goto node7081;
	}
node5719:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node359;
	} else {
		input[3] &= ~(1 << 3);
		goto node9269;
	}
node7345:
	b = randbool();
	if (b) {
		input[3] |= (1 << 1);
		goto node5029;
	} else {
		input[3] &= ~(1 << 1);
		goto node2989;
	}
node3877:
	b = false;
	if (b) {
		input[3] |= (1 << 6);
		return 0;
	} else {
		input[3] &= ~(1 << 6);
		goto node4636;
	}
node2466:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node2886;
	} else {
		input[3] &= ~(1 << 6);
		goto node1216;
	}
node8619:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node9385;
	}
node8082:
	b = true;
	if (b) {
		input[4] |= (1 << 0);
		goto node8656;
	} else {
		input[4] &= ~(1 << 0);
		return 0;
	}
node851:
	b = randbool();
	if (b) {
		input[2] |= (1 << 0);
		goto node6428;
	} else {
		input[2] &= ~(1 << 0);
		goto node7887;
	}
node4710:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node4933;
	} else {
		input[3] &= ~(1 << 6);
		goto node5871;
	}
node6777:
	b = true;
	if (b) {
		input[3] |= (1 << 2);
		goto node7332;
	} else {
		input[3] &= ~(1 << 2);
		return 0;
	}
node7616:
	b = randbool();
	if (b) {
		input[3] |= (1 << 1);
		goto node4735;
	} else {
		input[3] &= ~(1 << 1);
		goto node9262;
	}
node1825:
	b = true;
	if (b) {
		input[4] |= (1 << 6);
		goto node5665;
	} else {
		input[4] &= ~(1 << 6);
		return 0;
	}
node3191:
	b = true;
	if (b) {
		input[2] |= (1 << 2);
		goto node3115;
	} else {
		input[2] &= ~(1 << 2);
		return 0;
	}
node6150:
	b = randbool();
	if (b) {
		input[2] |= (1 << 0);
		goto node2949;
	} else {
		input[2] &= ~(1 << 0);
		goto node8394;
	}
node6993:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node7222;
	} else {
		input[3] &= ~(1 << 3);
		goto node3261;
	}
node9443:
	b = true;
	if (b) {
		input[4] |= (1 << 7);
		goto node2401;
	} else {
		input[4] &= ~(1 << 7);
		return 0;
	}
node7917:
	b = false;
	if (b) {
		input[3] |= (1 << 7);
		return 0;
	} else {
		input[3] &= ~(1 << 7);
		goto node6812;
	}
node3255:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node5534;
	}
node299:
	b = true;
	if (b) {
		input[5] |= (1 << 4);
		goto node7925;
	} else {
		input[5] &= ~(1 << 4);
		return 0;
	}
node2627:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node8073;
	}
node6744:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node6631;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node5058:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		return 6;
	}
node2296:
	b = false;
	if (b) {
		input[3] |= (1 << 2);
		return 0;
	} else {
		input[3] &= ~(1 << 2);
		goto node8686;
	}
node5289:
	b = false;
	if (b) {
		input[1] |= (1 << 1);
		return 0;
	} else {
		input[1] &= ~(1 << 1);
		goto node6186;
	}
node1289:
	b = false;
	if (b) {
		input[3] |= (1 << 7);
		return 0;
	} else {
		input[3] &= ~(1 << 7);
		goto node8718;
	}
node7720:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node7624;
	}
node2394:
	b = true;
	if (b) {
		input[3] |= (1 << 1);
		goto node7685;
	} else {
		input[3] &= ~(1 << 1);
		return 0;
	}
node9381:
	b = randbool();
	if (b) {
		input[4] |= (1 << 4);
		goto node929;
	} else {
		input[4] &= ~(1 << 4);
		goto node4388;
	}
node2265:
	b = true;
	if (b) {
		input[4] |= (1 << 2);
		goto node2356;
	} else {
		input[4] &= ~(1 << 2);
		return 0;
	}
node6121:
	b = false;
	if (b) {
		input[1] |= (1 << 5);
		return 0;
	} else {
		input[1] &= ~(1 << 5);
		goto node4736;
	}
node7560:
	b = true;
	if (b) {
		input[2] |= (1 << 2);
		goto node1892;
	} else {
		input[2] &= ~(1 << 2);
		return 0;
	}
node6936:
	b = false;
	if (b) {
		input[2] |= (1 << 5);
		return 0;
	} else {
		input[2] &= ~(1 << 5);
		goto node5201;
	}
node6176:
	b = randbool();
	if (b) {
		input[2] |= (1 << 0);
		goto node6110;
	} else {
		input[2] &= ~(1 << 0);
		goto node729;
	}
node8578:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node7412;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node7884:
	b = true;
	if (b) {
		input[3] |= (1 << 0);
		goto node5411;
	} else {
		input[3] &= ~(1 << 0);
		return 0;
	}
node5571:
	b = randbool();
	if (b) {
		input[1] |= (1 << 3);
		goto node5378;
	} else {
		input[1] &= ~(1 << 3);
		goto node148;
	}
node6301:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node7567;
	} else {
		input[2] &= ~(1 << 5);
		goto node1597;
	}
node3411:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node1902;
	} else {
		input[3] &= ~(1 << 5);
		goto node4597;
	}
node8844:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node700;
	} else {
		input[3] &= ~(1 << 5);
		goto node3223;
	}
node6092:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node6029;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node4182:
	b = true;
	if (b) {
		input[4] |= (1 << 6);
		goto node3079;
	} else {
		input[4] &= ~(1 << 6);
		return 0;
	}
node4683:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node9116;
	} else {
		input[2] &= ~(1 << 5);
		goto node1358;
	}
node8958:
	b = true;
	if (b) {
		input[2] |= (1 << 2);
		goto node3232;
	} else {
		input[2] &= ~(1 << 2);
		return 0;
	}
node2763:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node8454;
	} else {
		input[3] &= ~(1 << 4);
		goto node3029;
	}
node395:
	b = false;
	if (b) {
		input[4] |= (1 << 4);
		return 0;
	} else {
		input[4] &= ~(1 << 4);
		goto node4500;
	}
node8058:
	b = false;
	if (b) {
		input[2] |= (1 << 2);
		return 0;
	} else {
		input[2] &= ~(1 << 2);
		goto node9125;
	}
node2306:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node1523;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node6769:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node8776;
	}
node5368:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node7632;
	} else {
		input[3] &= ~(1 << 2);
		goto node4611;
	}
node1914:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node8194;
	} else {
		input[3] &= ~(1 << 4);
		goto node137;
	}
node8682:
	b = true;
	if (b) {
		input[1] |= (1 << 1);
		goto node3041;
	} else {
		input[1] &= ~(1 << 1);
		return 0;
	}
node7645:
	b = true;
	if (b) {
		input[1] |= (1 << 0);
		return 2;
	} else {
		input[1] &= ~(1 << 0);
		return 0;
	}
node3454:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node5660;
	} else {
		input[2] &= ~(1 << 2);
		goto node8536;
	}
node3731:
	b = false;
	if (b) {
		input[3] |= (1 << 7);
		return 0;
	} else {
		input[3] &= ~(1 << 7);
		goto node7160;
	}
node1673:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node6921;
	} else {
		input[3] &= ~(1 << 5);
		goto node3574;
	}
node6465:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node2725;
	}
node4447:
	b = false;
	if (b) {
		input[2] |= (1 << 3);
		return 0;
	} else {
		input[2] &= ~(1 << 3);
		goto node6566;
	}
node8292:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		goto node3192;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node7936:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node7779;
	} else {
		input[3] &= ~(1 << 5);
		goto node6054;
	}
node4329:
	b = false;
	if (b) {
		input[3] |= (1 << 1);
		return 0;
	} else {
		input[3] &= ~(1 << 1);
		goto node5528;
	}
node5695:
	b = randbool();
	if (b) {
		input[1] |= (1 << 0);
		goto node7455;
	} else {
		input[1] &= ~(1 << 0);
		goto node7250;
	}
node8443:
	b = false;
	if (b) {
		input[2] |= (1 << 3);
		return 0;
	} else {
		input[2] &= ~(1 << 3);
		goto node2805;
	}
node6211:
	b = true;
	if (b) {
		input[3] |= (1 << 1);
		goto node1363;
	} else {
		input[3] &= ~(1 << 1);
		return 0;
	}
node8314:
	b = false;
	if (b) {
		input[4] |= (1 << 5);
		return 0;
	} else {
		input[4] &= ~(1 << 5);
		goto node3993;
	}
node2072:
	b = randbool();
	if (b) {
		input[4] |= (1 << 4);
		goto node4817;
	} else {
		input[4] &= ~(1 << 4);
		goto node7913;
	}
node7260:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node5747;
	} else {
		input[2] &= ~(1 << 5);
		goto node8745;
	}
node1867:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node7090;
	} else {
		input[2] &= ~(1 << 2);
		goto node808;
	}
node94:
	b = randbool();
	if (b) {
		input[2] |= (1 << 0);
		goto node3799;
	} else {
		input[2] &= ~(1 << 0);
		goto node667;
	}
node2570:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node459;
	} else {
		input[3] &= ~(1 << 6);
		goto node95;
	}
node7123:
	b = false;
	if (b) {
		input[3] |= (1 << 2);
		return 0;
	} else {
		input[3] &= ~(1 << 2);
		goto node9016;
	}
node2192:
	b = false;
	if (b) {
		input[3] |= (1 << 0);
		return 0;
	} else {
		input[3] &= ~(1 << 0);
		goto node2813;
	}
node1062:
	b = false;
	if (b) {
		input[1] |= (1 << 5);
		return 0;
	} else {
		input[1] &= ~(1 << 5);
		goto node7204;
	}
node9354:
	b = false;
	if (b) {
		input[2] |= (1 << 3);
		return 0;
	} else {
		input[2] &= ~(1 << 3);
		goto node3145;
	}
node7581:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node5686;
	} else {
		input[3] &= ~(1 << 2);
		goto node6297;
	}
node2347:
	b = randbool();
	if (b) {
		input[4] |= (1 << 7);
		goto node5496;
	} else {
		input[4] &= ~(1 << 7);
		goto node4685;
	}
node6760:
	b = randbool();
	if (b) {
		input[1] |= (1 << 0);
		goto node4125;
	} else {
		input[1] &= ~(1 << 0);
		goto node7948;
	}
node8460:
	b = false;
	if (b) {
		input[2] |= (1 << 5);
		return 0;
	} else {
		input[2] &= ~(1 << 5);
		goto node9034;
	}
node216:
	b = false;
	if (b) {
		input[2] |= (1 << 0);
		return 0;
	} else {
		input[2] &= ~(1 << 0);
		goto node5068;
	}
node8877:
	b = true;
	if (b) {
		input[3] |= (1 << 0);
		goto node235;
	} else {
		input[3] &= ~(1 << 0);
		return 0;
	}
node6825:
	b = randbool();
	if (b) {
		input[1] |= (1 << 5);
		goto node3601;
	} else {
		input[1] &= ~(1 << 5);
		goto node7086;
	}
node6582:
	b = randbool();
	if (b) {
		input[2] |= (1 << 7);
		goto node3965;
	} else {
		input[2] &= ~(1 << 7);
		goto node1527;
	}
node6621:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node5066;
	} else {
		input[2] &= ~(1 << 6);
		goto node5791;
	}
node3278:
	b = false;
	if (b) {
		input[2] |= (1 << 3);
		return 0;
	} else {
		input[2] &= ~(1 << 3);
		goto node1855;
	}
node160:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node5134;
	} else {
		input[3] &= ~(1 << 2);
		return 4;
	}
node7261:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node4715;
	} else {
		input[2] &= ~(1 << 3);
		goto node6153;
	}
node141:
	b = true;
	if (b) {
		input[2] |= (1 << 3);
		goto node8649;
	} else {
		input[2] &= ~(1 << 3);
		return 0;
	}
node2063:
	b = false;
	if (b) {
		input[2] |= (1 << 1);
		return 0;
	} else {
		input[2] &= ~(1 << 1);
		goto node5684;
	}
node5120:
	b = randbool();
	if (b) {
		input[2] |= (1 << 0);
		goto node6553;
	} else {
		input[2] &= ~(1 << 0);
		goto node4006;
	}
node8760:
	b = true;
	if (b) {
		input[3] |= (1 << 6);
		goto node309;
	} else {
		input[3] &= ~(1 << 6);
		return 0;
	}
node2497:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node8157;
	} else {
		input[3] &= ~(1 << 2);
		goto node3157;
	}
node5294:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node4390;
	} else {
		input[2] &= ~(1 << 4);
		goto node2933;
	}
node2950:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node7516;
	} else {
		input[3] &= ~(1 << 5);
		goto node6441;
	}
node1563:
	b = true;
	if (b) {
		input[3] |= (1 << 2);
		goto node6037;
	} else {
		input[3] &= ~(1 << 2);
		return 0;
	}
node8099:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node8890;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node2093:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node7586;
	} else {
		input[2] &= ~(1 << 6);
		goto node7325;
	}
node9042:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node3853;
	}
node7092:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node3614;
	} else {
		input[3] &= ~(1 << 5);
		goto node6761;
	}
node6910:
	b = false;
	if (b) {
		input[3] |= (1 << 7);
		return 0;
	} else {
		input[3] &= ~(1 << 7);
		goto node8743;
	}
node161:
	b = true;
	if (b) {
		input[3] |= (1 << 1);
		goto node9453;
	} else {
		input[3] &= ~(1 << 1);
		return 0;
	}
node7334:
	b = false;
	if (b) {
		input[1] |= (1 << 1);
		return 0;
	} else {
		input[1] &= ~(1 << 1);
		goto node2138;
	}
node4129:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node8907;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node4378:
	b = false;
	if (b) {
		input[3] |= (1 << 7);
		return 0;
	} else {
		input[3] &= ~(1 << 7);
		goto node7426;
	}
node971:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		return 4;
	} else {
		input[3] &= ~(1 << 5);
		goto node4051;
	}
node4592:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node9317;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node9453:
	b = true;
	if (b) {
		input[3] |= (1 << 0);
		goto node5092;
	} else {
		input[3] &= ~(1 << 0);
		return 0;
	}
node2782:
	b = randbool();
	if (b) {
		input[4] |= (1 << 2);
		goto node694;
	} else {
		input[4] &= ~(1 << 2);
		goto node7777;
	}
node8184:
	b = true;
	if (b) {
		input[1] |= (1 << 3);
		goto node3591;
	} else {
		input[1] &= ~(1 << 3);
		return 0;
	}
node1260:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node209;
	} else {
		input[2] &= ~(1 << 5);
		goto node1302;
	}
node1313:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node2405;
	} else {
		input[2] &= ~(1 << 4);
		goto node8211;
	}
node364:
	b = false;
	if (b) {
		input[2] |= (1 << 3);
		return 0;
	} else {
		input[2] &= ~(1 << 3);
		goto node7612;
	}
node3416:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node137;
	} else {
		input[3] &= ~(1 << 3);
		goto node8190;
	}
node3780:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node6988;
	} else {
		input[3] &= ~(1 << 3);
		goto node3551;
	}
node8614:
	b = false;
	if (b) {
		input[4] |= (1 << 4);
		return 0;
	} else {
		input[4] &= ~(1 << 4);
		goto node797;
	}
node4388:
	b = true;
	if (b) {
		input[4] |= (1 << 3);
		goto node929;
	} else {
		input[4] &= ~(1 << 3);
		return 0;
	}
node8334:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node2441;
	} else {
		input[2] &= ~(1 << 6);
		goto node1504;
	}
node5493:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node726;
	}
node3042:
	b = false;
	if (b) {
		input[2] |= (1 << 0);
		return 0;
	} else {
		input[2] &= ~(1 << 0);
		goto node6428;
	}
node3093:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node6407;
	}
node196:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node137;
	} else {
		input[3] &= ~(1 << 3);
		goto node3131;
	}
node8905:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node4460;
	} else {
		input[3] &= ~(1 << 2);
		goto node7947;
	}
node3542:
	b = false;
	if (b) {
		input[6] |= (1 << 1);
		return 0;
	} else {
		input[6] &= ~(1 << 1);
		goto node768;
	}
node4771:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		goto node6968;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node6085:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node7639;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node7246:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node2952;
	} else {
		input[3] &= ~(1 << 4);
		goto node8776;
	}
node1217:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node3506;
	}
node1147:
	b = false;
	if (b) {
		input[4] |= (1 << 5);
		return 0;
	} else {
		input[4] &= ~(1 << 5);
		goto node5299;
	}
node6215:
	b = randbool();
	if (b) {
		input[4] |= (1 << 5);
		goto node6899;
	} else {
		input[4] &= ~(1 << 5);
		goto node5449;
	}
node7014:
	b = false;
	if (b) {
		input[2] |= (1 << 0);
		return 0;
	} else {
		input[2] &= ~(1 << 0);
		goto node5007;
	}
node6024:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node1240;
	} else {
		input[3] &= ~(1 << 5);
		goto node5639;
	}
node7453:
	b = false;
	if (b) {
		input[7] |= (1 << 0);
		return 0;
	} else {
		input[7] &= ~(1 << 0);
		return 8;
	}
node4673:
	b = randbool();
	if (b) {
		input[0] |= (1 << 0);
		goto node5467;
	} else {
		input[0] &= ~(1 << 0);
		goto node7067;
	}
node1826:
	b = randbool();
	if (b) {
		input[1] |= (1 << 1);
		goto node4576;
	} else {
		input[1] &= ~(1 << 1);
		goto node5423;
	}
node8684:
	b = false;
	if (b) {
		input[3] |= (1 << 6);
		return 0;
	} else {
		input[3] &= ~(1 << 6);
		goto node887;
	}
node1592:
	b = randbool();
	if (b) {
		input[3] |= (1 << 0);
		goto node7677;
	} else {
		input[3] &= ~(1 << 0);
		goto node5759;
	}
node8802:
	b = randbool();
	if (b) {
		input[1] |= (1 << 2);
		goto node4476;
	} else {
		input[1] &= ~(1 << 2);
		return 3;
	}
node4649:
	b = randbool();
	if (b) {
		input[2] |= (1 << 7);
		goto node51;
	} else {
		input[2] &= ~(1 << 7);
		goto node7798;
	}
node758:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		goto node2707;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node681:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node8930;
	}
node6807:
	b = randbool();
	if (b) {
		input[0] |= (1 << 4);
		goto node3240;
	} else {
		input[0] &= ~(1 << 4);
		goto node7233;
	}
node6583:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node3015;
	} else {
		input[2] &= ~(1 << 6);
		goto node6788;
	}
node955:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node6604;
	} else {
		input[2] &= ~(1 << 4);
		goto node3957;
	}
node7806:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node3535;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node8623:
	b = randbool();
	if (b) {
		input[1] |= (1 << 5);
		goto node5910;
	} else {
		input[1] &= ~(1 << 5);
		goto node2829;
	}
node3172:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node1440;
	} else {
		input[2] &= ~(1 << 5);
		goto node6426;
	}
node7058:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node3163;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node3589:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node5441;
	} else {
		input[3] &= ~(1 << 4);
		goto node7632;
	}
node2389:
	b = true;
	if (b) {
		input[1] |= (1 << 0);
		goto node1701;
	} else {
		input[1] &= ~(1 << 0);
		return 0;
	}
node2399:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node7858;
	} else {
		input[2] &= ~(1 << 4);
		goto node1467;
	}
node6550:
	b = false;
	if (b) {
		input[2] |= (1 << 3);
		return 0;
	} else {
		input[2] &= ~(1 << 3);
		goto node2004;
	}
node3603:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node3154;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node846:
	b = false;
	if (b) {
		input[3] |= (1 << 0);
		return 0;
	} else {
		input[3] &= ~(1 << 0);
		goto node7677;
	}
node1007:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node5292;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node1641:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node4220;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node3007:
	b = randbool();
	if (b) {
		input[4] |= (1 << 4);
		goto node5449;
	} else {
		input[4] &= ~(1 << 4);
		goto node2271;
	}
node8523:
	b = true;
	if (b) {
		input[4] |= (1 << 7);
		goto node3536;
	} else {
		input[4] &= ~(1 << 7);
		return 0;
	}
node1907:
	b = true;
	if (b) {
		input[1] |= (1 << 1);
		goto node7102;
	} else {
		input[1] &= ~(1 << 1);
		return 0;
	}
node4779:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node1161;
	} else {
		input[2] &= ~(1 << 2);
		goto node2315;
	}
node7510:
	b = false;
	if (b) {
		input[2] |= (1 << 1);
		return 0;
	} else {
		input[2] &= ~(1 << 1);
		goto node1995;
	}
node2505:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node2519;
	} else {
		input[3] &= ~(1 << 6);
		goto node6444;
	}
node3106:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node4349;
	} else {
		input[3] &= ~(1 << 5);
		goto node1466;
	}
node6785:
	b = true;
	if (b) {
		input[3] |= (1 << 2);
		goto node5932;
	} else {
		input[3] &= ~(1 << 2);
		return 0;
	}
node1802:
	b = true;
	if (b) {
		input[1] |= (1 << 3);
		return 4;
	} else {
		input[1] &= ~(1 << 3);
		return 0;
	}
node2511:
	b = false;
	if (b) {
		input[2] |= (1 << 7);
		return 0;
	} else {
		input[2] &= ~(1 << 7);
		goto node1124;
	}
node9328:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node8995;
	}
node8697:
	b = true;
	if (b) {
		input[2] |= (1 << 3);
		goto node6470;
	} else {
		input[2] &= ~(1 << 3);
		return 0;
	}
node1513:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node2307;
	} else {
		input[2] &= ~(1 << 3);
		goto node7537;
	}
node3614:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node8632;
	} else {
		input[3] &= ~(1 << 4);
		goto node137;
	}
node1755:
	b = false;
	if (b) {
		input[1] |= (1 << 4);
		return 0;
	} else {
		input[1] &= ~(1 << 4);
		goto node3772;
	}
node362:
	b = false;
	if (b) {
		input[1] |= (1 << 2);
		return 0;
	} else {
		input[1] &= ~(1 << 2);
		goto node3246;
	}
node3991:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node2130;
	} else {
		input[2] &= ~(1 << 5);
		goto node6603;
	}
node530:
	b = true;
	if (b) {
		input[3] |= (1 << 1);
		goto node6462;
	} else {
		input[3] &= ~(1 << 1);
		return 0;
	}
node6117:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node3815;
	}
node1375:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node3986;
	} else {
		input[3] &= ~(1 << 3);
		goto node1688;
	}
node3175:
	b = randbool();
	if (b) {
		input[3] |= (1 << 1);
		goto node1508;
	} else {
		input[3] &= ~(1 << 1);
		goto node2192;
	}
node1392:
	b = true;
	if (b) {
		input[4] |= (1 << 7);
		goto node8342;
	} else {
		input[4] &= ~(1 << 7);
		return 0;
	}
node5522:
	b = false;
	if (b) {
		input[3] |= (1 << 0);
		return 0;
	} else {
		input[3] &= ~(1 << 0);
		goto node2531;
	}
node9289:
	b = randbool();
	if (b) {
		input[3] |= (1 << 0);
		goto node7998;
	} else {
		input[3] &= ~(1 << 0);
		goto node3520;
	}
node790:
	b = false;
	if (b) {
		input[1] |= (1 << 1);
		return 0;
	} else {
		input[1] &= ~(1 << 1);
		goto node9304;
	}
node7506:
	b = true;
	if (b) {
		input[2] |= (1 << 6);
		return 3;
	} else {
		input[2] &= ~(1 << 6);
		return 0;
	}
node1722:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node534;
	} else {
		input[2] &= ~(1 << 3);
		goto node242;
	}
node5976:
	b = false;
	if (b) {
		input[2] |= (1 << 2);
		return 0;
	} else {
		input[2] &= ~(1 << 2);
		goto node8946;
	}
node9031:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node1861;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node1728:
	b = false;
	if (b) {
		input[3] |= (1 << 2);
		return 0;
	} else {
		input[3] &= ~(1 << 2);
		goto node3298;
	}
node3040:
	b = true;
	if (b) {
		input[1] |= (1 << 1);
		goto node2165;
	} else {
		input[1] &= ~(1 << 1);
		return 0;
	}
node7699:
	b = true;
	if (b) {
		input[1] |= (1 << 0);
		goto node9093;
	} else {
		input[1] &= ~(1 << 0);
		return 0;
	}
node8091:
	b = randbool();
	if (b) {
		input[2] |= (1 << 0);
		goto node423;
	} else {
		input[2] &= ~(1 << 0);
		goto node1373;
	}
node7056:
	b = false;
	if (b) {
		input[4] |= (1 << 4);
		return 0;
	} else {
		input[4] &= ~(1 << 4);
		goto node5030;
	}
node713:
	b = false;
	if (b) {
		input[4] |= (1 << 4);
		return 0;
	} else {
		input[4] &= ~(1 << 4);
		goto node1965;
	}
node148:
	b = randbool();
	if (b) {
		input[1] |= (1 << 2);
		goto node3207;
	} else {
		input[1] &= ~(1 << 2);
		goto node6262;
	}
node6483:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node2436;
	} else {
		input[3] &= ~(1 << 5);
		goto node7187;
	}
node6010:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node1315;
	} else {
		input[3] &= ~(1 << 5);
		goto node2742;
	}
node2980:
	b = true;
	if (b) {
		input[1] |= (1 << 1);
		goto node84;
	} else {
		input[1] &= ~(1 << 1);
		return 0;
	}
node9386:
	b = true;
	if (b) {
		input[3] |= (1 << 2);
		goto node2394;
	} else {
		input[3] &= ~(1 << 2);
		return 0;
	}
node5756:
	b = true;
	if (b) {
		input[3] |= (1 << 1);
		goto node9284;
	} else {
		input[3] &= ~(1 << 1);
		return 0;
	}
node4554:
	b = true;
	if (b) {
		input[1] |= (1 << 1);
		goto node8426;
	} else {
		input[1] &= ~(1 << 1);
		return 0;
	}
node2406:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node753;
	} else {
		input[2] &= ~(1 << 2);
		goto node2553;
	}
node4869:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		goto node4439;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node2383:
	b = true;
	if (b) {
		input[3] |= (1 << 6);
		goto node492;
	} else {
		input[3] &= ~(1 << 6);
		return 0;
	}
node6065:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node2630;
	}
node9127:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node9253;
	}
node7111:
	b = true;
	if (b) {
		input[1] |= (1 << 0);
		goto node7588;
	} else {
		input[1] &= ~(1 << 0);
		return 0;
	}
node7357:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node7174;
	} else {
		input[2] &= ~(1 << 6);
		goto node8512;
	}
node7406:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node6553;
	} else {
		input[2] &= ~(1 << 3);
		goto node9319;
	}
node7463:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		return 7;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node6547:
	b = true;
	if (b) {
		input[3] |= (1 << 0);
		return 6;
	} else {
		input[3] &= ~(1 << 0);
		return 0;
	}
node2182:
	b = true;
	if (b) {
		input[4] |= (1 << 5);
		goto node4631;
	} else {
		input[4] &= ~(1 << 5);
		return 0;
	}
node3771:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node2783;
	} else {
		input[2] &= ~(1 << 5);
		goto node5281;
	}
node7117:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node2187;
	} else {
		input[2] &= ~(1 << 2);
		goto node6371;
	}
node2114:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node4862;
	} else {
		input[3] &= ~(1 << 6);
		goto node9291;
	}
node5180:
	b = true;
	if (b) {
		input[4] |= (1 << 5);
		goto node7826;
	} else {
		input[4] &= ~(1 << 5);
		return 0;
	}
node4412:
	b = randbool();
	if (b) {
		input[4] |= (1 << 0);
		goto node8656;
	} else {
		input[4] &= ~(1 << 0);
		goto node7576;
	}
node1275:
	b = randbool();
	if (b) {
		input[1] |= (1 << 1);
		return 6;
	} else {
		input[1] &= ~(1 << 1);
		goto node4881;
	}
node3592:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node5638;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node857:
	b = randbool();
	if (b) {
		input[3] |= (1 << 1);
		goto node4444;
	} else {
		input[3] &= ~(1 << 1);
		goto node6462;
	}
node1538:
	b = true;
	if (b) {
		input[3] |= (1 << 1);
		goto node163;
	} else {
		input[3] &= ~(1 << 1);
		return 0;
	}
node1604:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node5182;
	} else {
		input[2] &= ~(1 << 3);
		goto node5976;
	}
node6378:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node7943;
	} else {
		input[3] &= ~(1 << 6);
		goto node4073;
	}
node578:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node7412;
	}
node1443:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node1431;
	}
node7372:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node9056;
	}
node5727:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node1445;
	}
node8637:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node7306;
	} else {
		input[2] &= ~(1 << 1);
		goto node1307;
	}
node2442:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node7471;
	} else {
		input[2] &= ~(1 << 1);
		goto node2955;
	}
node5455:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node7184;
	} else {
		input[3] &= ~(1 << 4);
		goto node3727;
	}
node3149:
	b = randbool();
	if (b) {
		input[4] |= (1 << 1);
		goto node2352;
	} else {
		input[4] &= ~(1 << 1);
		goto node7576;
	}
node4208:
	b = randbool();
	if (b) {
		input[0] |= (1 << 0);
		return 1;
	} else {
		input[0] &= ~(1 << 0);
		goto node3619;
	}
node1449:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node5143;
	} else {
		input[2] &= ~(1 << 2);
		goto node266;
	}
node9263:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		goto node535;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node8469:
	b = true;
	if (b) {
		input[4] |= (1 << 1);
		goto node7422;
	} else {
		input[4] &= ~(1 << 1);
		return 0;
	}
node5003:
	b = false;
	if (b) {
		input[4] |= (1 << 1);
		return 0;
	} else {
		input[4] &= ~(1 << 1);
		goto node1950;
	}
node9428:
	b = false;
	if (b) {
		input[2] |= (1 << 7);
		return 0;
	} else {
		input[2] &= ~(1 << 7);
		goto node3024;
	}
node8023:
	b = false;
	if (b) {
		input[2] |= (1 << 5);
		return 0;
	} else {
		input[2] &= ~(1 << 5);
		goto node6493;
	}
node5931:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		goto node4449;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node918:
	b = randbool();
	if (b) {
		input[2] |= (1 << 0);
		goto node5345;
	} else {
		input[2] &= ~(1 << 0);
		goto node3799;
	}
node3342:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		return 5;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node9442:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node8988;
	} else {
		input[3] &= ~(1 << 2);
		goto node6462;
	}
node4594:
	b = false;
	if (b) {
		input[1] |= (1 << 2);
		return 0;
	} else {
		input[1] &= ~(1 << 2);
		goto node5766;
	}
node7845:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node2786;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node8405:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node7874;
	} else {
		input[3] &= ~(1 << 6);
		goto node8196;
	}
node7785:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node2296;
	} else {
		input[3] &= ~(1 << 4);
		goto node6309;
	}
node7987:
	b = true;
	if (b) {
		input[3] |= (1 << 2);
		goto node4311;
	} else {
		input[3] &= ~(1 << 2);
		return 0;
	}
node4392:
	b = true;
	if (b) {
		input[4] |= (1 << 6);
		goto node9389;
	} else {
		input[4] &= ~(1 << 6);
		return 0;
	}
node467:
	b = true;
	if (b) {
		input[4] |= (1 << 2);
		goto node1491;
	} else {
		input[4] &= ~(1 << 2);
		return 0;
	}
node1664:
	b = false;
	if (b) {
		input[6] |= (1 << 1);
		return 0;
	} else {
		input[6] &= ~(1 << 1);
		goto node4619;
	}
node5181:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node8797;
	} else {
		input[2] &= ~(1 << 4);
		goto node6148;
	}
node4410:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node4891;
	} else {
		input[2] &= ~(1 << 3);
		goto node1207;
	}
node307:
	b = false;
	if (b) {
		input[2] |= (1 << 1);
		return 0;
	} else {
		input[2] &= ~(1 << 1);
		goto node7338;
	}
node6627:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node4144;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node6828:
	b = randbool();
	if (b) {
		input[2] |= (1 << 0);
		goto node667;
	} else {
		input[2] &= ~(1 << 0);
		goto node1775;
	}
node2620:
	b = true;
	if (b) {
		input[3] |= (1 << 7);
		goto node5341;
	} else {
		input[3] &= ~(1 << 7);
		return 0;
	}
node2161:
	b = randbool();
	if (b) {
		input[1] |= (1 << 2);
		goto node6500;
	} else {
		input[1] &= ~(1 << 2);
		goto node2843;
	}
node2833:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node4560;
	} else {
		input[2] &= ~(1 << 1);
		goto node7729;
	}
node2516:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node393;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node5325:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node8420;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node6381:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node3514;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node1792:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node1396;
	}
node717:
	b = true;
	if (b) {
		input[2] |= (1 << 2);
		goto node4782;
	} else {
		input[2] &= ~(1 << 2);
		return 0;
	}
node5090:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node4301;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node4678:
	b = randbool();
	if (b) {
		input[0] |= (1 << 0);
		goto node5243;
	} else {
		input[0] &= ~(1 << 0);
		goto node1447;
	}
node7860:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node132;
	} else {
		input[3] &= ~(1 << 7);
		goto node7846;
	}
node9405:
	b = true;
	if (b) {
		input[3] |= (1 << 7);
		goto node1168;
	} else {
		input[3] &= ~(1 << 7);
		return 0;
	}
node8212:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node8548;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node3927:
	b = false;
	if (b) {
		input[3] |= (1 << 0);
		return 0;
	} else {
		input[3] &= ~(1 << 0);
		goto node1241;
	}
node5817:
	b = randbool();
	if (b) {
		input[4] |= (1 << 7);
		goto node3978;
	} else {
		input[4] &= ~(1 << 7);
		goto node1699;
	}
node2092:
	b = true;
	if (b) {
		input[6] |= (1 << 2);
		goto node1198;
	} else {
		input[6] &= ~(1 << 2);
		return 0;
	}
node5413:
	b = true;
	if (b) {
		input[6] |= (1 << 2);
		goto node5742;
	} else {
		input[6] &= ~(1 << 2);
		return 0;
	}
node4600:
	b = true;
	if (b) {
		input[1] |= (1 << 1);
		goto node733;
	} else {
		input[1] &= ~(1 << 1);
		return 0;
	}
node1248:
	b = false;
	if (b) {
		input[2] |= (1 << 5);
		return 0;
	} else {
		input[2] &= ~(1 << 5);
		goto node6751;
	}
node5531:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node8696;
	} else {
		input[2] &= ~(1 << 5);
		goto node2789;
	}
node3648:
	b = randbool();
	if (b) {
		input[2] |= (1 << 0);
		goto node6252;
	} else {
		input[2] &= ~(1 << 0);
		goto node8717;
	}
node7207:
	b = randbool();
	if (b) {
		input[2] |= (1 << 0);
		goto node5906;
	} else {
		input[2] &= ~(1 << 0);
		goto node4546;
	}
node382:
	b = randbool();
	if (b) {
		input[3] |= (1 << 0);
		return 5;
	} else {
		input[3] &= ~(1 << 0);
		goto node5565;
	}
node28:
	b = true;
	if (b) {
		input[2] |= (1 << 6);
		goto node6937;
	} else {
		input[2] &= ~(1 << 6);
		return 0;
	}
node1042:
	b = true;
	if (b) {
		input[4] |= (1 << 6);
		goto node8314;
	} else {
		input[4] &= ~(1 << 6);
		return 0;
	}
node152:
	b = false;
	if (b) {
		input[2] |= (1 << 3);
		return 0;
	} else {
		input[2] &= ~(1 << 3);
		goto node8636;
	}
node5667:
	b = false;
	if (b) {
		input[3] |= (1 << 7);
		return 0;
	} else {
		input[3] &= ~(1 << 7);
		goto node1337;
	}
node3158:
	b = randbool();
	if (b) {
		input[4] |= (1 << 3);
		goto node4964;
	} else {
		input[4] &= ~(1 << 3);
		goto node6891;
	}
node1961:
	b = true;
	if (b) {
		input[2] |= (1 << 2);
		goto node4870;
	} else {
		input[2] &= ~(1 << 2);
		return 0;
	}
node7386:
	b = true;
	if (b) {
		input[3] |= (1 << 7);
		goto node6238;
	} else {
		input[3] &= ~(1 << 7);
		return 0;
	}
node7361:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node4537;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node1111:
	b = true;
	if (b) {
		input[4] |= (1 << 4);
		goto node1434;
	} else {
		input[4] &= ~(1 << 4);
		return 0;
	}
node8113:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node32;
	}
node8941:
	b = true;
	if (b) {
		input[4] |= (1 << 4);
		goto node8229;
	} else {
		input[4] &= ~(1 << 4);
		return 0;
	}
node8140:
	b = true;
	if (b) {
		input[5] |= (1 << 5);
		goto node299;
	} else {
		input[5] &= ~(1 << 5);
		return 0;
	}
node2601:
	b = randbool();
	if (b) {
		input[5] |= (1 << 4);
		goto node9230;
	} else {
		input[5] &= ~(1 << 4);
		goto node7934;
	}
node3190:
	b = false;
	if (b) {
		input[2] |= (1 << 5);
		return 0;
	} else {
		input[2] &= ~(1 << 5);
		goto node9272;
	}
node3738:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node3805;
	} else {
		input[2] &= ~(1 << 5);
		goto node1899;
	}
node1765:
	b = false;
	if (b) {
		input[3] |= (1 << 6);
		return 0;
	} else {
		input[3] &= ~(1 << 6);
		goto node7139;
	}
node8356:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node8800;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node3554:
	b = randbool();
	if (b) {
		input[4] |= (1 << 1);
		goto node8966;
	} else {
		input[4] &= ~(1 << 1);
		goto node5436;
	}
node3875:
	b = randbool();
	if (b) {
		input[6] |= (1 << 3);
		goto node5265;
	} else {
		input[6] &= ~(1 << 3);
		goto node1264;
	}
node9441:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node4958;
	} else {
		input[2] &= ~(1 << 3);
		goto node7887;
	}
node6080:
	b = true;
	if (b) {
		input[2] |= (1 << 2);
		goto node7840;
	} else {
		input[2] &= ~(1 << 2);
		return 0;
	}
node3755:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node7632;
	} else {
		input[3] &= ~(1 << 2);
		goto node5686;
	}
node4511:
	b = true;
	if (b) {
		input[4] |= (1 << 5);
		goto node7983;
	} else {
		input[4] &= ~(1 << 5);
		return 0;
	}
node4964:
	b = randbool();
	if (b) {
		input[4] |= (1 << 2);
		goto node2360;
	} else {
		input[4] &= ~(1 << 2);
		goto node3554;
	}
node5254:
	b = randbool();
	if (b) {
		input[1] |= (1 << 5);
		return 2;
	} else {
		input[1] &= ~(1 << 5);
		goto node4519;
	}
node7199:
	b = true;
	if (b) {
		input[4] |= (1 << 4);
		goto node8568;
	} else {
		input[4] &= ~(1 << 4);
		return 0;
	}
node2440:
	b = randbool();
	if (b) {
		input[1] |= (1 << 6);
		goto node6894;
	} else {
		input[1] &= ~(1 << 6);
		goto node945;
	}
node3123:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		return 8;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node6434:
	b = false;
	if (b) {
		input[3] |= (1 << 7);
		return 0;
	} else {
		input[3] &= ~(1 << 7);
		goto node2826;
	}
node7024:
	b = false;
	if (b) {
		input[3] |= (1 << 7);
		return 0;
	} else {
		input[3] &= ~(1 << 7);
		goto node2088;
	}
node5099:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node9075;
	}
node478:
	b = randbool();
	if (b) {
		input[4] |= (1 << 6);
		goto node8299;
	} else {
		input[4] &= ~(1 << 6);
		goto node9455;
	}
node985:
	b = randbool();
	if (b) {
		input[1] |= (1 << 3);
		goto node3241;
	} else {
		input[1] &= ~(1 << 3);
		goto node9013;
	}
node9020:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node5724;
	} else {
		input[3] &= ~(1 << 7);
		goto node1411;
	}
node6084:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node5220;
	} else {
		input[3] &= ~(1 << 7);
		goto node7270;
	}
node1915:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node951;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node5065:
	b = true;
	if (b) {
		input[4] |= (1 << 7);
		goto node3781;
	} else {
		input[4] &= ~(1 << 7);
		return 0;
	}
node3490:
	b = false;
	if (b) {
		input[4] |= (1 << 3);
		return 0;
	} else {
		input[4] &= ~(1 << 3);
		goto node6659;
	}
node9132:
	b = false;
	if (b) {
		input[4] |= (1 << 4);
		return 0;
	} else {
		input[4] &= ~(1 << 4);
		goto node1610;
	}
node6218:
	b = false;
	if (b) {
		input[2] |= (1 << 5);
		return 0;
	} else {
		input[2] &= ~(1 << 5);
		goto node8441;
	}
node8808:
	b = true;
	if (b) {
		input[2] |= (1 << 3);
		goto node3022;
	} else {
		input[2] &= ~(1 << 3);
		return 0;
	}
node4449:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node8258;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node7228:
	b = false;
	if (b) {
		input[3] |= (1 << 7);
		return 0;
	} else {
		input[3] &= ~(1 << 7);
		goto node7807;
	}
node5527:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node3520;
	} else {
		input[3] &= ~(1 << 3);
		goto node7876;
	}
node2199:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node8773;
	} else {
		input[3] &= ~(1 << 3);
		goto node137;
	}
node8985:
	b = true;
	if (b) {
		input[1] |= (1 << 1);
		goto node6543;
	} else {
		input[1] &= ~(1 << 1);
		return 0;
	}
node8737:
	b = true;
	if (b) {
		input[2] |= (1 << 2);
		goto node3285;
	} else {
		input[2] &= ~(1 << 2);
		return 0;
	}
node7010:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node2617;
	} else {
		input[3] &= ~(1 << 7);
		goto node7214;
	}
node71:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node3655;
	} else {
		input[3] &= ~(1 << 6);
		goto node5010;
	}
node4617:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node7766;
	} else {
		input[3] &= ~(1 << 6);
		goto node780;
	}
node5193:
	b = true;
	if (b) {
		input[4] |= (1 << 3);
		goto node1096;
	} else {
		input[4] &= ~(1 << 3);
		return 0;
	}
node7772:
	b = randbool();
	if (b) {
		input[4] |= (1 << 5);
		goto node7775;
	} else {
		input[4] &= ~(1 << 5);
		return 5;
	}
node5043:
	b = false;
	if (b) {
		input[2] |= (1 << 7);
		return 0;
	} else {
		input[2] &= ~(1 << 7);
		goto node511;
	}
node8725:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node8498;
	} else {
		input[2] &= ~(1 << 4);
		return 3;
	}
node7725:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node4715;
	} else {
		input[2] &= ~(1 << 3);
		goto node2314;
	}
node4249:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node2187;
	} else {
		input[2] &= ~(1 << 1);
		goto node6371;
	}
node4780:
	b = randbool();
	if (b) {
		input[2] |= (1 << 0);
		goto node3792;
	} else {
		input[2] &= ~(1 << 0);
		goto node6662;
	}
node6071:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node137;
	} else {
		input[3] &= ~(1 << 2);
		goto node9360;
	}
node5060:
	b = randbool();
	if (b) {
		input[0] |= (1 << 0);
		return 1;
	} else {
		input[0] &= ~(1 << 0);
		return 4;
	}
node6364:
	b = randbool();
	if (b) {
		input[1] |= (1 << 0);
		return 3;
	} else {
		input[1] &= ~(1 << 0);
		goto node5944;
	}
node8127:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node3201;
	}
node6915:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node1314;
	} else {
		input[3] &= ~(1 << 5);
		goto node5510;
	}
node7590:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node2342;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node2537:
	b = false;
	if (b) {
		input[4] |= (1 << 5);
		return 0;
	} else {
		input[4] &= ~(1 << 5);
		goto node6025;
	}
node1571:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node5237;
	} else {
		input[2] &= ~(1 << 6);
		goto node9402;
	}
node7291:
	b = false;
	if (b) {
		input[2] |= (1 << 5);
		return 0;
	} else {
		input[2] &= ~(1 << 5);
		goto node8708;
	}
node6819:
	b = true;
	if (b) {
		input[2] |= (1 << 3);
		goto node6810;
	} else {
		input[2] &= ~(1 << 3);
		return 0;
	}
node2798:
	b = randbool();
	if (b) {
		input[1] |= (1 << 1);
		goto node1730;
	} else {
		input[1] &= ~(1 << 1);
		goto node1330;
	}
node8276:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node6123;
	}
node3672:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node4245;
	}
node4131:
	b = false;
	if (b) {
		input[4] |= (1 << 4);
		return 0;
	} else {
		input[4] &= ~(1 << 4);
		goto node6530;
	}
node6358:
	b = true;
	if (b) {
		input[4] |= (1 << 1);
		goto node5682;
	} else {
		input[4] &= ~(1 << 1);
		return 0;
	}
node4488:
	b = randbool();
	if (b) {
		input[1] |= (1 << 7);
		goto node4588;
	} else {
		input[1] &= ~(1 << 7);
		goto node7050;
	}
node4633:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node8842;
	}
node6596:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node5222;
	} else {
		input[2] &= ~(1 << 2);
		goto node737;
	}
node3520:
	b = randbool();
	if (b) {
		input[4] |= (1 << 7);
		goto node2727;
	} else {
		input[4] &= ~(1 << 7);
		goto node7709;
	}
node714:
	b = randbool();
	if (b) {
		input[4] |= (1 << 1);
		return 7;
	} else {
		input[4] &= ~(1 << 1);
		goto node7741;
	}
node6565:
	b = randbool();
	if (b) {
		input[0] |= (1 << 0);
		goto node1255;
	} else {
		input[0] &= ~(1 << 0);
		goto node4488;
	}
node6473:
	b = false;
	if (b) {
		input[1] |= (1 << 3);
		return 0;
	} else {
		input[1] &= ~(1 << 3);
		goto node8020;
	}
node806:
	b = randbool();
	if (b) {
		input[1] |= (1 << 0);
		goto node2511;
	} else {
		input[1] &= ~(1 << 0);
		goto node5043;
	}
node2390:
	b = false;
	if (b) {
		input[2] |= (1 << 3);
		return 0;
	} else {
		input[2] &= ~(1 << 3);
		goto node7069;
	}
node1086:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node348;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node3898:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node3055;
	} else {
		input[3] &= ~(1 << 2);
		goto node4611;
	}
node3513:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node7097;
	} else {
		input[3] &= ~(1 << 5);
		goto node5814;
	}
node7552:
	b = false;
	if (b) {
		input[4] |= (1 << 7);
		return 0;
	} else {
		input[4] &= ~(1 << 7);
		goto node373;
	}
node6614:
	b = true;
	if (b) {
		input[2] |= (1 << 6);
		goto node4882;
	} else {
		input[2] &= ~(1 << 6);
		return 0;
	}
node6534:
	b = false;
	if (b) {
		input[2] |= (1 << 5);
		return 0;
	} else {
		input[2] &= ~(1 << 5);
		goto node8878;
	}
node5697:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node2849;
	} else {
		input[2] &= ~(1 << 4);
		goto node386;
	}
node3365:
	b = false;
	if (b) {
		input[2] |= (1 << 2);
		return 0;
	} else {
		input[2] &= ~(1 << 2);
		goto node4663;
	}
node3735:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		goto node5345;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node233:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node3427;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node3421:
	b = randbool();
	if (b) {
		input[4] |= (1 << 3);
		goto node7576;
	} else {
		input[4] &= ~(1 << 3);
		goto node7130;
	}
node6759:
	b = true;
	if (b) {
		input[4] |= (1 << 3);
		goto node5477;
	} else {
		input[4] &= ~(1 << 3);
		return 0;
	}
node6747:
	b = false;
	if (b) {
		input[5] |= (1 << 1);
		return 0;
	} else {
		input[5] &= ~(1 << 1);
		goto node4000;
	}
node5139:
	b = false;
	if (b) {
		input[4] |= (1 << 3);
		return 0;
	} else {
		input[4] &= ~(1 << 3);
		goto node3661;
	}
node1038:
	b = false;
	if (b) {
		input[2] |= (1 << 5);
		return 0;
	} else {
		input[2] &= ~(1 << 5);
		goto node9203;
	}
node5040:
	b = true;
	if (b) {
		input[2] |= (1 << 5);
		goto node3403;
	} else {
		input[2] &= ~(1 << 5);
		return 0;
	}
node5508:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node8797;
	} else {
		input[2] &= ~(1 << 4);
		goto node9224;
	}
node4041:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node7040;
	} else {
		input[2] &= ~(1 << 2);
		goto node7981;
	}
node3280:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node8311;
	} else {
		input[3] &= ~(1 << 3);
		goto node7429;
	}
node2735:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node2565;
	} else {
		input[3] &= ~(1 << 2);
		goto node8801;
	}
node4751:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node6213;
	} else {
		input[2] &= ~(1 << 2);
		return 3;
	}
node4087:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node7955;
	} else {
		input[2] &= ~(1 << 1);
		goto node117;
	}
node2826:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node2974;
	} else {
		input[3] &= ~(1 << 6);
		goto node4197;
	}
node8564:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node3815;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node2936:
	b = randbool();
	if (b) {
		input[3] |= (1 << 0);
		goto node2584;
	} else {
		input[3] &= ~(1 << 0);
		goto node6462;
	}
node7164:
	b = false;
	if (b) {
		input[4] |= (1 << 2);
		return 0;
	} else {
		input[4] &= ~(1 << 2);
		goto node5530;
	}
node167:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node105;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node1001:
	b = randbool();
	if (b) {
		input[2] |= (1 << 0);
		goto node3933;
	} else {
		input[2] &= ~(1 << 0);
		goto node8948;
	}
node8793:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node9368;
	} else {
		input[3] &= ~(1 << 6);
		goto node6318;
	}
node7764:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node9282;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node6809:
	b = randbool();
	if (b) {
		input[2] |= (1 << 7);
		goto node1462;
	} else {
		input[2] &= ~(1 << 7);
		goto node5437;
	}
node3425:
	b = false;
	if (b) {
		input[2] |= (1 << 1);
		return 0;
	} else {
		input[2] &= ~(1 << 1);
		goto node1874;
	}
node4192:
	b = true;
	if (b) {
		input[3] |= (1 << 6);
		goto node8341;
	} else {
		input[3] &= ~(1 << 6);
		return 0;
	}
node8963:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node4314;
	}
node7977:
	b = true;
	if (b) {
		input[4] |= (1 << 6);
		goto node1647;
	} else {
		input[4] &= ~(1 << 6);
		return 0;
	}
node9092:
	b = false;
	if (b) {
		input[4] |= (1 << 3);
		return 0;
	} else {
		input[4] &= ~(1 << 3);
		goto node5449;
	}
node5461:
	b = randbool();
	if (b) {
		input[1] |= (1 << 0);
		goto node1676;
	} else {
		input[1] &= ~(1 << 0);
		goto node510;
	}
node1694:
	b = randbool();
	if (b) {
		input[2] |= (1 << 0);
		goto node7887;
	} else {
		input[2] &= ~(1 << 0);
		goto node2897;
	}
node4532:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node7953;
	} else {
		input[3] &= ~(1 << 6);
		goto node5286;
	}
node1165:
	b = randbool();
	if (b) {
		input[4] |= (1 << 6);
		goto node2938;
	} else {
		input[4] &= ~(1 << 6);
		goto node2182;
	}
node3694:
	b = false;
	if (b) {
		input[4] |= (1 << 0);
		return 0;
	} else {
		input[4] &= ~(1 << 0);
		return 6;
	}
node1044:
	b = randbool();
	if (b) {
		input[1] |= (1 << 5);
		goto node3601;
	} else {
		input[1] &= ~(1 << 5);
		goto node4257;
	}
node5974:
	b = randbool();
	if (b) {
		input[2] |= (1 << 7);
		goto node6433;
	} else {
		input[2] &= ~(1 << 7);
		goto node5969;
	}
node4358:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node4553;
	} else {
		input[3] &= ~(1 << 6);
		goto node7634;
	}
node8643:
	b = false;
	if (b) {
		input[1] |= (1 << 3);
		return 0;
	} else {
		input[1] &= ~(1 << 3);
		goto node6305;
	}
node5564:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node137;
	} else {
		input[3] &= ~(1 << 2);
		goto node4735;
	}
node753:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node6371;
	} else {
		input[2] &= ~(1 << 1);
		goto node7226;
	}
node7236:
	b = false;
	if (b) {
		input[3] |= (1 << 7);
		return 0;
	} else {
		input[3] &= ~(1 << 7);
		goto node9157;
	}
node835:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node978;
	} else {
		input[3] &= ~(1 << 6);
		goto node2388;
	}
node1574:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node6889;
	} else {
		input[3] &= ~(1 << 6);
		goto node5941;
	}
node7172:
	b = randbool();
	if (b) {
		input[0] |= (1 << 5);
		goto node265;
	} else {
		input[0] &= ~(1 << 5);
		goto node1035;
	}
node1980:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node8695;
	} else {
		input[2] &= ~(1 << 6);
		goto node3698;
	}
node4804:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node4013;
	} else {
		input[2] &= ~(1 << 2);
		goto node8730;
	}
node2106:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node878;
	} else {
		input[3] &= ~(1 << 7);
		goto node8853;
	}
node4351:
	b = false;
	if (b) {
		input[3] |= (1 << 2);
		return 0;
	} else {
		input[3] &= ~(1 << 2);
		goto node3266;
	}
node8080:
	b = randbool();
	if (b) {
		input[3] |= (1 << 0);
		goto node2395;
	} else {
		input[3] &= ~(1 << 0);
		goto node6220;
	}
node6524:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node777;
	} else {
		input[3] &= ~(1 << 4);
		goto node3130;
	}
node7750:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node469;
	}
node3265:
	b = false;
	if (b) {
		input[3] |= (1 << 2);
		return 0;
	} else {
		input[3] &= ~(1 << 2);
		goto node3055;
	}
node1384:
	b = true;
	if (b) {
		input[5] |= (1 << 0);
		return 8;
	} else {
		input[5] &= ~(1 << 0);
		return 0;
	}
node3102:
	b = false;
	if (b) {
		input[2] |= (1 << 1);
		return 0;
	} else {
		input[2] &= ~(1 << 1);
		goto node6765;
	}
node6576:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node5856;
	}
node4515:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node4314;
	} else {
		input[3] &= ~(1 << 4);
		goto node9070;
	}
node1799:
	b = true;
	if (b) {
		input[3] |= (1 << 2);
		goto node5327;
	} else {
		input[3] &= ~(1 << 2);
		return 0;
	}
node2365:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node5963;
	} else {
		input[3] &= ~(1 << 2);
		goto node6778;
	}
node8874:
	b = false;
	if (b) {
		input[3] |= (1 << 0);
		return 0;
	} else {
		input[3] &= ~(1 << 0);
		goto node6124;
	}
node4078:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node686;
	} else {
		input[3] &= ~(1 << 5);
		goto node9320;
	}
node1015:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node6916;
	} else {
		input[3] &= ~(1 << 5);
		goto node7412;
	}
node2978:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node7632;
	} else {
		input[3] &= ~(1 << 3);
		goto node7411;
	}
node7821:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node5720;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node7867:
	b = true;
	if (b) {
		input[1] |= (1 << 4);
		goto node4251;
	} else {
		input[1] &= ~(1 << 4);
		return 0;
	}
node7719:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node4667;
	} else {
		input[2] &= ~(1 << 5);
		goto node8186;
	}
node1612:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node3856;
	}
node1860:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node8298;
	} else {
		input[3] &= ~(1 << 4);
		goto node490;
	}
node3324:
	b = false;
	if (b) {
		input[3] |= (1 << 2);
		return 0;
	} else {
		input[3] &= ~(1 << 2);
		goto node6297;
	}
node4236:
	b = false;
	if (b) {
		input[4] |= (1 << 5);
		return 0;
	} else {
		input[4] &= ~(1 << 5);
		goto node865;
	}
node496:
	b = randbool();
	if (b) {
		input[1] |= (1 << 2);
		goto node4965;
	} else {
		input[1] &= ~(1 << 2);
		goto node6186;
	}
node1267:
	b = false;
	if (b) {
		input[2] |= (1 << 3);
		return 0;
	} else {
		input[2] &= ~(1 << 3);
		goto node3685;
	}
node5012:
	b = false;
	if (b) {
		input[4] |= (1 << 6);
		return 0;
	} else {
		input[4] &= ~(1 << 6);
		goto node1514;
	}
node9226:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node8356;
	}
node8728:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node357;
	} else {
		input[3] &= ~(1 << 4);
		goto node5375;
	}
node930:
	b = randbool();
	if (b) {
		input[1] |= (1 << 4);
		goto node4594;
	} else {
		input[1] &= ~(1 << 4);
		goto node2932;
	}
node3973:
	b = false;
	if (b) {
		input[1] |= (1 << 3);
		return 0;
	} else {
		input[1] &= ~(1 << 3);
		goto node1559;
	}
node7989:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node4683;
	} else {
		input[2] &= ~(1 << 6);
		goto node7693;
	}
node994:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node5447;
	} else {
		input[3] &= ~(1 << 6);
		goto node3930;
	}
node4769:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node7071;
	} else {
		input[3] &= ~(1 << 6);
		goto node3273;
	}
node5804:
	b = randbool();
	if (b) {
		input[0] |= (1 << 0);
		goto node7363;
	} else {
		input[0] &= ~(1 << 0);
		goto node1943;
	}
node2692:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node4473;
	} else {
		input[2] &= ~(1 << 2);
		goto node8147;
	}
node8826:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node4450;
	} else {
		input[3] &= ~(1 << 4);
		goto node7997;
	}
node9416:
	b = false;
	if (b) {
		input[3] |= (1 << 2);
		return 0;
	} else {
		input[3] &= ~(1 << 2);
		goto node5422;
	}
node2643:
	b = randbool();
	if (b) {
		input[0] |= (1 << 1);
		goto node4678;
	} else {
		input[0] &= ~(1 << 1);
		goto node7966;
	}
node9170:
	b = true;
	if (b) {
		input[2] |= (1 << 5);
		goto node1075;
	} else {
		input[2] &= ~(1 << 5);
		return 0;
	}
node1522:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node8268;
	} else {
		input[3] &= ~(1 << 4);
		goto node334;
	}
node8168:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node6498;
	} else {
		input[3] &= ~(1 << 3);
		goto node7632;
	}
node4047:
	b = true;
	if (b) {
		input[4] |= (1 << 2);
		goto node6198;
	} else {
		input[4] &= ~(1 << 2);
		return 0;
	}
node4859:
	b = randbool();
	if (b) {
		input[1] |= (1 << 3);
		return 2;
	} else {
		input[1] &= ~(1 << 3);
		goto node2574;
	}
node6051:
	b = true;
	if (b) {
		input[2] |= (1 << 3);
		goto node6953;
	} else {
		input[2] &= ~(1 << 3);
		return 0;
	}
node3456:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node2860;
	}
node6717:
	b = false;
	if (b) {
		input[3] |= (1 << 2);
		return 0;
	} else {
		input[3] &= ~(1 << 2);
		goto node3056;
	}
node2396:
	b = false;
	if (b) {
		input[4] |= (1 << 0);
		return 0;
	} else {
		input[4] &= ~(1 << 0);
		goto node5645;
	}
node9348:
	b = randbool();
	if (b) {
		input[0] |= (1 << 0);
		goto node4059;
	} else {
		input[0] &= ~(1 << 0);
		return 2;
	}
node8582:
	b = false;
	if (b) {
		input[2] |= (1 << 6);
		return 0;
	} else {
		input[2] &= ~(1 << 6);
		goto node5874;
	}
node7400:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node6323;
	} else {
		input[2] &= ~(1 << 5);
		goto node6977;
	}
node6838:
	b = false;
	if (b) {
		input[2] |= (1 << 3);
		return 0;
	} else {
		input[2] &= ~(1 << 3);
		goto node9195;
	}
node3468:
	b = true;
	if (b) {
		input[1] |= (1 << 2);
		goto node7378;
	} else {
		input[1] &= ~(1 << 2);
		return 0;
	}
node4883:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node5373;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node1883:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node831;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node154:
	b = true;
	if (b) {
		input[3] |= (1 << 0);
		goto node7430;
	} else {
		input[3] &= ~(1 << 0);
		return 0;
	}
node1698:
	b = randbool();
	if (b) {
		input[4] |= (1 << 6);
		goto node3910;
	} else {
		input[4] &= ~(1 << 6);
		goto node4511;
	}
node3210:
	b = true;
	if (b) {
		input[4] |= (1 << 7);
		goto node8330;
	} else {
		input[4] &= ~(1 << 7);
		return 0;
	}
node1978:
	b = false;
	if (b) {
		input[1] |= (1 << 4);
		return 0;
	} else {
		input[1] &= ~(1 << 4);
		goto node5200;
	}
node5577:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node2056;
	} else {
		input[2] &= ~(1 << 5);
		goto node4910;
	}
node8187:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node8862;
	} else {
		input[2] &= ~(1 << 2);
		goto node5033;
	}
node7238:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node4434;
	} else {
		input[2] &= ~(1 << 2);
		goto node9395;
	}
node4944:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node7674;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node8239:
	b = true;
	if (b) {
		input[3] |= (1 << 7);
		goto node8672;
	} else {
		input[3] &= ~(1 << 7);
		return 0;
	}
node4775:
	b = false;
	if (b) {
		input[3] |= (1 << 0);
		return 0;
	} else {
		input[3] &= ~(1 << 0);
		goto node8605;
	}
node7957:
	b = false;
	if (b) {
		input[1] |= (1 << 4);
		return 0;
	} else {
		input[1] &= ~(1 << 4);
		goto node2587;
	}
node4257:
	b = randbool();
	if (b) {
		input[1] |= (1 << 4);
		goto node7086;
	} else {
		input[1] &= ~(1 << 4);
		goto node6771;
	}
node980:
	b = true;
	if (b) {
		input[1] |= (1 << 3);
		goto node8486;
	} else {
		input[1] &= ~(1 << 3);
		return 0;
	}
node1721:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node6051;
	}
node7225:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node9250;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node8282:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node372;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node8713:
	b = randbool();
	if (b) {
		input[4] |= (1 << 1);
		return 6;
	} else {
		input[4] &= ~(1 << 1);
		goto node675;
	}
node2266:
	b = randbool();
	if (b) {
		input[1] |= (1 << 7);
		goto node550;
	} else {
		input[1] &= ~(1 << 7);
		goto node4333;
	}
node5524:
	b = false;
	if (b) {
		input[2] |= (1 << 5);
		return 0;
	} else {
		input[2] &= ~(1 << 5);
		goto node3021;
	}
node488:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node5787;
	} else {
		input[2] &= ~(1 << 1);
		goto node6553;
	}
node5482:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node3952;
	}
node1902:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node5590;
	}
node5059:
	b = true;
	if (b) {
		input[4] |= (1 << 6);
		goto node2759;
	} else {
		input[4] &= ~(1 << 6);
		return 0;
	}
node514:
	b = true;
	if (b) {
		input[1] |= (1 << 1);
		goto node716;
	} else {
		input[1] &= ~(1 << 1);
		return 0;
	}
node7044:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node7887;
	} else {
		input[2] &= ~(1 << 1);
		goto node6428;
	}
node813:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node9421;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node7522:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node7318;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node8600:
	b = false;
	if (b) {
		input[3] |= (1 << 0);
		return 0;
	} else {
		input[3] &= ~(1 << 0);
		goto node9235;
	}
node239:
	b = true;
	if (b) {
		input[4] |= (1 << 1);
		goto node6326;
	} else {
		input[4] &= ~(1 << 1);
		return 0;
	}
node5403:
	b = true;
	if (b) {
		input[2] |= (1 << 3);
		goto node3912;
	} else {
		input[2] &= ~(1 << 3);
		return 0;
	}
node6430:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node8142;
	}
node5622:
	b = false;
	if (b) {
		input[3] |= (1 << 2);
		return 0;
	} else {
		input[3] &= ~(1 << 2);
		goto node6950;
	}
node4308:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node6949;
	} else {
		input[3] &= ~(1 << 2);
		goto node7551;
	}
node7322:
	b = randbool();
	if (b) {
		input[1] |= (1 << 7);
		goto node9322;
	} else {
		input[1] &= ~(1 << 7);
		goto node2586;
	}
node9178:
	b = randbool();
	if (b) {
		input[2] |= (1 << 7);
		goto node9324;
	} else {
		input[2] &= ~(1 << 7);
		goto node8119;
	}
node5128:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node7260;
	} else {
		input[2] &= ~(1 << 6);
		goto node4003;
	}
node2056:
	b = true;
	if (b) {
		input[2] |= (1 << 4);
		goto node5077;
	} else {
		input[2] &= ~(1 << 4);
		return 0;
	}
node9043:
	b = false;
	if (b) {
		input[3] |= (1 << 2);
		return 0;
	} else {
		input[3] &= ~(1 << 2);
		goto node6037;
	}
node1533:
	b = randbool();
	if (b) {
		input[4] |= (1 << 4);
		goto node6858;
	} else {
		input[4] &= ~(1 << 4);
		goto node7994;
	}
node5304:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node1251;
	} else {
		input[3] &= ~(1 << 5);
		goto node2316;
	}
node1745:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node6708;
	} else {
		input[3] &= ~(1 << 4);
		goto node7590;
	}
node7389:
	b = randbool();
	if (b) {
		input[0] |= (1 << 1);
		goto node3943;
	} else {
		input[0] &= ~(1 << 1);
		goto node6067;
	}
node2424:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node8796;
	}
node8592:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node6537;
	} else {
		input[2] &= ~(1 << 1);
		goto node1256;
	}
node5546:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node6126;
	} else {
		input[3] &= ~(1 << 7);
		goto node7881;
	}
node1411:
	b = false;
	if (b) {
		input[3] |= (1 << 6);
		return 0;
	} else {
		input[3] &= ~(1 << 6);
		goto node3676;
	}
node7418:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node7766;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node4712:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node530;
	} else {
		input[3] &= ~(1 << 2);
		goto node137;
	}
node742:
	b = true;
	if (b) {
		input[4] |= (1 << 2);
		goto node7559;
	} else {
		input[4] &= ~(1 << 2);
		return 0;
	}
node5478:
	b = randbool();
	if (b) {
		input[1] |= (1 << 2);
		goto node5929;
	} else {
		input[1] &= ~(1 << 2);
		goto node9201;
	}
node9190:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node2428;
	}
node862:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		goto node5262;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node2341:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node2497;
	}
node8205:
	b = randbool();
	if (b) {
		input[3] |= (1 << 1);
		goto node8732;
	} else {
		input[3] &= ~(1 << 1);
		goto node5492;
	}
node2509:
	b = randbool();
	if (b) {
		input[4] |= (1 << 2);
		goto node8381;
	} else {
		input[4] &= ~(1 << 2);
		return 7;
	}
node4092:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node20;
	} else {
		input[3] &= ~(1 << 7);
		goto node300;
	}
node444:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node1410;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node3041:
	b = randbool();
	if (b) {
		input[1] |= (1 << 0);
		goto node5056;
	} else {
		input[1] &= ~(1 << 0);
		goto node3095;
	}
node5256:
	b = false;
	if (b) {
		input[2] |= (1 << 7);
		return 0;
	} else {
		input[2] &= ~(1 << 7);
		goto node3866;
	}
node812:
	b = randbool();
	if (b) {
		input[2] |= (1 << 7);
		goto node4422;
	} else {
		input[2] &= ~(1 << 7);
		goto node1881;
	}
node171:
	b = false;
	if (b) {
		input[2] |= (1 << 5);
		return 0;
	} else {
		input[2] &= ~(1 << 5);
		goto node707;
	}
node556:
	b = true;
	if (b) {
		input[2] |= (1 << 3);
		goto node4882;
	} else {
		input[2] &= ~(1 << 3);
		return 0;
	}
node6683:
	b = false;
	if (b) {
		input[2] |= (1 << 1);
		return 0;
	} else {
		input[2] &= ~(1 << 1);
		goto node117;
	}
node7993:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node137;
	} else {
		input[3] &= ~(1 << 3);
		goto node3818;
	}
node3189:
	b = randbool();
	if (b) {
		input[1] |= (1 << 2);
		goto node1621;
	} else {
		input[1] &= ~(1 << 2);
		goto node6696;
	}
node13:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node9219;
	} else {
		input[2] &= ~(1 << 2);
		goto node488;
	}
node9148:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node8134;
	}
node5339:
	b = true;
	if (b) {
		input[3] |= (1 << 0);
		goto node7184;
	} else {
		input[3] &= ~(1 << 0);
		return 0;
	}
node6003:
	b = false;
	if (b) {
		input[3] |= (1 << 7);
		return 0;
	} else {
		input[3] &= ~(1 << 7);
		goto node2457;
	}
node7909:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node8903;
	} else {
		input[3] &= ~(1 << 7);
		goto node8404;
	}
node6668:
	b = true;
	if (b) {
		input[4] |= (1 << 7);
		goto node419;
	} else {
		input[4] &= ~(1 << 7);
		return 0;
	}
node6274:
	b = randbool();
	if (b) {
		input[1] |= (1 << 4);
		goto node727;
	} else {
		input[1] &= ~(1 << 4);
		goto node6249;
	}
node1606:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node3815;
	} else {
		input[3] &= ~(1 << 5);
		goto node5110;
	}
node1977:
	b = true;
	if (b) {
		input[3] |= (1 << 2);
		goto node2797;
	} else {
		input[3] &= ~(1 << 2);
		return 0;
	}
node3809:
	b = false;
	if (b) {
		input[4] |= (1 << 3);
		return 0;
	} else {
		input[4] &= ~(1 << 3);
		goto node302;
	}
node6960:
	b = true;
	if (b) {
		input[5] |= (1 << 2);
		goto node4200;
	} else {
		input[5] &= ~(1 << 2);
		return 0;
	}
node7745:
	b = false;
	if (b) {
		input[1] |= (1 << 3);
		return 0;
	} else {
		input[1] &= ~(1 << 3);
		goto node7534;
	}
node8644:
	b = true;
	if (b) {
		input[2] |= (1 << 4);
		goto node8700;
	} else {
		input[2] &= ~(1 << 4);
		return 0;
	}
node1804:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node3025;
	}
node7498:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		goto node6743;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node7311:
	b = false;
	if (b) {
		input[2] |= (1 << 1);
		return 0;
	} else {
		input[2] &= ~(1 << 1);
		goto node851;
	}
node8076:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node6656;
	} else {
		input[3] &= ~(1 << 7);
		goto node6259;
	}
node7327:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node5492;
	} else {
		input[3] &= ~(1 << 2);
		goto node3541;
	}
node1117:
	b = randbool();
	if (b) {
		input[0] |= (1 << 1);
		return 1;
	} else {
		input[0] &= ~(1 << 1);
		goto node5108;
	}
node8010:
	b = false;
	if (b) {
		input[1] |= (1 << 1);
		return 0;
	} else {
		input[1] &= ~(1 << 1);
		goto node1601;
	}
node429:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node2528;
	}
node7748:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node681;
	} else {
		input[3] &= ~(1 << 6);
		goto node6444;
	}
node3606:
	b = true;
	if (b) {
		input[3] |= (1 << 6);
		goto node2906;
	} else {
		input[3] &= ~(1 << 6);
		return 0;
	}
node700:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node9194;
	} else {
		input[3] &= ~(1 << 4);
		goto node7429;
	}
node5792:
	b = randbool();
	if (b) {
		input[2] |= (1 << 0);
		goto node6405;
	} else {
		input[2] &= ~(1 << 0);
		goto node6674;
	}
node5785:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node7573;
	} else {
		input[3] &= ~(1 << 5);
		goto node6723;
	}
node6762:
	b = true;
	if (b) {
		input[3] |= (1 << 1);
		goto node3053;
	} else {
		input[3] &= ~(1 << 1);
		return 0;
	}
node3229:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node4995;
	} else {
		input[3] &= ~(1 << 4);
		goto node892;
	}
node8363:
	b = false;
	if (b) {
		input[2] |= (1 << 7);
		return 0;
	} else {
		input[2] &= ~(1 << 7);
		goto node1005;
	}
node3748:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node7854;
	} else {
		input[2] &= ~(1 << 4);
		goto node7095;
	}
node5052:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node746;
	} else {
		input[2] &= ~(1 << 4);
		goto node8737;
	}
node365:
	b = false;
	if (b) {
		input[2] |= (1 << 1);
		return 0;
	} else {
		input[2] &= ~(1 << 1);
		return 3;
	}
node4705:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node230;
	} else {
		input[3] &= ~(1 << 5);
		goto node2745;
	}
node316:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node319;
	} else {
		input[3] &= ~(1 << 3);
		goto node2995;
	}
node4880:
	b = false;
	if (b) {
		input[1] |= (1 << 4);
		return 0;
	} else {
		input[1] &= ~(1 << 4);
		goto node9165;
	}
node8051:
	b = randbool();
	if (b) {
		input[2] |= (1 << 0);
		goto node62;
	} else {
		input[2] &= ~(1 << 0);
		goto node6737;
	}
node2625:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node4206;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node4635:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node6873;
	} else {
		input[3] &= ~(1 << 6);
		goto node8748;
	}
node2926:
	b = false;
	if (b) {
		input[1] |= (1 << 2);
		return 0;
	} else {
		input[1] &= ~(1 << 2);
		goto node4432;
	}
node1051:
	b = false;
	if (b) {
		input[2] |= (1 << 1);
		return 0;
	} else {
		input[2] &= ~(1 << 1);
		goto node4176;
	}
node6879:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node1797;
	} else {
		input[2] &= ~(1 << 1);
		goto node6371;
	}
node9184:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node4538;
	} else {
		input[3] &= ~(1 << 6);
		goto node572;
	}
node5495:
	b = true;
	if (b) {
		input[4] |= (1 << 7);
		goto node4312;
	} else {
		input[4] &= ~(1 << 7);
		return 0;
	}
node4427:
	b = randbool();
	if (b) {
		input[2] |= (1 << 7);
		goto node2255;
	} else {
		input[2] &= ~(1 << 7);
		goto node4061;
	}
node8428:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node3680;
	}
node5718:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node507;
	} else {
		input[3] &= ~(1 << 7);
		goto node4769;
	}
node3553:
	b = randbool();
	if (b) {
		input[4] |= (1 << 4);
		goto node875;
	} else {
		input[4] &= ~(1 << 4);
		goto node7114;
	}
node9316:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node8580;
	} else {
		input[3] &= ~(1 << 3);
		goto node80;
	}
node5064:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node4316;
	} else {
		input[3] &= ~(1 << 2);
		goto node3157;
	}
node4719:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node6080;
	} else {
		input[2] &= ~(1 << 3);
		goto node7292;
	}
node772:
	b = true;
	if (b) {
		input[3] |= (1 << 0);
		goto node871;
	} else {
		input[3] &= ~(1 << 0);
		return 0;
	}
node5299:
	b = false;
	if (b) {
		input[4] |= (1 << 4);
		return 0;
	} else {
		input[4] &= ~(1 << 4);
		goto node2787;
	}
node2471:
	b = false;
	if (b) {
		input[4] |= (1 << 3);
		return 0;
	} else {
		input[4] &= ~(1 << 3);
		goto node3990;
	}
node7627:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node3318;
	} else {
		input[3] &= ~(1 << 5);
		goto node2292;
	}
node2618:
	b = false;
	if (b) {
		input[1] |= (1 << 3);
		return 0;
	} else {
		input[1] &= ~(1 << 3);
		goto node8802;
	}
node195:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node405;
	} else {
		input[2] &= ~(1 << 5);
		goto node8376;
	}
node8145:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node505;
	} else {
		input[2] &= ~(1 << 5);
		goto node689;
	}
node1065:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node4447;
	}
node739:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node8746;
	} else {
		input[3] &= ~(1 << 7);
		goto node6023;
	}
node2626:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node5688;
	} else {
		input[3] &= ~(1 << 6);
		goto node1598;
	}
node922:
	b = randbool();
	if (b) {
		input[2] |= (1 << 7);
		goto node4276;
	} else {
		input[2] &= ~(1 << 7);
		goto node5165;
	}
node4345:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node2482;
	} else {
		input[2] &= ~(1 << 6);
		goto node1369;
	}
node4929:
	b = false;
	if (b) {
		input[2] |= (1 << 3);
		return 0;
	} else {
		input[2] &= ~(1 << 3);
		goto node1151;
	}
node2264:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node6546;
	} else {
		input[3] &= ~(1 << 2);
		goto node1524;
	}
node6489:
	b = false;
	if (b) {
		input[2] |= (1 << 7);
		return 0;
	} else {
		input[2] &= ~(1 << 7);
		goto node3654;
	}
node4589:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node5359;
	} else {
		input[2] &= ~(1 << 5);
		goto node8272;
	}
node3424:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node2313;
	} else {
		input[2] &= ~(1 << 4);
		goto node6788;
	}
node3439:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		goto node3611;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node3590:
	b = true;
	if (b) {
		input[3] |= (1 << 0);
		goto node3210;
	} else {
		input[3] &= ~(1 << 0);
		return 0;
	}
node2565:
	b = true;
	if (b) {
		input[3] |= (1 << 1);
		goto node3651;
	} else {
		input[3] &= ~(1 << 1);
		return 0;
	}
node1897:
	b = false;
	if (b) {
		input[4] |= (1 << 1);
		return 0;
	} else {
		input[4] &= ~(1 << 1);
		goto node8083;
	}
node2018:
	b = randbool();
	if (b) {
		input[1] |= (1 << 6);
		goto node1103;
	} else {
		input[1] &= ~(1 << 6);
		goto node5284;
	}
node8959:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node5137;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node8309:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node4701;
	} else {
		input[3] &= ~(1 << 6);
		goto node9375;
	}
node8310:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node7241;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node4042:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node6203;
	} else {
		input[3] &= ~(1 << 5);
		goto node7879;
	}
node2260:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node4628;
	} else {
		input[3] &= ~(1 << 5);
		goto node7391;
	}
node8032:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node7528;
	} else {
		input[2] &= ~(1 << 3);
		goto node2616;
	}
node5887:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node6226;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node3786:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node7438;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node3873:
	b = true;
	if (b) {
		input[4] |= (1 << 7);
		goto node4256;
	} else {
		input[4] &= ~(1 << 7);
		return 0;
	}
node1747:
	b = randbool();
	if (b) {
		input[4] |= (1 << 5);
		goto node4816;
	} else {
		input[4] &= ~(1 << 5);
		goto node4698;
	}
node3964:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node7887;
	} else {
		input[2] &= ~(1 << 1);
		goto node1556;
	}
node8843:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node1344;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node1218:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node3776;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node187:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node2365;
	}
node8997:
	b = randbool();
	if (b) {
		input[4] |= (1 << 5);
		goto node6564;
	} else {
		input[4] &= ~(1 << 5);
		goto node6618;
	}
node4013:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		goto node8959;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node8052:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node6181;
	} else {
		input[3] &= ~(1 << 6);
		goto node7176;
	}
node7218:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node8658;
	}
node4695:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node3968;
	} else {
		input[2] &= ~(1 << 4);
		goto node6089;
	}
node6403:
	b = false;
	if (b) {
		input[2] |= (1 << 3);
		return 0;
	} else {
		input[2] &= ~(1 << 3);
		goto node1003;
	}
node2749:
	b = true;
	if (b) {
		input[3] |= (1 << 6);
		goto node9031;
	} else {
		input[3] &= ~(1 << 6);
		return 0;
	}
node8252:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node7726;
	} else {
		input[3] &= ~(1 << 5);
		goto node3588;
	}
node5978:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node2662;
	} else {
		input[3] &= ~(1 << 4);
		goto node3733;
	}
node6680:
	b = false;
	if (b) {
		input[1] |= (1 << 7);
		return 0;
	} else {
		input[1] &= ~(1 << 7);
		goto node7548;
	}
node281:
	b = false;
	if (b) {
		input[1] |= (1 << 3);
		return 0;
	} else {
		input[1] &= ~(1 << 3);
		goto node8152;
	}
node4370:
	b = true;
	if (b) {
		input[2] |= (1 << 3);
		goto node166;
	} else {
		input[2] &= ~(1 << 3);
		return 0;
	}
node2630:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node997;
	}
node6329:
	b = true;
	if (b) {
		input[4] |= (1 << 4);
		goto node1515;
	} else {
		input[4] &= ~(1 << 4);
		return 0;
	}
node2262:
	b = false;
	if (b) {
		input[1] |= (1 << 5);
		return 0;
	} else {
		input[1] &= ~(1 << 5);
		goto node7635;
	}
node2806:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node5661;
	} else {
		input[3] &= ~(1 << 7);
		goto node4595;
	}
node604:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node1222;
	} else {
		input[3] &= ~(1 << 6);
		goto node3338;
	}
node567:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node5240;
	} else {
		input[3] &= ~(1 << 5);
		goto node7435;
	}
node7134:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node4819;
	}
node5502:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node1152;
	} else {
		input[3] &= ~(1 << 2);
		goto node5422;
	}
node8731:
	b = false;
	if (b) {
		input[3] |= (1 << 6);
		return 0;
	} else {
		input[3] &= ~(1 << 6);
		goto node6085;
	}
node5585:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node2910;
	}
node7652:
	b = randbool();
	if (b) {
		input[1] |= (1 << 5);
		return 2;
	} else {
		input[1] &= ~(1 << 5);
		goto node5288;
	}
node7307:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node1845;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node2498:
	b = true;
	if (b) {
		input[3] |= (1 << 1);
		goto node3034;
	} else {
		input[3] &= ~(1 << 1);
		return 0;
	}
node4393:
	b = false;
	if (b) {
		input[4] |= (1 << 5);
		return 0;
	} else {
		input[4] &= ~(1 << 5);
		goto node597;
	}
node8015:
	b = false;
	if (b) {
		input[2] |= (1 << 7);
		return 0;
	} else {
		input[2] &= ~(1 << 7);
		goto node7939;
	}
node450:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		return 7;
	} else {
		input[2] &= ~(1 << 2);
		goto node6919;
	}
node1667:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node9166;
	} else {
		input[3] &= ~(1 << 7);
		goto node8112;
	}
node1163:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node1914;
	} else {
		input[3] &= ~(1 << 5);
		goto node5014;
	}
node7943:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node3433;
	} else {
		input[3] &= ~(1 << 5);
		goto node2408;
	}
node559:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node538;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node2955:
	b = false;
	if (b) {
		input[2] |= (1 << 0);
		return 0;
	} else {
		input[2] &= ~(1 << 0);
		goto node3343;
	}
node1190:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node1933;
	}
node2430:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node3121;
	} else {
		input[3] &= ~(1 << 3);
		goto node3755;
	}
node8458:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node7599;
	}
node5483:
	b = false;
	if (b) {
		input[3] |= (1 << 2);
		return 0;
	} else {
		input[3] &= ~(1 << 2);
		goto node7112;
	}
node5163:
	b = false;
	if (b) {
		input[4] |= (1 << 4);
		return 0;
	} else {
		input[4] &= ~(1 << 4);
		goto node17;
	}
node3689:
	b = randbool();
	if (b) {
		input[1] |= (1 << 0);
		goto node156;
	} else {
		input[1] &= ~(1 << 0);
		goto node734;
	}
node5459:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node1772;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node7129:
	b = false;
	if (b) {
		input[4] |= (1 << 5);
		return 0;
	} else {
		input[4] &= ~(1 << 5);
		goto node1291;
	}
node2706:
	b = true;
	if (b) {
		input[2] |= (1 << 7);
		goto node4038;
	} else {
		input[2] &= ~(1 << 7);
		return 0;
	}
node3703:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node3373;
	} else {
		input[2] &= ~(1 << 5);
		goto node7285;
	}
node2009:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node3354;
	} else {
		input[2] &= ~(1 << 1);
		goto node7578;
	}
node1681:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node6635;
	} else {
		input[3] &= ~(1 << 5);
		goto node1353;
	}
node625:
	b = randbool();
	if (b) {
		input[1] |= (1 << 4);
		goto node1650;
	} else {
		input[1] &= ~(1 << 4);
		goto node5486;
	}
node6015:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node1858;
	} else {
		input[2] &= ~(1 << 5);
		goto node6323;
	}
node7369:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node7306;
	} else {
		input[2] &= ~(1 << 1);
		goto node6176;
	}
node699:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node6477;
	} else {
		input[3] &= ~(1 << 5);
		goto node8400;
	}
node632:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node7366;
	} else {
		input[3] &= ~(1 << 4);
		goto node269;
	}
node2835:
	b = false;
	if (b) {
		input[4] |= (1 << 2);
		return 0;
	} else {
		input[4] &= ~(1 << 2);
		goto node7321;
	}
node8774:
	b = randbool();
	if (b) {
		input[1] |= (1 << 4);
		goto node1350;
	} else {
		input[1] &= ~(1 << 4);
		goto node8802;
	}
node4985:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node3128;
	} else {
		input[2] &= ~(1 << 4);
		goto node7636;
	}
node2320:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node7632;
	} else {
		input[3] &= ~(1 << 3);
		goto node1169;
	}
node3904:
	b = randbool();
	if (b) {
		input[1] |= (1 << 0);
		goto node3402;
	} else {
		input[1] &= ~(1 << 0);
		goto node194;
	}
node7458:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node6340;
	} else {
		input[2] &= ~(1 << 6);
		goto node4991;
	}
node6243:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		goto node4250;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node2528:
	b = true;
	if (b) {
		input[2] |= (1 << 3);
		goto node5328;
	} else {
		input[2] &= ~(1 << 3);
		return 0;
	}
node2329:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node780;
	} else {
		input[3] &= ~(1 << 5);
		goto node4324;
	}
node2197:
	b = true;
	if (b) {
		input[4] |= (1 << 3);
		goto node1432;
	} else {
		input[4] &= ~(1 << 3);
		return 0;
	}
node324:
	b = randbool();
	if (b) {
		input[3] |= (1 << 0);
		goto node7632;
	} else {
		input[3] &= ~(1 << 0);
		goto node9011;
	}
node9198:
	b = false;
	if (b) {
		input[1] |= (1 << 3);
		return 0;
	} else {
		input[1] &= ~(1 << 3);
		goto node1265;
	}
node7901:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		return 3;
	} else {
		input[2] &= ~(1 << 5);
		goto node9046;
	}
node9215:
	b = false;
	if (b) {
		input[2] |= (1 << 3);
		return 0;
	} else {
		input[2] &= ~(1 << 3);
		goto node881;
	}
node5532:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		goto node5788;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node4562:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node2687;
	} else {
		input[3] &= ~(1 << 5);
		goto node3393;
	}
node1262:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node3618;
	} else {
		input[3] &= ~(1 << 4);
		goto node3600;
	}
node8260:
	b = randbool();
	if (b) {
		input[1] |= (1 << 5);
		goto node1930;
	} else {
		input[1] &= ~(1 << 5);
		goto node4033;
	}
node664:
	b = true;
	if (b) {
		input[4] |= (1 << 5);
		goto node990;
	} else {
		input[4] &= ~(1 << 5);
		return 0;
	}
node7108:
	b = randbool();
	if (b) {
		input[2] |= (1 << 0);
		goto node2246;
	} else {
		input[2] &= ~(1 << 0);
		goto node3981;
	}
node6398:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node8703;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node2554:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node199;
	} else {
		input[3] &= ~(1 << 6);
		goto node7237;
	}
node1243:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node6054;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node5778:
	b = false;
	if (b) {
		input[3] |= (1 << 2);
		return 0;
	} else {
		input[3] &= ~(1 << 2);
		goto node1994;
	}
node3034:
	b = false;
	if (b) {
		input[3] |= (1 << 0);
		return 0;
	} else {
		input[3] &= ~(1 << 0);
		goto node5131;
	}
node592:
	b = false;
	if (b) {
		input[1] |= (1 << 2);
		return 0;
	} else {
		input[1] &= ~(1 << 2);
		goto node7277;
	}
node526:
	b = randbool();
	if (b) {
		input[1] |= (1 << 1);
		goto node2363;
	} else {
		input[1] &= ~(1 << 1);
		goto node837;
	}
node6878:
	b = false;
	if (b) {
		input[2] |= (1 << 2);
		return 0;
	} else {
		input[2] &= ~(1 << 2);
		goto node4626;
	}
node4373:
	b = false;
	if (b) {
		input[2] |= (1 << 0);
		return 0;
	} else {
		input[2] &= ~(1 << 0);
		goto node8207;
	}
node5157:
	b = false;
	if (b) {
		input[3] |= (1 << 1);
		return 0;
	} else {
		input[3] &= ~(1 << 1);
		goto node3371;
	}
node232:
	b = false;
	if (b) {
		input[2] |= (1 << 5);
		return 0;
	} else {
		input[2] &= ~(1 << 5);
		goto node6584;
	}
node7654:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node1226;
	} else {
		input[2] &= ~(1 << 4);
		goto node3307;
	}
node3245:
	b = true;
	if (b) {
		input[4] |= (1 << 3);
		goto node6400;
	} else {
		input[4] &= ~(1 << 3);
		return 0;
	}
node5745:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node6987;
	} else {
		input[3] &= ~(1 << 4);
		goto node892;
	}
node1110:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node137;
	} else {
		input[3] &= ~(1 << 3);
		goto node7308;
	}
node999:
	b = randbool();
	if (b) {
		input[1] |= (1 << 5);
		goto node5097;
	} else {
		input[1] &= ~(1 << 5);
		goto node8991;
	}
node6374:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node1882;
	} else {
		input[2] &= ~(1 << 3);
		goto node620;
	}
node7360:
	b = false;
	if (b) {
		input[2] |= (1 << 1);
		return 0;
	} else {
		input[2] &= ~(1 << 1);
		goto node2465;
	}
node5068:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node4171;
	} else {
		input[3] &= ~(1 << 7);
		goto node7556;
	}
node3320:
	b = true;
	if (b) {
		input[3] |= (1 << 6);
		goto node7814;
	} else {
		input[3] &= ~(1 << 6);
		return 0;
	}
node6539:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node58;
	}
node6771:
	b = false;
	if (b) {
		input[1] |= (1 << 3);
		return 0;
	} else {
		input[1] &= ~(1 << 3);
		goto node7086;
	}
node2125:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node8031;
	} else {
		input[2] &= ~(1 << 4);
		goto node8408;
	}
node6920:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node9031;
	} else {
		input[3] &= ~(1 << 6);
		goto node4331;
	}
node2278:
	b = false;
	if (b) {
		input[4] |= (1 << 5);
		return 0;
	} else {
		input[4] &= ~(1 << 5);
		goto node6542;
	}
node7582:
	b = randbool();
	if (b) {
		input[3] |= (1 << 0);
		goto node2395;
	} else {
		input[3] &= ~(1 << 0);
		goto node2584;
	}
node804:
	b = randbool();
	if (b) {
		input[4] |= (1 << 5);
		goto node4839;
	} else {
		input[4] &= ~(1 << 5);
		goto node7392;
	}
node4168:
	b = false;
	if (b) {
		input[3] |= (1 << 0);
		return 0;
	} else {
		input[3] &= ~(1 << 0);
		goto node7392;
	}
node6601:
	b = false;
	if (b) {
		input[2] |= (1 << 6);
		return 0;
	} else {
		input[2] &= ~(1 << 6);
		goto node9418;
	}
node975:
	b = false;
	if (b) {
		input[2] |= (1 << 5);
		return 0;
	} else {
		input[2] &= ~(1 << 5);
		goto node7158;
	}
node291:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node1987;
	} else {
		input[3] &= ~(1 << 7);
		goto node5465;
	}
node2304:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node2162;
	} else {
		input[3] &= ~(1 << 6);
		goto node699;
	}
node5837:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node8122;
	}
node2288:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node6462;
	} else {
		input[3] &= ~(1 << 3);
		goto node5815;
	}
node1661:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node2870;
	} else {
		input[3] &= ~(1 << 7);
		goto node8684;
	}
node3459:
	b = true;
	if (b) {
		input[4] |= (1 << 5);
		goto node8178;
	} else {
		input[4] &= ~(1 << 5);
		return 0;
	}
node238:
	b = false;
	if (b) {
		input[4] |= (1 << 3);
		return 0;
	} else {
		input[4] &= ~(1 << 3);
		goto node6602;
	}
node4282:
	b = randbool();
	if (b) {
		input[1] |= (1 << 0);
		goto node8015;
	} else {
		input[1] &= ~(1 << 0);
		goto node3067;
	}
node213:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node5559;
	} else {
		input[3] &= ~(1 << 4);
		goto node5846;
	}
node3309:
	b = false;
	if (b) {
		input[2] |= (1 << 0);
		return 0;
	} else {
		input[2] &= ~(1 << 0);
		goto node4387;
	}
node6803:
	b = true;
	if (b) {
		input[3] |= (1 << 6);
		goto node1608;
	} else {
		input[3] &= ~(1 << 6);
		return 0;
	}
node2013:
	b = false;
	if (b) {
		input[3] |= (1 << 2);
		return 0;
	} else {
		input[3] &= ~(1 << 2);
		goto node5945;
	}
node3569:
	b = false;
	if (b) {
		input[3] |= (1 << 1);
		return 0;
	} else {
		input[3] &= ~(1 << 1);
		goto node9241;
	}
node5512:
	b = true;
	if (b) {
		input[4] |= (1 << 6);
		goto node2537;
	} else {
		input[4] &= ~(1 << 6);
		return 0;
	}
node3422:
	b = true;
	if (b) {
		input[5] |= (1 << 3);
		goto node3239;
	} else {
		input[5] &= ~(1 << 3);
		return 0;
	}
node5218:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		return 3;
	} else {
		input[2] &= ~(1 << 5);
		goto node9305;
	}
node6097:
	b = true;
	if (b) {
		input[2] |= (1 << 2);
		goto node877;
	} else {
		input[2] &= ~(1 << 2);
		return 0;
	}
node755:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node2628;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node6679:
	b = randbool();
	if (b) {
		input[4] |= (1 << 7);
		goto node6934;
	} else {
		input[4] &= ~(1 << 7);
		goto node6824;
	}
node834:
	b = false;
	if (b) {
		input[2] |= (1 << 7);
		return 0;
	} else {
		input[2] &= ~(1 << 7);
		goto node735;
	}
node7179:
	b = false;
	if (b) {
		input[2] |= (1 << 7);
		return 0;
	} else {
		input[2] &= ~(1 << 7);
		goto node2240;
	}
node7587:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node3404;
	} else {
		input[2] &= ~(1 << 2);
		goto node9000;
	}
node4570:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node6630;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node4261:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node8211;
	} else {
		input[2] &= ~(1 << 5);
		goto node3548;
	}
node4113:
	b = true;
	if (b) {
		input[2] |= (1 << 3);
		goto node2548;
	} else {
		input[2] &= ~(1 << 3);
		return 0;
	}
node3350:
	b = true;
	if (b) {
		input[2] |= (1 << 2);
		goto node2044;
	} else {
		input[2] &= ~(1 << 2);
		return 0;
	}
node7643:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node6553;
	} else {
		input[2] &= ~(1 << 2);
		goto node5468;
	}
node5816:
	b = true;
	if (b) {
		input[3] |= (1 << 0);
		goto node3238;
	} else {
		input[3] &= ~(1 << 0);
		return 0;
	}
node2415:
	b = false;
	if (b) {
		input[4] |= (1 << 1);
		return 0;
	} else {
		input[4] &= ~(1 << 1);
		goto node6973;
	}
node5782:
	b = false;
	if (b) {
		input[2] |= (1 << 5);
		return 0;
	} else {
		input[2] &= ~(1 << 5);
		goto node9191;
	}
node847:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node6553;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node9281:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node2292;
	} else {
		input[3] &= ~(1 << 6);
		goto node8548;
	}
node2185:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node6649;
	} else {
		input[3] &= ~(1 << 3);
		goto node6006;
	}
node538:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node359;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node1590:
	b = false;
	if (b) {
		input[3] |= (1 << 2);
		return 0;
	} else {
		input[3] &= ~(1 << 2);
		goto node1445;
	}
node6306:
	b = randbool();
	if (b) {
		input[1] |= (1 << 0);
		goto node3525;
	} else {
		input[1] &= ~(1 << 0);
		goto node5031;
	}
node4825:
	b = false;
	if (b) {
		input[2] |= (1 << 2);
		return 0;
	} else {
		input[2] &= ~(1 << 2);
		goto node8592;
	}
node218:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node6419;
	}
node2152:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node4145;
	} else {
		input[3] &= ~(1 << 4);
		goto node7766;
	}
node4572:
	b = randbool();
	if (b) {
		input[4] |= (1 << 6);
		goto node6443;
	} else {
		input[4] &= ~(1 << 6);
		goto node1668;
	}
node6891:
	b = true;
	if (b) {
		input[4] |= (1 << 2);
		goto node5991;
	} else {
		input[4] &= ~(1 << 2);
		return 0;
	}
node6183:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node4748;
	}
node5799:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node7488;
	} else {
		input[3] &= ~(1 << 4);
		goto node1018;
	}
node2181:
	b = true;
	if (b) {
		input[3] |= (1 << 1);
		goto node8065;
	} else {
		input[3] &= ~(1 << 1);
		return 0;
	}
node3369:
	b = true;
	if (b) {
		input[1] |= (1 << 3);
		return 3;
	} else {
		input[1] &= ~(1 << 3);
		return 0;
	}
node407:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node6150;
	} else {
		input[2] &= ~(1 << 1);
		goto node3286;
	}
node2026:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node5942;
	} else {
		input[3] &= ~(1 << 4);
		goto node4264;
	}
node1818:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node5166;
	} else {
		input[3] &= ~(1 << 4);
		goto node4064;
	}
node1742:
	b = true;
	if (b) {
		input[3] |= (1 << 1);
		goto node5492;
	} else {
		input[3] &= ~(1 << 1);
		return 0;
	}
node5784:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node5034;
	} else {
		input[2] &= ~(1 << 1);
		goto node5345;
	}
node2864:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		goto node8825;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node9326:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node4704;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node5105:
	b = true;
	if (b) {
		input[3] |= (1 << 7);
		goto node3924;
	} else {
		input[3] &= ~(1 << 7);
		return 0;
	}
node7302:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node6181;
	} else {
		input[3] &= ~(1 << 6);
		goto node7883;
	}
node383:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node6864;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node3798:
	b = randbool();
	if (b) {
		input[2] |= (1 << 0);
		return 7;
	} else {
		input[2] &= ~(1 << 0);
		return 3;
	}
node4596:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node5798;
	} else {
		input[3] &= ~(1 << 6);
		goto node5285;
	}
node1869:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node8454;
	} else {
		input[3] &= ~(1 << 4);
		goto node1915;
	}
node4213:
	b = false;
	if (b) {
		input[4] |= (1 << 3);
		return 0;
	} else {
		input[4] &= ~(1 << 3);
		goto node4702;
	}
node8767:
	b = randbool();
	if (b) {
		input[7] |= (1 << 4);
		goto node973;
	} else {
		input[7] &= ~(1 << 4);
		goto node8615;
	}
node2411:
	b = false;
	if (b) {
		input[1] |= (1 << 2);
		return 0;
	} else {
		input[1] &= ~(1 << 2);
		goto node974;
	}
node6149:
	b = false;
	if (b) {
		input[2] |= (1 << 1);
		return 0;
	} else {
		input[2] &= ~(1 << 1);
		goto node3455;
	}
node3394:
	b = true;
	if (b) {
		input[4] |= (1 << 3);
		goto node1365;
	} else {
		input[4] &= ~(1 << 3);
		return 0;
	}
node7070:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node5811;
	} else {
		input[3] &= ~(1 << 7);
		goto node2981;
	}
node6300:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node8705;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node1453:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node6611;
	} else {
		input[2] &= ~(1 << 5);
		goto node6861;
	}
node3096:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node9367;
	} else {
		input[2] &= ~(1 << 5);
		goto node7521;
	}
node449:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node7568;
	}
node8060:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node6234;
	} else {
		input[2] &= ~(1 << 1);
		goto node2024;
	}
node6039:
	b = false;
	if (b) {
		input[2] |= (1 << 0);
		return 0;
	} else {
		input[2] &= ~(1 << 0);
		goto node5121;
	}
node1040:
	b = false;
	if (b) {
		input[2] |= (1 << 0);
		return 0;
	} else {
		input[2] &= ~(1 << 0);
		goto node357;
	}
node4009:
	b = true;
	if (b) {
		input[4] |= (1 << 2);
		goto node8528;
	} else {
		input[4] &= ~(1 << 2);
		return 0;
	}
node2983:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node2448;
	} else {
		input[3] &= ~(1 << 4);
		goto node7632;
	}
node4290:
	b = randbool();
	if (b) {
		input[6] |= (1 << 6);
		goto node9051;
	} else {
		input[6] &= ~(1 << 6);
		goto node7423;
	}
node6996:
	b = false;
	if (b) {
		input[1] |= (1 << 0);
		return 0;
	} else {
		input[1] &= ~(1 << 0);
		goto node6572;
	}
node4275:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node8176;
	} else {
		input[2] &= ~(1 << 6);
		goto node1304;
	}
node8792:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node3405;
	} else {
		input[2] &= ~(1 << 1);
		goto node7887;
	}
node9145:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node7052;
	} else {
		input[3] &= ~(1 << 7);
		goto node7270;
	}
node5046:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node5510;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node2559:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node8589;
	}
node8957:
	b = true;
	if (b) {
		input[7] |= (1 << 3);
		goto node1376;
	} else {
		input[7] &= ~(1 << 3);
		return 0;
	}
node8895:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node3872;
	} else {
		input[2] &= ~(1 << 1);
		goto node8992;
	}
node826:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node2529;
	} else {
		input[3] &= ~(1 << 7);
		goto node8079;
	}
node3655:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node6171;
	}
node3314:
	b = true;
	if (b) {
		input[3] |= (1 << 1);
		goto node6037;
	} else {
		input[3] &= ~(1 << 1);
		return 0;
	}
node7703:
	b = true;
	if (b) {
		input[4] |= (1 << 7);
		goto node1635;
	} else {
		input[4] &= ~(1 << 7);
		return 0;
	}
node8556:
	b = true;
	if (b) {
		input[4] |= (1 << 0);
		return 8;
	} else {
		input[4] &= ~(1 << 0);
		return 0;
	}
node940:
	b = true;
	if (b) {
		input[3] |= (1 << 2);
		goto node1049;
	} else {
		input[3] &= ~(1 << 2);
		return 0;
	}
node4452:
	b = true;
	if (b) {
		input[2] |= (1 << 4);
		goto node2322;
	} else {
		input[2] &= ~(1 << 4);
		return 0;
	}
node976:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node7470;
	} else {
		input[2] &= ~(1 << 4);
		goto node2066;
	}
node189:
	b = false;
	if (b) {
		input[2] |= (1 << 2);
		return 0;
	} else {
		input[2] &= ~(1 << 2);
		goto node7433;
	}
node6339:
	b = true;
	if (b) {
		input[3] |= (1 << 6);
		goto node2717;
	} else {
		input[3] &= ~(1 << 6);
		return 0;
	}
node6064:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node7766;
	}
node3502:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node2726;
	} else {
		input[3] &= ~(1 << 3);
		goto node2801;
	}
node5704:
	b = randbool();
	if (b) {
		input[1] |= (1 << 5);
		goto node1944;
	} else {
		input[1] &= ~(1 << 5);
		goto node7496;
	}
node5126:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node7899;
	} else {
		input[3] &= ~(1 << 5);
		goto node2237;
	}
node2530:
	b = false;
	if (b) {
		input[3] |= (1 << 1);
		return 0;
	} else {
		input[3] &= ~(1 << 1);
		goto node8921;
	}
node330:
	b = false;
	if (b) {
		input[2] |= (1 << 5);
		return 0;
	} else {
		input[2] &= ~(1 << 5);
		goto node3609;
	}
node558:
	b = true;
	if (b) {
		input[2] |= (1 << 2);
		goto node6131;
	} else {
		input[2] &= ~(1 << 2);
		return 0;
	}
node1962:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node293;
	} else {
		input[3] &= ~(1 << 7);
		goto node6896;
	}
node1578:
	b = true;
	if (b) {
		input[3] |= (1 << 6);
		goto node7613;
	} else {
		input[3] &= ~(1 << 6);
		return 0;
	}
node6800:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node9212;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node3090:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node3032;
	} else {
		input[3] &= ~(1 << 5);
		goto node2460;
	}
node8316:
	b = randbool();
	if (b) {
		input[0] |= (1 << 2);
		return 1;
	} else {
		input[0] &= ~(1 << 2);
		goto node1762;
	}
node859:
	b = randbool();
	if (b) {
		input[1] |= (1 << 2);
		goto node2980;
	} else {
		input[1] &= ~(1 << 2);
		goto node5766;
	}
node4417:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node3799;
	} else {
		input[2] &= ~(1 << 2);
		goto node8457;
	}
node1097:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node1955;
	} else {
		input[2] &= ~(1 << 2);
		goto node6482;
	}
node7738:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node3849;
	} else {
		input[2] &= ~(1 << 2);
		goto node808;
	}
node7350:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node9118;
	} else {
		input[2] &= ~(1 << 1);
		goto node4304;
	}
node1370:
	b = false;
	if (b) {
		input[2] |= (1 << 1);
		return 0;
	} else {
		input[2] &= ~(1 << 1);
		goto node4077;
	}
node3209:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node548;
	} else {
		input[3] &= ~(1 << 6);
		goto node8776;
	}
node7407:
	b = randbool();
	if (b) {
		input[5] |= (1 << 0);
		return 11;
	} else {
		input[5] &= ~(1 << 0);
		goto node3171;
	}
node4220:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node6082;
	}
node5932:
	b = true;
	if (b) {
		input[3] |= (1 << 1);
		goto node8351;
	} else {
		input[3] &= ~(1 << 1);
		return 0;
	}
node8629:
	b = true;
	if (b) {
		input[1] |= (1 << 2);
		goto node5721;
	} else {
		input[1] &= ~(1 << 2);
		return 0;
	}
node3737:
	b = true;
	if (b) {
		input[1] |= (1 << 1);
		goto node272;
	} else {
		input[1] &= ~(1 << 1);
		return 0;
	}
node4210:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node185;
	} else {
		input[2] &= ~(1 << 6);
		goto node2769;
	}
node5006:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node2977;
	} else {
		input[2] &= ~(1 << 2);
		goto node8060;
	}
node6737:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node5913;
	} else {
		input[3] &= ~(1 << 7);
		goto node1179;
	}
node4288:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node5090;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node2924:
	b = randbool();
	if (b) {
		input[3] |= (1 << 0);
		goto node3520;
	} else {
		input[3] &= ~(1 << 0);
		goto node7283;
	}
node1665:
	b = true;
	if (b) {
		input[1] |= (1 << 0);
		goto node6809;
	} else {
		input[1] &= ~(1 << 0);
		return 0;
	}
node8878:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node7413;
	}
node5215:
	b = false;
	if (b) {
		input[2] |= (1 << 2);
		return 0;
	} else {
		input[2] &= ~(1 << 2);
		goto node9121;
	}
node2906:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node1374;
	}
node891:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node957;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node7486:
	b = false;
	if (b) {
		input[1] |= (1 << 3);
		return 0;
	} else {
		input[1] &= ~(1 << 3);
		goto node3884;
	}
node6481:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node3330;
	} else {
		input[2] &= ~(1 << 2);
		goto node9466;
	}
node6410:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node7063;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node7315:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node2956;
	} else {
		input[3] &= ~(1 << 7);
		goto node8678;
	}
node3801:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node46;
	} else {
		input[3] &= ~(1 << 5);
		goto node7969;
	}
node2067:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node7878;
	}
node5636:
	b = randbool();
	if (b) {
		input[6] |= (1 << 6);
		goto node1102;
	} else {
		input[6] &= ~(1 << 6);
		goto node49;
	}
node6810:
	b = false;
	if (b) {
		input[2] |= (1 << 2);
		return 0;
	} else {
		input[2] &= ~(1 << 2);
		goto node5806;
	}
node3498:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node6462;
	} else {
		input[3] &= ~(1 << 2);
		goto node9353;
	}
node2961:
	b = randbool();
	if (b) {
		input[4] |= (1 << 1);
		goto node4987;
	} else {
		input[4] &= ~(1 << 1);
		goto node7576;
	}
node1498:
	b = false;
	if (b) {
		input[1] |= (1 << 5);
		return 0;
	} else {
		input[1] &= ~(1 << 5);
		goto node1494;
	}
node1503:
	b = randbool();
	if (b) {
		input[1] |= (1 << 4);
		goto node7800;
	} else {
		input[1] &= ~(1 << 4);
		goto node1944;
	}
node6531:
	b = randbool();
	if (b) {
		input[1] |= (1 << 4);
		goto node4594;
	} else {
		input[1] &= ~(1 << 4);
		goto node3859;
	}
node5835:
	b = true;
	if (b) {
		input[1] |= (1 << 1);
		goto node6783;
	} else {
		input[1] &= ~(1 << 1);
		return 0;
	}
node843:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node907;
	} else {
		input[2] &= ~(1 << 2);
		goto node2063;
	}
node7090:
	b = false;
	if (b) {
		input[2] |= (1 << 1);
		return 0;
	} else {
		input[2] &= ~(1 << 1);
		goto node3042;
	}
node2945:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node4411;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node3878:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node6462;
	} else {
		input[3] &= ~(1 << 3);
		goto node312;
	}
node9423:
	b = randbool();
	if (b) {
		input[1] |= (1 << 6);
		goto node6449;
	} else {
		input[1] &= ~(1 << 6);
		goto node5357;
	}
node3135:
	b = true;
	if (b) {
		input[1] |= (1 << 2);
		goto node2843;
	} else {
		input[1] &= ~(1 << 2);
		return 0;
	}
node1703:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node6320;
	} else {
		input[2] &= ~(1 << 4);
		goto node3580;
	}
node5124:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node8149;
	} else {
		input[3] &= ~(1 << 7);
		goto node3877;
	}
node423:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node2721;
	} else {
		input[3] &= ~(1 << 7);
		goto node4522;
	}
node445:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node8279;
	}
node7038:
	b = false;
	if (b) {
		input[4] |= (1 << 1);
		return 0;
	} else {
		input[4] &= ~(1 << 1);
		goto node7741;
	}
node7067:
	b = randbool();
	if (b) {
		input[1] |= (1 << 7);
		goto node5266;
	} else {
		input[1] &= ~(1 << 7);
		goto node4333;
	}
node4847:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node907;
	} else {
		input[2] &= ~(1 << 2);
		goto node7887;
	}
node6399:
	b = false;
	if (b) {
		input[3] |= (1 << 1);
		return 0;
	} else {
		input[3] &= ~(1 << 1);
		goto node215;
	}
node5310:
	b = true;
	if (b) {
		input[4] |= (1 << 6);
		goto node2814;
	} else {
		input[4] &= ~(1 << 6);
		return 0;
	}
node7326:
	b = false;
	if (b) {
		input[3] |= (1 << 6);
		return 0;
	} else {
		input[3] &= ~(1 << 6);
		goto node6888;
	}
node4271:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node544;
	}
node3219:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node6393;
	}
node9100:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node3324;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node3395:
	b = randbool();
	if (b) {
		input[1] |= (1 << 6);
		goto node3843;
	} else {
		input[1] &= ~(1 << 6);
		goto node7985;
	}
node9425:
	b = false;
	if (b) {
		input[2] |= (1 << 1);
		return 0;
	} else {
		input[2] &= ~(1 << 1);
		goto node7239;
	}
node367:
	b = randbool();
	if (b) {
		input[2] |= (1 << 0);
		goto node9175;
	} else {
		input[2] &= ~(1 << 0);
		goto node7860;
	}
node1315:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node5191;
	} else {
		input[3] &= ~(1 << 4);
		goto node911;
	}
node5984:
	b = false;
	if (b) {
		input[4] |= (1 << 2);
		return 0;
	} else {
		input[4] &= ~(1 << 2);
		goto node756;
	}
node2482:
	b = false;
	if (b) {
		input[2] |= (1 << 5);
		return 0;
	} else {
		input[2] &= ~(1 << 5);
		goto node8376;
	}
node7234:
	b = false;
	if (b) {
		input[2] |= (1 << 5);
		return 0;
	} else {
		input[2] &= ~(1 << 5);
		goto node2770;
	}
node8821:
	b = true;
	if (b) {
		input[3] |= (1 << 6);
		goto node8843;
	} else {
		input[3] &= ~(1 << 6);
		return 0;
	}
node4591:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node6527;
	} else {
		input[3] &= ~(1 << 5);
		goto node8106;
	}
node6835:
	b = false;
	if (b) {
		input[3] |= (1 << 2);
		return 0;
	} else {
		input[3] &= ~(1 << 2);
		goto node7632;
	}
node8368:
	b = randbool();
	if (b) {
		input[1] |= (1 << 3);
		goto node8497;
	} else {
		input[1] &= ~(1 << 3);
		goto node6380;
	}
node5821:
	b = true;
	if (b) {
		input[2] |= (1 << 3);
		goto node288;
	} else {
		input[2] &= ~(1 << 3);
		return 0;
	}
node5806:
	b = false;
	if (b) {
		input[2] |= (1 << 1);
		return 0;
	} else {
		input[2] &= ~(1 << 1);
		goto node6552;
	}
node1984:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node1252;
	} else {
		input[3] &= ~(1 << 2);
		goto node7128;
	}
node7254:
	b = randbool();
	if (b) {
		input[4] |= (1 << 3);
		goto node2360;
	} else {
		input[4] &= ~(1 << 3);
		goto node4599;
	}
node8241:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node6913;
	}
node892:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node3478;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node9124:
	b = randbool();
	if (b) {
		input[2] |= (1 << 7);
		goto node2596;
	} else {
		input[2] &= ~(1 << 7);
		goto node8816;
	}
node7478:
	b = false;
	if (b) {
		input[2] |= (1 << 5);
		return 0;
	} else {
		input[2] &= ~(1 << 5);
		goto node1858;
	}
node3002:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node6233;
	} else {
		input[2] &= ~(1 << 2);
		return 3;
	}
node3465:
	b = randbool();
	if (b) {
		input[2] |= (1 << 0);
		return 9;
	} else {
		input[2] &= ~(1 << 0);
		goto node2518;
	}
node408:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node8061;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node8112:
	b = true;
	if (b) {
		input[3] |= (1 << 6);
		goto node5282;
	} else {
		input[3] &= ~(1 << 6);
		return 0;
	}
node7876:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node3266;
	} else {
		input[3] &= ~(1 << 2);
		goto node7632;
	}
node3831:
	b = randbool();
	if (b) {
		input[4] |= (1 << 6);
		goto node2560;
	} else {
		input[4] &= ~(1 << 6);
		goto node2477;
	}
node8440:
	b = randbool();
	if (b) {
		input[4] |= (1 << 3);
		goto node875;
	} else {
		input[4] &= ~(1 << 3);
		goto node1966;
	}
node972:
	b = randbool();
	if (b) {
		input[4] |= (1 << 2);
		goto node2128;
	} else {
		input[4] &= ~(1 << 2);
		goto node2754;
	}
node1107:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node7224;
	} else {
		input[2] &= ~(1 << 6);
		goto node1097;
	}
node5332:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node4293;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node4501:
	b = true;
	if (b) {
		input[1] |= (1 << 5);
		goto node5051;
	} else {
		input[1] &= ~(1 << 5);
		return 0;
	}
node1999:
	b = true;
	if (b) {
		input[2] |= (1 << 6);
		goto node5595;
	} else {
		input[2] &= ~(1 << 6);
		return 0;
	}
node684:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node8026;
	} else {
		input[3] &= ~(1 << 6);
		goto node8196;
	}
node1200:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node5643;
	}
node4476:
	b = randbool();
	if (b) {
		input[1] |= (1 << 1);
		return 3;
	} else {
		input[1] &= ~(1 << 1);
		goto node5968;
	}
node7685:
	b = true;
	if (b) {
		input[3] |= (1 << 0);
		goto node8395;
	} else {
		input[3] &= ~(1 << 0);
		return 0;
	}
node4419:
	b = false;
	if (b) {
		input[3] |= (1 << 0);
		return 0;
	} else {
		input[3] &= ~(1 << 0);
		goto node1509;
	}
node5641:
	b = false;
	if (b) {
		input[2] |= (1 << 7);
		return 0;
	} else {
		input[2] &= ~(1 << 7);
		goto node8021;
	}
node7223:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node1479;
	} else {
		input[2] &= ~(1 << 5);
		goto node8281;
	}
node6755:
	b = true;
	if (b) {
		input[2] |= (1 << 2);
		goto node7107;
	} else {
		input[2] &= ~(1 << 2);
		return 0;
	}
node2190:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node2699;
	} else {
		input[3] &= ~(1 << 7);
		goto node2608;
	}
node6145:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node5923;
	}
node3157:
	b = true;
	if (b) {
		input[3] |= (1 << 1);
		goto node6671;
	} else {
		input[3] &= ~(1 << 1);
		return 0;
	}
node5452:
	b = false;
	if (b) {
		input[3] |= (1 << 1);
		return 0;
	} else {
		input[3] &= ~(1 << 1);
		goto node219;
	}
node3566:
	b = randbool();
	if (b) {
		input[1] |= (1 << 2);
		goto node1482;
	} else {
		input[1] &= ~(1 << 2);
		goto node7277;
	}
node3742:
	b = randbool();
	if (b) {
		input[2] |= (1 << 0);
		goto node2716;
	} else {
		input[2] &= ~(1 << 0);
		goto node8297;
	}
node6580:
	b = randbool();
	if (b) {
		input[4] |= (1 << 1);
		goto node8912;
	} else {
		input[4] &= ~(1 << 1);
		goto node439;
	}
node541:
	b = false;
	if (b) {
		input[2] |= (1 << 7);
		return 0;
	} else {
		input[2] &= ~(1 << 7);
		goto node455;
	}
node2752:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node705;
	} else {
		input[3] &= ~(1 << 6);
		goto node8034;
	}
node8881:
	b = false;
	if (b) {
		input[3] |= (1 << 6);
		return 0;
	} else {
		input[3] &= ~(1 << 6);
		goto node6658;
	}
node8599:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node9153;
	} else {
		input[3] &= ~(1 << 2);
		goto node3314;
	}
node1081:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node3957;
	} else {
		input[2] &= ~(1 << 4);
		goto node5711;
	}
node4892:
	b = false;
	if (b) {
		input[2] |= (1 << 2);
		return 0;
	} else {
		input[2] &= ~(1 << 2);
		goto node4224;
	}
node1711:
	b = true;
	if (b) {
		input[3] |= (1 << 6);
		goto node4884;
	} else {
		input[3] &= ~(1 << 6);
		return 0;
	}
node1992:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node3244;
	} else {
		input[3] &= ~(1 << 5);
		goto node903;
	}
node4332:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node5564;
	} else {
		input[3] &= ~(1 << 3);
		goto node7308;
	}
node6395:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node7054;
	}
node1942:
	b = randbool();
	if (b) {
		input[4] |= (1 << 6);
		goto node2938;
	} else {
		input[4] &= ~(1 << 6);
		goto node3194;
	}
node3293:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node2646;
	} else {
		input[3] &= ~(1 << 3);
		goto node2996;
	}
node512:
	b = false;
	if (b) {
		input[3] |= (1 << 2);
		return 0;
	} else {
		input[3] &= ~(1 << 2);
		goto node1746;
	}
node91:
	b = randbool();
	if (b) {
		input[0] |= (1 << 0);
		goto node4413;
	} else {
		input[0] &= ~(1 << 0);
		goto node4703;
	}
node2144:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node5345;
	} else {
		input[2] &= ~(1 << 3);
		goto node5177;
	}
node4242:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node7758;
	} else {
		input[3] &= ~(1 << 6);
		goto node6010;
	}
node1352:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node2078;
	}
node5894:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node7816;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node2458:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node6462;
	} else {
		input[3] &= ~(1 << 3);
		goto node5603;
	}
node1153:
	b = true;
	if (b) {
		input[4] |= (1 << 6);
		goto node4236;
	} else {
		input[4] &= ~(1 << 6);
		return 0;
	}
node5950:
	b = randbool();
	if (b) {
		input[4] |= (1 << 1);
		goto node7417;
	} else {
		input[4] &= ~(1 << 1);
		goto node9168;
	}
node4058:
	b = randbool();
	if (b) {
		input[4] |= (1 << 5);
		goto node5878;
	} else {
		input[4] &= ~(1 << 5);
		goto node5794;
	}
node8503:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node6027;
	} else {
		input[2] &= ~(1 << 3);
		goto node9130;
	}
node3308:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node5404;
	} else {
		input[2] &= ~(1 << 3);
		goto node4654;
	}
node8966:
	b = true;
	if (b) {
		input[5] |= (1 << 7);
		goto node7849;
	} else {
		input[5] &= ~(1 << 7);
		return 0;
	}
node2398:
	b = false;
	if (b) {
		input[2] |= (1 << 6);
		return 0;
	} else {
		input[2] &= ~(1 << 6);
		goto node9098;
	}
node3567:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node3307;
	}
node2867:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node1745;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node178:
	b = randbool();
	if (b) {
		input[4] |= (1 << 6);
		goto node990;
	} else {
		input[4] &= ~(1 << 6);
		goto node1611;
	}
node607:
	b = true;
	if (b) {
		input[4] |= (1 << 6);
		goto node8362;
	} else {
		input[4] &= ~(1 << 6);
		return 0;
	}
node6764:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node7101;
	} else {
		input[2] &= ~(1 << 1);
		goto node6854;
	}
node2010:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node8672;
	} else {
		input[3] &= ~(1 << 7);
		goto node6971;
	}
node2387:
	b = false;
	if (b) {
		input[3] |= (1 << 7);
		return 0;
	} else {
		input[3] &= ~(1 << 7);
		goto node3344;
	}
node8033:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node3174;
	} else {
		input[3] &= ~(1 << 5);
		goto node780;
	}
node593:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node6563;
	} else {
		input[3] &= ~(1 << 5);
		goto node4656;
	}
node2887:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node6065;
	}
node5934:
	b = true;
	if (b) {
		input[4] |= (1 << 4);
		goto node1846;
	} else {
		input[4] &= ~(1 << 4);
		return 0;
	}
node3286:
	b = randbool();
	if (b) {
		input[2] |= (1 << 0);
		goto node6562;
	} else {
		input[2] &= ~(1 << 0);
		goto node8832;
	}
node3428:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node4367;
	}
node2687:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node2942;
	} else {
		input[3] &= ~(1 << 4);
		goto node9229;
	}
node4656:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node3878;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node75:
	b = false;
	if (b) {
		input[6] |= (1 << 1);
		return 0;
	} else {
		input[6] &= ~(1 << 1);
		goto node6935;
	}
node2568:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node4041;
	} else {
		input[2] &= ~(1 << 3);
		goto node7521;
	}
node8536:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node367;
	} else {
		input[2] &= ~(1 << 1);
		goto node5754;
	}
node8129:
	b = false;
	if (b) {
		input[3] |= (1 << 0);
		return 0;
	} else {
		input[3] &= ~(1 << 0);
		goto node8053;
	}
node4070:
	b = false;
	if (b) {
		input[3] |= (1 << 0);
		return 0;
	} else {
		input[3] &= ~(1 << 0);
		goto node4267;
	}
node8342:
	b = true;
	if (b) {
		input[4] |= (1 << 6);
		goto node7625;
	} else {
		input[4] &= ~(1 << 6);
		return 0;
	}
node6967:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		goto node6055;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node4856:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node4734;
	} else {
		input[3] &= ~(1 << 6);
		goto node3625;
	}
node2662:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node4925;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node4831:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node1416;
	} else {
		input[2] &= ~(1 << 5);
		goto node8812;
	}
node5809:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node3197;
	} else {
		input[2] &= ~(1 << 3);
		goto node2187;
	}
node2838:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node2008;
	} else {
		input[2] &= ~(1 << 2);
		goto node1272;
	}
node8411:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node6504;
	} else {
		input[3] &= ~(1 << 2);
		goto node7397;
	}
node948:
	b = randbool();
	if (b) {
		input[3] |= (1 << 1);
		goto node6220;
	} else {
		input[3] &= ~(1 << 1);
		goto node8380;
	}
node9394:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node1113;
	} else {
		input[2] &= ~(1 << 5);
		goto node9299;
	}
node1982:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node8193;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node9063:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node1217;
	} else {
		input[3] &= ~(1 << 4);
		goto node3506;
	}
node5772:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node9306;
	} else {
		input[2] &= ~(1 << 2);
		goto node1234;
	}
node4005:
	b = false;
	if (b) {
		input[2] |= (1 << 1);
		return 0;
	} else {
		input[2] &= ~(1 << 1);
		goto node1212;
	}
node475:
	b = true;
	if (b) {
		input[4] |= (1 << 2);
		goto node392;
	} else {
		input[4] &= ~(1 << 2);
		return 0;
	}
node3230:
	b = true;
	if (b) {
		input[5] |= (1 << 0);
		goto node3646;
	} else {
		input[5] &= ~(1 << 0);
		return 0;
	}
node8169:
	b = true;
	if (b) {
		input[5] |= (1 << 6);
		goto node8140;
	} else {
		input[5] &= ~(1 << 6);
		return 0;
	}
node9209:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node6848;
	} else {
		input[2] &= ~(1 << 4);
		goto node9441;
	}
node4708:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node9000;
	} else {
		input[2] &= ~(1 << 2);
		goto node6371;
	}
node8618:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node351;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node105:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node4022;
	} else {
		input[3] &= ~(1 << 7);
		goto node3840;
	}
node7517:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node5198;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node3120:
	b = false;
	if (b) {
		input[3] |= (1 << 2);
		return 0;
	} else {
		input[3] &= ~(1 << 2);
		goto node5759;
	}
node2409:
	b = randbool();
	if (b) {
		input[4] |= (1 << 3);
		goto node2360;
	} else {
		input[4] &= ~(1 << 3);
		goto node4289;
	}
node4518:
	b = false;
	if (b) {
		input[1] |= (1 << 5);
		return 0;
	} else {
		input[1] &= ~(1 << 5);
		goto node8385;
	}
node4854:
	b = randbool();
	if (b) {
		input[1] |= (1 << 2);
		goto node6186;
	} else {
		input[1] &= ~(1 << 2);
		goto node314;
	}
node6439:
	b = false;
	if (b) {
		input[2] |= (1 << 1);
		return 0;
	} else {
		input[2] &= ~(1 << 1);
		goto node5986;
	}
node1251:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node3382;
	} else {
		input[3] &= ~(1 << 4);
		goto node137;
	}
node5446:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node3170;
	} else {
		input[3] &= ~(1 << 4);
		goto node9364;
	}
node9333:
	b = true;
	if (b) {
		input[3] |= (1 << 0);
		goto node9114;
	} else {
		input[3] &= ~(1 << 0);
		return 0;
	}
node1486:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node4810;
	} else {
		input[2] &= ~(1 << 4);
		goto node2187;
	}
node2661:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node5405;
	} else {
		input[3] &= ~(1 << 4);
		goto node892;
	}
node7833:
	b = false;
	if (b) {
		input[3] |= (1 << 2);
		return 0;
	} else {
		input[3] &= ~(1 << 2);
		goto node5337;
	}
node4669:
	b = true;
	if (b) {
		input[3] |= (1 << 2);
		goto node5492;
	} else {
		input[3] &= ~(1 << 2);
		return 0;
	}
node5905:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node1058;
	} else {
		input[2] &= ~(1 << 4);
		goto node4650;
	}
node6686:
	b = false;
	if (b) {
		input[3] |= (1 << 2);
		return 0;
	} else {
		input[3] &= ~(1 << 2);
		goto node6220;
	}
node9476:
	b = true;
	if (b) {
		input[3] |= (1 << 1);
		goto node3808;
	} else {
		input[3] &= ~(1 << 1);
		return 0;
	}
node5050:
	b = false;
	if (b) {
		input[5] |= (1 << 1);
		return 0;
	} else {
		input[5] &= ~(1 << 1);
		goto node4951;
	}
node1074:
	b = randbool();
	if (b) {
		input[2] |= (1 << 7);
		goto node666;
	} else {
		input[2] &= ~(1 << 7);
		goto node3967;
	}
node7380:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node1530;
	} else {
		input[3] &= ~(1 << 5);
		goto node8004;
	}
node4877:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node508;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node2925:
	b = true;
	if (b) {
		input[4] |= (1 << 4);
		goto node6229;
	} else {
		input[4] &= ~(1 << 4);
		return 0;
	}
node960:
	b = randbool();
	if (b) {
		input[1] |= (1 << 7);
		goto node7394;
	} else {
		input[1] &= ~(1 << 7);
		goto node3160;
	}
node3437:
	b = false;
	if (b) {
		input[1] |= (1 << 0);
		return 0;
	} else {
		input[1] &= ~(1 << 0);
		return 3;
	}
node6460:
	b = randbool();
	if (b) {
		input[2] |= (1 << 7);
		goto node5994;
	} else {
		input[2] &= ~(1 << 7);
		goto node8042;
	}
node2578:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node4751;
	} else {
		input[2] &= ~(1 << 5);
		goto node5525;
	}
node8101:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node8776;
	} else {
		input[3] &= ~(1 << 4);
		goto node2084;
	}
node1056:
	b = randbool();
	if (b) {
		input[3] |= (1 << 1);
		return 5;
	} else {
		input[3] &= ~(1 << 1);
		goto node8600;
	}
node6093:
	b = true;
	if (b) {
		input[4] |= (1 << 6);
		goto node984;
	} else {
		input[4] &= ~(1 << 6);
		return 0;
	}
node1784:
	b = randbool();
	if (b) {
		input[1] |= (1 << 6);
		goto node6943;
	} else {
		input[1] &= ~(1 << 6);
		goto node999;
	}
node4246:
	b = true;
	if (b) {
		input[1] |= (1 << 2);
		goto node4700;
	} else {
		input[1] &= ~(1 << 2);
		return 0;
	}
node5611:
	b = true;
	if (b) {
		input[1] |= (1 << 0);
		goto node541;
	} else {
		input[1] &= ~(1 << 0);
		return 0;
	}
node2830:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node1857;
	} else {
		input[2] &= ~(1 << 5);
		goto node8272;
	}
node8553:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node6465;
	} else {
		input[3] &= ~(1 << 6);
		goto node9301;
	}
node144:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node1563;
	} else {
		input[3] &= ~(1 << 3);
		goto node2600;
	}
node4237:
	b = false;
	if (b) {
		input[4] |= (1 << 3);
		return 0;
	} else {
		input[4] &= ~(1 << 3);
		goto node8622;
	}
node4389:
	b = false;
	if (b) {
		input[1] |= (1 << 1);
		return 0;
	} else {
		input[1] &= ~(1 << 1);
		goto node6813;
	}
node4910:
	b = true;
	if (b) {
		input[2] |= (1 << 4);
		goto node2620;
	} else {
		input[2] &= ~(1 << 4);
		return 0;
	}
node6455:
	b = false;
	if (b) {
		input[2] |= (1 << 1);
		return 0;
	} else {
		input[2] &= ~(1 << 1);
		goto node5345;
	}
node7779:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node6054;
	} else {
		input[3] &= ~(1 << 4);
		goto node1243;
	}
node4072:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node4349;
	} else {
		input[3] &= ~(1 << 5);
		goto node6880;
	}
node7411:
	b = true;
	if (b) {
		input[3] |= (1 << 2);
		goto node7632;
	} else {
		input[3] &= ~(1 << 2);
		return 0;
	}
node9010:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node4586;
	} else {
		input[3] &= ~(1 << 2);
		goto node3237;
	}
node7637:
	b = true;
	if (b) {
		input[4] |= (1 << 7);
		goto node3064;
	} else {
		input[4] &= ~(1 << 7);
		return 0;
	}
node7431:
	b = randbool();
	if (b) {
		input[1] |= (1 << 0);
		goto node5382;
	} else {
		input[1] &= ~(1 << 0);
		goto node1300;
	}
node3492:
	b = true;
	if (b) {
		input[2] |= (1 << 3);
		goto node1586;
	} else {
		input[2] &= ~(1 << 3);
		return 0;
	}
node7351:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		goto node210;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node7998:
	b = randbool();
	if (b) {
		input[4] |= (1 << 7);
		goto node4182;
	} else {
		input[4] &= ~(1 << 7);
		goto node3831;
	}
node6273:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node3650;
	} else {
		input[3] &= ~(1 << 3);
		goto node7411;
	}
node8358:
	b = true;
	if (b) {
		input[3] |= (1 << 2);
		goto node4460;
	} else {
		input[3] &= ~(1 << 2);
		return 0;
	}
node7817:
	b = false;
	if (b) {
		input[4] |= (1 << 5);
		return 0;
	} else {
		input[4] &= ~(1 << 5);
		goto node4228;
	}
node4478:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node3743;
	} else {
		input[3] &= ~(1 << 6);
		goto node2400;
	}
node5923:
	b = true;
	if (b) {
		input[3] |= (1 << 2);
		goto node2928;
	} else {
		input[3] &= ~(1 << 2);
		return 0;
	}
node9276:
	b = false;
	if (b) {
		input[1] |= (1 << 3);
		return 0;
	} else {
		input[1] &= ~(1 << 3);
		goto node2301;
	}
node5926:
	b = randbool();
	if (b) {
		input[1] |= (1 << 0);
		goto node4646;
	} else {
		input[1] &= ~(1 << 0);
		goto node3242;
	}
node6308:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node4216;
	} else {
		input[3] &= ~(1 << 4);
		goto node6577;
	}
node8480:
	b = false;
	if (b) {
		input[3] |= (1 << 0);
		return 0;
	} else {
		input[3] &= ~(1 << 0);
		goto node2946;
	}
node2107:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node1875;
	}
node107:
	b = false;
	if (b) {
		input[3] |= (1 << 1);
		return 0;
	} else {
		input[3] &= ~(1 << 1);
		goto node4445;
	}
node6365:
	b = true;
	if (b) {
		input[2] |= (1 << 7);
		goto node2142;
	} else {
		input[2] &= ~(1 << 7);
		return 0;
	}
node3086:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node6936;
	} else {
		input[2] &= ~(1 << 6);
		goto node7478;
	}
node5519:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node3738;
	} else {
		input[2] &= ~(1 << 6);
		goto node9287;
	}
node5676:
	b = true;
	if (b) {
		input[2] |= (1 << 2);
		goto node2294;
	} else {
		input[2] &= ~(1 << 2);
		return 0;
	}
node7802:
	b = randbool();
	if (b) {
		input[2] |= (1 << 0);
		goto node6667;
	} else {
		input[2] &= ~(1 << 0);
		goto node186;
	}
node3455:
	b = false;
	if (b) {
		input[2] |= (1 << 0);
		return 0;
	} else {
		input[2] &= ~(1 << 0);
		goto node3140;
	}
node1600:
	b = false;
	if (b) {
		input[4] |= (1 << 7);
		return 0;
	} else {
		input[4] &= ~(1 << 7);
		goto node3596;
	}
node3159:
	b = true;
	if (b) {
		input[4] |= (1 << 2);
		goto node3874;
	} else {
		input[4] &= ~(1 << 2);
		return 0;
	}
node2205:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node4351;
	}
node6090:
	b = true;
	if (b) {
		input[2] |= (1 << 2);
		goto node9019;
	} else {
		input[2] &= ~(1 << 2);
		return 0;
	}
node173:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		goto node3136;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node3127:
	b = randbool();
	if (b) {
		input[4] |= (1 << 0);
		goto node7576;
	} else {
		input[4] &= ~(1 << 0);
		goto node8656;
	}
node4770:
	b = true;
	if (b) {
		input[2] |= (1 << 5);
		goto node8233;
	} else {
		input[2] &= ~(1 << 5);
		return 0;
	}
node5711:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node6165;
	} else {
		input[2] &= ~(1 << 3);
		goto node3957;
	}
node4354:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node3115;
	} else {
		input[2] &= ~(1 << 2);
		goto node7256;
	}
node6282:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node8578;
	} else {
		input[3] &= ~(1 << 5);
		goto node7412;
	}
node4371:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node3777;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node5943:
	b = true;
	if (b) {
		input[4] |= (1 << 5);
		goto node6857;
	} else {
		input[4] &= ~(1 << 5);
		return 0;
	}
node8157:
	b = randbool();
	if (b) {
		input[3] |= (1 << 1);
		goto node6671;
	} else {
		input[3] &= ~(1 << 1);
		goto node3520;
	}
node9154:
	b = randbool();
	if (b) {
		input[4] |= (1 << 5);
		goto node2489;
	} else {
		input[4] &= ~(1 << 5);
		goto node1096;
	}
node2184:
	b = randbool();
	if (b) {
		input[1] |= (1 << 7);
		goto node4690;
	} else {
		input[1] &= ~(1 << 7);
		goto node4333;
	}
node3372:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node1439;
	} else {
		input[2] &= ~(1 << 5);
		goto node2675;
	}
node7161:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node9252;
	} else {
		input[3] &= ~(1 << 4);
		goto node3520;
	}
node7148:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node6926;
	} else {
		input[3] &= ~(1 << 4);
		goto node2635;
	}
node6283:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node160;
	} else {
		input[3] &= ~(1 << 4);
		goto node1948;
	}
node575:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node8451;
	} else {
		input[3] &= ~(1 << 3);
		goto node5584;
	}
node1829:
	b = true;
	if (b) {
		input[4] |= (1 << 5);
		goto node7055;
	} else {
		input[4] &= ~(1 << 5);
		return 0;
	}
node6964:
	b = true;
	if (b) {
		input[6] |= (1 << 3);
		goto node2092;
	} else {
		input[6] &= ~(1 << 3);
		return 0;
	}
node1261:
	b = false;
	if (b) {
		input[2] |= (1 << 1);
		return 0;
	} else {
		input[2] &= ~(1 << 1);
		goto node690;
	}
node3769:
	b = true;
	if (b) {
		input[3] |= (1 << 1);
		goto node8647;
	} else {
		input[3] &= ~(1 << 1);
		return 0;
	}
node3653:
	b = false;
	if (b) {
		input[4] |= (1 << 5);
		return 0;
	} else {
		input[4] &= ~(1 << 5);
		goto node5895;
	}
node5513:
	b = false;
	if (b) {
		input[4] |= (1 << 5);
		return 0;
	} else {
		input[4] &= ~(1 << 5);
		goto node519;
	}
node8753:
	b = false;
	if (b) {
		input[2] |= (1 << 6);
		return 0;
	} else {
		input[2] &= ~(1 << 6);
		goto node8089;
	}
node2725:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node2506;
	} else {
		input[3] &= ~(1 << 4);
		goto node3485;
	}
node4749:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node4093;
	} else {
		input[3] &= ~(1 << 2);
		goto node3220;
	}
node2555:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node207;
	} else {
		input[2] &= ~(1 << 6);
		goto node3797;
	}
node7823:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node2220;
	} else {
		input[3] &= ~(1 << 4);
		goto node196;
	}
node2120:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node8871;
	} else {
		input[3] &= ~(1 << 4);
		goto node579;
	}
node8738:
	b = false;
	if (b) {
		input[4] |= (1 << 4);
		return 0;
	} else {
		input[4] &= ~(1 << 4);
		goto node8757;
	}
node1768:
	b = true;
	if (b) {
		input[5] |= (1 << 0);
		return 7;
	} else {
		input[5] &= ~(1 << 0);
		return 0;
	}
node6179:
	b = false;
	if (b) {
		input[2] |= (1 << 1);
		return 0;
	} else {
		input[2] &= ~(1 << 1);
		goto node749;
	}
node8847:
	b = false;
	if (b) {
		input[1] |= (1 << 3);
		return 0;
	} else {
		input[1] &= ~(1 << 3);
		goto node4584;
	}
node2696:
	b = true;
	if (b) {
		input[2] |= (1 << 7);
		goto node7880;
	} else {
		input[2] &= ~(1 << 7);
		return 0;
	}
node4853:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node3667;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node5514:
	b = true;
	if (b) {
		input[3] |= (1 << 1);
		goto node4808;
	} else {
		input[3] &= ~(1 << 1);
		return 0;
	}
node2463:
	b = randbool();
	if (b) {
		input[5] |= (1 << 2);
		goto node7177;
	} else {
		input[5] &= ~(1 << 2);
		return 6;
	}
node8269:
	b = randbool();
	if (b) {
		input[3] |= (1 << 1);
		goto node2338;
	} else {
		input[3] &= ~(1 << 1);
		goto node3077;
	}
node5170:
	b = true;
	if (b) {
		input[4] |= (1 << 2);
		goto node8956;
	} else {
		input[4] &= ~(1 << 2);
		return 0;
	}
node1419:
	b = randbool();
	if (b) {
		input[1] |= (1 << 3);
		goto node931;
	} else {
		input[1] &= ~(1 << 3);
		goto node6495;
	}
node2816:
	b = true;
	if (b) {
		input[1] |= (1 << 0);
		goto node4513;
	} else {
		input[1] &= ~(1 << 0);
		return 0;
	}
node5980:
	b = false;
	if (b) {
		input[2] |= (1 << 5);
		return 0;
	} else {
		input[2] &= ~(1 << 5);
		goto node6636;
	}
node7330:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node7943;
	} else {
		input[3] &= ~(1 << 6);
		goto node6915;
	}
node4610:
	b = true;
	if (b) {
		input[3] |= (1 << 6);
		goto node2378;
	} else {
		input[3] &= ~(1 << 6);
		return 0;
	}
node2209:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node5563;
	}
node5790:
	b = true;
	if (b) {
		input[1] |= (1 << 4);
		goto node2348;
	} else {
		input[1] &= ~(1 << 4);
		return 0;
	}
node1129:
	b = true;
	if (b) {
		input[3] |= (1 << 0);
		goto node6976;
	} else {
		input[3] &= ~(1 << 0);
		return 0;
	}
node6492:
	b = randbool();
	if (b) {
		input[1] |= (1 << 1);
		goto node4767;
	} else {
		input[1] &= ~(1 << 1);
		goto node7111;
	}
node2814:
	b = false;
	if (b) {
		input[4] |= (1 << 5);
		return 0;
	} else {
		input[4] &= ~(1 << 5);
		goto node2760;
	}
node8066:
	b = randbool();
	if (b) {
		input[4] |= (1 << 4);
		goto node7722;
	} else {
		input[4] &= ~(1 << 4);
		goto node1057;
	}
node5309:
	b = randbool();
	if (b) {
		input[3] |= (1 << 1);
		goto node1129;
	} else {
		input[3] &= ~(1 << 1);
		goto node9333;
	}
node959:
	b = false;
	if (b) {
		input[3] |= (1 << 1);
		return 0;
	} else {
		input[3] &= ~(1 << 1);
		goto node3808;
	}
node1035:
	b = randbool();
	if (b) {
		input[0] |= (1 << 4);
		goto node1485;
	} else {
		input[0] &= ~(1 << 4);
		goto node1022;
	}
node6108:
	b = randbool();
	if (b) {
		input[1] |= (1 << 6);
		goto node4501;
	} else {
		input[1] &= ~(1 << 6);
		goto node6078;
	}
node9104:
	b = false;
	if (b) {
		input[2] |= (1 << 7);
		return 0;
	} else {
		input[2] &= ~(1 << 7);
		goto node6886;
	}
node355:
	b = false;
	if (b) {
		input[3] |= (1 << 7);
		return 0;
	} else {
		input[3] &= ~(1 << 7);
		goto node6356;
	}
node9047:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node4193;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node9352:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node633;
	} else {
		input[3] &= ~(1 << 3);
		goto node4711;
	}
node8455:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node7869;
	}
node4684:
	b = false;
	if (b) {
		input[2] |= (1 << 3);
		return 0;
	} else {
		input[2] &= ~(1 << 3);
		goto node3444;
	}
node7452:
	b = randbool();
	if (b) {
		input[3] |= (1 << 1);
		goto node1129;
	} else {
		input[3] &= ~(1 << 1);
		goto node5591;
	}
node2268:
	b = randbool();
	if (b) {
		input[1] |= (1 << 4);
		goto node7086;
	} else {
		input[1] &= ~(1 << 4);
		goto node8643;
	}
node8803:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node3374;
	} else {
		input[2] &= ~(1 << 5);
		goto node202;
	}
node754:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node6106;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node7983:
	b = true;
	if (b) {
		input[4] |= (1 << 2);
		goto node1674;
	} else {
		input[4] &= ~(1 << 2);
		return 0;
	}
node5290:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node2968;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node3715:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node8026;
	} else {
		input[3] &= ~(1 << 6);
		goto node2683;
	}
node150:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node2037;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node6332:
	b = false;
	if (b) {
		input[3] |= (1 << 2);
		return 0;
	} else {
		input[3] &= ~(1 << 2);
		goto node5901;
	}
node427:
	b = randbool();
	if (b) {
		input[4] |= (1 << 5);
		goto node8667;
	} else {
		input[4] &= ~(1 << 5);
		goto node2432;
	}
node1090:
	b = false;
	if (b) {
		input[1] |= (1 << 3);
		return 0;
	} else {
		input[1] &= ~(1 << 3);
		goto node6642;
	}
node5827:
	b = randbool();
	if (b) {
		input[1] |= (1 << 0);
		goto node9428;
	} else {
		input[1] &= ~(1 << 0);
		goto node3242;
	}
node7841:
	b = false;
	if (b) {
		input[2] |= (1 << 1);
		return 0;
	} else {
		input[2] &= ~(1 << 1);
		goto node30;
	}
node3840:
	b = false;
	if (b) {
		input[3] |= (1 << 6);
		return 0;
	} else {
		input[3] &= ~(1 << 6);
		goto node8564;
	}
node6659:
	b = true;
	if (b) {
		input[4] |= (1 << 2);
		goto node1470;
	} else {
		input[4] &= ~(1 << 2);
		return 0;
	}
node8175:
	b = true;
	if (b) {
		input[4] |= (1 << 2);
		goto node7809;
	} else {
		input[4] &= ~(1 << 2);
		return 0;
	}
node6746:
	b = true;
	if (b) {
		input[4] |= (1 << 2);
		goto node4194;
	} else {
		input[4] &= ~(1 << 2);
		return 0;
	}
node4111:
	b = true;
	if (b) {
		input[1] |= (1 << 2);
		goto node4554;
	} else {
		input[1] &= ~(1 << 2);
		return 0;
	}
node3114:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node4772;
	} else {
		input[2] &= ~(1 << 2);
		goto node3026;
	}
node1277:
	b = true;
	if (b) {
		input[3] |= (1 << 6);
		goto node6873;
	} else {
		input[3] &= ~(1 << 6);
		return 0;
	}
node1011:
	b = false;
	if (b) {
		input[3] |= (1 << 2);
		return 0;
	} else {
		input[3] &= ~(1 << 2);
		goto node137;
	}
node5751:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		return 4;
	} else {
		input[3] &= ~(1 << 2);
		goto node3881;
	}
node896:
	b = false;
	if (b) {
		input[4] |= (1 << 7);
		return 0;
	} else {
		input[4] &= ~(1 << 7);
		goto node6107;
	}
node3659:
	b = randbool();
	if (b) {
		input[1] |= (1 << 2);
		goto node3475;
	} else {
		input[1] &= ~(1 << 2);
		goto node828;
	}
node7520:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node317;
	} else {
		input[2] &= ~(1 << 5);
		goto node8226;
	}
node5078:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node1277;
	} else {
		input[3] &= ~(1 << 7);
		goto node7865;
	}
node5946:
	b = true;
	if (b) {
		input[4] |= (1 << 6);
		goto node427;
	} else {
		input[4] &= ~(1 << 6);
		return 0;
	}
node2682:
	b = true;
	if (b) {
		input[4] |= (1 << 4);
		goto node48;
	} else {
		input[4] &= ~(1 << 4);
		return 0;
	}
node6880:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node1269;
	} else {
		input[3] &= ~(1 << 4);
		goto node9407;
	}
node2923:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node120;
	} else {
		input[3] &= ~(1 << 2);
		goto node1742;
	}
node6041:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node4316;
	} else {
		input[3] &= ~(1 << 2);
		goto node1599;
	}
node8984:
	b = randbool();
	if (b) {
		input[1] |= (1 << 2);
		goto node1926;
	} else {
		input[1] &= ~(1 << 2);
		return 2;
	}
node4170:
	b = true;
	if (b) {
		input[1] |= (1 << 1);
		goto node7427;
	} else {
		input[1] &= ~(1 << 1);
		return 0;
	}
node1245:
	b = true;
	if (b) {
		input[3] |= (1 << 7);
		goto node5607;
	} else {
		input[3] &= ~(1 << 7);
		return 0;
	}
node9113:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node3672;
	}
node8917:
	b = true;
	if (b) {
		input[4] |= (1 << 3);
		goto node3942;
	} else {
		input[4] &= ~(1 << 3);
		return 0;
	}
node5995:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node8824;
	} else {
		input[3] &= ~(1 << 7);
		goto node4755;
	}
node5445:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node5099;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node7932:
	b = false;
	if (b) {
		input[3] |= (1 << 2);
		return 0;
	} else {
		input[3] &= ~(1 << 2);
		goto node5492;
	}
node6883:
	b = false;
	if (b) {
		input[4] |= (1 << 5);
		return 0;
	} else {
		input[4] &= ~(1 << 5);
		goto node2900;
	}
node4094:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node2831;
	} else {
		input[2] &= ~(1 << 5);
		goto node8483;
	}
node6553:
	b = false;
	if (b) {
		input[3] |= (1 << 7);
		return 0;
	} else {
		input[3] &= ~(1 << 7);
		goto node586;
	}
node2825:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node3989;
	} else {
		input[3] &= ~(1 << 7);
		goto node8188;
	}
node2391:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node8620;
	} else {
		input[3] &= ~(1 << 5);
		goto node1195;
	}
node4718:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node8777;
	} else {
		input[3] &= ~(1 << 4);
		goto node7591;
	}
node8923:
	b = false;
	if (b) {
		input[2] |= (1 << 3);
		return 0;
	} else {
		input[2] &= ~(1 << 3);
		goto node8831;
	}
node1014:
	b = randbool();
	if (b) {
		input[1] |= (1 << 0);
		goto node4125;
	} else {
		input[1] &= ~(1 << 0);
		goto node9345;
	}
node2669:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node7148;
	} else {
		input[3] &= ~(1 << 5);
		goto node7421;
	}
node3787:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node2722;
	} else {
		input[3] &= ~(1 << 3);
		goto node2610;
	}
node8226:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node165;
	} else {
		input[2] &= ~(1 << 4);
		goto node1226;
	}
node5404:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node8771;
	} else {
		input[2] &= ~(1 << 2);
		goto node847;
	}
node6822:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node254;
	} else {
		input[3] &= ~(1 << 3);
		goto node7581;
	}
node1649:
	b = randbool();
	if (b) {
		input[5] |= (1 << 7);
		goto node2673;
	} else {
		input[5] &= ~(1 << 7);
		goto node1669;
	}
node3720:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node2676;
	} else {
		input[2] &= ~(1 << 3);
		goto node3358;
	}
node3188:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node1114;
	} else {
		input[3] &= ~(1 << 5);
		goto node4741;
	}
node6059:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node8406;
	}
node6420:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node5356;
	}
node438:
	b = true;
	if (b) {
		input[3] |= (1 << 2);
		goto node4329;
	} else {
		input[3] &= ~(1 << 2);
		return 0;
	}
node4498:
	b = false;
	if (b) {
		input[4] |= (1 << 7);
		return 0;
	} else {
		input[4] &= ~(1 << 7);
		goto node5640;
	}
node1233:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node7668;
	}
node7017:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node6684;
	} else {
		input[2] &= ~(1 << 1);
		goto node4151;
	}
node3387:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node6902;
	} else {
		input[3] &= ~(1 << 5);
		goto node1506;
	}
node7341:
	b = randbool();
	if (b) {
		input[1] |= (1 << 0);
		return 2;
	} else {
		input[1] &= ~(1 << 0);
		goto node6186;
	}
node6188:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node5916;
	} else {
		input[3] &= ~(1 << 6);
		goto node5313;
	}
node2111:
	b = true;
	if (b) {
		input[4] |= (1 << 6);
		goto node237;
	} else {
		input[4] &= ~(1 << 6);
		return 0;
	}
node3629:
	b = false;
	if (b) {
		input[2] |= (1 << 2);
		return 0;
	} else {
		input[2] &= ~(1 << 2);
		goto node6371;
	}
node3154:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node3583;
	} else {
		input[3] &= ~(1 << 7);
		goto node4959;
	}
node8122:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node9058;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node8031:
	b = true;
	if (b) {
		input[2] |= (1 << 3);
		goto node4786;
	} else {
		input[2] &= ~(1 << 3);
		return 0;
	}
node3933:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node2883;
	} else {
		input[3] &= ~(1 << 7);
		goto node527;
	}
node992:
	b = randbool();
	if (b) {
		input[1] |= (1 << 4);
		goto node8047;
	} else {
		input[1] &= ~(1 << 4);
		goto node3144;
	}
node7471:
	b = false;
	if (b) {
		input[2] |= (1 << 0);
		return 0;
	} else {
		input[2] &= ~(1 << 0);
		goto node7898;
	}
node791:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node6504;
	}
node8422:
	b = true;
	if (b) {
		input[4] |= (1 << 5);
		goto node5449;
	} else {
		input[4] &= ~(1 << 5);
		return 0;
	}
node2355:
	b = true;
	if (b) {
		input[4] |= (1 << 2);
		goto node6185;
	} else {
		input[4] &= ~(1 << 2);
		return 0;
	}
node4090:
	b = randbool();
	if (b) {
		input[2] |= (1 << 7);
		goto node5820;
	} else {
		input[2] &= ~(1 << 7);
		goto node1178;
	}
node8336:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node709;
	} else {
		input[2] &= ~(1 << 4);
		goto node8727;
	}
node5788:
	b = false;
	if (b) {
		input[2] |= (1 << 0);
		return 0;
	} else {
		input[2] &= ~(1 << 0);
		goto node5825;
	}
node7941:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node901;
	} else {
		input[3] &= ~(1 << 7);
		goto node8133;
	}
node7607:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node1952;
	} else {
		input[3] &= ~(1 << 7);
		goto node8979;
	}
node374:
	b = randbool();
	if (b) {
		input[4] |= (1 << 5);
		goto node674;
	} else {
		input[4] &= ~(1 << 5);
		goto node2513;
	}
node1447:
	b = randbool();
	if (b) {
		input[1] |= (1 << 7);
		goto node6459;
	} else {
		input[1] &= ~(1 << 7);
		goto node1629;
	}
node4040:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node6536;
	} else {
		input[2] &= ~(1 << 4);
		goto node7325;
	}
node4568:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node718;
	} else {
		input[2] &= ~(1 << 2);
		goto node1709;
	}
node2686:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node1661;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node7933:
	b = randbool();
	if (b) {
		input[3] |= (1 << 0);
		return 6;
	} else {
		input[3] &= ~(1 << 0);
		goto node7678;
	}
node2102:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node7702;
	} else {
		input[3] &= ~(1 << 7);
		goto node2201;
	}
node7910:
	b = false;
	if (b) {
		input[3] |= (1 << 7);
		return 0;
	} else {
		input[3] &= ~(1 << 7);
		goto node5095;
	}
node246:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node3119;
	} else {
		input[3] &= ~(1 << 6);
		goto node856;
	}
node7864:
	b = true;
	if (b) {
		input[3] |= (1 << 6);
		goto node5726;
	} else {
		input[3] &= ~(1 << 6);
		return 0;
	}
node5602:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node7441;
	}
node3279:
	b = randbool();
	if (b) {
		input[2] |= (1 << 0);
		goto node2187;
	} else {
		input[2] &= ~(1 << 0);
		goto node7872;
	}
node3740:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node755;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node1531:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node5961;
	}
node177:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node7893;
	} else {
		input[3] &= ~(1 << 2);
		goto node2384;
	}
node5570:
	b = false;
	if (b) {
		input[4] |= (1 << 1);
		return 0;
	} else {
		input[4] &= ~(1 << 1);
		goto node7576;
	}
node7968:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node3047;
	} else {
		input[3] &= ~(1 << 7);
		goto node7270;
	}
node409:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node8157;
	} else {
		input[3] &= ~(1 << 2);
		goto node1028;
	}
node8567:
	b = false;
	if (b) {
		input[4] |= (1 << 5);
		return 0;
	} else {
		input[4] &= ~(1 << 5);
		goto node1611;
	}
node8729:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node4113;
	}
node1996:
	b = randbool();
	if (b) {
		input[2] |= (1 << 0);
		goto node8880;
	} else {
		input[2] &= ~(1 << 0);
		goto node9183;
	}
node908:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node1466;
	}
node3777:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node870;
	} else {
		input[3] &= ~(1 << 4);
		goto node7970;
	}
node3003:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node5962;
	}
node4303:
	b = randbool();
	if (b) {
		input[1] |= (1 << 5);
		goto node8918;
	} else {
		input[1] &= ~(1 << 5);
		goto node6125;
	}
node1256:
	b = false;
	if (b) {
		input[2] |= (1 << 0);
		return 0;
	} else {
		input[2] &= ~(1 << 0);
		goto node8239;
	}
node7561:
	b = true;
	if (b) {
		input[3] |= (1 << 6);
		goto node9473;
	} else {
		input[3] &= ~(1 << 6);
		return 0;
	}
node3318:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node4598;
	} else {
		input[3] &= ~(1 << 4);
		goto node2292;
	}
node7265:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node9369;
	}
node2646:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node8157;
	} else {
		input[3] &= ~(1 << 2);
		goto node3520;
	}
node8887:
	b = randbool();
	if (b) {
		input[1] |= (1 << 1);
		goto node5343;
	} else {
		input[1] &= ~(1 << 1);
		goto node4691;
	}
node3179:
	b = randbool();
	if (b) {
		input[2] |= (1 << 7);
		goto node1347;
	} else {
		input[2] &= ~(1 << 7);
		goto node2953;
	}
node5414:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		goto node7705;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node7312:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node8755;
	} else {
		input[3] &= ~(1 << 6);
		goto node5106;
	}
node1908:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node7557;
	}
node175:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node8776;
	} else {
		input[3] &= ~(1 << 4);
		goto node7339;
	}
node8125:
	b = false;
	if (b) {
		input[6] |= (1 << 0);
		return 0;
	} else {
		input[6] &= ~(1 << 0);
		return 7;
	}
node2704:
	b = randbool();
	if (b) {
		input[1] |= (1 << 6);
		goto node4461;
	} else {
		input[1] &= ~(1 << 6);
		goto node6942;
	}
node5836:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node1516;
	} else {
		input[2] &= ~(1 << 5);
		goto node2130;
	}
node8166:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node2023;
	} else {
		input[2] &= ~(1 << 4);
		goto node6323;
	}
node3501:
	b = false;
	if (b) {
		input[2] |= (1 << 2);
		return 0;
	} else {
		input[2] &= ~(1 << 2);
		goto node4602;
	}
node8727:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node4659;
	} else {
		input[2] &= ~(1 << 2);
		goto node2135;
	}
node1083:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node2911;
	} else {
		input[3] &= ~(1 << 4);
		goto node2021;
	}
node64:
	b = randbool();
	if (b) {
		input[1] |= (1 << 3);
		goto node2411;
	} else {
		input[1] &= ~(1 << 3);
		goto node4142;
	}
node6380:
	b = randbool();
	if (b) {
		input[1] |= (1 << 2);
		goto node946;
	} else {
		input[1] &= ~(1 << 2);
		goto node7792;
	}
node4830:
	b = false;
	if (b) {
		input[2] |= (1 << 7);
		return 0;
	} else {
		input[2] &= ~(1 << 7);
		goto node4956;
	}
node1060:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node5239;
	} else {
		input[3] &= ~(1 << 6);
		goto node226;
	}
node2907:
	b = randbool();
	if (b) {
		input[3] |= (1 << 1);
		return 4;
	} else {
		input[3] &= ~(1 << 1);
		goto node3147;
	}
node5840:
	b = randbool();
	if (b) {
		input[1] |= (1 << 5);
		goto node7086;
	} else {
		input[1] &= ~(1 << 5);
		goto node4257;
	}
node6142:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node4202;
	} else {
		input[2] &= ~(1 << 4);
		goto node3173;
	}
node4226:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node2336;
	} else {
		input[3] &= ~(1 << 6);
		goto node5046;
	}
node1610:
	b = true;
	if (b) {
		input[4] |= (1 << 3);
		goto node3013;
	} else {
		input[4] &= ~(1 << 3);
		return 0;
	}
node1679:
	b = randbool();
	if (b) {
		input[2] |= (1 << 0);
		goto node577;
	} else {
		input[2] &= ~(1 << 0);
		goto node5433;
	}
node3963:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node633;
	} else {
		input[3] &= ~(1 << 3);
		goto node7599;
	}
node1252:
	b = true;
	if (b) {
		input[3] |= (1 << 1);
		goto node5604;
	} else {
		input[3] &= ~(1 << 1);
		return 0;
	}
node2338:
	b = false;
	if (b) {
		input[3] |= (1 << 0);
		return 0;
	} else {
		input[3] &= ~(1 << 0);
		goto node5817;
	}
node4232:
	b = true;
	if (b) {
		input[4] |= (1 << 2);
		goto node9430;
	} else {
		input[4] &= ~(1 << 2);
		return 0;
	}
node2099:
	b = false;
	if (b) {
		input[5] |= (1 << 0);
		return 0;
	} else {
		input[5] &= ~(1 << 0);
		goto node2092;
	}
node6736:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node6196;
	} else {
		input[2] &= ~(1 << 2);
		return 3;
	}
node1882:
	b = false;
	if (b) {
		input[2] |= (1 << 2);
		return 0;
	} else {
		input[2] &= ~(1 << 2);
		goto node6826;
	}
node6756:
	b = true;
	if (b) {
		input[2] |= (1 << 2);
		goto node5248;
	} else {
		input[2] &= ~(1 << 2);
		return 0;
	}
node21:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node5585;
	} else {
		input[3] &= ~(1 << 5);
		goto node7221;
	}
node5764:
	b = false;
	if (b) {
		input[3] |= (1 << 2);
		return 0;
	} else {
		input[3] &= ~(1 << 2);
		goto node1126;
	}
node7212:
	b = randbool();
	if (b) {
		input[3] |= (1 << 0);
		goto node137;
	} else {
		input[3] &= ~(1 << 0);
		goto node4682;
	}
node6651:
	b = true;
	if (b) {
		input[5] |= (1 << 2);
		goto node811;
	} else {
		input[5] &= ~(1 << 2);
		return 0;
	}
node5119:
	b = randbool();
	if (b) {
		input[1] |= (1 << 2);
		goto node7205;
	} else {
		input[1] &= ~(1 << 2);
		goto node2511;
	}
node5231:
	b = randbool();
	if (b) {
		input[1] |= (1 << 0);
		goto node1670;
	} else {
		input[1] &= ~(1 << 0);
		goto node8195;
	}
node4508:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node22;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node1043:
	b = true;
	if (b) {
		input[4] |= (1 << 5);
		goto node9381;
	} else {
		input[4] &= ~(1 << 5);
		return 0;
	}
node8181:
	b = true;
	if (b) {
		input[4] |= (1 << 0);
		goto node6994;
	} else {
		input[4] &= ~(1 << 0);
		return 0;
	}
node7340:
	b = true;
	if (b) {
		input[5] |= (1 << 5);
		goto node8893;
	} else {
		input[5] &= ~(1 << 5);
		return 0;
	}
node8170:
	b = false;
	if (b) {
		input[2] |= (1 << 3);
		return 0;
	} else {
		input[2] &= ~(1 << 3);
		goto node8479;
	}
node4379:
	b = false;
	if (b) {
		input[3] |= (1 << 6);
		return 0;
	} else {
		input[3] &= ~(1 << 6);
		goto node919;
	}
node2225:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node548;
	} else {
		input[3] &= ~(1 << 5);
		goto node5755;
	}
node6992:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node9239;
	}
node424:
	b = true;
	if (b) {
		input[3] |= (1 << 2);
		goto node8921;
	} else {
		input[3] &= ~(1 << 2);
		return 0;
	}
node4444:
	b = false;
	if (b) {
		input[3] |= (1 << 0);
		return 0;
	} else {
		input[3] &= ~(1 << 0);
		goto node6462;
	}
node9261:
	b = true;
	if (b) {
		input[3] |= (1 << 0);
		goto node7774;
	} else {
		input[3] &= ~(1 << 0);
		return 0;
	}
node675:
	b = randbool();
	if (b) {
		input[4] |= (1 << 0);
		return 10;
	} else {
		input[4] &= ~(1 << 0);
		return 6;
	}
node3487:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node7887;
	} else {
		input[2] &= ~(1 << 2);
		goto node117;
	}
node4972:
	b = false;
	if (b) {
		input[3] |= (1 << 0);
		return 0;
	} else {
		input[3] &= ~(1 << 0);
		goto node740;
	}
node3334:
	b = false;
	if (b) {
		input[4] |= (1 << 7);
		return 0;
	} else {
		input[4] &= ~(1 << 7);
		goto node3882;
	}
node6247:
	b = randbool();
	if (b) {
		input[1] |= (1 << 5);
		goto node6526;
	} else {
		input[1] &= ~(1 << 5);
		goto node7086;
	}
node3852:
	b = randbool();
	if (b) {
		input[1] |= (1 << 4);
		goto node4175;
	} else {
		input[1] &= ~(1 << 4);
		goto node9276;
	}
node5498:
	b = false;
	if (b) {
		input[1] |= (1 << 2);
		return 0;
	} else {
		input[1] &= ~(1 << 2);
		goto node5479;
	}
node5164:
	b = randbool();
	if (b) {
		input[1] |= (1 << 2);
		goto node6787;
	} else {
		input[1] &= ~(1 << 2);
		goto node2511;
	}
node88:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node2137;
	}
node7759:
	b = true;
	if (b) {
		input[5] |= (1 << 2);
		goto node7770;
	} else {
		input[5] &= ~(1 << 2);
		return 0;
	}
node7571:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node7019;
	} else {
		input[3] &= ~(1 << 5);
		goto node1424;
	}
node7591:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node8777;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node8573:
	b = true;
	if (b) {
		input[3] |= (1 << 2);
		goto node1263;
	} else {
		input[3] &= ~(1 << 2);
		return 0;
	}
node310:
	b = randbool();
	if (b) {
		input[3] |= (1 << 1);
		goto node7808;
	} else {
		input[3] &= ~(1 << 1);
		goto node3442;
	}
node320:
	b = true;
	if (b) {
		input[3] |= (1 << 0);
		goto node4052;
	} else {
		input[3] &= ~(1 << 0);
		return 0;
	}
node5557:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node5162;
	} else {
		input[3] &= ~(1 << 4);
		goto node5954;
	}
node5598:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node810;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node7427:
	b = randbool();
	if (b) {
		input[1] |= (1 << 0);
		goto node5388;
	} else {
		input[1] &= ~(1 << 0);
		goto node4011;
	}
node7760:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node2556;
	} else {
		input[2] &= ~(1 << 5);
		goto node4751;
	}
node2425:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		goto node5656;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node8383:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node483;
	} else {
		input[3] &= ~(1 << 7);
		goto node7214;
	}
node1205:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node8509;
	} else {
		input[3] &= ~(1 << 7);
		goto node9162;
	}
node8163:
	b = true;
	if (b) {
		input[3] |= (1 << 6);
		goto node6726;
	} else {
		input[3] &= ~(1 << 6);
		return 0;
	}
node4135:
	b = randbool();
	if (b) {
		input[3] |= (1 << 1);
		goto node3808;
	} else {
		input[3] &= ~(1 << 1);
		goto node6220;
	}
node6486:
	b = true;
	if (b) {
		input[5] |= (1 << 3);
		goto node1753;
	} else {
		input[5] &= ~(1 << 3);
		return 0;
	}
node7403:
	b = false;
	if (b) {
		input[2] |= (1 << 1);
		return 0;
	} else {
		input[2] &= ~(1 << 1);
		goto node7073;
	}
node5341:
	b = true;
	if (b) {
		input[3] |= (1 << 6);
		goto node2559;
	} else {
		input[3] &= ~(1 << 6);
		return 0;
	}
node3688:
	b = randbool();
	if (b) {
		input[1] |= (1 << 2);
		goto node7529;
	} else {
		input[1] &= ~(1 << 2);
		goto node2511;
	}
node7653:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node8145;
	} else {
		input[2] &= ~(1 << 6);
		goto node689;
	}
node4296:
	b = false;
	if (b) {
		input[2] |= (1 << 5);
		return 0;
	} else {
		input[2] &= ~(1 << 5);
		goto node7329;
	}
node2322:
	b = false;
	if (b) {
		input[2] |= (1 << 3);
		return 0;
	} else {
		input[2] &= ~(1 << 3);
		goto node2008;
	}
node5899:
	b = false;
	if (b) {
		input[2] |= (1 << 2);
		return 0;
	} else {
		input[2] &= ~(1 << 2);
		goto node641;
	}
node5953:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		goto node3139;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node9434:
	b = false;
	if (b) {
		input[5] |= (1 << 0);
		return 0;
	} else {
		input[5] &= ~(1 << 0);
		goto node8202;
	}
node9399:
	b = randbool();
	if (b) {
		input[6] |= (1 << 6);
		goto node9051;
	} else {
		input[6] &= ~(1 << 6);
		goto node5443;
	}
node6019:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node1343;
	} else {
		input[3] &= ~(1 << 5);
		goto node6441;
	}
node8390:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node5622;
	}
node376:
	b = true;
	if (b) {
		input[3] |= (1 << 2);
		goto node9153;
	} else {
		input[3] &= ~(1 << 2);
		return 0;
	}
node8527:
	b = randbool();
	if (b) {
		input[4] |= (1 << 6);
		goto node4393;
	} else {
		input[4] &= ~(1 << 6);
		goto node2562;
	}
node138:
	b = true;
	if (b) {
		input[4] |= (1 << 5);
		goto node6516;
	} else {
		input[4] &= ~(1 << 5);
		return 0;
	}
node1539:
	b = randbool();
	if (b) {
		input[4] |= (1 << 3);
		goto node1720;
	} else {
		input[4] &= ~(1 << 3);
		goto node3661;
	}
node1762:
	b = randbool();
	if (b) {
		input[0] |= (1 << 1);
		return 1;
	} else {
		input[0] &= ~(1 << 1);
		goto node6591;
	}
node8575:
	b = randbool();
	if (b) {
		input[1] |= (1 << 6);
		goto node7853;
	} else {
		input[1] &= ~(1 << 6);
		goto node6782;
	}
node9000:
	b = false;
	if (b) {
		input[2] |= (1 << 1);
		return 0;
	} else {
		input[2] &= ~(1 << 1);
		goto node6371;
	}
node9420:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node2035;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node4563:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node5717;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node6836:
	b = randbool();
	if (b) {
		input[3] |= (1 << 0);
		return 8;
	} else {
		input[3] &= ~(1 << 0);
		return 4;
	}
node6937:
	b = true;
	if (b) {
		input[2] |= (1 << 5);
		goto node8448;
	} else {
		input[2] &= ~(1 << 5);
		return 0;
	}
node794:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		return 4;
	}
node1729:
	b = randbool();
	if (b) {
		input[4] |= (1 << 7);
		goto node5408;
	} else {
		input[4] &= ~(1 << 7);
		goto node3870;
	}
node4996:
	b = randbool();
	if (b) {
		input[4] |= (1 << 3);
		goto node1720;
	} else {
		input[4] &= ~(1 << 3);
		goto node8974;
	}
node9003:
	b = randbool();
	if (b) {
		input[3] |= (1 << 1);
		goto node1183;
	} else {
		input[3] &= ~(1 << 1);
		goto node8480;
	}
node3565:
	b = true;
	if (b) {
		input[4] |= (1 << 5);
		goto node2804;
	} else {
		input[4] &= ~(1 << 5);
		return 0;
	}
node4909:
	b = true;
	if (b) {
		input[2] |= (1 << 7);
		goto node7506;
	} else {
		input[2] &= ~(1 << 7);
		return 0;
	}
node5619:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node8702;
	} else {
		input[2] &= ~(1 << 4);
		goto node3100;
	}
node3826:
	b = true;
	if (b) {
		input[2] |= (1 << 2);
		goto node7279;
	} else {
		input[2] &= ~(1 << 2);
		return 0;
	}
node2136:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node8914;
	} else {
		input[3] &= ~(1 << 7);
		goto node9281;
	}
node1240:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node3219;
	}
node8772:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node7251;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node9448:
	b = randbool();
	if (b) {
		input[1] |= (1 << 5);
		return 2;
	} else {
		input[1] &= ~(1 << 5);
		goto node6548;
	}
node5132:
	b = true;
	if (b) {
		input[2] |= (1 << 7);
		goto node8690;
	} else {
		input[2] &= ~(1 << 7);
		return 0;
	}
node5481:
	b = false;
	if (b) {
		input[3] |= (1 << 6);
		return 0;
	} else {
		input[3] &= ~(1 << 6);
		goto node7229;
	}
node2859:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node4377;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node2703:
	b = randbool();
	if (b) {
		input[0] |= (1 << 2);
		goto node5293;
	} else {
		input[0] &= ~(1 << 2);
		goto node3955;
	}
node5674:
	b = true;
	if (b) {
		input[1] |= (1 << 1);
		goto node7793;
	} else {
		input[1] &= ~(1 << 1);
		return 0;
	}
node4970:
	b = false;
	if (b) {
		input[2] |= (1 << 3);
		return 0;
	} else {
		input[2] &= ~(1 << 3);
		goto node5976;
	}
node5812:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node4444;
	} else {
		input[3] &= ~(1 << 3);
		goto node8489;
	}
node9189:
	b = randbool();
	if (b) {
		input[5] |= (1 << 6);
		goto node1446;
	} else {
		input[5] &= ~(1 << 6);
		goto node6651;
	}
node2388:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node3723;
	} else {
		input[3] &= ~(1 << 5);
		goto node301;
	}
node1168:
	b = true;
	if (b) {
		input[3] |= (1 << 6);
		goto node3440;
	} else {
		input[3] &= ~(1 << 6);
		return 0;
	}
node4167:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node3453;
	} else {
		input[3] &= ~(1 << 3);
		goto node4864;
	}
node3091:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node2158;
	} else {
		input[3] &= ~(1 << 2);
		goto node137;
	}
node4387:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node7620;
	} else {
		input[3] &= ~(1 << 2);
		return 8;
	}
node4487:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node7765;
	}
node2797:
	b = true;
	if (b) {
		input[3] |= (1 << 1);
		goto node4778;
	} else {
		input[3] &= ~(1 << 1);
		return 0;
	}
node4164:
	b = randbool();
	if (b) {
		input[3] |= (1 << 1);
		goto node7156;
	} else {
		input[3] &= ~(1 << 1);
		goto node1904;
	}
node3651:
	b = true;
	if (b) {
		input[3] |= (1 << 0);
		goto node4340;
	} else {
		input[3] &= ~(1 << 0);
		return 0;
	}
node5757:
	b = false;
	if (b) {
		input[4] |= (1 << 1);
		return 0;
	} else {
		input[4] &= ~(1 << 1);
		goto node8305;
	}
node1597:
	b = true;
	if (b) {
		input[2] |= (1 << 2);
		goto node7344;
	} else {
		input[2] &= ~(1 << 2);
		return 0;
	}
node8748:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node229;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node5744:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node1159;
	} else {
		input[3] &= ~(1 << 4);
		goto node6616;
	}
node7349:
	b = randbool();
	if (b) {
		input[4] |= (1 << 0);
		goto node9168;
	} else {
		input[4] &= ~(1 << 0);
		goto node3019;
	}
node3054:
	b = false;
	if (b) {
		input[4] |= (1 << 0);
		return 0;
	} else {
		input[4] &= ~(1 << 0);
		goto node5947;
	}
node1555:
	b = true;
	if (b) {
		input[2] |= (1 << 3);
		goto node8848;
	} else {
		input[2] &= ~(1 << 3);
		return 0;
	}
node4194:
	b = true;
	if (b) {
		input[4] |= (1 << 1);
		goto node5270;
	} else {
		input[4] &= ~(1 << 1);
		return 0;
	}
node8393:
	b = false;
	if (b) {
		input[6] |= (1 << 0);
		return 0;
	} else {
		input[6] &= ~(1 << 0);
		goto node6368;
	}
node38:
	b = false;
	if (b) {
		input[2] |= (1 << 5);
		return 0;
	} else {
		input[2] &= ~(1 << 5);
		goto node1960;
	}
node9472:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node9362;
	} else {
		input[3] &= ~(1 << 6);
		goto node6874;
	}
node3011:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node1273;
	}
node6267:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node4316;
	} else {
		input[3] &= ~(1 << 2);
		goto node9108;
	}
node2585:
	b = true;
	if (b) {
		input[4] |= (1 << 5);
		goto node5933;
	} else {
		input[4] &= ~(1 << 5);
		return 0;
	}
node4951:
	b = randbool();
	if (b) {
		input[5] |= (1 << 0);
		return 8;
	} else {
		input[5] &= ~(1 << 0);
		goto node2250;
	}
node5418:
	b = false;
	if (b) {
		input[5] |= (1 << 1);
		return 0;
	} else {
		input[5] &= ~(1 << 1);
		goto node2238;
	}
node3839:
	b = randbool();
	if (b) {
		input[0] |= (1 << 1);
		goto node5770;
	} else {
		input[0] &= ~(1 << 1);
		goto node3059;
	}
node8344:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node5052;
	} else {
		input[2] &= ~(1 << 5);
		goto node8737;
	}
node8370:
	b = randbool();
	if (b) {
		input[2] |= (1 << 0);
		goto node5714;
	} else {
		input[2] &= ~(1 << 0);
		goto node4482;
	}
node987:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node1771;
	} else {
		input[3] &= ~(1 << 7);
		goto node2291;
	}
node7377:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node5415;
	}
node3043:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node9254;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node6373:
	b = randbool();
	if (b) {
		input[1] |= (1 << 5);
		goto node1930;
	} else {
		input[1] &= ~(1 << 5);
		goto node4593;
	}
node5885:
	b = randbool();
	if (b) {
		input[1] |= (1 << 2);
		goto node4868;
	} else {
		input[1] &= ~(1 << 2);
		goto node4726;
	}
node9014:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node9018;
	} else {
		input[2] &= ~(1 << 6);
		goto node6426;
	}
node5530:
	b = false;
	if (b) {
		input[4] |= (1 << 1);
		return 0;
	} else {
		input[4] &= ~(1 << 1);
		goto node4987;
	}
node9431:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node5567;
	}
node2433:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node6199;
	} else {
		input[2] &= ~(1 << 2);
		goto node2290;
	}
node8491:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node4976;
	} else {
		input[2] &= ~(1 << 2);
		goto node847;
	}
node8723:
	b = true;
	if (b) {
		input[3] |= (1 << 1);
		goto node4453;
	} else {
		input[3] &= ~(1 << 1);
		return 0;
	}
node6824:
	b = randbool();
	if (b) {
		input[4] |= (1 << 6);
		goto node6934;
	} else {
		input[4] &= ~(1 << 6);
		goto node6129;
	}
node9068:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node4062;
	} else {
		input[2] &= ~(1 << 6);
		goto node5246;
	}
node157:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node9130;
	} else {
		input[2] &= ~(1 << 4);
		goto node807;
	}
node2991:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node7000;
	}
node3049:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node3497;
	} else {
		input[3] &= ~(1 << 4);
		goto node437;
	}
node5503:
	b = false;
	if (b) {
		input[2] |= (1 << 5);
		return 0;
	} else {
		input[2] &= ~(1 << 5);
		goto node849;
	}
node1554:
	b = true;
	if (b) {
		input[2] |= (1 << 5);
		goto node6095;
	} else {
		input[2] &= ~(1 << 5);
		return 0;
	}
node5828:
	b = true;
	if (b) {
		input[2] |= (1 << 2);
		goto node8457;
	} else {
		input[2] &= ~(1 << 2);
		return 0;
	}
node2553:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		goto node6371;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node7226:
	b = randbool();
	if (b) {
		input[2] |= (1 << 0);
		goto node2187;
	} else {
		input[2] &= ~(1 << 0);
		goto node2095;
	}
node387:
	b = false;
	if (b) {
		input[3] |= (1 << 6);
		return 0;
	} else {
		input[3] &= ~(1 << 6);
		goto node4676;
	}
node3155:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node6721;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node8189:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node6600;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node6391:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node1375;
	} else {
		input[3] &= ~(1 << 4);
		goto node9364;
	}
node4405:
	b = randbool();
	if (b) {
		input[2] |= (1 << 7);
		goto node7347;
	} else {
		input[2] &= ~(1 << 7);
		goto node9202;
	}
node1437:
	b = true;
	if (b) {
		input[2] |= (1 << 6);
		goto node402;
	} else {
		input[2] &= ~(1 << 6);
		return 0;
	}
node7210:
	b = false;
	if (b) {
		input[2] |= (1 << 5);
		return 0;
	} else {
		input[2] &= ~(1 << 5);
		goto node3567;
	}
node8485:
	b = false;
	if (b) {
		input[2] |= (1 << 3);
		return 0;
	} else {
		input[2] &= ~(1 << 3);
		goto node5186;
	}
node1284:
	b = randbool();
	if (b) {
		input[2] |= (1 << 0);
		goto node9445;
	} else {
		input[2] &= ~(1 << 0);
		goto node338;
	}
node2796:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node5662;
	}
node5422:
	b = false;
	if (b) {
		input[3] |= (1 << 1);
		return 0;
	} else {
		input[3] &= ~(1 << 1);
		goto node6372;
	}
node9437:
	b = randbool();
	if (b) {
		input[4] |= (1 << 6);
		goto node8422;
	} else {
		input[4] &= ~(1 << 6);
		goto node344;
	}
node8882:
	b = true;
	if (b) {
		input[1] |= (1 << 0);
		goto node5132;
	} else {
		input[1] &= ~(1 << 0);
		return 0;
	}
node202:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node3225;
	} else {
		input[2] &= ~(1 << 4);
		goto node4751;
	}
node7555:
	b = true;
	if (b) {
		input[2] |= (1 << 2);
		goto node3439;
	} else {
		input[2] &= ~(1 << 2);
		return 0;
	}
node4422:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node6439;
	} else {
		input[2] &= ~(1 << 2);
		goto node8780;
	}
node4507:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		return 4;
	} else {
		input[3] &= ~(1 << 5);
		goto node3496;
	}
node771:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node4444;
	} else {
		input[3] &= ~(1 << 3);
		goto node6796;
	}
node7791:
	b = randbool();
	if (b) {
		input[4] |= (1 << 1);
		goto node756;
	} else {
		input[4] &= ~(1 << 1);
		goto node7203;
	}
node2169:
	b = true;
	if (b) {
		input[3] |= (1 << 0);
		goto node290;
	} else {
		input[3] &= ~(1 << 0);
		return 0;
	}
node2007:
	b = randbool();
	if (b) {
		input[1] |= (1 << 6);
		goto node6286;
	} else {
		input[1] &= ~(1 << 6);
		goto node9024;
	}
node1991:
	b = true;
	if (b) {
		input[2] |= (1 << 2);
		goto node5982;
	} else {
		input[2] &= ~(1 << 2);
		return 0;
	}
node6743:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node7192;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node5692:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node1581;
	} else {
		input[3] &= ~(1 << 6);
		goto node8155;
	}
node6949:
	b = true;
	if (b) {
		input[3] |= (1 << 1);
		goto node4109;
	} else {
		input[3] &= ~(1 << 1);
		return 0;
	}
node5241:
	b = true;
	if (b) {
		input[3] |= (1 << 1);
		goto node2170;
	} else {
		input[3] &= ~(1 << 1);
		return 0;
	}
node2667:
	b = true;
	if (b) {
		input[2] |= (1 << 2);
		goto node1227;
	} else {
		input[2] &= ~(1 << 2);
		return 0;
	}
node9331:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node3765;
	} else {
		input[3] &= ~(1 << 4);
		goto node162;
	}
node1159:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node7632;
	}
node2877:
	b = randbool();
	if (b) {
		input[4] |= (1 << 5);
		goto node1326;
	} else {
		input[4] &= ~(1 << 5);
		goto node4169;
	}
node8606:
	b = false;
	if (b) {
		input[2] |= (1 << 5);
		return 0;
	} else {
		input[2] &= ~(1 << 5);
		goto node1804;
	}
node5631:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node5488;
	} else {
		input[2] &= ~(1 << 1);
		goto node8409;
	}
node5345:
	b = false;
	if (b) {
		input[3] |= (1 << 7);
		return 0;
	} else {
		input[3] &= ~(1 << 7);
		goto node4617;
	}
node7570:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node1792;
	} else {
		input[3] &= ~(1 << 6);
		goto node6057;
	}
node3006:
	b = true;
	if (b) {
		input[4] |= (1 << 6);
		goto node928;
	} else {
		input[4] &= ~(1 << 6);
		return 0;
	}
node2193:
	b = randbool();
	if (b) {
		input[4] |= (1 << 6);
		goto node5449;
	} else {
		input[4] &= ~(1 << 6);
		goto node929;
	}
node3967:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node4238;
	} else {
		input[2] &= ~(1 << 6);
		goto node5853;
	}
node203:
	b = false;
	if (b) {
		input[2] |= (1 << 1);
		return 0;
	} else {
		input[2] &= ~(1 << 1);
		goto node7058;
	}
node3799:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node9061;
	} else {
		input[3] &= ~(1 << 7);
		goto node4617;
	}
node4549:
	b = true;
	if (b) {
		input[4] |= (1 << 3);
		goto node4671;
	} else {
		input[4] &= ~(1 << 3);
		return 0;
	}
node2649:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node2299;
	} else {
		input[2] &= ~(1 << 5);
		goto node6517;
	}
node2237:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node6284;
	}
node2628:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node1116;
	}
node2979:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node415;
	} else {
		input[3] &= ~(1 << 3);
		goto node8952;
	}
node2525:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node3520;
	} else {
		input[3] &= ~(1 << 3);
		goto node5023;
	}
node5435:
	b = false;
	if (b) {
		input[4] |= (1 << 4);
		return 0;
	} else {
		input[4] &= ~(1 << 4);
		goto node1057;
	}
node8561:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node6589;
	} else {
		input[3] &= ~(1 << 3);
		goto node3827;
	}
node8035:
	b = randbool();
	if (b) {
		input[1] |= (1 << 1);
		goto node8894;
	} else {
		input[1] &= ~(1 << 1);
		goto node603;
	}
node1998:
	b = randbool();
	if (b) {
		input[1] |= (1 << 0);
		goto node6186;
	} else {
		input[1] &= ~(1 << 0);
		goto node6906;
	}
node8636:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node7498;
	} else {
		input[2] &= ~(1 << 2);
		goto node847;
	}
node6927:
	b = randbool();
	if (b) {
		input[3] |= (1 << 1);
		goto node8574;
	} else {
		input[3] &= ~(1 << 1);
		goto node6462;
	}
node8911:
	b = false;
	if (b) {
		input[4] |= (1 << 7);
		return 0;
	} else {
		input[4] &= ~(1 << 7);
		goto node9064;
	}
node2947:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node208;
	} else {
		input[2] &= ~(1 << 5);
		goto node4919;
	}
node2408:
	b = true;
	if (b) {
		input[3] |= (1 << 2);
		goto node2493;
	} else {
		input[3] &= ~(1 << 2);
		return 0;
	}
node7956:
	b = false;
	if (b) {
		input[3] |= (1 << 1);
		return 0;
	} else {
		input[3] &= ~(1 << 1);
		goto node1095;
	}
node6509:
	b = randbool();
	if (b) {
		input[4] |= (1 << 1);
		goto node2352;
	} else {
		input[4] &= ~(1 << 1);
		goto node8082;
	}
node5284:
	b = randbool();
	if (b) {
		input[1] |= (1 << 5);
		goto node8669;
	} else {
		input[1] &= ~(1 << 5);
		goto node3300;
	}
node8979:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node4028;
	} else {
		input[3] &= ~(1 << 6);
		goto node2487;
	}
node1345:
	b = true;
	if (b) {
		input[3] |= (1 << 2);
		goto node107;
	} else {
		input[3] &= ~(1 << 2);
		return 0;
	}
node1271:
	b = false;
	if (b) {
		input[2] |= (1 << 7);
		return 0;
	} else {
		input[2] &= ~(1 << 7);
		goto node4085;
	}
node552:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node8097;
	} else {
		input[2] &= ~(1 << 4);
		goto node7655;
	}
node8709:
	b = true;
	if (b) {
		input[3] |= (1 << 6);
		goto node7483;
	} else {
		input[3] &= ~(1 << 6);
		return 0;
	}
node8360:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node4643;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node8595:
	b = false;
	if (b) {
		input[1] |= (1 << 4);
		return 0;
	} else {
		input[1] &= ~(1 << 4);
		goto node935;
	}
node4632:
	b = false;
	if (b) {
		input[2] |= (1 << 5);
		return 0;
	} else {
		input[2] &= ~(1 << 5);
		goto node3641;
	}
node8543:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node2040;
	} else {
		input[2] &= ~(1 << 4);
		goto node3444;
	}
node4224:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node1911;
	} else {
		input[2] &= ~(1 << 1);
		goto node1077;
	}
node2882:
	b = true;
	if (b) {
		input[3] |= (1 << 7);
		goto node5045;
	} else {
		input[3] &= ~(1 << 7);
		return 0;
	}
node7775:
	b = randbool();
	if (b) {
		input[4] |= (1 << 4);
		goto node4902;
	} else {
		input[4] &= ~(1 << 4);
		return 5;
	}
node775:
	b = randbool();
	if (b) {
		input[2] |= (1 << 7);
		goto node584;
	} else {
		input[2] &= ~(1 << 7);
		goto node4874;
	}
node3631:
	b = false;
	if (b) {
		input[3] |= (1 << 1);
		return 0;
	} else {
		input[3] &= ~(1 << 1);
		goto node5604;
	}
node3238:
	b = false;
	if (b) {
		input[4] |= (1 << 7);
		return 0;
	} else {
		input[4] &= ~(1 << 7);
		goto node5999;
	}
node2122:
	b = randbool();
	if (b) {
		input[5] |= (1 << 7);
		goto node4616;
	} else {
		input[5] &= ~(1 << 7);
		goto node5271;
	}
node6841:
	b = false;
	if (b) {
		input[4] |= (1 << 5);
		return 0;
	} else {
		input[4] &= ~(1 << 5);
		goto node4499;
	}
node4726:
	b = randbool();
	if (b) {
		input[1] |= (1 << 1);
		goto node2690;
	} else {
		input[1] &= ~(1 << 1);
		goto node5142;
	}
node1395:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node1501;
	} else {
		input[2] &= ~(1 << 5);
		goto node5476;
	}
node3200:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		goto node350;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node4306:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node7062;
	} else {
		input[3] &= ~(1 << 6);
		goto node7109;
	}
node4057:
	b = false;
	if (b) {
		input[3] |= (1 << 1);
		return 0;
	} else {
		input[3] &= ~(1 << 1);
		goto node3913;
	}
node5408:
	b = randbool();
	if (b) {
		input[4] |= (1 << 6);
		goto node374;
	} else {
		input[4] &= ~(1 << 6);
		goto node8401;
	}
node6868:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node6615;
	}
node8577:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node5851;
	} else {
		input[3] &= ~(1 << 7);
		goto node2466;
	}
node3028:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node7903;
	} else {
		input[3] &= ~(1 << 6);
		goto node212;
	}
node2147:
	b = true;
	if (b) {
		input[3] |= (1 << 1);
		goto node3590;
	} else {
		input[3] &= ~(1 << 1);
		return 0;
	}
node7416:
	b = true;
	if (b) {
		input[4] |= (1 << 1);
		goto node7485;
	} else {
		input[4] &= ~(1 << 1);
		return 0;
	}
node6735:
	b = false;
	if (b) {
		input[2] |= (1 << 5);
		return 0;
	} else {
		input[2] &= ~(1 << 5);
		goto node6496;
	}
node3510:
	b = false;
	if (b) {
		input[2] |= (1 << 2);
		return 0;
	} else {
		input[2] &= ~(1 << 2);
		goto node6166;
	}
node6588:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node1163;
	} else {
		input[3] &= ~(1 << 6);
		goto node2845;
	}
node1390:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node1159;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node644:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node6540;
	}
node6133:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node596;
	} else {
		input[3] &= ~(1 << 4);
		goto node2584;
	}
node1659:
	b = randbool();
	if (b) {
		input[1] |= (1 << 3);
		goto node8629;
	} else {
		input[1] &= ~(1 << 3);
		goto node7856;
	}
node7081:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node2429;
	} else {
		input[2] &= ~(1 << 3);
		goto node7887;
	}
node7401:
	b = true;
	if (b) {
		input[2] |= (1 << 3);
		goto node6555;
	} else {
		input[2] &= ~(1 << 3);
		return 0;
	}
node184:
	b = false;
	if (b) {
		input[2] |= (1 << 7);
		return 0;
	} else {
		input[2] &= ~(1 << 7);
		goto node3306;
	}
node4369:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node938;
	} else {
		input[2] &= ~(1 << 3);
		goto node8272;
	}
node6276:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node1878;
	}
node1518:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node794;
	} else {
		input[3] &= ~(1 << 4);
		return 4;
	}
node7769:
	b = randbool();
	if (b) {
		input[4] |= (1 << 1);
		return 5;
	} else {
		input[4] &= ~(1 << 1);
		goto node3793;
	}
node4374:
	b = true;
	if (b) {
		input[2] |= (1 << 5);
		goto node2913;
	} else {
		input[2] &= ~(1 << 5);
		return 0;
	}
node2038:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node633;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node8785:
	b = false;
	if (b) {
		input[3] |= (1 << 1);
		return 0;
	} else {
		input[3] &= ~(1 << 1);
		goto node2812;
	}
node8481:
	b = true;
	if (b) {
		input[4] |= (1 << 1);
		goto node2808;
	} else {
		input[4] &= ~(1 << 1);
		return 0;
	}
node1142:
	b = randbool();
	if (b) {
		input[1] |= (1 << 2);
		goto node2511;
	} else {
		input[1] &= ~(1 << 2);
		goto node561;
	}
node4737:
	b = false;
	if (b) {
		input[2] |= (1 << 6);
		return 0;
	} else {
		input[2] &= ~(1 << 6);
		goto node6141;
	}
node3752:
	b = true;
	if (b) {
		input[2] |= (1 << 2);
		goto node3511;
	} else {
		input[2] &= ~(1 << 2);
		return 0;
	}
node4014:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node3951;
	} else {
		input[3] &= ~(1 << 7);
		goto node6339;
	}
node3710:
	b = randbool();
	if (b) {
		input[3] |= (1 << 1);
		return 4;
	} else {
		input[3] &= ~(1 << 1);
		goto node1642;
	}
node7373:
	b = randbool();
	if (b) {
		input[4] |= (1 << 6);
		goto node766;
	} else {
		input[4] &= ~(1 << 6);
		goto node7753;
	}
node1080:
	b = randbool();
	if (b) {
		input[1] |= (1 << 3);
		return 6;
	} else {
		input[1] &= ~(1 << 3);
		return 3;
	}
node4787:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		goto node8338;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node9249:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node1787;
	} else {
		input[3] &= ~(1 << 7);
		goto node7270;
	}
node3488:
	b = false;
	if (b) {
		input[3] |= (1 << 1);
		return 0;
	} else {
		input[3] &= ~(1 << 1);
		goto node3442;
	}
node7550:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node5188;
	} else {
		input[3] &= ~(1 << 5);
		goto node3909;
	}
node9466:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		goto node3354;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node6799:
	b = false;
	if (b) {
		input[3] |= (1 << 7);
		return 0;
	} else {
		input[3] &= ~(1 << 7);
		goto node7390;
	}
node3147:
	b = false;
	if (b) {
		input[3] |= (1 << 0);
		return 0;
	} else {
		input[3] &= ~(1 << 0);
		goto node6679;
	}
node9389:
	b = true;
	if (b) {
		input[4] |= (1 << 2);
		return 5;
	} else {
		input[4] &= ~(1 << 2);
		return 0;
	}
node8257:
	b = randbool();
	if (b) {
		input[1] |= (1 << 1);
		goto node6306;
	} else {
		input[1] &= ~(1 << 1);
		goto node1377;
	}
node8335:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node5912;
	} else {
		input[2] &= ~(1 << 5);
		goto node9018;
	}
node482:
	b = randbool();
	if (b) {
		input[2] |= (1 << 0);
		goto node4097;
	} else {
		input[2] &= ~(1 << 0);
		goto node3023;
	}
node6843:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node8521;
	} else {
		input[2] &= ~(1 << 6);
		goto node5389;
	}
node5067:
	b = false;
	if (b) {
		input[2] |= (1 << 5);
		return 0;
	} else {
		input[2] &= ~(1 << 5);
		goto node1046;
	}
node9217:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node6674;
	} else {
		input[2] &= ~(1 << 1);
		goto node5792;
	}
node9040:
	b = false;
	if (b) {
		input[4] |= (1 << 4);
		return 0;
	} else {
		input[4] &= ~(1 << 4);
		goto node485;
	}
node2500:
	b = false;
	if (b) {
		input[4] |= (1 << 2);
		return 0;
	} else {
		input[4] &= ~(1 << 2);
		goto node179;
	}
node6608:
	b = false;
	if (b) {
		input[1] |= (1 << 7);
		return 0;
	} else {
		input[1] &= ~(1 << 7);
		goto node4333;
	}
node5618:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node2441;
	} else {
		input[2] &= ~(1 << 6);
		goto node7210;
	}
node9163:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node7218;
	} else {
		input[3] &= ~(1 << 6);
		goto node8658;
	}
node2323:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node4145;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node6036:
	b = randbool();
	if (b) {
		input[3] |= (1 << 1);
		goto node5983;
	} else {
		input[3] &= ~(1 << 1);
		goto node4295;
	}
node3005:
	b = false;
	if (b) {
		input[3] |= (1 << 0);
		return 0;
	} else {
		input[3] &= ~(1 << 0);
		goto node875;
	}
node2653:
	b = randbool();
	if (b) {
		input[1] |= (1 << 7);
		goto node3702;
	} else {
		input[1] &= ~(1 << 7);
		goto node9222;
	}
node3269:
	b = true;
	if (b) {
		input[1] |= (1 << 1);
		goto node3816;
	} else {
		input[1] &= ~(1 << 1);
		return 0;
	}
node3811:
	b = true;
	if (b) {
		input[2] |= (1 << 2);
		goto node2357;
	} else {
		input[2] &= ~(1 << 2);
		return 0;
	}
node1179:
	b = true;
	if (b) {
		input[3] |= (1 << 6);
		goto node4936;
	} else {
		input[3] &= ~(1 << 6);
		return 0;
	}
node2992:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node6829;
	} else {
		input[3] &= ~(1 << 4);
		goto node1840;
	}
node4464:
	b = true;
	if (b) {
		input[4] |= (1 << 1);
		goto node8332;
	} else {
		input[4] &= ~(1 << 1);
		return 0;
	}
node2485:
	b = false;
	if (b) {
		input[2] |= (1 << 5);
		return 0;
	} else {
		input[2] &= ~(1 << 5);
		goto node3364;
	}
node5261:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node6832;
	} else {
		input[2] &= ~(1 << 3);
		goto node3863;
	}
node8809:
	b = randbool();
	if (b) {
		input[2] |= (1 << 0);
		goto node5469;
	} else {
		input[2] &= ~(1 << 0);
		goto node826;
	}
node7970:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node7447;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node5683:
	b = randbool();
	if (b) {
		input[1] |= (1 << 7);
		goto node2591;
	} else {
		input[1] &= ~(1 << 7);
		goto node4454;
	}
node4158:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node45;
	} else {
		input[2] &= ~(1 << 6);
		goto node4544;
	}
node9267:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node1913;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node7139:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node5367;
	}
node8935:
	b = false;
	if (b) {
		input[4] |= (1 << 6);
		return 0;
	} else {
		input[4] &= ~(1 << 6);
		goto node2176;
	}
node6052:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node3398;
	} else {
		input[2] &= ~(1 << 2);
		goto node4076;
	}
node4606:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		goto node8500;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node7415:
	b = true;
	if (b) {
		input[4] |= (1 << 4);
		goto node1584;
	} else {
		input[4] &= ~(1 << 4);
		return 0;
	}
node2200:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node1479;
	} else {
		input[2] &= ~(1 << 5);
		goto node2823;
	}
node1524:
	b = randbool();
	if (b) {
		input[3] |= (1 << 1);
		goto node6462;
	} else {
		input[3] &= ~(1 << 1);
		goto node7156;
	}
node7781:
	b = true;
	if (b) {
		input[3] |= (1 << 1);
		goto node2016;
	} else {
		input[3] &= ~(1 << 1);
		return 0;
	}
node6732:
	b = false;
	if (b) {
		input[3] |= (1 << 1);
		return 0;
	} else {
		input[3] &= ~(1 << 1);
		goto node297;
	}
node2531:
	b = true;
	if (b) {
		input[4] |= (1 << 7);
		goto node256;
	} else {
		input[4] &= ~(1 << 7);
		return 0;
	}
node4612:
	b = randbool();
	if (b) {
		input[1] |= (1 << 2);
		goto node6905;
	} else {
		input[1] &= ~(1 << 2);
		goto node8858;
	}
node6572:
	b = true;
	if (b) {
		input[2] |= (1 << 7);
		goto node1885;
	} else {
		input[2] &= ~(1 << 7);
		return 0;
	}
node7095:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node2433;
	} else {
		input[2] &= ~(1 << 3);
		goto node3665;
	}
node3774:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node367;
	} else {
		input[2] &= ~(1 << 1);
		goto node413;
	}
node3046:
	b = true;
	if (b) {
		input[3] |= (1 << 7);
		goto node390;
	} else {
		input[3] &= ~(1 << 7);
		return 0;
	}
node8915:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node3700;
	}
node4222:
	b = randbool();
	if (b) {
		input[1] |= (1 << 0);
		goto node6809;
	} else {
		input[1] &= ~(1 << 0);
		goto node2019;
	}
node1327:
	b = false;
	if (b) {
		input[2] |= (1 << 7);
		return 0;
	} else {
		input[2] &= ~(1 << 7);
		goto node8022;
	}
node6060:
	b = randbool();
	if (b) {
		input[3] |= (1 << 1);
		goto node5492;
	} else {
		input[3] &= ~(1 << 1);
		goto node1777;
	}
node6078:
	b = randbool();
	if (b) {
		input[1] |= (1 << 5);
		goto node592;
	} else {
		input[1] &= ~(1 << 5);
		goto node7465;
	}
node3919:
	b = randbool();
	if (b) {
		input[1] |= (1 << 0);
		goto node1677;
	} else {
		input[1] &= ~(1 << 0);
		goto node2511;
	}
node5129:
	b = randbool();
	if (b) {
		input[2] |= (1 << 0);
		goto node6033;
	} else {
		input[2] &= ~(1 << 0);
		goto node987;
	}
node3389:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node3650;
	} else {
		input[3] &= ~(1 << 3);
		goto node1169;
	}
node2267:
	b = false;
	if (b) {
		input[3] |= (1 << 2);
		return 0;
	} else {
		input[3] &= ~(1 << 2);
		goto node4311;
	}
node49:
	b = randbool();
	if (b) {
		input[6] |= (1 << 5);
		goto node4658;
	} else {
		input[6] &= ~(1 << 5);
		goto node6261;
	}
node7335:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node1226;
	} else {
		input[2] &= ~(1 << 4);
		goto node3778;
	}
node3025:
	b = true;
	if (b) {
		input[2] |= (1 << 3);
		goto node7555;
	} else {
		input[2] &= ~(1 << 3);
		return 0;
	}
node6027:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node7973;
	} else {
		input[2] &= ~(1 << 2);
		goto node9000;
	}
node7633:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node7101;
	} else {
		input[2] &= ~(1 << 1);
		goto node3603;
	}
node7241:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node5276;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node2576:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node2989;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node2900:
	b = false;
	if (b) {
		input[4] |= (1 << 4);
		return 0;
	} else {
		input[4] &= ~(1 << 4);
		goto node5069;
	}
node1208:
	b = true;
	if (b) {
		input[4] |= (1 << 2);
		goto node7100;
	} else {
		input[4] &= ~(1 << 2);
		return 0;
	}
node1105:
	b = randbool();
	if (b) {
		input[1] |= (1 << 1);
		goto node8581;
	} else {
		input[1] &= ~(1 << 1);
		goto node2690;
	}
node6978:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node8591;
	} else {
		input[2] &= ~(1 << 4);
		goto node7159;
	}
node9062:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node3578;
	} else {
		input[3] &= ~(1 << 7);
		goto node1033;
	}
node8533:
	b = false;
	if (b) {
		input[3] |= (1 << 2);
		return 0;
	} else {
		input[3] &= ~(1 << 2);
		goto node5647;
	}
node2672:
	b = true;
	if (b) {
		input[3] |= (1 << 2);
		goto node137;
	} else {
		input[3] &= ~(1 << 2);
		return 0;
	}
node8777:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node8549;
	} else {
		input[3] &= ~(1 << 2);
		return 4;
	}
node373:
	b = randbool();
	if (b) {
		input[4] |= (1 << 6);
		goto node8327;
	} else {
		input[4] &= ~(1 << 6);
		goto node1781;
	}
node2375:
	b = randbool();
	if (b) {
		input[1] |= (1 << 4);
		goto node7915;
	} else {
		input[1] &= ~(1 << 4);
		goto node7724;
	}
node6414:
	b = randbool();
	if (b) {
		input[3] |= (1 << 0);
		goto node3727;
	} else {
		input[3] &= ~(1 << 0);
		goto node7751;
	}
node5100:
	b = false;
	if (b) {
		input[3] |= (1 << 0);
		return 0;
	} else {
		input[3] &= ~(1 << 0);
		goto node5759;
	}
node6067:
	b = randbool();
	if (b) {
		input[0] |= (1 << 0);
		goto node2730;
	} else {
		input[0] &= ~(1 << 0);
		goto node8557;
	}
node4888:
	b = randbool();
	if (b) {
		input[1] |= (1 << 0);
		goto node7928;
	} else {
		input[1] &= ~(1 << 0);
		goto node7839;
	}
node2445:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node8861;
	} else {
		input[2] &= ~(1 << 5);
		goto node993;
	}
node3759:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node2130;
	} else {
		input[2] &= ~(1 << 5);
		goto node6549;
	}
node1429:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node8024;
	} else {
		input[2] &= ~(1 << 3);
		goto node6779;
	}
node9285:
	b = true;
	if (b) {
		input[1] |= (1 << 6);
		goto node7652;
	} else {
		input[1] &= ~(1 << 6);
		return 0;
	}
node5593:
	b = true;
	if (b) {
		input[2] |= (1 << 7);
		goto node5085;
	} else {
		input[2] &= ~(1 << 7);
		return 0;
	}
node3944:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node1752;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node9407:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node662;
	}
node2813:
	b = true;
	if (b) {
		input[4] |= (1 << 7);
		goto node7718;
	} else {
		input[4] &= ~(1 << 7);
		return 0;
	}
node898:
	b = false;
	if (b) {
		input[5] |= (1 << 1);
		return 0;
	} else {
		input[5] &= ~(1 << 1);
		goto node2099;
	}
node8418:
	b = randbool();
	if (b) {
		input[1] |= (1 << 0);
		goto node1259;
	} else {
		input[1] &= ~(1 << 0);
		goto node7731;
	}
node7181:
	b = true;
	if (b) {
		input[2] |= (1 << 6);
		goto node9069;
	} else {
		input[2] &= ~(1 << 6);
		return 0;
	}
node4248:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node7042;
	}
node288:
	b = true;
	if (b) {
		input[2] |= (1 << 2);
		goto node2632;
	} else {
		input[2] &= ~(1 << 2);
		return 0;
	}
node4792:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node3958;
	} else {
		input[3] &= ~(1 << 6);
		goto node2571;
	}
node6663:
	b = false;
	if (b) {
		input[4] |= (1 << 7);
		return 0;
	} else {
		input[4] &= ~(1 << 7);
		goto node4190;
	}
node1064:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node8525;
	} else {
		input[2] &= ~(1 << 6);
		goto node2312;
	}
node8304:
	b = false;
	if (b) {
		input[3] |= (1 << 7);
		return 0;
	} else {
		input[3] &= ~(1 << 7);
		goto node1125;
	}
node6514:
	b = true;
	if (b) {
		input[4] |= (1 << 6);
		goto node7297;
	} else {
		input[4] &= ~(1 << 6);
		return 0;
	}
node3431:
	b = false;
	if (b) {
		input[4] |= (1 << 4);
		return 0;
	} else {
		input[4] &= ~(1 << 4);
		goto node2471;
	}
node8715:
	b = randbool();
	if (b) {
		input[1] |= (1 << 3);
		goto node6423;
	} else {
		input[1] &= ~(1 << 3);
		goto node5097;
	}
node3751:
	b = false;
	if (b) {
		input[2] |= (1 << 3);
		return 0;
	} else {
		input[2] &= ~(1 << 3);
		goto node7716;
	}
node385:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node6732;
	} else {
		input[3] &= ~(1 << 2);
		goto node6692;
	}
node8978:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node3753;
	} else {
		input[2] &= ~(1 << 4);
		goto node7542;
	}
node2791:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node117;
	} else {
		input[2] &= ~(1 << 1);
		return 3;
	}
node249:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node3244;
	} else {
		input[3] &= ~(1 << 5);
		goto node845;
	}
node3333:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node9032;
	} else {
		input[3] &= ~(1 << 4);
		goto node5448;
	}
node1376:
	b = true;
	if (b) {
		input[7] |= (1 << 2);
		goto node4822;
	} else {
		input[7] &= ~(1 << 2);
		return 0;
	}
node906:
	b = false;
	if (b) {
		input[1] |= (1 << 2);
		return 0;
	} else {
		input[1] &= ~(1 << 2);
		goto node3290;
	}
node5910:
	b = false;
	if (b) {
		input[1] |= (1 << 2);
		return 0;
	} else {
		input[1] &= ~(1 << 2);
		goto node2511;
	}
node1340:
	b = true;
	if (b) {
		input[3] |= (1 << 6);
		goto node1218;
	} else {
		input[3] &= ~(1 << 6);
		return 0;
	}
node6980:
	b = true;
	if (b) {
		input[4] |= (1 << 7);
		goto node5623;
	} else {
		input[4] &= ~(1 << 7);
		return 0;
	}
node2379:
	b = true;
	if (b) {
		input[4] |= (1 << 5);
		goto node8667;
	} else {
		input[4] &= ~(1 << 5);
		return 0;
	}
node5760:
	b = true;
	if (b) {
		input[4] |= (1 << 0);
		goto node5075;
	} else {
		input[4] &= ~(1 << 0);
		return 0;
	}
node7145:
	b = false;
	if (b) {
		input[2] |= (1 << 1);
		return 0;
	} else {
		input[2] &= ~(1 << 1);
		goto node1796;
	}
node1693:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		goto node2686;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node574:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node5022;
	}
node9240:
	b = false;
	if (b) {
		input[3] |= (1 << 0);
		return 0;
	} else {
		input[3] &= ~(1 << 0);
		goto node3728;
	}
node2880:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node2130;
	} else {
		input[2] &= ~(1 << 5);
		goto node5737;
	}
node4832:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node9358;
	}
node5032:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		goto node2540;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node4349:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node2756;
	} else {
		input[3] &= ~(1 << 4);
		goto node9452;
	}
node7500:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node9152;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node5610:
	b = false;
	if (b) {
		input[3] |= (1 << 2);
		return 0;
	} else {
		input[3] &= ~(1 << 2);
		goto node7616;
	}
node2812:
	b = false;
	if (b) {
		input[3] |= (1 << 0);
		return 0;
	} else {
		input[3] &= ~(1 << 0);
		goto node7136;
	}
node1009:
	b = true;
	if (b) {
		input[4] |= (1 << 2);
		goto node5417;
	} else {
		input[4] &= ~(1 << 2);
		return 0;
	}
node7459:
	b = false;
	if (b) {
		input[2] |= (1 << 5);
		return 0;
	} else {
		input[2] &= ~(1 << 5);
		goto node7567;
	}
node278:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node594;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node1509:
	b = true;
	if (b) {
		input[4] |= (1 << 7);
		goto node8445;
	} else {
		input[4] &= ~(1 << 7);
		return 0;
	}
node3275:
	b = randbool();
	if (b) {
		input[4] |= (1 << 2);
		goto node5570;
	} else {
		input[4] &= ~(1 << 2);
		goto node7576;
	}
node3074:
	b = true;
	if (b) {
		input[3] |= (1 << 7);
		goto node6598;
	} else {
		input[3] &= ~(1 << 7);
		return 0;
	}
node4424:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node4022;
	} else {
		input[3] &= ~(1 << 7);
		goto node977;
	}
node265:
	b = randbool();
	if (b) {
		input[0] |= (1 << 4);
		goto node1575;
	} else {
		input[0] &= ~(1 << 4);
		goto node448;
	}
node5847:
	b = randbool();
	if (b) {
		input[1] |= (1 << 6);
		goto node1620;
	} else {
		input[1] &= ~(1 << 6);
		goto node6990;
	}
node4868:
	b = true;
	if (b) {
		input[1] |= (1 << 1);
		goto node4060;
	} else {
		input[1] &= ~(1 << 1);
		return 0;
	}
node6262:
	b = true;
	if (b) {
		input[1] |= (1 << 1);
		goto node801;
	} else {
		input[1] &= ~(1 << 1);
		return 0;
	}
node8807:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node8583;
	} else {
		input[2] &= ~(1 << 6);
		goto node1231;
	}
node1774:
	b = true;
	if (b) {
		input[2] |= (1 << 3);
		goto node5044;
	} else {
		input[2] &= ~(1 << 3);
		return 0;
	}
node704:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node5015;
	} else {
		input[3] &= ~(1 << 5);
		goto node5601;
	}
node2510:
	b = randbool();
	if (b) {
		input[2] |= (1 << 7);
		goto node4297;
	} else {
		input[2] &= ~(1 << 7);
		goto node7929;
	}
node4595:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node7749;
	} else {
		input[3] &= ~(1 << 6);
		goto node3513;
	}
node1836:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node1908;
	} else {
		input[3] &= ~(1 << 6);
		goto node1776;
	}
node978:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node9039;
	} else {
		input[3] &= ~(1 << 5);
		goto node5547;
	}
node1135:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node3032;
	} else {
		input[3] &= ~(1 << 5);
		goto node5693;
	}
node56:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node6267;
	}
node4621:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node8919;
	} else {
		input[2] &= ~(1 << 5);
		goto node4132;
	}
node9096:
	b = false;
	if (b) {
		input[3] |= (1 << 6);
		return 0;
	} else {
		input[3] &= ~(1 << 6);
		goto node5178;
	}
node2089:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node777;
	} else {
		input[3] &= ~(1 << 4);
		goto node8436;
	}
node8635:
	b = true;
	if (b) {
		input[4] |= (1 << 5);
		goto node2478;
	} else {
		input[4] &= ~(1 << 5);
		return 0;
	}
node6874:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node5146;
	} else {
		input[3] &= ~(1 << 5);
		goto node818;
	}
node1400:
	b = true;
	if (b) {
		input[4] |= (1 << 5);
		goto node2072;
	} else {
		input[4] &= ~(1 << 5);
		return 0;
	}
node4000:
	b = true;
	if (b) {
		input[5] |= (1 << 0);
		goto node4666;
	} else {
		input[5] &= ~(1 << 0);
		return 0;
	}
node1527:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node4219;
	} else {
		input[2] &= ~(1 << 6);
		goto node7515;
	}
node9120:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node6975;
	} else {
		input[2] &= ~(1 << 5);
		goto node8166;
	}
node8613:
	b = randbool();
	if (b) {
		input[2] |= (1 << 0);
		return 11;
	} else {
		input[2] &= ~(1 << 0);
		return 7;
	}
node8864:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node536;
	} else {
		input[3] &= ~(1 << 7);
		goto node8939;
	}
node5421:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node6343;
	} else {
		input[3] &= ~(1 << 4);
		goto node777;
	}
node4281:
	b = randbool();
	if (b) {
		input[0] |= (1 << 1);
		goto node8130;
	} else {
		input[0] &= ~(1 << 1);
		goto node4494;
	}
node8535:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node7291;
	} else {
		input[2] &= ~(1 << 6);
		goto node1232;
	}
node1304:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node1945;
	} else {
		input[2] &= ~(1 << 5);
		goto node8131;
	}
node8499:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node7351;
	} else {
		input[2] &= ~(1 << 2);
		goto node6653;
	}
node4607:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		goto node8593;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node7190:
	b = false;
	if (b) {
		input[2] |= (1 << 0);
		return 0;
	} else {
		input[2] &= ~(1 << 0);
		goto node8777;
	}
node7491:
	b = true;
	if (b) {
		input[2] |= (1 << 5);
		goto node1358;
	} else {
		input[2] &= ~(1 << 5);
		return 0;
	}
node6193:
	b = true;
	if (b) {
		input[2] |= (1 << 2);
		goto node7194;
	} else {
		input[2] &= ~(1 << 2);
		return 0;
	}
node5965:
	b = randbool();
	if (b) {
		input[2] |= (1 << 0);
		goto node8577;
	} else {
		input[2] &= ~(1 << 0);
		goto node8434;
	}
node5748:
	b = randbool();
	if (b) {
		input[2] |= (1 << 0);
		goto node3792;
	} else {
		input[2] &= ~(1 << 0);
		goto node6532;
	}
node1431:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node5548;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node7976:
	b = true;
	if (b) {
		input[3] |= (1 << 1);
		goto node154;
	} else {
		input[3] &= ~(1 << 1);
		return 0;
	}
node807:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node7587;
	} else {
		input[2] &= ~(1 << 3);
		goto node9130;
	}
node3947:
	b = false;
	if (b) {
		input[2] |= (1 << 1);
		return 0;
	} else {
		input[2] &= ~(1 << 1);
		goto node408;
	}
node2246:
	b = true;
	if (b) {
		input[3] |= (1 << 7);
		goto node8914;
	} else {
		input[3] &= ~(1 << 7);
		return 0;
	}
node5501:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node7823;
	} else {
		input[3] &= ~(1 << 5);
		goto node3779;
	}
node4843:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node5028;
	} else {
		input[3] &= ~(1 << 4);
		goto node1200;
	}
node8773:
	b = true;
	if (b) {
		input[3] |= (1 << 2);
		goto node7065;
	} else {
		input[3] &= ~(1 << 2);
		return 0;
	}
node5213:
	b = false;
	if (b) {
		input[2] |= (1 << 7);
		return 0;
	} else {
		input[2] &= ~(1 << 7);
		goto node6263;
	}
node9440:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node1211;
	} else {
		input[2] &= ~(1 << 3);
		goto node1744;
	}
node719:
	b = false;
	if (b) {
		input[2] |= (1 << 1);
		return 0;
	} else {
		input[2] &= ~(1 << 1);
		goto node6947;
	}
node9290:
	b = randbool();
	if (b) {
		input[2] |= (1 << 0);
		goto node5344;
	} else {
		input[2] &= ~(1 << 0);
		goto node7264;
	}
node3453:
	b = false;
	if (b) {
		input[3] |= (1 << 2);
		return 0;
	} else {
		input[3] &= ~(1 << 2);
		goto node1742;
	}
node2143:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node7630;
	} else {
		input[2] &= ~(1 << 5);
		goto node4882;
	}
node5033:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node5424;
	} else {
		input[2] &= ~(1 << 1);
		goto node7605;
	}
node9001:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node4440;
	}
node8190:
	b = true;
	if (b) {
		input[3] |= (1 << 2);
		goto node9360;
	} else {
		input[3] &= ~(1 << 2);
		return 0;
	}
node795:
	b = randbool();
	if (b) {
		input[4] |= (1 << 3);
		goto node8305;
	} else {
		input[4] &= ~(1 << 3);
		goto node2999;
	}
node3914:
	b = false;
	if (b) {
		input[5] |= (1 << 0);
		return 0;
	} else {
		input[5] &= ~(1 << 0);
		goto node2042;
	}
node4850:
	b = false;
	if (b) {
		input[1] |= (1 << 3);
		return 0;
	} else {
		input[1] &= ~(1 << 3);
		goto node503;
	}
node6450:
	b = randbool();
	if (b) {
		input[2] |= (1 << 7);
		goto node7519;
	} else {
		input[2] &= ~(1 << 7);
		goto node5618;
	}
node889:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node2624;
	} else {
		input[2] &= ~(1 << 5);
		goto node8024;
	}
node1988:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node5026;
	} else {
		input[3] &= ~(1 << 6);
		goto node8387;
	}
node4894:
	b = true;
	if (b) {
		input[4] |= (1 << 0);
		goto node4017;
	} else {
		input[4] &= ~(1 << 0);
		return 0;
	}
node180:
	b = randbool();
	if (b) {
		input[1] |= (1 << 1);
		goto node7645;
	} else {
		input[1] &= ~(1 << 1);
		return 2;
	}
node2232:
	b = false;
	if (b) {
		input[2] |= (1 << 0);
		return 0;
	} else {
		input[2] &= ~(1 << 0);
		goto node2450;
	}
node8072:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node4872;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node1839:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node5273;
	}
node1454:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node2735;
	}
node1474:
	b = false;
	if (b) {
		input[3] |= (1 << 1);
		return 0;
	} else {
		input[3] &= ~(1 << 1);
		goto node5569;
	}
node7022:
	b = randbool();
	if (b) {
		input[1] |= (1 << 4);
		goto node2334;
	} else {
		input[1] &= ~(1 << 4);
		goto node6315;
	}
node7669:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node6484;
	} else {
		input[3] &= ~(1 << 6);
		goto node571;
	}
node983:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node5107;
	} else {
		input[3] &= ~(1 << 4);
		goto node8522;
	}
node5922:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node6950;
	}
node5406:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node6950;
	} else {
		input[3] &= ~(1 << 2);
		goto node4139;
	}
node1305:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node857;
	} else {
		input[3] &= ~(1 << 2);
		goto node2958;
	}
node6831:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node8095;
	} else {
		input[2] &= ~(1 << 6);
		goto node6101;
	}
node8347:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node8578;
	}
node5720:
	b = false;
	if (b) {
		input[3] |= (1 << 2);
		return 0;
	} else {
		input[3] &= ~(1 << 2);
		goto node6692;
	}
node7447:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node6297;
	} else {
		input[3] &= ~(1 << 2);
		goto node6950;
	}
node7174:
	b = true;
	if (b) {
		input[2] |= (1 << 5);
		goto node2230;
	} else {
		input[2] &= ~(1 << 5);
		return 0;
	}
node6968:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node8191;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node7829:
	b = false;
	if (b) {
		input[1] |= (1 << 4);
		return 0;
	} else {
		input[1] &= ~(1 << 4);
		goto node2417;
	}
node2823:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node5185;
	}
node6986:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node4565;
	} else {
		input[2] &= ~(1 << 3);
		goto node8702;
	}
node7700:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node6946;
	} else {
		input[2] &= ~(1 << 2);
		goto node3264;
	}
node3785:
	b = false;
	if (b) {
		input[3] |= (1 << 6);
		return 0;
	} else {
		input[3] &= ~(1 << 6);
		goto node8544;
	}
node4725:
	b = true;
	if (b) {
		input[5] |= (1 << 0);
		goto node7837;
	} else {
		input[5] &= ~(1 << 0);
		return 0;
	}
node2503:
	b = false;
	if (b) {
		input[2] |= (1 << 5);
		return 0;
	} else {
		input[2] &= ~(1 << 5);
		goto node9084;
	}
node1170:
	b = true;
	if (b) {
		input[5] |= (1 << 3);
		goto node1446;
	} else {
		input[5] &= ~(1 << 3);
		return 0;
	}
node6257:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node2732;
	} else {
		input[2] &= ~(1 << 1);
		goto node5396;
	}
node4665:
	b = false;
	if (b) {
		input[3] |= (1 << 6);
		return 0;
	} else {
		input[3] &= ~(1 << 6);
		goto node566;
	}
node8196:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node5598;
	}
node8380:
	b = randbool();
	if (b) {
		input[3] |= (1 << 0);
		goto node6220;
	} else {
		input[3] &= ~(1 << 0);
		goto node3520;
	}
node5891:
	b = randbool();
	if (b) {
		input[5] |= (1 << 7);
		goto node1511;
	} else {
		input[5] &= ~(1 << 7);
		goto node2878;
	}
node784:
	b = randbool();
	if (b) {
		input[6] |= (1 << 4);
		goto node5265;
	} else {
		input[6] &= ~(1 << 4);
		goto node3875;
	}
node5627:
	b = false;
	if (b) {
		input[2] |= (1 << 7);
		return 0;
	} else {
		input[2] &= ~(1 << 7);
		goto node487;
	}
node6320:
	b = true;
	if (b) {
		input[2] |= (1 << 3);
		goto node3410;
	} else {
		input[2] &= ~(1 << 3);
		return 0;
	}
node4763:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node8386;
	} else {
		input[2] &= ~(1 << 1);
		goto node3799;
	}
node1077:
	b = false;
	if (b) {
		input[2] |= (1 << 0);
		return 0;
	} else {
		input[2] &= ~(1 << 0);
		goto node5995;
	}
node244:
	b = true;
	if (b) {
		input[3] |= (1 << 1);
		goto node8129;
	} else {
		input[3] &= ~(1 << 1);
		return 0;
	}
node6664:
	b = true;
	if (b) {
		input[4] |= (1 << 0);
		goto node8966;
	} else {
		input[4] &= ~(1 << 0);
		return 0;
	}
node6316:
	b = randbool();
	if (b) {
		input[1] |= (1 << 0);
		goto node5641;
	} else {
		input[1] &= ~(1 << 0);
		goto node7584;
	}
node6242:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node2187;
	} else {
		input[2] &= ~(1 << 3);
		goto node6997;
	}
node7402:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node1492;
	} else {
		input[2] &= ~(1 << 2);
		goto node1710;
	}
node5773:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node5204;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node2922:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node3181;
	}
node8074:
	b = randbool();
	if (b) {
		input[4] |= (1 << 6);
		goto node8299;
	} else {
		input[4] &= ~(1 << 6);
		goto node6714;
	}
node7131:
	b = false;
	if (b) {
		input[1] |= (1 << 3);
		return 0;
	} else {
		input[1] &= ~(1 << 3);
		goto node7289;
	}
node363:
	b = false;
	if (b) {
		input[2] |= (1 << 7);
		return 0;
	} else {
		input[2] &= ~(1 << 7);
		goto node3826;
	}
node5267:
	b = false;
	if (b) {
		input[2] |= (1 << 5);
		return 0;
	} else {
		input[2] &= ~(1 << 5);
		goto node7206;
	}
node7432:
	b = false;
	if (b) {
		input[2] |= (1 << 2);
		return 0;
	} else {
		input[2] &= ~(1 << 2);
		goto node9395;
	}
node5848:
	b = randbool();
	if (b) {
		input[1] |= (1 << 4);
		goto node592;
	} else {
		input[1] &= ~(1 << 4);
		goto node4437;
	}
node4512:
	b = true;
	if (b) {
		input[1] |= (1 << 1);
		goto node314;
	} else {
		input[1] &= ~(1 << 1);
		return 0;
	}
node7168:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node5596;
	} else {
		input[2] &= ~(1 << 3);
		goto node3365;
	}
node1371:
	b = true;
	if (b) {
		input[3] |= (1 << 7);
		goto node7763;
	} else {
		input[3] &= ~(1 << 7);
		return 0;
	}
node6001:
	b = randbool();
	if (b) {
		input[0] |= (1 << 1);
		goto node5804;
	} else {
		input[0] &= ~(1 << 1);
		goto node4673;
	}
node5920:
	b = true;
	if (b) {
		input[1] |= (1 << 0);
		goto node834;
	} else {
		input[1] &= ~(1 << 0);
		return 0;
	}
node1215:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node3190;
	} else {
		input[2] &= ~(1 << 6);
		goto node345;
	}
node8158:
	b = randbool();
	if (b) {
		input[1] |= (1 << 2);
		goto node1651;
	} else {
		input[1] &= ~(1 << 2);
		goto node1171;
	}
node5379:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node153;
	} else {
		input[2] &= ~(1 << 2);
		goto node4763;
	}
node434:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node8777;
	} else {
		input[3] &= ~(1 << 3);
		goto node1444;
	}
node5298:
	b = randbool();
	if (b) {
		input[3] |= (1 << 1);
		goto node5604;
	} else {
		input[3] &= ~(1 << 1);
		goto node6462;
	}
node3412:
	b = randbool();
	if (b) {
		input[4] |= (1 << 6);
		goto node5588;
	} else {
		input[4] &= ~(1 << 6);
		goto node1747;
	}
node2587:
	b = randbool();
	if (b) {
		input[1] |= (1 << 3);
		goto node3832;
	} else {
		input[1] &= ~(1 << 3);
		goto node5736;
	}
node2758:
	b = randbool();
	if (b) {
		input[1] |= (1 << 1);
		goto node7356;
	} else {
		input[1] &= ~(1 << 1);
		goto node6186;
	}
node2095:
	b = false;
	if (b) {
		input[3] |= (1 << 7);
		return 0;
	} else {
		input[3] &= ~(1 << 7);
		goto node4527;
	}
node8678:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node4028;
	} else {
		input[3] &= ~(1 << 6);
		goto node3573;
	}
node1657:
	b = true;
	if (b) {
		input[4] |= (1 << 1);
		goto node8181;
	} else {
		input[4] &= ~(1 << 1);
		return 0;
	}
node18:
	b = randbool();
	if (b) {
		input[5] |= (1 << 6);
		goto node1753;
	} else {
		input[5] &= ~(1 << 6);
		goto node3994;
	}
node4917:
	b = randbool();
	if (b) {
		input[1] |= (1 << 5);
		goto node5427;
	} else {
		input[1] &= ~(1 << 5);
		goto node992;
	}
node9053:
	b = true;
	if (b) {
		input[1] |= (1 << 1);
		goto node1209;
	} else {
		input[1] &= ~(1 << 1);
		return 0;
	}
node6729:
	b = randbool();
	if (b) {
		input[2] |= (1 << 7);
		goto node51;
	} else {
		input[2] &= ~(1 << 7);
		goto node2555;
	}
node2041:
	b = true;
	if (b) {
		input[3] |= (1 << 0);
		goto node6499;
	} else {
		input[3] &= ~(1 << 0);
		return 0;
	}
node7576:
	b = randbool();
	if (b) {
		input[5] |= (1 << 7);
		goto node7849;
	} else {
		input[5] &= ~(1 << 7);
		goto node4866;
	}
node1414:
	b = false;
	if (b) {
		input[2] |= (1 << 7);
		return 0;
	} else {
		input[2] &= ~(1 << 7);
		goto node1571;
	}
node5975:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node8003;
	} else {
		input[2] &= ~(1 << 2);
		goto node2553;
	}
node2523:
	b = randbool();
	if (b) {
		input[2] |= (1 << 0);
		goto node1962;
	} else {
		input[2] &= ~(1 << 0);
		goto node62;
	}
node1726:
	b = true;
	if (b) {
		input[3] |= (1 << 6);
		goto node3142;
	} else {
		input[3] &= ~(1 << 6);
		return 0;
	}
node7842:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node530;
	} else {
		input[3] &= ~(1 << 2);
		goto node9475;
	}
node6185:
	b = randbool();
	if (b) {
		input[4] |= (1 << 1);
		goto node2808;
	} else {
		input[4] &= ~(1 << 1);
		goto node5055;
	}
node7548:
	b = randbool();
	if (b) {
		input[1] |= (1 << 6);
		goto node4528;
	} else {
		input[1] &= ~(1 << 6);
		goto node3639;
	}
node1428:
	b = randbool();
	if (b) {
		input[1] |= (1 << 4);
		goto node7905;
	} else {
		input[1] &= ~(1 << 4);
		goto node7954;
	}
node303:
	b = false;
	if (b) {
		input[1] |= (1 << 2);
		return 0;
	} else {
		input[1] &= ~(1 << 2);
		goto node5898;
	}
node3824:
	b = true;
	if (b) {
		input[2] |= (1 << 7);
		goto node1437;
	} else {
		input[2] &= ~(1 << 7);
		return 0;
	}
node6326:
	b = randbool();
	if (b) {
		input[5] |= (1 << 7);
		goto node4400;
	} else {
		input[5] &= ~(1 << 7);
		goto node18;
	}
node816:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		return 3;
	} else {
		input[2] &= ~(1 << 2);
		goto node365;
	}
node9346:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node8248;
	} else {
		input[2] &= ~(1 << 2);
		goto node825;
	}
node4993:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node1342;
	} else {
		input[3] &= ~(1 << 6);
		goto node8326;
	}
node4623:
	b = randbool();
	if (b) {
		input[4] |= (1 << 6);
		goto node1147;
	} else {
		input[4] &= ~(1 << 6);
		goto node8997;
	}
node6172:
	b = false;
	if (b) {
		input[4] |= (1 << 5);
		return 0;
	} else {
		input[4] &= ~(1 << 5);
		goto node2339;
	}
node6681:
	b = false;
	if (b) {
		input[2] |= (1 << 6);
		return 0;
	} else {
		input[2] &= ~(1 << 6);
		goto node4309;
	}
node6474:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node4370;
	} else {
		input[2] &= ~(1 << 5);
		goto node228;
	}
node3825:
	b = true;
	if (b) {
		input[2] |= (1 << 2);
		goto node7841;
	} else {
		input[2] &= ~(1 << 2);
		return 0;
	}
node2679:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node2335;
	} else {
		input[3] &= ~(1 << 7);
		goto node9373;
	}
node1272:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node1928;
	} else {
		input[2] &= ~(1 << 1);
		goto node851;
	}
node9196:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node1810;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node1623:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node4962;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node7788:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node3011;
	} else {
		input[3] &= ~(1 << 4);
		goto node5573;
	}
node3239:
	b = randbool();
	if (b) {
		input[5] |= (1 << 2);
		goto node7231;
	} else {
		input[5] &= ~(1 << 2);
		return 7;
	}
node2534:
	b = randbool();
	if (b) {
		input[1] |= (1 << 2);
		goto node4170;
	} else {
		input[1] &= ~(1 << 2);
		goto node400;
	}
node3918:
	b = true;
	if (b) {
		input[1] |= (1 << 1);
		goto node1927;
	} else {
		input[1] &= ~(1 << 1);
		return 0;
	}
node4578:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node1578;
	} else {
		input[3] &= ~(1 << 7);
		goto node8405;
	}
node6219:
	b = false;
	if (b) {
		input[3] |= (1 << 2);
		return 0;
	} else {
		input[3] &= ~(1 << 2);
		goto node5309;
	}
node6876:
	b = false;
	if (b) {
		input[3] |= (1 << 0);
		return 0;
	} else {
		input[3] &= ~(1 << 0);
		goto node760;
	}
node1435:
	b = true;
	if (b) {
		input[1] |= (1 << 1);
		goto node9149;
	} else {
		input[1] &= ~(1 << 1);
		return 0;
	}
node4664:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node7104;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node6655:
	b = true;
	if (b) {
		input[3] |= (1 << 6);
		goto node2858;
	} else {
		input[3] &= ~(1 << 6);
		return 0;
	}
node2845:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node1505;
	} else {
		input[3] &= ~(1 << 5);
		goto node3779;
	}
node1093:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node9181;
	} else {
		input[3] &= ~(1 << 5);
		goto node2146;
	}
node2447:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node9212;
	} else {
		input[3] &= ~(1 << 4);
		goto node4104;
	}
node1155:
	b = randbool();
	if (b) {
		input[1] |= (1 << 1);
		goto node7596;
	} else {
		input[1] &= ~(1 << 1);
		goto node6186;
	}
node2277:
	b = true;
	if (b) {
		input[3] |= (1 << 2);
		goto node1406;
	} else {
		input[3] &= ~(1 << 2);
		return 0;
	}
node33:
	b = true;
	if (b) {
		input[4] |= (1 << 5);
		goto node5030;
	} else {
		input[4] &= ~(1 << 5);
		return 0;
	}
node8399:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		return 3;
	} else {
		input[2] &= ~(1 << 3);
		goto node4114;
	}
node2057:
	b = false;
	if (b) {
		input[2] |= (1 << 0);
		return 0;
	} else {
		input[2] &= ~(1 << 0);
		goto node667;
	}
node6180:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node5348;
	}
node777:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node7632;
	} else {
		input[3] &= ~(1 << 3);
		goto node4838;
	}
node7184:
	b = true;
	if (b) {
		input[4] |= (1 << 7);
		goto node9213;
	} else {
		input[4] &= ~(1 << 7);
		return 0;
	}
node8602:
	b = randbool();
	if (b) {
		input[1] |= (1 << 3);
		goto node8431;
	} else {
		input[1] &= ~(1 << 3);
		goto node3746;
	}
node2179:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node2386;
	} else {
		input[2] &= ~(1 << 5);
		goto node9174;
	}
node5690:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node5307;
	} else {
		input[2] &= ~(1 << 4);
		goto node7700;
	}
node1408:
	b = randbool();
	if (b) {
		input[2] |= (1 << 0);
		goto node7701;
	} else {
		input[2] &= ~(1 << 0);
		goto node9409;
	}
node8565:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node3137;
	} else {
		input[3] &= ~(1 << 5);
		goto node595;
	}
node8143:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node4857;
	} else {
		input[3] &= ~(1 << 2);
		goto node7551;
	}
node6163:
	b = randbool();
	if (b) {
		input[5] |= (1 << 4);
		goto node1446;
	} else {
		input[5] &= ~(1 << 4);
		goto node1170;
	}
node6044:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node9099;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node1758:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node7766;
	} else {
		input[3] &= ~(1 << 5);
		goto node4757;
	}
node3415:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node4489;
	} else {
		input[3] &= ~(1 << 4);
		goto node6577;
	}
node9468:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node778;
	} else {
		input[3] &= ~(1 << 3);
		goto node4425;
	}
node5635:
	b = true;
	if (b) {
		input[4] |= (1 << 4);
		goto node3245;
	} else {
		input[4] &= ~(1 << 4);
		return 0;
	}
node6564:
	b = randbool();
	if (b) {
		input[4] |= (1 << 4);
		goto node7707;
	} else {
		input[4] &= ~(1 << 4);
		goto node1490;
	}
node3924:
	b = true;
	if (b) {
		input[3] |= (1 << 6);
		goto node8762;
	} else {
		input[3] &= ~(1 << 6);
		return 0;
	}
node2259:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node1219;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node5023:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node2637;
	} else {
		input[3] &= ~(1 << 2);
		goto node3520;
	}
node4093:
	b = true;
	if (b) {
		input[4] |= (1 << 7);
		goto node4530;
	} else {
		input[4] &= ~(1 << 7);
		return 0;
	}
node3970:
	b = randbool();
	if (b) {
		input[5] |= (1 << 6);
		goto node8182;
	} else {
		input[5] &= ~(1 << 6);
		goto node6026;
	}
node1467:
	b = true;
	if (b) {
		input[2] |= (1 << 3);
		goto node2187;
	} else {
		input[2] &= ~(1 << 3);
		return 0;
	}
node640:
	b = true;
	if (b) {
		input[2] |= (1 << 2);
		goto node6475;
	} else {
		input[2] &= ~(1 << 2);
		return 0;
	}
node1417:
	b = false;
	if (b) {
		input[2] |= (1 << 0);
		return 0;
	} else {
		input[2] &= ~(1 << 0);
		goto node4364;
	}
node6491:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node6266;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node9260:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node4469;
	} else {
		input[3] &= ~(1 << 3);
		goto node1896;
	}
node3165:
	b = false;
	if (b) {
		input[3] |= (1 << 2);
		return 0;
	} else {
		input[3] &= ~(1 << 2);
		goto node3987;
	}
node2065:
	b = randbool();
	if (b) {
		input[1] |= (1 << 6);
		goto node5081;
	} else {
		input[1] &= ~(1 << 6);
		goto node799;
	}
node2776:
	b = randbool();
	if (b) {
		input[2] |= (1 << 0);
		return 8;
	} else {
		input[2] &= ~(1 << 0);
		goto node7936;
	}
node2061:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node2038;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node384:
	b = false;
	if (b) {
		input[4] |= (1 << 1);
		return 0;
	} else {
		input[4] &= ~(1 << 1);
		goto node8243;
	}
node6216:
	b = randbool();
	if (b) {
		input[1] |= (1 << 6);
		goto node5704;
	} else {
		input[1] &= ~(1 << 6);
		goto node5840;
	}
node1671:
	b = false;
	if (b) {
		input[2] |= (1 << 6);
		return 0;
	} else {
		input[2] &= ~(1 << 6);
		goto node7439;
	}
node6633:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node5851;
	} else {
		input[3] &= ~(1 << 7);
		goto node4506;
	}
node7509:
	b = false;
	if (b) {
		input[2] |= (1 << 2);
		return 0;
	} else {
		input[2] &= ~(1 << 2);
		goto node5088;
	}
node580:
	b = true;
	if (b) {
		input[4] |= (1 << 7);
		goto node4942;
	} else {
		input[4] &= ~(1 << 7);
		return 0;
	}
node687:
	b = false;
	if (b) {
		input[4] |= (1 << 5);
		return 0;
	} else {
		input[4] &= ~(1 << 5);
		goto node4436;
	}
node7583:
	b = randbool();
	if (b) {
		input[4] |= (1 << 1);
		goto node5436;
	} else {
		input[4] &= ~(1 << 1);
		goto node8656;
	}
node60:
	b = randbool();
	if (b) {
		input[2] |= (1 << 7);
		goto node936;
	} else {
		input[2] &= ~(1 << 7);
		goto node6843;
	}
node458:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node5637;
	} else {
		input[2] &= ~(1 << 1);
		goto node5748;
	}
node8273:
	b = false;
	if (b) {
		input[3] |= (1 << 2);
		return 0;
	} else {
		input[3] &= ~(1 << 2);
		goto node5521;
	}
node7596:
	b = true;
	if (b) {
		input[1] |= (1 << 0);
		goto node4909;
	} else {
		input[1] &= ~(1 << 0);
		return 0;
	}
node2789:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node152;
	}
node2581:
	b = true;
	if (b) {
		input[2] |= (1 << 2);
		goto node9414;
	} else {
		input[2] &= ~(1 << 2);
		return 0;
	}
node7803:
	b = true;
	if (b) {
		input[4] |= (1 << 7);
		goto node4056;
	} else {
		input[4] &= ~(1 << 7);
		return 0;
	}
node147:
	b = true;
	if (b) {
		input[1] |= (1 << 6);
		goto node5254;
	} else {
		input[1] &= ~(1 << 6);
		return 0;
	}
node4601:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node3447;
	} else {
		input[2] &= ~(1 << 5);
		goto node66;
	}
node1682:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node8198;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node1668:
	b = true;
	if (b) {
		input[4] |= (1 << 5);
		goto node6924;
	} else {
		input[4] &= ~(1 << 5);
		return 0;
	}
node3763:
	b = true;
	if (b) {
		input[4] |= (1 << 4);
		return 6;
	} else {
		input[4] &= ~(1 << 4);
		return 0;
	}
node7900:
	b = randbool();
	if (b) {
		input[1] |= (1 << 6);
		goto node9438;
	} else {
		input[1] &= ~(1 << 6);
		goto node1202;
	}
node8433:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node7802;
	} else {
		input[2] &= ~(1 << 1);
		goto node9086;
	}
node8445:
	b = true;
	if (b) {
		input[4] |= (1 << 6);
		goto node7978;
	} else {
		input[4] &= ~(1 << 6);
		return 0;
	}
node3564:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node7092;
	} else {
		input[3] &= ~(1 << 6);
		goto node7353;
	}
node6388:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node357;
	} else {
		input[3] &= ~(1 << 4);
		goto node7078;
	}
node3643:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node2196;
	} else {
		input[3] &= ~(1 << 2);
		goto node8686;
	}
node2698:
	b = true;
	if (b) {
		input[4] |= (1 << 2);
		goto node3149;
	} else {
		input[4] &= ~(1 << 2);
		return 0;
	}
node7849:
	b = true;
	if (b) {
		input[5] |= (1 << 6);
		return 6;
	} else {
		input[5] &= ~(1 << 6);
		return 0;
	}
node968:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node2747;
	}
node4642:
	b = false;
	if (b) {
		input[2] |= (1 << 2);
		return 0;
	} else {
		input[2] &= ~(1 << 2);
		goto node7593;
	}
node7301:
	b = true;
	if (b) {
		input[3] |= (1 << 7);
		goto node4355;
	} else {
		input[3] &= ~(1 << 7);
		return 0;
	}
node4082:
	b = false;
	if (b) {
		input[2] |= (1 << 0);
		return 0;
	} else {
		input[2] &= ~(1 << 0);
		goto node8304;
	}
node5148:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node989;
	}
node4010:
	b = randbool();
	if (b) {
		input[5] |= (1 << 6);
		goto node1767;
	} else {
		input[5] &= ~(1 << 6);
		goto node1615;
	}
node8754:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node7191;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node7891:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node8975;
	} else {
		input[2] &= ~(1 << 5);
		goto node2034;
	}
node7227:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node6159;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node7055:
	b = true;
	if (b) {
		input[4] |= (1 << 4);
		goto node7272;
	} else {
		input[4] &= ~(1 << 4);
		return 0;
	}
node6611:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node7725;
	} else {
		input[2] &= ~(1 << 4);
		goto node7255;
	}
node9294:
	b = false;
	if (b) {
		input[2] |= (1 << 3);
		return 0;
	} else {
		input[2] &= ~(1 << 3);
		goto node9117;
	}
node4397:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node1284;
	} else {
		input[2] &= ~(1 << 1);
		goto node7220;
	}
node8749:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node3520;
	} else {
		input[3] &= ~(1 << 3);
		goto node7462;
	}
node4490:
	b = true;
	if (b) {
		input[3] |= (1 << 2);
		goto node1445;
	} else {
		input[3] &= ~(1 << 2);
		return 0;
	}
node298:
	b = false;
	if (b) {
		input[4] |= (1 << 7);
		return 0;
	} else {
		input[4] &= ~(1 << 7);
		goto node2030;
	}
node3306:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node8335;
	} else {
		input[2] &= ~(1 << 6);
		goto node4495;
	}
node351:
	b = false;
	if (b) {
		input[3] |= (1 << 7);
		return 0;
	} else {
		input[3] &= ~(1 << 7);
		goto node8731;
	}
node8853:
	b = true;
	if (b) {
		input[3] |= (1 << 6);
		goto node2599;
	} else {
		input[3] &= ~(1 << 6);
		return 0;
	}
node4756:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node3786;
	}
node3891:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node56;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node8103:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node7470;
	} else {
		input[2] &= ~(1 << 4);
		goto node5884;
	}
node8649:
	b = true;
	if (b) {
		input[2] |= (1 << 2);
		goto node5532;
	} else {
		input[2] &= ~(1 << 2);
		return 0;
	}
node3458:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node9355;
	} else {
		input[3] &= ~(1 << 2);
		goto node7790;
	}
node7951:
	b = true;
	if (b) {
		input[2] |= (1 << 6);
		goto node5524;
	} else {
		input[2] &= ~(1 << 6);
		return 0;
	}
node8167:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		goto node8618;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node7660:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node7695;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node2721:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node2991;
	} else {
		input[3] &= ~(1 << 6);
		goto node5291;
	}
node5440:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node8168;
	} else {
		input[3] &= ~(1 << 4);
		goto node6616;
	}
node6988:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node896;
	} else {
		input[3] &= ~(1 << 2);
		goto node9387;
	}
node3782:
	b = randbool();
	if (b) {
		input[1] |= (1 << 5);
		goto node2160;
	} else {
		input[1] &= ~(1 << 5);
		goto node2164;
	}
node1359:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node661;
	} else {
		input[2] &= ~(1 << 1);
		goto node8457;
	}
node764:
	b = false;
	if (b) {
		input[2] |= (1 << 0);
		return 0;
	} else {
		input[2] &= ~(1 << 0);
		goto node1276;
	}
node3388:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node5857;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node8692:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node7195;
	}
node8856:
	b = randbool();
	if (b) {
		input[4] |= (1 << 3);
		goto node2532;
	} else {
		input[4] &= ~(1 << 3);
		goto node5803;
	}
node190:
	b = false;
	if (b) {
		input[2] |= (1 << 1);
		return 0;
	} else {
		input[2] &= ~(1 << 1);
		goto node3354;
	}
node9039:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node3796;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node4027:
	b = false;
	if (b) {
		input[3] |= (1 << 6);
		return 0;
	} else {
		input[3] &= ~(1 << 6);
		goto node2558;
	}
node7473:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node548;
	}
node3105:
	b = randbool();
	if (b) {
		input[4] |= (1 << 3);
		goto node1720;
	} else {
		input[4] &= ~(1 << 3);
		goto node3823;
	}
node3500:
	b = false;
	if (b) {
		input[2] |= (1 << 5);
		return 0;
	} else {
		input[2] &= ~(1 << 5);
		goto node2424;
	}
node7045:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node5234;
	} else {
		input[3] &= ~(1 << 5);
		goto node8004;
	}
node1173:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node2320;
	} else {
		input[3] &= ~(1 << 5);
		goto node15;
	}
node8845:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node1949;
	}
node2112:
	b = randbool();
	if (b) {
		input[1] |= (1 << 3);
		goto node6143;
	} else {
		input[1] &= ~(1 << 3);
		goto node2310;
	}
node3301:
	b = true;
	if (b) {
		input[2] |= (1 << 5);
		goto node7507;
	} else {
		input[2] &= ~(1 << 5);
		return 0;
	}
node4321:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node3225;
	} else {
		input[2] &= ~(1 << 5);
		goto node4751;
	}
node9465:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node2774;
	} else {
		input[2] &= ~(1 << 4);
		goto node8262;
	}
node126:
	b = true;
	if (b) {
		input[2] |= (1 << 2);
		goto node85;
	} else {
		input[2] &= ~(1 << 2);
		return 0;
	}
node5451:
	b = true;
	if (b) {
		input[3] |= (1 << 6);
		goto node8240;
	} else {
		input[3] &= ~(1 << 6);
		return 0;
	}
node2461:
	b = true;
	if (b) {
		input[3] |= (1 << 2);
		goto node8953;
	} else {
		input[3] &= ~(1 << 2);
		return 0;
	}
node3636:
	b = randbool();
	if (b) {
		input[1] |= (1 << 3);
		goto node1293;
	} else {
		input[1] &= ~(1 << 3);
		goto node5658;
	}
node337:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node3799;
	}
node9318:
	b = true;
	if (b) {
		input[3] |= (1 << 1);
		goto node9017;
	} else {
		input[3] &= ~(1 << 1);
		return 0;
	}
node8855:
	b = true;
	if (b) {
		input[4] |= (1 << 5);
		goto node2051;
	} else {
		input[4] &= ~(1 << 5);
		return 0;
	}
node6710:
	b = false;
	if (b) {
		input[1] |= (1 << 4);
		return 0;
	} else {
		input[1] &= ~(1 << 4);
		goto node8407;
	}
node4625:
	b = randbool();
	if (b) {
		input[1] |= (1 << 1);
		goto node6275;
	} else {
		input[1] &= ~(1 << 1);
		goto node3708;
	}
node5648:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node125;
	} else {
		input[2] &= ~(1 << 4);
		goto node1187;
	}
node6716:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node548;
	} else {
		input[3] &= ~(1 << 4);
		goto node6123;
	}
node2146:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node334;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node1849:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node3165;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node6981:
	b = randbool();
	if (b) {
		input[0] |= (1 << 0);
		goto node1789;
	} else {
		input[0] &= ~(1 << 0);
		goto node2266;
	}
node757:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node9015;
	}
node6751:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node7527;
	}
node5172:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node3974;
	} else {
		input[2] &= ~(1 << 2);
		return 5;
	}
node8043:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node632;
	} else {
		input[3] &= ~(1 << 5);
		goto node6357;
	}
node2393:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node8909;
	} else {
		input[3] &= ~(1 << 3);
		goto node1305;
	}
node952:
	b = true;
	if (b) {
		input[3] |= (1 << 1);
		goto node3345;
	} else {
		input[3] &= ~(1 << 1);
		return 0;
	}
node7711:
	b = true;
	if (b) {
		input[4] |= (1 << 2);
		goto node2360;
	} else {
		input[4] &= ~(1 << 2);
		return 0;
	}
node6174:
	b = randbool();
	if (b) {
		input[1] |= (1 << 7);
		goto node2251;
	} else {
		input[1] &= ~(1 << 7);
		goto node1784;
	}
node2486:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node7040;
	} else {
		input[2] &= ~(1 << 2);
		goto node1716;
	}
node1433:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node6059;
	}
node2071:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node3146;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node9097:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node5471;
	}
node1383:
	b = true;
	if (b) {
		input[3] |= (1 << 2);
		goto node3520;
	} else {
		input[3] &= ~(1 << 2);
		return 0;
	}
node2638:
	b = true;
	if (b) {
		input[4] |= (1 << 0);
		return 6;
	} else {
		input[4] &= ~(1 << 0);
		return 0;
	}
node7485:
	b = false;
	if (b) {
		input[4] |= (1 << 0);
		return 0;
	} else {
		input[4] &= ~(1 << 0);
		goto node8305;
	}
node6691:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node2296;
	} else {
		input[3] &= ~(1 << 4);
		goto node4415;
	}
node27:
	b = false;
	if (b) {
		input[2] |= (1 << 6);
		return 0;
	} else {
		input[2] &= ~(1 << 6);
		goto node7384;
	}
node6544:
	b = true;
	if (b) {
		input[2] |= (1 << 3);
		goto node8219;
	} else {
		input[2] &= ~(1 << 3);
		return 0;
	}
node7167:
	b = false;
	if (b) {
		input[2] |= (1 << 3);
		return 0;
	} else {
		input[2] &= ~(1 << 3);
		goto node4390;
	}
node3842:
	b = false;
	if (b) {
		input[4] |= (1 << 5);
		return 0;
	} else {
		input[4] &= ~(1 << 5);
		goto node6918;
	}
node3656:
	b = randbool();
	if (b) {
		input[1] |= (1 << 2);
		goto node9041;
	} else {
		input[1] &= ~(1 << 2);
		goto node497;
	}
node1161:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node4287;
	} else {
		input[2] &= ~(1 << 1);
		goto node7108;
	}
node2145:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node4793;
	} else {
		input[3] &= ~(1 << 6);
		goto node174;
	}
node5913:
	b = false;
	if (b) {
		input[3] |= (1 << 6);
		return 0;
	} else {
		input[3] &= ~(1 << 6);
		goto node4173;
	}
node8679:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node7500;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node3652:
	b = true;
	if (b) {
		input[4] |= (1 << 5);
		goto node4615;
	} else {
		input[4] &= ~(1 << 5);
		return 0;
	}
node5097:
	b = false;
	if (b) {
		input[1] |= (1 << 2);
		return 0;
	} else {
		input[1] &= ~(1 << 2);
		goto node2674;
	}
node6696:
	b = randbool();
	if (b) {
		input[1] |= (1 << 1);
		goto node3919;
	} else {
		input[1] &= ~(1 << 1);
		goto node4492;
	}
node9089:
	b = true;
	if (b) {
		input[2] |= (1 << 3);
		goto node2449;
	} else {
		input[2] &= ~(1 << 3);
		return 0;
	}
node6291:
	b = randbool();
	if (b) {
		input[4] |= (1 << 3);
		goto node2698;
	} else {
		input[4] &= ~(1 << 3);
		goto node245;
	}
node3258:
	b = true;
	if (b) {
		input[4] |= (1 << 2);
		goto node4079;
	} else {
		input[4] &= ~(1 << 2);
		return 0;
	}
node5553:
	b = false;
	if (b) {
		input[3] |= (1 << 2);
		return 0;
	} else {
		input[3] &= ~(1 << 2);
		goto node6285;
	}
node8312:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node2158;
	} else {
		input[3] &= ~(1 << 2);
		goto node8279;
	}
node7465:
	b = randbool();
	if (b) {
		input[1] |= (1 << 4);
		goto node592;
	} else {
		input[1] &= ~(1 << 4);
		goto node4141;
	}
node1714:
	b = randbool();
	if (b) {
		input[1] |= (1 << 1);
		goto node3242;
	} else {
		input[1] &= ~(1 << 1);
		goto node5926;
	}
node5824:
	b = randbool();
	if (b) {
		input[2] |= (1 << 7);
		goto node6831;
	} else {
		input[2] &= ~(1 << 7);
		goto node1301;
	}
node116:
	b = false;
	if (b) {
		input[2] |= (1 << 5);
		return 0;
	} else {
		input[2] &= ~(1 << 5);
		goto node3151;
	}
node6811:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node2189;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node6999:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node1627;
	} else {
		input[3] &= ~(1 << 5);
		goto node7558;
	}
node4416:
	b = randbool();
	if (b) {
		input[3] |= (1 << 1);
		return 5;
	} else {
		input[3] &= ~(1 << 1);
		goto node5528;
	}
node6383:
	b = randbool();
	if (b) {
		input[5] |= (1 << 4);
		goto node6960;
	} else {
		input[5] &= ~(1 << 4);
		goto node6014;
	}
node6095:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node9460;
	} else {
		input[2] &= ~(1 << 4);
		goto node8820;
	}
node3664:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node8120;
	} else {
		input[2] &= ~(1 << 3);
		goto node563;
	}
node6673:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node3354;
	} else {
		input[2] &= ~(1 << 2);
		goto node9466;
	}
node7257:
	b = true;
	if (b) {
		input[3] |= (1 << 6);
		goto node9226;
	} else {
		input[3] &= ~(1 << 6);
		return 0;
	}
node4693:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node137;
	} else {
		input[3] &= ~(1 << 3);
		goto node5149;
	}
node3144:
	b = false;
	if (b) {
		input[1] |= (1 << 3);
		return 0;
	} else {
		input[1] &= ~(1 << 3);
		goto node1394;
	}
node6151:
	b = true;
	if (b) {
		input[2] |= (1 << 2);
		goto node8337;
	} else {
		input[2] &= ~(1 << 2);
		return 0;
	}
node3563:
	b = randbool();
	if (b) {
		input[2] |= (1 << 0);
		goto node5555;
	} else {
		input[2] &= ~(1 << 0);
		goto node4283;
	}
node6511:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node691;
	} else {
		input[3] &= ~(1 << 7);
		goto node3877;
	}
node5665:
	b = false;
	if (b) {
		input[4] |= (1 << 5);
		return 0;
	} else {
		input[4] &= ~(1 << 5);
		goto node5435;
	}
node379:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node9325;
	} else {
		input[2] &= ~(1 << 1);
		goto node5597;
	}
node9227:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node8547;
	} else {
		input[3] &= ~(1 << 4);
		goto node3733;
	}
node1760:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node6314;
	} else {
		input[3] &= ~(1 << 4);
		goto node5812;
	}
node4188:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node5728;
	} else {
		input[3] &= ~(1 << 3);
		goto node5022;
	}
node5138:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node7833;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node5257:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node2579;
	} else {
		input[2] &= ~(1 << 4);
		goto node5600;
	}
node3667:
	b = false;
	if (b) {
		input[3] |= (1 << 7);
		return 0;
	} else {
		input[3] &= ~(1 << 7);
		goto node2340;
	}
node5621:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node3560;
	} else {
		input[3] &= ~(1 << 4);
		goto node2244;
	}
node4631:
	b = false;
	if (b) {
		input[4] |= (1 << 3);
		return 0;
	} else {
		input[4] &= ~(1 << 3);
		goto node4671;
	}
node4343:
	b = randbool();
	if (b) {
		input[1] |= (1 << 3);
		goto node8961;
	} else {
		input[1] &= ~(1 << 3);
		goto node1872;
	}
node7451:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		goto node8282;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node8879:
	b = false;
	if (b) {
		input[2] |= (1 << 1);
		return 0;
	} else {
		input[2] &= ~(1 << 1);
		goto node2187;
	}
node1923:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node8435;
	} else {
		input[3] &= ~(1 << 6);
		goto node4562;
	}
node5206:
	b = false;
	if (b) {
		input[3] |= (1 << 1);
		return 0;
	} else {
		input[3] &= ~(1 << 1);
		goto node669;
	}
node3579:
	b = randbool();
	if (b) {
		input[1] |= (1 << 5);
		goto node1503;
	} else {
		input[1] &= ~(1 << 5);
		goto node1944;
	}
node1891:
	b = false;
	if (b) {
		input[1] |= (1 << 5);
		return 0;
	} else {
		input[1] &= ~(1 << 5);
		goto node7926;
	}
node8337:
	b = false;
	if (b) {
		input[2] |= (1 << 1);
		return 0;
	} else {
		input[2] &= ~(1 << 1);
		goto node4225;
	}
node6707:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node20;
	} else {
		input[3] &= ~(1 << 7);
		goto node8641;
	}
node9074:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node7367;
	} else {
		input[3] &= ~(1 << 6);
		goto node6104;
	}
node3435:
	b = randbool();
	if (b) {
		input[4] |= (1 << 2);
		goto node6202;
	} else {
		input[4] &= ~(1 << 2);
		goto node1720;
	}
node9051:
	b = true;
	if (b) {
		input[6] |= (1 << 2);
		goto node1916;
	} else {
		input[6] &= ~(1 << 2);
		return 0;
	}
node8030:
	b = randbool();
	if (b) {
		input[1] |= (1 << 1);
		goto node762;
	} else {
		input[1] &= ~(1 << 1);
		goto node6613;
	}
node6429:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node704;
	} else {
		input[3] &= ~(1 << 6);
		goto node3801;
	}
node3962:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node8113;
	} else {
		input[3] &= ~(1 << 5);
		goto node6713;
	}
node308:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node2175;
	} else {
		input[3] &= ~(1 << 5);
		goto node4741;
	}
node4628:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node8139;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node1116:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node3050;
	} else {
		input[3] &= ~(1 << 2);
		goto node540;
	}
node3323:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node2995;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node6983:
	b = randbool();
	if (b) {
		input[1] |= (1 << 0);
		goto node510;
	} else {
		input[1] &= ~(1 << 0);
		return 3;
	}
node584:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node2954;
	} else {
		input[2] &= ~(1 << 6);
		goto node982;
	}
node5620:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node7470;
	} else {
		input[2] &= ~(1 << 4);
		goto node5876;
	}
node793:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		goto node1289;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node4250:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node4439;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node5036:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node8949;
	} else {
		input[3] &= ~(1 << 6);
		goto node2097;
	}
node9095:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node3504;
	} else {
		input[2] &= ~(1 << 6);
		goto node5566;
	}
node8322:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node1735;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node7170:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node5026;
	} else {
		input[3] &= ~(1 << 6);
		goto node2772;
	}
node950:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node8625;
	} else {
		input[3] &= ~(1 << 5);
		goto node1246;
	}
node2759:
	b = false;
	if (b) {
		input[4] |= (1 << 5);
		return 0;
	} else {
		input[4] &= ~(1 << 5);
		goto node9132;
	}
node598:
	b = false;
	if (b) {
		input[4] |= (1 << 2);
		return 0;
	} else {
		input[4] &= ~(1 << 2);
		goto node7576;
	}
node5200:
	b = randbool();
	if (b) {
		input[1] |= (1 << 3);
		goto node1199;
	} else {
		input[1] &= ~(1 << 3);
		goto node8218;
	}
node3475:
	b = randbool();
	if (b) {
		input[1] |= (1 << 1);
		goto node4576;
	} else {
		input[1] &= ~(1 << 1);
		goto node6334;
	}
node8413:
	b = false;
	if (b) {
		input[2] |= (1 << 5);
		return 0;
	} else {
		input[2] &= ~(1 << 5);
		goto node8998;
	}
node6501:
	b = true;
	if (b) {
		input[3] |= (1 << 7);
		goto node5308;
	} else {
		input[3] &= ~(1 << 7);
		return 0;
	}
node9297:
	b = false;
	if (b) {
		input[3] |= (1 << 0);
		return 0;
	} else {
		input[3] &= ~(1 << 0);
		goto node2462;
	}
node17:
	b = true;
	if (b) {
		input[4] |= (1 << 3);
		goto node2265;
	} else {
		input[4] &= ~(1 << 3);
		return 0;
	}
node6850:
	b = false;
	if (b) {
		input[2] |= (1 << 0);
		return 0;
	} else {
		input[2] &= ~(1 << 0);
		return 3;
	}
node8324:
	b = true;
	if (b) {
		input[3] |= (1 << 7);
		goto node8571;
	} else {
		input[3] &= ~(1 << 7);
		return 0;
	}
node844:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node1521;
	} else {
		input[3] &= ~(1 << 5);
		goto node8005;
	}
node9239:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node2461;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node3660:
	b = randbool();
	if (b) {
		input[3] |= (1 << 1);
		goto node3954;
	} else {
		input[3] &= ~(1 << 1);
		goto node3867;
	}
node34:
	b = true;
	if (b) {
		input[4] |= (1 << 2);
		goto node5004;
	} else {
		input[4] &= ~(1 << 2);
		return 0;
	}
node8083:
	b = false;
	if (b) {
		input[4] |= (1 << 0);
		return 0;
	} else {
		input[4] &= ~(1 << 0);
		goto node6974;
	}
node3938:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node5687;
	} else {
		input[2] &= ~(1 << 1);
		goto node9461;
	}
node4651:
	b = false;
	if (b) {
		input[3] |= (1 << 6);
		return 0;
	} else {
		input[3] &= ~(1 << 6);
		goto node4570;
	}
node2663:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node8279;
	} else {
		input[3] &= ~(1 << 2);
		goto node1445;
	}
node3055:
	b = true;
	if (b) {
		input[3] |= (1 << 1);
		goto node7632;
	} else {
		input[3] &= ~(1 << 1);
		return 0;
	}
node696:
	b = randbool();
	if (b) {
		input[3] |= (1 << 1);
		goto node4444;
	} else {
		input[3] &= ~(1 << 1);
		goto node7112;
	}
node5092:
	b = false;
	if (b) {
		input[4] |= (1 << 7);
		return 0;
	} else {
		input[4] &= ~(1 << 7);
		goto node6806;
	}
node850:
	b = false;
	if (b) {
		input[2] |= (1 << 1);
		return 0;
	} else {
		input[2] &= ~(1 << 1);
		goto node5787;
	}
node5162:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node3718;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node7085:
	b = true;
	if (b) {
		input[6] |= (1 << 3);
		goto node8202;
	} else {
		input[6] &= ~(1 << 3);
		return 0;
	}
node3702:
	b = randbool();
	if (b) {
		input[1] |= (1 << 6);
		goto node3729;
	} else {
		input[1] &= ~(1 << 6);
		goto node7724;
	}
node2444:
	b = false;
	if (b) {
		input[1] |= (1 << 2);
		return 0;
	} else {
		input[1] &= ~(1 << 2);
		goto node3296;
	}
node7492:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node2741;
	} else {
		input[2] &= ~(1 << 5);
		goto node3118;
	}
node1487:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node3002;
	} else {
		input[2] &= ~(1 << 3);
		goto node6736;
	}
node868:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		goto node2557;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node5759:
	b = false;
	if (b) {
		input[4] |= (1 << 7);
		return 0;
	} else {
		input[4] &= ~(1 << 7);
		goto node5393;
	}
node2558:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node8027;
	} else {
		input[3] &= ~(1 << 5);
		goto node9320;
	}
node5679:
	b = true;
	if (b) {
		input[3] |= (1 << 2);
		goto node3314;
	} else {
		input[3] &= ~(1 << 2);
		return 0;
	}
node2202:
	b = false;
	if (b) {
		input[2] |= (1 << 3);
		return 0;
	} else {
		input[2] &= ~(1 << 3);
		goto node126;
	}
node686:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node6671;
	} else {
		input[3] &= ~(1 << 3);
		goto node4046;
	}
node8078:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node2768;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node6371:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node2187;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node6105:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node8266;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node3995:
	b = false;
	if (b) {
		input[3] |= (1 << 0);
		return 0;
	} else {
		input[3] &= ~(1 << 0);
		goto node827;
	}
node2352:
	b = false;
	if (b) {
		input[4] |= (1 << 0);
		return 0;
	} else {
		input[4] &= ~(1 << 0);
		goto node7576;
	}
node3788:
	b = randbool();
	if (b) {
		input[5] |= (1 << 4);
		goto node3994;
	} else {
		input[5] &= ~(1 << 4);
		goto node1029;
	}
node2822:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node2491;
	}
node1416:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node8812;
	} else {
		input[2] &= ~(1 << 4);
		goto node3683;
	}
node8146:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node8712;
	} else {
		input[2] &= ~(1 << 3);
		goto node8058;
	}
node5659:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node6294;
	} else {
		input[2] &= ~(1 << 3);
		goto node3863;
	}
node1561:
	b = false;
	if (b) {
		input[3] |= (1 << 7);
		return 0;
	} else {
		input[3] &= ~(1 << 7);
		goto node4241;
	}
node3152:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node4604;
	} else {
		input[3] &= ~(1 << 4);
		goto node9364;
	}
node6244:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node8719;
	} else {
		input[3] &= ~(1 << 7);
		goto node2752;
	}
node5095:
	b = false;
	if (b) {
		input[3] |= (1 << 6);
		return 0;
	} else {
		input[3] &= ~(1 << 6);
		goto node7147;
	}
node9342:
	b = randbool();
	if (b) {
		input[3] |= (1 << 0);
		goto node6220;
	} else {
		input[3] &= ~(1 << 0);
		goto node4887;
	}
node8506:
	b = true;
	if (b) {
		input[4] |= (1 << 3);
		goto node9173;
	} else {
		input[4] &= ~(1 << 3);
		return 0;
	}
node2713:
	b = true;
	if (b) {
		input[4] |= (1 << 2);
		goto node8707;
	} else {
		input[4] &= ~(1 << 2);
		return 0;
	}
node923:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node1560;
	} else {
		input[2] &= ~(1 << 5);
		goto node3544;
	}
node8766:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node8417;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node7972:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node5475;
	} else {
		input[2] &= ~(1 << 6);
		goto node6711;
	}
node6632:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node3534;
	}
node6166:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node3470;
	} else {
		input[2] &= ~(1 << 1);
		goto node243;
	}
node4932:
	b = randbool();
	if (b) {
		input[2] |= (1 << 0);
		goto node8598;
	} else {
		input[2] &= ~(1 << 0);
		goto node2136;
	}
node7414:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node8572;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node3419:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node3420;
	} else {
		input[3] &= ~(1 << 7);
		goto node5562;
	}
node8888:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node9465;
	} else {
		input[2] &= ~(1 << 5);
		goto node8262;
	}
node1966:
	b = true;
	if (b) {
		input[4] |= (1 << 2);
		goto node9456;
	} else {
		input[4] &= ~(1 << 2);
		return 0;
	}
node142:
	b = false;
	if (b) {
		input[2] |= (1 << 2);
		return 0;
	} else {
		input[2] &= ~(1 << 2);
		goto node6137;
	}
node132:
	b = true;
	if (b) {
		input[3] |= (1 << 6);
		goto node2778;
	} else {
		input[3] &= ~(1 << 6);
		return 0;
	}
node5823:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node7675;
	} else {
		input[3] &= ~(1 << 5);
		goto node3321;
	}
node6923:
	b = false;
	if (b) {
		input[3] |= (1 << 1);
		return 0;
	} else {
		input[3] &= ~(1 << 1);
		goto node8601;
	}
node9413:
	b = true;
	if (b) {
		input[2] |= (1 << 2);
		goto node6849;
	} else {
		input[2] &= ~(1 << 2);
		return 0;
	}
node8182:
	b = true;
	if (b) {
		input[5] |= (1 << 2);
		goto node898;
	} else {
		input[5] &= ~(1 << 2);
		return 0;
	}
node5102:
	b = false;
	if (b) {
		input[2] |= (1 << 7);
		return 0;
	} else {
		input[2] &= ~(1 << 7);
		goto node5676;
	}
node9236:
	b = false;
	if (b) {
		input[2] |= (1 << 7);
		return 0;
	} else {
		input[2] &= ~(1 << 7);
		goto node3086;
	}
node169:
	b = randbool();
	if (b) {
		input[2] |= (1 << 0);
		goto node6933;
	} else {
		input[2] &= ~(1 << 0);
		goto node6587;
	}
node5928:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node1746;
	} else {
		input[3] &= ~(1 << 2);
		goto node9476;
	}
node3315:
	b = false;
	if (b) {
		input[5] |= (1 << 1);
		return 0;
	} else {
		input[5] &= ~(1 << 1);
		goto node7125;
	}
node3523:
	b = randbool();
	if (b) {
		input[1] |= (1 << 6);
		goto node8913;
	} else {
		input[1] &= ~(1 << 6);
		goto node1250;
	}
node5382:
	b = false;
	if (b) {
		input[2] |= (1 << 7);
		return 0;
	} else {
		input[2] &= ~(1 << 7);
		goto node9237;
	}
node5409:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node8388;
	} else {
		input[2] &= ~(1 << 5);
		goto node7646;
	}
node8000:
	b = true;
	if (b) {
		input[2] |= (1 << 5);
		goto node8414;
	} else {
		input[2] &= ~(1 << 5);
		return 0;
	}
node1475:
	b = randbool();
	if (b) {
		input[3] |= (1 << 1);
		goto node2395;
	} else {
		input[3] &= ~(1 << 1);
		goto node5604;
	}
node6519:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		goto node3392;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node7101:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node7863;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node3311:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node6984;
	} else {
		input[3] &= ~(1 << 5);
		goto node7162;
	}
node9114:
	b = true;
	if (b) {
		input[4] |= (1 << 7);
		goto node7717;
	} else {
		input[4] &= ~(1 << 7);
		return 0;
	}
node8541:
	b = randbool();
	if (b) {
		input[5] |= (1 << 1);
		return 6;
	} else {
		input[5] &= ~(1 << 1);
		goto node8829;
	}
node884:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node7670;
	} else {
		input[3] &= ~(1 << 4);
		goto node686;
	}
node3493:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node5633;
	} else {
		input[3] &= ~(1 << 7);
		goto node4788;
	}
node8034:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node1141;
	} else {
		input[3] &= ~(1 << 5);
		goto node3891;
	}
node1343:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node2846;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node3014:
	b = true;
	if (b) {
		input[2] |= (1 << 7);
		goto node2640;
	} else {
		input[2] &= ~(1 << 7);
		return 0;
	}
node4757:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node7766;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node597:
	b = false;
	if (b) {
		input[4] |= (1 << 4);
		return 0;
	} else {
		input[4] &= ~(1 << 4);
		goto node3990;
	}
node8079:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node8587;
	} else {
		input[3] &= ~(1 << 6);
		goto node8033;
	}
node7430:
	b = randbool();
	if (b) {
		input[4] |= (1 << 7);
		goto node3078;
	} else {
		input[4] &= ~(1 << 7);
		goto node2163;
	}
node3647:
	b = randbool();
	if (b) {
		input[0] |= (1 << 1);
		goto node5371;
	} else {
		input[0] &= ~(1 << 1);
		goto node2740;
	}
node3621:
	b = false;
	if (b) {
		input[2] |= (1 << 2);
		return 0;
	} else {
		input[2] &= ~(1 << 2);
		goto node917;
	}
node8712:
	b = true;
	if (b) {
		input[2] |= (1 << 2);
		goto node1261;
	} else {
		input[2] &= ~(1 << 2);
		return 0;
	}
node6706:
	b = false;
	if (b) {
		input[3] |= (1 << 7);
		return 0;
	} else {
		input[3] &= ~(1 << 7);
		goto node6720;
	}
node7557:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node1772;
	}
node375:
	b = false;
	if (b) {
		input[4] |= (1 << 4);
		return 0;
	} else {
		input[4] &= ~(1 << 4);
		goto node4128;
	}
node9254:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node5664;
	} else {
		input[3] &= ~(1 << 2);
		return 5;
	}
node3134:
	b = randbool();
	if (b) {
		input[1] |= (1 << 2);
		goto node2254;
	} else {
		input[1] &= ~(1 << 2);
		goto node4726;
	}
node6586:
	b = false;
	if (b) {
		input[2] |= (1 << 2);
		return 0;
	} else {
		input[2] &= ~(1 << 2);
		goto node1370;
	}
node3080:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node907;
	} else {
		input[2] &= ~(1 << 2);
		goto node2008;
	}
node4971:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node5916;
	} else {
		input[3] &= ~(1 << 7);
		goto node6188;
	}
node4147:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node8310;
	} else {
		input[3] &= ~(1 << 6);
		goto node5538;
	}
node2660:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node3626;
	}
node1323:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node3657;
	} else {
		input[3] &= ~(1 << 7);
		goto node6281;
	}
node492:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node3726;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node909:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node4574;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node4500:
	b = false;
	if (b) {
		input[4] |= (1 << 3);
		return 0;
	} else {
		input[4] &= ~(1 << 3);
		goto node1766;
	}
node6787:
	b = false;
	if (b) {
		input[1] |= (1 << 1);
		return 0;
	} else {
		input[1] &= ~(1 << 1);
		goto node716;
	}
node869:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node7676;
	}
node2801:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node8157;
	} else {
		input[3] &= ~(1 << 2);
		goto node9153;
	}
node8144:
	b = randbool();
	if (b) {
		input[1] |= (1 << 6);
		goto node1864;
	} else {
		input[1] &= ~(1 << 6);
		goto node3821;
	}
node7255:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node7887;
	} else {
		input[2] &= ~(1 << 3);
		goto node4847;
	}
node7399:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node2086;
	} else {
		input[2] &= ~(1 << 6);
		goto node7317;
	}
node5650:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node6967;
	} else {
		input[2] &= ~(1 << 2);
		goto node6371;
	}
node4895:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node1000;
	} else {
		input[2] &= ~(1 << 3);
		goto node6097;
	}
node8478:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node6522;
	} else {
		input[2] &= ~(1 << 2);
		goto node1441;
	}
node1336:
	b = randbool();
	if (b) {
		input[4] |= (1 << 5);
		goto node7415;
	} else {
		input[4] &= ~(1 << 5);
		goto node3813;
	}
node3531:
	b = true;
	if (b) {
		input[4] |= (1 << 2);
		goto node905;
	} else {
		input[4] &= ~(1 << 2);
		return 0;
	}
node2573:
	b = randbool();
	if (b) {
		input[7] |= (1 << 5);
		goto node8767;
	} else {
		input[7] &= ~(1 << 5);
		goto node973;
	}
node9216:
	b = false;
	if (b) {
		input[2] |= (1 << 3);
		return 0;
	} else {
		input[2] &= ~(1 << 3);
		goto node6451;
	}
node6213:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		return 3;
	} else {
		input[2] &= ~(1 << 1);
		goto node8651;
	}
node8617:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node3493;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node4314:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node5276;
	}
node3913:
	b = false;
	if (b) {
		input[3] |= (1 << 0);
		return 0;
	} else {
		input[3] &= ~(1 << 0);
		goto node8551;
	}
node2351:
	b = false;
	if (b) {
		input[4] |= (1 << 3);
		return 0;
	} else {
		input[4] &= ~(1 << 3);
		goto node972;
	}
node4301:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node3960;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node1458:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node3088;
	} else {
		input[3] &= ~(1 << 2);
		goto node1445;
	}
node4902:
	b = false;
	if (b) {
		input[4] |= (1 << 3);
		return 0;
	} else {
		input[4] &= ~(1 << 3);
		return 5;
	}
node7532:
	b = false;
	if (b) {
		input[4] |= (1 << 0);
		return 0;
	} else {
		input[4] &= ~(1 << 0);
		goto node7276;
	}
node2006:
	b = randbool();
	if (b) {
		input[6] |= (1 << 7);
		goto node4075;
	} else {
		input[6] &= ~(1 << 7);
		goto node8496;
	}
node882:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node7545;
	} else {
		input[3] &= ~(1 << 6);
		goto node308;
	}
node4245:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node952;
	} else {
		input[3] &= ~(1 << 2);
		goto node3182;
	}
node6393:
	b = false;
	if (b) {
		input[3] |= (1 << 2);
		return 0;
	} else {
		input[3] &= ~(1 << 2);
		goto node6637;
	}
node5142:
	b = true;
	if (b) {
		input[1] |= (1 << 0);
		goto node6186;
	} else {
		input[1] &= ~(1 << 0);
		return 0;
	}
node2100:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node3279;
	} else {
		input[2] &= ~(1 << 1);
		goto node7226;
	}
node3103:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node9310;
	} else {
		input[3] &= ~(1 << 7);
		goto node9096;
	}
node3282:
	b = randbool();
	if (b) {
		input[4] |= (1 << 3);
		goto node2500;
	} else {
		input[4] &= ~(1 << 3);
		goto node3275;
	}
node6500:
	b = true;
	if (b) {
		input[1] |= (1 << 1);
		goto node3549;
	} else {
		input[1] &= ~(1 << 1);
		return 0;
	}
node1764:
	b = true;
	if (b) {
		input[1] |= (1 << 0);
		goto node8208;
	} else {
		input[1] &= ~(1 << 0);
		return 0;
	}
node8329:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node534;
	} else {
		input[2] &= ~(1 << 3);
		goto node8219;
	}
node1143:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node5844;
	} else {
		input[2] &= ~(1 << 3);
		return 3;
	}
node5743:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node1581;
	} else {
		input[3] &= ~(1 << 6);
		goto node8347;
	}
node55:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node3743;
	} else {
		input[3] &= ~(1 << 6);
		goto node1047;
	}
node1028:
	b = randbool();
	if (b) {
		input[3] |= (1 << 1);
		goto node4644;
	} else {
		input[3] &= ~(1 << 1);
		goto node6452;
	}
node3059:
	b = false;
	if (b) {
		input[0] |= (1 << 0);
		return 0;
	} else {
		input[0] &= ~(1 << 0);
		return 2;
	}
node7329:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node2281;
	}
node3404:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		goto node9059;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node570:
	b = true;
	if (b) {
		input[3] |= (1 << 6);
		goto node3479;
	} else {
		input[3] &= ~(1 << 6);
		return 0;
	}
node1581:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node2909;
	}
node4947:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node7920;
	} else {
		input[3] &= ~(1 << 2);
		goto node2834;
	}
node4381:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node1588;
	} else {
		input[2] &= ~(1 << 3);
		goto node1806;
	}
node7217:
	b = true;
	if (b) {
		input[2] |= (1 << 3);
		goto node3752;
	} else {
		input[2] &= ~(1 << 3);
		return 0;
	}
node9117:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node7369;
	} else {
		input[2] &= ~(1 << 2);
		goto node8637;
	}
node1344:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node1098;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node8473:
	b = false;
	if (b) {
		input[3] |= (1 << 1);
		return 0;
	} else {
		input[3] &= ~(1 << 1);
		goto node5816;
	}
node1192:
	b = randbool();
	if (b) {
		input[5] |= (1 << 6);
		goto node4616;
	} else {
		input[5] &= ~(1 << 6);
		goto node6881;
	}
node751:
	b = randbool();
	if (b) {
		input[1] |= (1 << 7);
		goto node8739;
	} else {
		input[1] &= ~(1 << 7);
		goto node9423;
	}
node7878:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node9239;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node5477:
	b = true;
	if (b) {
		input[4] |= (1 << 2);
		goto node7203;
	} else {
		input[4] &= ~(1 << 2);
		return 0;
	}
node2087:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node4490;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node8392:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node235;
	} else {
		input[3] &= ~(1 << 2);
		goto node8794;
	}
node4150:
	b = false;
	if (b) {
		input[1] |= (1 << 3);
		return 0;
	} else {
		input[1] &= ~(1 << 3);
		goto node453;
	}
node4520:
	b = false;
	if (b) {
		input[2] |= (1 << 6);
		return 0;
	} else {
		input[2] &= ~(1 << 6);
		goto node6002;
	}
node5431:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node9111;
	} else {
		input[2] &= ~(1 << 4);
		goto node7406;
	}
node5754:
	b = randbool();
	if (b) {
		input[2] |= (1 << 0);
		goto node8505;
	} else {
		input[2] &= ~(1 << 0);
		goto node6476;
	}
node3726:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node794;
	}
node4668:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node9101;
	} else {
		input[3] &= ~(1 << 3);
		goto node4677;
	}
node5781:
	b = randbool();
	if (b) {
		input[3] |= (1 << 1);
		return 6;
	} else {
		input[3] &= ~(1 << 1);
		goto node6876;
	}
node658:
	b = randbool();
	if (b) {
		input[3] |= (1 << 0);
		goto node5752;
	} else {
		input[3] &= ~(1 << 0);
		goto node7632;
	}
node7885:
	b = false;
	if (b) {
		input[4] |= (1 << 1);
		return 0;
	} else {
		input[4] &= ~(1 << 1);
		goto node3694;
	}
node3696:
	b = randbool();
	if (b) {
		input[1] |= (1 << 0);
		goto node541;
	} else {
		input[1] &= ~(1 << 0);
		goto node8363;
	}
node5801:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node5480;
	} else {
		input[2] &= ~(1 << 3);
		goto node6553;
	}
node1010:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node3132;
	}
node494:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node7947;
	} else {
		input[3] &= ~(1 << 2);
		goto node1281;
	}
node5523:
	b = false;
	if (b) {
		input[1] |= (1 << 1);
		return 0;
	} else {
		input[1] &= ~(1 << 1);
		goto node8208;
	}
node4936:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node5250;
	} else {
		input[3] &= ~(1 << 5);
		goto node6081;
	}
node9385:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node1098;
	}
node3289:
	b = randbool();
	if (b) {
		input[0] |= (1 << 0);
		goto node3584;
	} else {
		input[0] &= ~(1 << 0);
		goto node8203;
	}
node4849:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node4127;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node7052:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node8099;
	} else {
		input[3] &= ~(1 << 6);
		goto node211;
	}
node8246:
	b = true;
	if (b) {
		input[3] |= (1 << 6);
		goto node4717;
	} else {
		input[3] &= ~(1 << 6);
		return 0;
	}
node5582:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node187;
	}
node2345:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node7309;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node378:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node6819;
	} else {
		input[2] &= ~(1 << 4);
		goto node3580;
	}
node4939:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node7887;
	} else {
		input[2] &= ~(1 << 1);
		goto node7845;
	}
node2540:
	b = false;
	if (b) {
		input[2] |= (1 << 0);
		return 0;
	} else {
		input[2] &= ~(1 << 0);
		goto node2817;
	}
node878:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node6834;
	} else {
		input[3] &= ~(1 << 6);
		goto node5285;
	}
node5380:
	b = true;
	if (b) {
		input[3] |= (1 << 6);
		goto node1912;
	} else {
		input[3] &= ~(1 << 6);
		return 0;
	}
node4440:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node5781;
	} else {
		input[3] &= ~(1 << 2);
		return 6;
	}
node8331:
	b = true;
	if (b) {
		input[4] |= (1 << 5);
		goto node2959;
	} else {
		input[4] &= ~(1 << 5);
		return 0;
	}
node1302:
	b = true;
	if (b) {
		input[2] |= (1 << 4);
		goto node1596;
	} else {
		input[2] &= ~(1 << 4);
		return 0;
	}
node145:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node4609;
	} else {
		input[2] &= ~(1 << 2);
		goto node2791;
	}
node620:
	b = false;
	if (b) {
		input[2] |= (1 << 2);
		return 0;
	} else {
		input[2] &= ~(1 << 2);
		goto node1084;
	}
node1505:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node6898;
	} else {
		input[3] &= ~(1 << 4);
		goto node196;
	}
node7043:
	b = randbool();
	if (b) {
		input[3] |= (1 << 1);
		goto node8380;
	} else {
		input[3] &= ~(1 << 1);
		goto node3520;
	}
node5381:
	b = true;
	if (b) {
		input[3] |= (1 << 1);
		return 4;
	} else {
		input[3] &= ~(1 << 1);
		return 0;
	}
node7747:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node8254;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node8549:
	b = randbool();
	if (b) {
		input[3] |= (1 << 1);
		return 4;
	} else {
		input[3] &= ~(1 << 1);
		goto node6836;
	}
node270:
	b = false;
	if (b) {
		input[3] |= (1 << 0);
		return 0;
	} else {
		input[3] &= ~(1 << 0);
		goto node8996;
	}
node8834:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node4049;
	} else {
		input[3] &= ~(1 << 7);
		goto node4531;
	}
node619:
	b = true;
	if (b) {
		input[2] |= (1 << 3);
		goto node2034;
	} else {
		input[2] &= ~(1 << 3);
		return 0;
	}
node8646:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node791;
	}
node2860:
	b = false;
	if (b) {
		input[3] |= (1 << 2);
		return 0;
	} else {
		input[3] &= ~(1 << 2);
		goto node6682;
	}
node9138:
	b = randbool();
	if (b) {
		input[5] |= (1 << 6);
		goto node354;
	} else {
		input[5] &= ~(1 << 6);
		goto node7049;
	}
node6063:
	b = true;
	if (b) {
		input[4] |= (1 << 2);
		goto node1720;
	} else {
		input[4] &= ~(1 << 2);
		return 0;
	}
node2019:
	b = randbool();
	if (b) {
		input[2] |= (1 << 7);
		goto node7506;
	} else {
		input[2] &= ~(1 << 7);
		goto node5437;
	}
node6952:
	b = true;
	if (b) {
		input[2] |= (1 << 4);
		goto node3791;
	} else {
		input[2] &= ~(1 << 4);
		return 0;
	}
node9329:
	b = true;
	if (b) {
		input[2] |= (1 << 2);
		goto node1693;
	} else {
		input[2] &= ~(1 << 2);
		return 0;
	}
node601:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node1114;
	} else {
		input[3] &= ~(1 << 5);
		goto node9220;
	}
node5447:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node4069;
	} else {
		input[3] &= ~(1 << 5);
		goto node6466;
	}
node5506:
	b = false;
	if (b) {
		input[3] |= (1 << 1);
		return 0;
	} else {
		input[3] &= ~(1 << 1);
		goto node7666;
	}
node7461:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node7561;
	} else {
		input[3] &= ~(1 << 7);
		goto node3715;
	}
node2847:
	b = randbool();
	if (b) {
		input[4] |= (1 << 3);
		goto node6063;
	} else {
		input[4] &= ~(1 << 3);
		goto node4009;
	}
node8041:
	b = true;
	if (b) {
		input[1] |= (1 << 0);
		goto node1853;
	} else {
		input[1] &= ~(1 << 0);
		return 0;
	}
node2889:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node2930;
	} else {
		input[2] &= ~(1 << 5);
		goto node5843;
	}
node7668:
	b = true;
	if (b) {
		input[2] |= (1 << 3);
		goto node8737;
	} else {
		input[2] &= ~(1 << 3);
		return 0;
	}
node3097:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node5879;
	} else {
		input[2] &= ~(1 << 3);
		goto node1873;
	}
node9414:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		goto node111;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node1441:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node8716;
	} else {
		input[2] &= ~(1 << 1);
		goto node5870;
	}
node5135:
	b = true;
	if (b) {
		input[2] |= (1 << 5);
		goto node4146;
	} else {
		input[2] &= ~(1 << 5);
		return 0;
	}
node9105:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node1352;
	} else {
		input[3] &= ~(1 << 6);
		goto node4042;
	}
node562:
	b = false;
	if (b) {
		input[2] |= (1 << 1);
		return 0;
	} else {
		input[2] &= ~(1 << 1);
		goto node6103;
	}
node9176:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node3642;
	} else {
		input[3] &= ~(1 << 5);
		goto node8776;
	}
node79:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node3472;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node9430:
	b = randbool();
	if (b) {
		input[4] |= (1 << 1);
		goto node6994;
	} else {
		input[4] &= ~(1 << 1);
		goto node654;
	}
node8128:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node3083;
	} else {
		input[3] &= ~(1 << 3);
		goto node5022;
	}
node5153:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node1094;
	} else {
		input[3] &= ~(1 << 2);
		return 6;
	}
node503:
	b = true;
	if (b) {
		input[1] |= (1 << 2);
		goto node4389;
	} else {
		input[1] &= ~(1 << 2);
		return 0;
	}
node454:
	b = true;
	if (b) {
		input[1] |= (1 << 0);
		goto node5974;
	} else {
		input[1] &= ~(1 << 0);
		return 0;
	}
node621:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		goto node7009;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node9166:
	b = true;
	if (b) {
		input[3] |= (1 << 6);
		goto node5798;
	} else {
		input[3] &= ~(1 << 6);
		return 0;
	}
node536:
	b = false;
	if (b) {
		input[3] |= (1 << 6);
		return 0;
	} else {
		input[3] &= ~(1 << 6);
		goto node7045;
	}
node7888:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node7428;
	} else {
		input[3] &= ~(1 << 4);
		goto node9385;
	}
node1402:
	b = randbool();
	if (b) {
		input[0] |= (1 << 6);
		goto node7333;
	} else {
		input[0] &= ~(1 << 6);
		goto node7172;
	}
node8529:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node3375;
	} else {
		input[2] &= ~(1 << 4);
		goto node7159;
	}
node1288:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node955;
	} else {
		input[2] &= ~(1 << 5);
		goto node6518;
	}
node7089:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node4313;
	} else {
		input[2] &= ~(1 << 4);
		goto node7655;
	}
node4146:
	b = true;
	if (b) {
		input[2] |= (1 << 4);
		goto node4895;
	} else {
		input[2] &= ~(1 << 4);
		return 0;
	}
node1692:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node1597;
	} else {
		input[2] &= ~(1 << 4);
		goto node8842;
	}
node6644:
	b = true;
	if (b) {
		input[2] |= (1 << 7);
		goto node2276;
	} else {
		input[2] &= ~(1 << 7);
		return 0;
	}
node988:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node8325;
	} else {
		input[3] &= ~(1 << 7);
		goto node8638;
	}
node2201:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node2467;
	} else {
		input[3] &= ~(1 << 6);
		goto node7911;
	}
node2011:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node8398;
	}
node2493:
	b = false;
	if (b) {
		input[3] |= (1 << 1);
		return 0;
	} else {
		input[3] &= ~(1 << 1);
		goto node3559;
	}
node7628:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node7563;
	} else {
		input[3] &= ~(1 << 5);
		goto node5148;
	}
node9292:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node9469;
	} else {
		input[3] &= ~(1 << 2);
		goto node7684;
	}
node4064:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node5997;
	}
node9075:
	b = true;
	if (b) {
		input[3] |= (1 << 2);
		goto node7156;
	} else {
		input[3] &= ~(1 << 2);
		return 0;
	}
node1066:
	b = randbool();
	if (b) {
		input[3] |= (1 << 0);
		goto node5818;
	} else {
		input[3] &= ~(1 << 0);
		goto node896;
	}
node3426:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node3950;
	} else {
		input[2] &= ~(1 << 1);
		goto node7887;
	}
node1794:
	b = true;
	if (b) {
		input[4] |= (1 << 2);
		goto node1338;
	} else {
		input[4] &= ~(1 << 2);
		return 0;
	}
node1096:
	b = randbool();
	if (b) {
		input[4] |= (1 << 2);
		goto node336;
	} else {
		input[4] &= ~(1 << 2);
		return 6;
	}
node2574:
	b = randbool();
	if (b) {
		input[1] |= (1 << 2);
		goto node5805;
	} else {
		input[1] &= ~(1 << 2);
		goto node2758;
	}
node1024:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node93;
	}
node587:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node7412;
	} else {
		input[3] &= ~(1 << 4);
		goto node5205;
	}
node2903:
	b = false;
	if (b) {
		input[3] |= (1 << 1);
		return 0;
	} else {
		input[3] &= ~(1 << 1);
		goto node4990;
	}
node7250:
	b = false;
	if (b) {
		input[2] |= (1 << 7);
		return 0;
	} else {
		input[2] &= ~(1 << 7);
		goto node2398;
	}
node7784:
	b = false;
	if (b) {
		input[2] |= (1 << 0);
		return 0;
	} else {
		input[2] &= ~(1 << 0);
		goto node6054;
	}
node4294:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node8350;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node3977:
	b = true;
	if (b) {
		input[3] |= (1 << 1);
		goto node7212;
	} else {
		input[3] &= ~(1 << 1);
		return 0;
	}
node1241:
	b = true;
	if (b) {
		input[4] |= (1 << 7);
		goto node3030;
	} else {
		input[4] &= ~(1 << 7);
		return 0;
	}
node6846:
	b = true;
	if (b) {
		input[1] |= (1 << 5);
		goto node2177;
	} else {
		input[1] &= ~(1 << 5);
		return 0;
	}
node5617:
	b = randbool();
	if (b) {
		input[2] |= (1 << 7);
		goto node8778;
	} else {
		input[2] &= ~(1 << 7);
		goto node4320;
	}
node2939:
	b = false;
	if (b) {
		input[4] |= (1 << 2);
		return 0;
	} else {
		input[4] &= ~(1 << 2);
		goto node439;
	}
node2999:
	b = randbool();
	if (b) {
		input[4] |= (1 << 2);
		goto node6202;
	} else {
		input[4] &= ~(1 << 2);
		goto node8305;
	}
node5081:
	b = randbool();
	if (b) {
		input[1] |= (1 << 5);
		goto node2451;
	} else {
		input[1] &= ~(1 << 5);
		goto node4446;
	}
node4342:
	b = false;
	if (b) {
		input[1] |= (1 << 5);
		return 0;
	} else {
		input[1] &= ~(1 << 5);
		goto node6304;
	}
node8998:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node3308;
	}
node6203:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node136;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node4255:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node7412;
	}
node1030:
	b = randbool();
	if (b) {
		input[1] |= (1 << 4);
		goto node8283;
	} else {
		input[1] &= ~(1 << 4);
		goto node4318;
	}
node9325:
	b = randbool();
	if (b) {
		input[2] |= (1 << 0);
		goto node4945;
	} else {
		input[2] &= ~(1 << 0);
		goto node1371;
	}
node3989:
	b = true;
	if (b) {
		input[3] |= (1 << 6);
		goto node4072;
	} else {
		input[3] &= ~(1 << 6);
		return 0;
	}
node8846:
	b = true;
	if (b) {
		input[4] |= (1 << 7);
		goto node8806;
	} else {
		input[4] &= ~(1 << 7);
		return 0;
	}
node5986:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node8403;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node7562:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node2476;
	}
node5320:
	b = randbool();
	if (b) {
		input[1] |= (1 << 2);
		goto node2216;
	} else {
		input[1] &= ~(1 << 2);
		goto node2511;
	}
node7116:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node29;
	} else {
		input[2] &= ~(1 << 6);
		goto node966;
	}
node6141:
	b = false;
	if (b) {
		input[2] |= (1 << 5);
		return 0;
	} else {
		input[2] &= ~(1 << 5);
		goto node1310;
	}
node3261:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node3488;
	} else {
		input[3] &= ~(1 << 2);
		goto node9360;
	}
node2315:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node3354;
	} else {
		input[2] &= ~(1 << 1);
		goto node117;
	}
node1974:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node6770;
	} else {
		input[3] &= ~(1 << 4);
		goto node279;
	}
node9397:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node3551;
	}
node3212:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node3266;
	} else {
		input[3] &= ~(1 << 2);
		goto node1126;
	}
node1407:
	b = false;
	if (b) {
		input[3] |= (1 << 0);
		return 0;
	} else {
		input[3] &= ~(1 << 0);
		goto node9023;
	}
node9072:
	b = randbool();
	if (b) {
		input[1] |= (1 << 1);
		goto node551;
	} else {
		input[1] &= ~(1 << 1);
		goto node5142;
	}
node304:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node5438;
	} else {
		input[2] &= ~(1 << 5);
		goto node6237;
	}
node1018:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node5002;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node2084:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node2550;
	}
node3874:
	b = true;
	if (b) {
		input[4] |= (1 << 1);
		goto node4973;
	} else {
		input[4] &= ~(1 << 1);
		return 0;
	}
node2326:
	b = true;
	if (b) {
		input[2] |= (1 << 6);
		goto node6847;
	} else {
		input[2] &= ~(1 << 6);
		return 0;
	}
node6225:
	b = true;
	if (b) {
		input[3] |= (1 << 7);
		goto node1711;
	} else {
		input[3] &= ~(1 << 7);
		return 0;
	}
node3572:
	b = true;
	if (b) {
		input[3] |= (1 << 7);
		goto node901;
	} else {
		input[3] &= ~(1 << 7);
		return 0;
	}
node3380:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node2414;
	}
node4420:
	b = true;
	if (b) {
		input[4] |= (1 << 2);
		goto node7885;
	} else {
		input[4] &= ~(1 << 2);
		return 0;
	}
node8049:
	b = true;
	if (b) {
		input[2] |= (1 << 2);
		goto node1856;
	} else {
		input[2] &= ~(1 << 2);
		return 0;
	}
node1517:
	b = false;
	if (b) {
		input[2] |= (1 << 1);
		return 0;
	} else {
		input[2] &= ~(1 << 1);
		goto node9420;
	}
node241:
	b = false;
	if (b) {
		input[2] |= (1 << 7);
		return 0;
	} else {
		input[2] &= ~(1 << 7);
		goto node8334;
	}
node2429:
	b = false;
	if (b) {
		input[2] |= (1 << 2);
		return 0;
	} else {
		input[2] &= ~(1 << 2);
		goto node7887;
	}
node7487:
	b = true;
	if (b) {
		input[3] |= (1 << 7);
		goto node6998;
	} else {
		input[3] &= ~(1 << 7);
		return 0;
	}
node1972:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node493;
	} else {
		input[3] &= ~(1 << 5);
		goto node1502;
	}
node8266:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node335;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node8298:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node7945;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node3926:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node90;
	}
node8722:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node6950;
	} else {
		input[3] &= ~(1 << 2);
		goto node6297;
	}
node2808:
	b = false;
	if (b) {
		input[4] |= (1 << 0);
		return 0;
	} else {
		input[4] &= ~(1 << 0);
		goto node439;
	}
node4361:
	b = true;
	if (b) {
		input[1] |= (1 << 2);
		goto node3336;
	} else {
		input[1] &= ~(1 << 2);
		return 0;
	}
node8240:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node4430;
	}
node995:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node5799;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node2414:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node349;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node6941:
	b = randbool();
	if (b) {
		input[4] |= (1 << 4);
		goto node8067;
	} else {
		input[4] &= ~(1 << 4);
		goto node2702;
	}
node8124:
	b = false;
	if (b) {
		input[4] |= (1 << 3);
		return 0;
	} else {
		input[4] &= ~(1 << 3);
		goto node6676;
	}
node2829:
	b = randbool();
	if (b) {
		input[1] |= (1 << 4);
		goto node5910;
	} else {
		input[1] &= ~(1 << 4);
		goto node6860;
	}
node7786:
	b = true;
	if (b) {
		input[1] |= (1 << 3);
		goto node4099;
	} else {
		input[1] &= ~(1 << 3);
		return 0;
	}
node8018:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node2536;
	} else {
		input[3] &= ~(1 << 4);
		goto node6822;
	}
node693:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node8157;
	} else {
		input[3] &= ~(1 << 2);
		goto node8750;
	}
node5280:
	b = randbool();
	if (b) {
		input[4] |= (1 << 3);
		goto node6733;
	} else {
		input[4] &= ~(1 << 3);
		goto node4279;
	}
node3300:
	b = false;
	if (b) {
		input[1] |= (1 << 4);
		return 0;
	} else {
		input[1] &= ~(1 << 4);
		goto node1876;
	}
node6158:
	b = false;
	if (b) {
		input[2] |= (1 << 3);
		return 0;
	} else {
		input[2] &= ~(1 << 3);
		goto node4882;
	}
node4450:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node8659;
	} else {
		input[3] &= ~(1 << 3);
		goto node7308;
	}
node8218:
	b = randbool();
	if (b) {
		input[1] |= (1 << 2);
		goto node7645;
	} else {
		input[1] &= ~(1 << 2);
		goto node193;
	}
node6186:
	b = randbool();
	if (b) {
		input[2] |= (1 << 7);
		goto node7506;
	} else {
		input[2] &= ~(1 << 7);
		goto node6231;
	}
node109:
	b = true;
	if (b) {
		input[2] |= (1 << 5);
		return 4;
	} else {
		input[2] &= ~(1 << 5);
		return 0;
	}
node2132:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node6785;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node1309:
	b = true;
	if (b) {
		input[4] |= (1 << 5);
		goto node6989;
	} else {
		input[4] &= ~(1 << 5);
		return 0;
	}
node5540:
	b = true;
	if (b) {
		input[4] |= (1 << 3);
		goto node7094;
	} else {
		input[4] &= ~(1 << 3);
		return 0;
	}
node8840:
	b = true;
	if (b) {
		input[1] |= (1 << 2);
		goto node1339;
	} else {
		input[1] &= ~(1 << 2);
		return 0;
	}
node7641:
	b = false;
	if (b) {
		input[1] |= (1 << 2);
		return 0;
	} else {
		input[1] &= ~(1 << 2);
		goto node7446;
	}
node4177:
	b = false;
	if (b) {
		input[2] |= (1 << 6);
		return 0;
	} else {
		input[2] &= ~(1 << 6);
		goto node4632;
	}
node3641:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node6774;
	}
node1723:
	b = true;
	if (b) {
		input[2] |= (1 << 3);
		goto node5432;
	} else {
		input[2] &= ~(1 << 3);
		return 0;
	}
node6209:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node1799;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node1756:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node2269;
	} else {
		input[2] &= ~(1 << 3);
		goto node4502;
	}
node6545:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node2075;
	} else {
		input[2] &= ~(1 << 2);
		goto node6376;
	}
node68:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node9468;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node8681:
	b = randbool();
	if (b) {
		input[4] |= (1 << 5);
		goto node1111;
	} else {
		input[4] &= ~(1 << 5);
		goto node8941;
	}
node2828:
	b = randbool();
	if (b) {
		input[1] |= (1 << 7);
		goto node7178;
	} else {
		input[1] &= ~(1 << 7);
		goto node6216;
	}
node3585:
	b = randbool();
	if (b) {
		input[1] |= (1 << 6);
		goto node4518;
	} else {
		input[1] &= ~(1 << 6);
		goto node4154;
	}
node6826:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		goto node3997;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node3827:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node8987;
	} else {
		input[3] &= ~(1 << 2);
		goto node1126;
	}
node5970:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node873;
	} else {
		input[3] &= ~(1 << 2);
		goto node3363;
	}
node6924:
	b = randbool();
	if (b) {
		input[4] |= (1 << 4);
		goto node6659;
	} else {
		input[4] &= ~(1 << 4);
		goto node3257;
	}
node1348:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node7946;
	}
node3793:
	b = randbool();
	if (b) {
		input[4] |= (1 << 0);
		return 9;
	} else {
		input[4] &= ~(1 << 0);
		goto node9314;
	}
node7838:
	b = randbool();
	if (b) {
		input[1] |= (1 << 2);
		goto node1045;
	} else {
		input[1] &= ~(1 << 2);
		goto node4726;
	}
node900:
	b = false;
	if (b) {
		input[2] |= (1 << 6);
		return 0;
	} else {
		input[2] &= ~(1 << 6);
		goto node8071;
	}
node3608:
	b = false;
	if (b) {
		input[2] |= (1 << 5);
		return 0;
	} else {
		input[2] &= ~(1 << 5);
		goto node1065;
	}
node1373:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node770;
	} else {
		input[3] &= ~(1 << 7);
		goto node8112;
	}
node5699:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node2541;
	} else {
		input[3] &= ~(1 << 6);
		goto node1917;
	}
node4297:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node9306;
	} else {
		input[2] &= ~(1 << 2);
		goto node1031;
	}
node5395:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node7121;
	} else {
		input[2] &= ~(1 << 2);
		goto node2553;
	}
node4931:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node7660;
	} else {
		input[2] &= ~(1 << 1);
		goto node443;
	}
node2180:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node7226;
	} else {
		input[2] &= ~(1 << 1);
		goto node2187;
	}
node465:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node9153;
	} else {
		input[3] &= ~(1 << 2);
		goto node6637;
	}
node3945:
	b = true;
	if (b) {
		input[1] |= (1 << 0);
		goto node4745;
	} else {
		input[1] &= ~(1 << 0);
		return 0;
	}
node6129:
	b = randbool();
	if (b) {
		input[4] |= (1 << 5);
		goto node3724;
	} else {
		input[4] &= ~(1 << 5);
		goto node3888;
	}
node7663:
	b = randbool();
	if (b) {
		input[1] |= (1 << 2);
		goto node8795;
	} else {
		input[1] &= ~(1 << 2);
		goto node7277;
	}
node42:
	b = false;
	if (b) {
		input[2] |= (1 << 7);
		return 0;
	} else {
		input[2] &= ~(1 << 7);
		goto node3000;
	}
node7303:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node3630;
	}
node5576:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node9110;
	} else {
		input[3] &= ~(1 << 2);
		goto node8801;
	}
node827:
	b = randbool();
	if (b) {
		input[4] |= (1 << 7);
		goto node5310;
	} else {
		input[4] &= ~(1 << 7);
		goto node6758;
	}
node3251:
	b = randbool();
	if (b) {
		input[1] |= (1 << 3);
		goto node6186;
	} else {
		input[1] &= ~(1 << 3);
		goto node8300;
	}
node1899:
	b = true;
	if (b) {
		input[2] |= (1 << 4);
		goto node7743;
	} else {
		input[2] &= ~(1 << 4);
		return 0;
	}
node5295:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node3783;
	} else {
		input[2] &= ~(1 << 2);
		goto node808;
	}
node1868:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node1245;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node8350:
	b = false;
	if (b) {
		input[3] |= (1 << 2);
		return 0;
	} else {
		input[3] &= ~(1 << 2);
		goto node5206;
	}
node2552:
	b = true;
	if (b) {
		input[7] |= (1 << 2);
		goto node9067;
	} else {
		input[7] &= ~(1 << 2);
		return 0;
	}
node5628:
	b = true;
	if (b) {
		input[2] |= (1 << 7);
		goto node7494;
	} else {
		input[2] &= ~(1 << 7);
		return 0;
	}
node1358:
	b = true;
	if (b) {
		input[2] |= (1 << 4);
		return 3;
	} else {
		input[2] &= ~(1 << 4);
		return 0;
	}
node6975:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node2023;
	}
node2582:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node2187;
	} else {
		input[2] &= ~(1 << 1);
		goto node433;
	}
node6530:
	b = false;
	if (b) {
		input[4] |= (1 << 3);
		return 0;
	} else {
		input[4] &= ~(1 << 3);
		goto node8087;
	}
node5947:
	b = true;
	if (b) {
		input[5] |= (1 << 7);
		goto node3384;
	} else {
		input[5] &= ~(1 << 7);
		return 0;
	}
node8752:
	b = true;
	if (b) {
		input[2] |= (1 << 7);
		goto node6755;
	} else {
		input[2] &= ~(1 << 7);
		return 0;
	}
node6958:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node7632;
	} else {
		input[3] &= ~(1 << 3);
		goto node6675;
	}
node7384:
	b = false;
	if (b) {
		input[2] |= (1 << 5);
		return 0;
	} else {
		input[2] &= ~(1 << 5);
		goto node6868;
	}
node5202:
	b = randbool();
	if (b) {
		input[2] |= (1 << 0);
		goto node9392;
	} else {
		input[2] &= ~(1 << 0);
		goto node7487;
	}
node4739:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node3613;
	}
node7618:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node3090;
	} else {
		input[3] &= ~(1 << 6);
		goto node1972;
	}
node5586:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node5668;
	} else {
		input[3] &= ~(1 << 4);
		goto node3916;
	}
node6152:
	b = randbool();
	if (b) {
		input[1] |= (1 << 6);
		goto node7795;
	} else {
		input[1] &= ~(1 << 6);
		goto node5518;
	}
node2124:
	b = randbool();
	if (b) {
		input[1] |= (1 << 2);
		goto node8257;
	} else {
		input[1] &= ~(1 << 2);
		goto node8035;
	}
node1113:
	b = true;
	if (b) {
		input[2] |= (1 << 3);
		goto node5041;
	} else {
		input[2] &= ~(1 << 3);
		return 0;
	}
node8272:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node3476;
	} else {
		input[2] &= ~(1 << 2);
		goto node5632;
	}
node3271:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node2708;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node3111:
	b = false;
	if (b) {
		input[2] |= (1 << 0);
		return 0;
	} else {
		input[2] &= ~(1 << 0);
		goto node5373;
	}
node2710:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node9238;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node1523:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node4490;
	}
node6448:
	b = false;
	if (b) {
		input[3] |= (1 << 2);
		return 0;
	} else {
		input[3] &= ~(1 << 2);
		goto node8518;
	}
node3803:
	b = true;
	if (b) {
		input[1] |= (1 << 0);
		goto node7323;
	} else {
		input[1] &= ~(1 << 0);
		return 0;
	}
node2790:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node7887;
	}
node3587:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node4504;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node6227:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node6290;
	} else {
		input[3] &= ~(1 << 5);
		goto node7766;
	}
node5693:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node7053;
	} else {
		input[3] &= ~(1 << 4);
		goto node3975;
	}
node3162:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node4263;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node4034:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node6769;
	} else {
		input[3] &= ~(1 << 5);
		goto node2952;
	}
node3734:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node3819;
	} else {
		input[3] &= ~(1 << 2);
		goto node3520;
	}
node8279:
	b = true;
	if (b) {
		input[3] |= (1 << 1);
		goto node6372;
	} else {
		input[3] &= ~(1 << 1);
		return 0;
	}
node3791:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node7560;
	} else {
		input[2] &= ~(1 << 3);
		goto node8037;
	}
node3032:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node8980;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node3545:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node137;
	} else {
		input[3] &= ~(1 << 4);
		goto node5750;
	}
node3594:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node1742;
	} else {
		input[3] &= ~(1 << 2);
		goto node2134;
	}
node529:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node3520;
	} else {
		input[3] &= ~(1 << 2);
		goto node5882;
	}
node6016:
	b = true;
	if (b) {
		input[2] |= (1 << 5);
		goto node866;
	} else {
		input[2] &= ~(1 << 5);
		return 0;
	}
node3605:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node4919;
	} else {
		input[2] &= ~(1 << 5);
		goto node8737;
	}
node5066:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node3620;
	} else {
		input[2] &= ~(1 << 5);
		goto node5791;
	}
node3760:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node6521;
	}
node6631:
	b = true;
	if (b) {
		input[3] |= (1 << 2);
		goto node2779;
	} else {
		input[3] &= ~(1 << 2);
		return 0;
	}
node8707:
	b = true;
	if (b) {
		input[4] |= (1 << 1);
		goto node2027;
	} else {
		input[4] &= ~(1 << 1);
		return 0;
	}
node8102:
	b = true;
	if (b) {
		input[2] |= (1 << 7);
		goto node2667;
	} else {
		input[2] &= ~(1 << 7);
		return 0;
	}
node1479:
	b = true;
	if (b) {
		input[2] |= (1 << 4);
		goto node3616;
	} else {
		input[2] &= ~(1 << 4);
		return 0;
	}
node3835:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node6879;
	} else {
		input[2] &= ~(1 << 2);
		goto node6371;
	}
node234:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node7987;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node8514:
	b = false;
	if (b) {
		input[4] |= (1 << 0);
		return 0;
	} else {
		input[4] &= ~(1 << 0);
		goto node8477;
	}
node2159:
	b = randbool();
	if (b) {
		input[0] |= (1 << 0);
		goto node5300;
	} else {
		input[0] &= ~(1 << 0);
		goto node960;
	}
node6905:
	b = true;
	if (b) {
		input[1] |= (1 << 1);
		goto node7645;
	} else {
		input[1] &= ~(1 << 1);
		return 0;
	}
node7103:
	b = false;
	if (b) {
		input[3] |= (1 << 7);
		return 0;
	} else {
		input[3] &= ~(1 << 7);
		goto node1704;
	}
node8371:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node6133;
	} else {
		input[3] &= ~(1 << 5);
		goto node2725;
	}
node2958:
	b = false;
	if (b) {
		input[3] |= (1 << 1);
		return 0;
	} else {
		input[3] &= ~(1 << 1);
		goto node5029;
	}
node1958:
	b = false;
	if (b) {
		input[4] |= (1 << 3);
		return 0;
	} else {
		input[4] &= ~(1 << 3);
		goto node8540;
	}
node422:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node3380;
	} else {
		input[3] &= ~(1 << 6);
		goto node134;
	}
node6130:
	b = randbool();
	if (b) {
		input[0] |= (1 << 1);
		goto node2159;
	} else {
		input[0] &= ~(1 << 1);
		goto node1188;
	}
node6304:
	b = false;
	if (b) {
		input[1] |= (1 << 4);
		return 0;
	} else {
		input[1] &= ~(1 << 4);
		goto node6359;
	}
node8126:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node8345;
	} else {
		input[2] &= ~(1 << 6);
		goto node3605;
	}
node5389:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node6469;
	} else {
		input[2] &= ~(1 << 5);
		goto node8922;
	}
node9171:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node7376;
	} else {
		input[3] &= ~(1 << 7);
		goto node127;
	}
node5365:
	b = true;
	if (b) {
		input[3] |= (1 << 7);
		goto node6132;
	} else {
		input[3] &= ~(1 << 7);
		return 0;
	}
node6249:
	b = randbool();
	if (b) {
		input[1] |= (1 << 3);
		goto node480;
	} else {
		input[1] &= ~(1 << 3);
		goto node5428;
	}
node2285:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node1319;
	}
node683:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node3191;
	} else {
		input[2] &= ~(1 << 3);
		goto node6052;
	}
node4145:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node7766;
	}
node4295:
	b = randbool();
	if (b) {
		input[3] |= (1 << 0);
		goto node8288;
	} else {
		input[3] &= ~(1 << 0);
		goto node6037;
	}
node2611:
	b = randbool();
	if (b) {
		input[4] |= (1 << 6);
		goto node8693;
	} else {
		input[4] &= ~(1 << 6);
		goto node6030;
	}
node8797:
	b = false;
	if (b) {
		input[2] |= (1 << 2);
		return 0;
	} else {
		input[2] &= ~(1 << 2);
		goto node847;
	}
node4926:
	b = false;
	if (b) {
		input[3] |= (1 << 1);
		return 0;
	} else {
		input[3] &= ~(1 << 1);
		goto node846;
	}
node6221:
	b = true;
	if (b) {
		input[4] |= (1 << 4);
		goto node7477;
	} else {
		input[4] &= ~(1 << 4);
		return 0;
	}
node345:
	b = false;
	if (b) {
		input[2] |= (1 << 5);
		return 0;
	} else {
		input[2] &= ~(1 << 5);
		goto node2285;
	}
node1596:
	b = true;
	if (b) {
		input[2] |= (1 << 3);
		goto node6574;
	} else {
		input[2] &= ~(1 << 3);
		return 0;
	}
node7726:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node6307;
	}
node2938:
	b = true;
	if (b) {
		input[4] |= (1 << 5);
		goto node2471;
	} else {
		input[4] &= ~(1 << 5);
		return 0;
	}
node361:
	b = randbool();
	if (b) {
		input[1] |= (1 << 5);
		goto node8385;
	} else {
		input[1] &= ~(1 << 5);
		goto node1944;
	}
node2047:
	b = true;
	if (b) {
		input[1] |= (1 << 5);
		goto node6709;
	} else {
		input[1] &= ~(1 << 5);
		return 0;
	}
node5220:
	b = true;
	if (b) {
		input[3] |= (1 << 6);
		goto node8099;
	} else {
		input[3] &= ~(1 << 6);
		return 0;
	}
node9410:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node7187;
	}
node2688:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node2979;
	} else {
		input[3] &= ~(1 << 4);
		goto node6351;
	}
node2140:
	b = false;
	if (b) {
		input[3] |= (1 << 1);
		return 0;
	} else {
		input[3] &= ~(1 << 1);
		goto node9297;
	}
node5343:
	b = randbool();
	if (b) {
		input[1] |= (1 << 0);
		goto node3179;
	} else {
		input[1] &= ~(1 << 0);
		goto node8160;
	}
node8763:
	b = true;
	if (b) {
		input[4] |= (1 << 6);
		goto node8855;
	} else {
		input[4] &= ~(1 << 6);
		return 0;
	}
node7125:
	b = randbool();
	if (b) {
		input[5] |= (1 << 0);
		return 7;
	} else {
		input[5] &= ~(1 << 0);
		goto node7921;
	}
node6991:
	b = randbool();
	if (b) {
		input[1] |= (1 << 0);
		goto node258;
	} else {
		input[1] &= ~(1 << 0);
		goto node8161;
	}
node6594:
	b = randbool();
	if (b) {
		input[2] |= (1 << 7);
		goto node5796;
	} else {
		input[2] &= ~(1 << 7);
		goto node4021;
	}
node7922:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node2806;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node763:
	b = randbool();
	if (b) {
		input[2] |= (1 << 7);
		goto node4126;
	} else {
		input[2] &= ~(1 << 7);
		goto node3270;
	}
node4383:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node6910;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node1321:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node7474;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node7007:
	b = true;
	if (b) {
		input[3] |= (1 << 1);
		goto node2936;
	} else {
		input[3] &= ~(1 << 1);
		return 0;
	}
node6347:
	b = true;
	if (b) {
		input[4] |= (1 << 2);
		goto node360;
	} else {
		input[4] &= ~(1 << 2);
		return 0;
	}
node3068:
	b = false;
	if (b) {
		input[4] |= (1 << 3);
		return 0;
	} else {
		input[4] &= ~(1 << 3);
		goto node628;
	}
node1133:
	b = true;
	if (b) {
		input[2] |= (1 << 6);
		goto node5800;
	} else {
		input[2] &= ~(1 << 6);
		return 0;
	}
node2569:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node4106;
	} else {
		input[3] &= ~(1 << 6);
		goto node150;
	}
node902:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node9332;
	}
node2778:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node5445;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node8875:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		return 5;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node1846:
	b = randbool();
	if (b) {
		input[4] |= (1 << 3);
		goto node8259;
	} else {
		input[4] &= ~(1 << 3);
		goto node555;
	}
node8500:
	b = false;
	if (b) {
		input[2] |= (1 << 0);
		return 0;
	} else {
		input[2] &= ~(1 << 0);
		goto node333;
	}
node2149:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node8303;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node6725:
	b = randbool();
	if (b) {
		input[1] |= (1 << 4);
		return 2;
	} else {
		input[1] &= ~(1 << 4);
		goto node7405;
	}
node9065:
	b = true;
	if (b) {
		input[3] |= (1 << 6);
		goto node2260;
	} else {
		input[3] &= ~(1 << 6);
		return 0;
	}
node5957:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node711;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node912:
	b = true;
	if (b) {
		input[4] |= (1 << 4);
		goto node6114;
	} else {
		input[4] &= ~(1 << 4);
		return 0;
	}
node630:
	b = randbool();
	if (b) {
		input[0] |= (1 << 0);
		goto node7322;
	} else {
		input[0] &= ~(1 << 0);
		goto node182;
	}
node1232:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node429;
	} else {
		input[2] &= ~(1 << 5);
		goto node4957;
	}
node1786:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node6519;
	} else {
		input[2] &= ~(1 << 2);
		goto node6454;
	}
node8927:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node5488;
	} else {
		input[2] &= ~(1 << 1);
		goto node7871;
	}
node1085:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node4162;
	}
node90:
	b = true;
	if (b) {
		input[3] |= (1 << 2);
		goto node3050;
	} else {
		input[3] &= ~(1 << 2);
		return 0;
	}
node7830:
	b = true;
	if (b) {
		input[1] |= (1 << 1);
		goto node287;
	} else {
		input[1] &= ~(1 << 1);
		return 0;
	}
node7712:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node8136;
	} else {
		input[2] &= ~(1 << 5);
		goto node2965;
	}
node1504:
	b = false;
	if (b) {
		input[2] |= (1 << 5);
		return 0;
	} else {
		input[2] &= ~(1 << 5);
		goto node431;
	}
node4028:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node3229;
	} else {
		input[3] &= ~(1 << 5);
		goto node6491;
	}
node870:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node5553;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node2374:
	b = true;
	if (b) {
		input[4] |= (1 << 7);
		goto node1825;
	} else {
		input[4] &= ~(1 << 7);
		return 0;
	}
node6892:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node5241;
	} else {
		input[3] &= ~(1 << 2);
		goto node2600;
	}
node1656:
	b = false;
	if (b) {
		input[3] |= (1 << 0);
		return 0;
	} else {
		input[3] &= ~(1 << 0);
		goto node4580;
	}
node7709:
	b = randbool();
	if (b) {
		input[4] |= (1 << 6);
		goto node990;
	} else {
		input[4] &= ~(1 << 6);
		goto node9078;
	}
node3327:
	b = false;
	if (b) {
		input[4] |= (1 << 0);
		return 0;
	} else {
		input[4] &= ~(1 << 0);
		goto node7203;
	}
node7771:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node8889;
	} else {
		input[2] &= ~(1 << 3);
		goto node4390;
	}
node2008:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		goto node1928;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node6053:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node5365;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node2541:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node6713;
	}
node7723:
	b = randbool();
	if (b) {
		input[1] |= (1 << 5);
		goto node8774;
	} else {
		input[1] &= ~(1 << 5);
		goto node8802;
	}
node7385:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		goto node3376;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node1811:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node6011;
	} else {
		input[3] &= ~(1 << 6);
		goto node2680;
	}
node1640:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node8086;
	} else {
		input[3] &= ~(1 << 6);
		goto node6579;
	}
node5728:
	b = false;
	if (b) {
		input[3] |= (1 << 2);
		return 0;
	} else {
		input[3] &= ~(1 << 2);
		goto node5298;
	}
node3368:
	b = true;
	if (b) {
		input[4] |= (1 << 2);
		goto node1897;
	} else {
		input[4] &= ~(1 << 2);
		return 0;
	}
node8711:
	b = false;
	if (b) {
		input[2] |= (1 << 6);
		return 0;
	} else {
		input[2] &= ~(1 << 6);
		goto node92;
	}
node5359:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node4369;
	} else {
		input[2] &= ~(1 << 4);
		goto node8272;
	}
node759:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node1524;
	} else {
		input[3] &= ~(1 << 2);
		goto node7920;
	}
node7018:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node118;
	}
node301:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node8014;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node6505:
	b = randbool();
	if (b) {
		input[1] |= (1 << 0);
		goto node7383;
	} else {
		input[1] &= ~(1 << 0);
		goto node9271;
	}
node155:
	b = randbool();
	if (b) {
		input[1] |= (1 << 0);
		return 2;
	} else {
		input[1] &= ~(1 << 0);
		return 5;
	}
node7672:
	b = false;
	if (b) {
		input[2] |= (1 << 5);
		return 0;
	} else {
		input[2] &= ~(1 << 5);
		goto node7687;
	}
node1887:
	b = false;
	if (b) {
		input[2] |= (1 << 3);
		return 0;
	} else {
		input[2] &= ~(1 << 3);
		goto node2473;
	}
node125:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node2187;
	} else {
		input[2] &= ~(1 << 3);
		goto node2775;
	}
node1189:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node4791;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node5770:
	b = true;
	if (b) {
		input[0] |= (1 << 0);
		goto node2298;
	} else {
		input[0] &= ~(1 << 0);
		return 0;
	}
node1278:
	b = true;
	if (b) {
		input[3] |= (1 << 6);
		goto node3814;
	} else {
		input[3] &= ~(1 << 6);
		return 0;
	}
node8685:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node2745;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node566:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node1443;
	}
node7982:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node5099;
	}
node781:
	b = false;
	if (b) {
		input[3] |= (1 << 2);
		return 0;
	} else {
		input[3] &= ~(1 << 2);
		goto node2853;
	}
node7363:
	b = randbool();
	if (b) {
		input[1] |= (1 << 7);
		goto node2695;
	} else {
		input[1] &= ~(1 << 7);
		goto node4333;
	}
node6620:
	b = randbool();
	if (b) {
		input[2] |= (1 << 7);
		goto node853;
	} else {
		input[2] &= ~(1 << 7);
		goto node4345;
	}
node3849:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		goto node813;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node4809:
	b = false;
	if (b) {
		input[4] |= (1 << 5);
		return 0;
	} else {
		input[4] &= ~(1 << 5);
		goto node990;
	}
node3218:
	b = false;
	if (b) {
		input[3] |= (1 << 6);
		return 0;
	} else {
		input[3] &= ~(1 << 6);
		goto node4307;
	}
node5979:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node896;
	} else {
		input[3] &= ~(1 << 3);
		goto node8361;
	}
node2407:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node6200;
	} else {
		input[3] &= ~(1 << 2);
		goto node8686;
	}
node3056:
	b = true;
	if (b) {
		input[3] |= (1 << 1);
		goto node1129;
	} else {
		input[3] &= ~(1 << 1);
		return 0;
	}
node1689:
	b = randbool();
	if (b) {
		input[4] |= (1 << 7);
		goto node522;
	} else {
		input[4] &= ~(1 << 7);
		goto node3412;
	}
node5800:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node7364;
	} else {
		input[2] &= ~(1 << 5);
		goto node2770;
	}
node939:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node6234;
	} else {
		input[2] &= ~(1 << 1);
		goto node8078;
	}
node3722:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node8608;
	} else {
		input[3] &= ~(1 << 5);
		goto node5586;
	}
node3457:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node6071;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node3169:
	b = false;
	if (b) {
		input[5] |= (1 << 1);
		return 0;
	} else {
		input[5] &= ~(1 << 1);
		goto node7274;
	}
node3410:
	b = false;
	if (b) {
		input[2] |= (1 << 2);
		return 0;
	} else {
		input[2] &= ~(1 << 2);
		goto node626;
	}
node6208:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node5034;
	} else {
		input[2] &= ~(1 << 1);
		goto node1193;
	}
node1496:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node5366;
	} else {
		input[3] &= ~(1 << 6);
		goto node8127;
	}
node7054:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node8107;
	} else {
		input[3] &= ~(1 << 2);
		goto node5259;
	}
node3649:
	b = true;
	if (b) {
		input[3] |= (1 << 2);
		goto node5779;
	} else {
		input[3] &= ~(1 << 2);
		return 0;
	}
node6940:
	b = false;
	if (b) {
		input[3] |= (1 << 1);
		return 0;
	} else {
		input[3] &= ~(1 << 1);
		goto node5776;
	}
node7456:
	b = false;
	if (b) {
		input[4] |= (1 << 7);
		return 0;
	} else {
		input[4] &= ~(1 << 7);
		goto node7638;
	}
node1629:
	b = randbool();
	if (b) {
		input[1] |= (1 << 6);
		goto node2705;
	} else {
		input[1] &= ~(1 << 6);
		goto node876;
	}
node527:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node776;
	} else {
		input[3] &= ~(1 << 6);
		goto node3411;
	}
node1909:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node8673;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node2750:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node1383;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node7789:
	b = false;
	if (b) {
		input[3] |= (1 << 1);
		return 0;
	} else {
		input[3] &= ~(1 << 1);
		goto node5998;
	}
node8988:
	b = randbool();
	if (b) {
		input[3] |= (1 << 1);
		goto node2936;
	} else {
		input[3] &= ~(1 << 1);
		goto node6462;
	}
node8037:
	b = true;
	if (b) {
		input[2] |= (1 << 2);
		goto node5931;
	} else {
		input[2] &= ~(1 << 2);
		return 0;
	}
node6865:
	b = false;
	if (b) {
		input[3] |= (1 << 6);
		return 0;
	} else {
		input[3] &= ~(1 << 6);
		goto node4288;
	}
node879:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node9302;
	} else {
		input[3] &= ~(1 << 6);
		goto node8039;
	}
node2083:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node8910;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node7778:
	b = true;
	if (b) {
		input[2] |= (1 << 5);
		goto node8860;
	} else {
		input[2] &= ~(1 << 5);
		return 0;
	}
node2855:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node8001;
	} else {
		input[2] &= ~(1 << 5);
		goto node5648;
	}
node9272:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node9294;
	}
node4402:
	b = false;
	if (b) {
		input[3] |= (1 << 7);
		return 0;
	} else {
		input[3] &= ~(1 << 7);
		goto node7143;
	}
node7408:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node1597;
	} else {
		input[2] &= ~(1 << 4);
		goto node9210;
	}
node3228:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node5866;
	}
node2522:
	b = true;
	if (b) {
		input[3] |= (1 << 1);
		goto node1089;
	} else {
		input[3] &= ~(1 << 1);
		return 0;
	}
node5411:
	b = false;
	if (b) {
		input[4] |= (1 << 7);
		return 0;
	} else {
		input[4] &= ~(1 << 7);
		goto node979;
	}
node5199:
	b = false;
	if (b) {
		input[4] |= (1 << 7);
		return 0;
	} else {
		input[4] &= ~(1 << 7);
		goto node3070;
	}
node8289:
	b = true;
	if (b) {
		input[4] |= (1 << 5);
		goto node5260;
	} else {
		input[4] &= ~(1 << 5);
		return 0;
	}
node5868:
	b = randbool();
	if (b) {
		input[1] |= (1 << 3);
		goto node6479;
	} else {
		input[1] &= ~(1 << 3);
		goto node3436;
	}
node7797:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node5739;
	} else {
		input[2] &= ~(1 << 3);
		goto node145;
	}
node3026:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node1996;
	} else {
		input[2] &= ~(1 << 1);
		goto node5116;
	}
node5877:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		return 4;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node2489:
	b = randbool();
	if (b) {
		input[4] |= (1 << 4);
		goto node7512;
	} else {
		input[4] &= ~(1 << 4);
		goto node1096;
	}
node3448:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node3487;
	} else {
		input[2] &= ~(1 << 3);
		goto node1873;
	}
node5272:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node1903;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node4267:
	b = false;
	if (b) {
		input[4] |= (1 << 7);
		return 0;
	} else {
		input[4] &= ~(1 << 7);
		goto node236;
	}
node5363:
	b = false;
	if (b) {
		input[1] |= (1 << 3);
		return 0;
	} else {
		input[1] &= ~(1 << 3);
		goto node7115;
	}
node4745:
	b = false;
	if (b) {
		input[2] |= (1 << 7);
		return 0;
	} else {
		input[2] &= ~(1 << 7);
		goto node6390;
	}
node563:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node6354;
	} else {
		input[2] &= ~(1 << 2);
		goto node8177;
	}
node4299:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node4885;
	} else {
		input[3] &= ~(1 << 4);
		goto node6462;
	}
node2843:
	b = true;
	if (b) {
		input[1] |= (1 << 0);
		goto node7277;
	} else {
		input[1] &= ~(1 << 0);
		return 0;
	}
node3543:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node3946;
	} else {
		input[2] &= ~(1 << 5);
		goto node3114;
	}
node3449:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node6766;
	} else {
		input[3] &= ~(1 << 6);
		goto node9211;
	}
node3478:
	b = true;
	if (b) {
		input[3] |= (1 << 2);
		goto node1126;
	} else {
		input[3] &= ~(1 << 2);
		return 0;
	}
node2943:
	b = randbool();
	if (b) {
		input[4] |= (1 << 5);
		goto node2712;
	} else {
		input[4] &= ~(1 << 5);
		goto node2647;
	}
node6417:
	b = randbool();
	if (b) {
		input[5] |= (1 << 6);
		goto node5021;
	} else {
		input[5] &= ~(1 << 6);
		goto node5541;
	}
node6847:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node6611;
	} else {
		input[2] &= ~(1 << 5);
		goto node1795;
	}
node9429:
	b = true;
	if (b) {
		input[2] |= (1 << 4);
		goto node4728;
	} else {
		input[2] &= ~(1 << 4);
		return 0;
	}
node6069:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node5196;
	}
node7575:
	b = true;
	if (b) {
		input[4] |= (1 << 5);
		goto node5895;
	} else {
		input[4] &= ~(1 << 5);
		return 0;
	}
node8054:
	b = false;
	if (b) {
		input[4] |= (1 << 2);
		return 0;
	} else {
		input[4] &= ~(1 << 2);
		goto node8180;
	}
node7837:
	b = randbool();
	if (b) {
		input[6] |= (1 << 7);
		goto node1749;
	} else {
		input[6] &= ~(1 << 7);
		goto node9399;
	}
node8820:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node636;
	} else {
		input[2] &= ~(1 << 3);
		goto node1210;
	}
node3988:
	b = true;
	if (b) {
		input[3] |= (1 << 7);
		goto node2749;
	} else {
		input[3] &= ~(1 << 7);
		return 0;
	}
node9376:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node5100;
	} else {
		input[3] &= ~(1 << 2);
		goto node1896;
	}
node4372:
	b = randbool();
	if (b) {
		input[4] |= (1 << 3);
		goto node7777;
	} else {
		input[4] &= ~(1 << 3);
		goto node1019;
	}
node6823:
	b = randbool();
	if (b) {
		input[3] |= (1 << 1);
		goto node2584;
	} else {
		input[3] &= ~(1 << 1);
		goto node2936;
	}
node5227:
	b = true;
	if (b) {
		input[7] |= (1 << 2);
		goto node2368;
	} else {
		input[7] &= ~(1 << 2);
		return 0;
	}
node8021:
	b = false;
	if (b) {
		input[2] |= (1 << 6);
		return 0;
	} else {
		input[2] &= ~(1 << 6);
		goto node5154;
	}
node7189:
	b = true;
	if (b) {
		input[2] |= (1 << 2);
		goto node8167;
	} else {
		input[2] &= ~(1 << 2);
		return 0;
	}
node6605:
	b = false;
	if (b) {
		input[2] |= (1 << 2);
		return 0;
	} else {
		input[2] &= ~(1 << 2);
		goto node4005;
	}
node9028:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node8013;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node5221:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node4179;
	}
node349:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node539;
	} else {
		input[3] &= ~(1 << 3);
		goto node7287;
	}
node8871:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node4416;
	} else {
		input[3] &= ~(1 << 2);
		return 5;
	}
node8574:
	b = randbool();
	if (b) {
		input[3] |= (1 << 0);
		goto node6462;
	} else {
		input[3] &= ~(1 << 0);
		goto node2584;
	}
node2324:
	b = false;
	if (b) {
		input[4] |= (1 << 5);
		return 0;
	} else {
		input[4] &= ~(1 << 5);
		goto node6842;
	}
node8222:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node7780;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node204:
	b = true;
	if (b) {
		input[3] |= (1 << 2);
		goto node7444;
	} else {
		input[3] &= ~(1 << 2);
		return 0;
	}
node5019:
	b = randbool();
	if (b) {
		input[4] |= (1 << 6);
		goto node5277;
	} else {
		input[4] &= ~(1 << 6);
		goto node4587;
	}
node6408:
	b = false;
	if (b) {
		input[2] |= (1 << 3);
		return 0;
	} else {
		input[2] &= ~(1 << 3);
		goto node7761;
	}
node2367:
	b = false;
	if (b) {
		input[4] |= (1 << 0);
		return 0;
	} else {
		input[4] &= ~(1 << 0);
		goto node6994;
	}
node9304:
	b = false;
	if (b) {
		input[1] |= (1 << 0);
		return 0;
	} else {
		input[1] &= ~(1 << 0);
		goto node3113;
	}
node7916:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node2327;
	} else {
		input[2] &= ~(1 << 6);
		goto node5705;
	}
node6739:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node5510;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node8528:
	b = randbool();
	if (b) {
		input[4] |= (1 << 1);
		goto node7485;
	} else {
		input[4] &= ~(1 << 1);
		goto node2027;
	}
node7704:
	b = true;
	if (b) {
		input[1] |= (1 << 0);
		return 3;
	} else {
		input[1] &= ~(1 << 0);
		return 0;
	}
node8141:
	b = randbool();
	if (b) {
		input[1] |= (1 << 2);
		goto node6186;
	} else {
		input[1] &= ~(1 << 2);
		goto node9072;
	}
node4851:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node6361;
	} else {
		input[2] &= ~(1 << 4);
		goto node2619;
	}
node3385:
	b = false;
	if (b) {
		input[2] |= (1 << 1);
		return 0;
	} else {
		input[2] &= ~(1 << 1);
		goto node8220;
	}
node1916:
	b = false;
	if (b) {
		input[6] |= (1 << 1);
		return 0;
	} else {
		input[6] &= ~(1 << 1);
		goto node3031;
	}
node3949:
	b = false;
	if (b) {
		input[2] |= (1 << 5);
		return 0;
	} else {
		input[2] &= ~(1 << 5);
		goto node8729;
	}
node1663:
	b = false;
	if (b) {
		input[2] |= (1 << 1);
		return 0;
	} else {
		input[2] &= ~(1 << 1);
		goto node7169;
	}
node4872:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node3963;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node7531:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		return 4;
	} else {
		input[3] &= ~(1 << 4);
		goto node794;
	}
node1470:
	b = false;
	if (b) {
		input[4] |= (1 << 1);
		return 0;
	} else {
		input[4] &= ~(1 << 1);
		goto node2396;
	}
node670:
	b = randbool();
	if (b) {
		input[2] |= (1 << 7);
		goto node953;
	} else {
		input[2] &= ~(1 << 7);
		goto node7458;
	}
node2257:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node7887;
	} else {
		input[2] &= ~(1 << 3);
		goto node5921;
	}
node6116:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node4323;
	} else {
		input[3] &= ~(1 << 5);
		goto node275;
	}
node3429:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node6462;
	} else {
		input[3] &= ~(1 << 3);
		goto node4712;
	}
node6542:
	b = false;
	if (b) {
		input[4] |= (1 << 4);
		return 0;
	} else {
		input[4] &= ~(1 << 4);
		goto node9078;
	}
node4017:
	b = randbool();
	if (b) {
		input[5] |= (1 << 7);
		goto node7849;
	} else {
		input[5] &= ~(1 << 7);
		goto node3203;
	}
node8120:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node6722;
	} else {
		input[2] &= ~(1 << 2);
		goto node4095;
	}
node3876:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node6428;
	} else {
		input[2] &= ~(1 << 1);
		goto node7887;
	}
node6969:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node9273;
	} else {
		input[3] &= ~(1 << 6);
		goto node1355;
	}
node9055:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node3291;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node5449:
	b = true;
	if (b) {
		input[4] |= (1 << 2);
		goto node9274;
	} else {
		input[4] &= ~(1 << 2);
		return 0;
	}
node9274:
	b = false;
	if (b) {
		input[4] |= (1 << 1);
		return 0;
	} else {
		input[4] &= ~(1 << 1);
		goto node8213;
	}
node7073:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node8062;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node347:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node4398;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node4542:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node3726;
	} else {
		input[3] &= ~(1 << 5);
		goto node7531;
	}
node4300:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node73;
	} else {
		input[3] &= ~(1 << 4);
		goto node1531;
	}
node8439:
	b = randbool();
	if (b) {
		input[3] |= (1 << 0);
		goto node8288;
	} else {
		input[3] &= ~(1 << 0);
		goto node2989;
	}
node4128:
	b = true;
	if (b) {
		input[4] |= (1 << 3);
		goto node4116;
	} else {
		input[4] &= ~(1 << 3);
		return 0;
	}
node3859:
	b = randbool();
	if (b) {
		input[1] |= (1 << 3);
		goto node5301;
	} else {
		input[1] &= ~(1 << 3);
		goto node4594;
	}
node8132:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node7908;
	} else {
		input[2] &= ~(1 << 4);
		goto node2130;
	}
node3298:
	b = true;
	if (b) {
		input[3] |= (1 << 1);
		goto node9342;
	} else {
		input[3] &= ~(1 << 1);
		return 0;
	}
node4319:
	b = randbool();
	if (b) {
		input[0] |= (1 << 2);
		goto node6001;
	} else {
		input[0] &= ~(1 << 2);
		goto node8232;
	}
node6002:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node8919;
	} else {
		input[2] &= ~(1 << 5);
		goto node5619;
	}
node3272:
	b = randbool();
	if (b) {
		input[2] |= (1 << 0);
		goto node7070;
	} else {
		input[2] &= ~(1 << 0);
		goto node1667;
	}
node901:
	b = true;
	if (b) {
		input[3] |= (1 << 6);
		goto node6020;
	} else {
		input[3] &= ~(1 << 6);
		return 0;
	}
node3841:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node2083;
	}
node7421:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node2525;
	} else {
		input[3] &= ~(1 << 4);
		goto node8867;
	}
node2349:
	b = true;
	if (b) {
		input[1] |= (1 << 0);
		goto node6450;
	} else {
		input[1] &= ~(1 << 0);
		return 0;
	}
node253:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node2095;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node7661:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node2267;
	}
node7826:
	b = randbool();
	if (b) {
		input[4] |= (1 << 4);
		goto node1096;
	} else {
		input[4] &= ~(1 << 4);
		goto node5193;
	}
node1005:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node2844;
	} else {
		input[2] &= ~(1 << 6);
		goto node3150;
	}
node6009:
	b = true;
	if (b) {
		input[2] |= (1 << 2);
		goto node1025;
	} else {
		input[2] &= ~(1 << 2);
		return 0;
	}
node36:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node871;
	} else {
		input[3] &= ~(1 << 2);
		goto node2470;
	}
node4335:
	b = false;
	if (b) {
		input[3] |= (1 << 1);
		return 0;
	} else {
		input[3] &= ~(1 << 1);
		goto node5709;
	}
node893:
	b = true;
	if (b) {
		input[4] |= (1 << 7);
		goto node3401;
	} else {
		input[4] &= ~(1 << 7);
		return 0;
	}
node8288:
	b = true;
	if (b) {
		input[4] |= (1 << 7);
		goto node894;
	} else {
		input[4] &= ~(1 << 7);
		return 0;
	}
node6382:
	b = true;
	if (b) {
		input[4] |= (1 << 7);
		goto node2111;
	} else {
		input[4] &= ~(1 << 7);
		return 0;
	}
node1387:
	b = false;
	if (b) {
		input[4] |= (1 << 3);
		return 0;
	} else {
		input[4] &= ~(1 << 3);
		goto node599;
	}
node2970:
	b = randbool();
	if (b) {
		input[1] |= (1 << 6);
		goto node5474;
	} else {
		input[1] &= ~(1 << 6);
		goto node1637;
	}
node1589:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node6497;
	} else {
		input[2] &= ~(1 << 1);
		goto node2187;
	}
node1924:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node9022;
	}
node7027:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node5153;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node8854:
	b = randbool();
	if (b) {
		input[3] |= (1 << 1);
		goto node6194;
	} else {
		input[3] &= ~(1 << 1);
		goto node4735;
	}
node188:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node5983;
	} else {
		input[3] &= ~(1 << 2);
		goto node2600;
	}
node1176:
	b = true;
	if (b) {
		input[3] |= (1 << 1);
		goto node2989;
	} else {
		input[3] &= ~(1 << 1);
		return 0;
	}
node8918:
	b = true;
	if (b) {
		input[1] |= (1 << 4);
		goto node545;
	} else {
		input[1] &= ~(1 << 4);
		return 0;
	}
node4344:
	b = true;
	if (b) {
		input[1] |= (1 << 1);
		goto node9401;
	} else {
		input[1] &= ~(1 << 1);
		return 0;
	}
node1403:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node7364;
	} else {
		input[2] &= ~(1 << 5);
		goto node745;
	}
node3391:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node6371;
	} else {
		input[2] &= ~(1 << 1);
		goto node2187;
	}
node3192:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node4191;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node4652:
	b = false;
	if (b) {
		input[3] |= (1 << 6);
		return 0;
	} else {
		input[3] &= ~(1 << 6);
		goto node567;
	}
node5565:
	b = randbool();
	if (b) {
		input[4] |= (1 << 5);
		goto node3183;
	} else {
		input[4] &= ~(1 << 5);
		goto node5170;
	}
node8983:
	b = true;
	if (b) {
		input[5] |= (1 << 2);
		return 6;
	} else {
		input[5] &= ~(1 << 2);
		return 0;
	}
node5742:
	b = false;
	if (b) {
		input[6] |= (1 << 1);
		return 0;
	} else {
		input[6] &= ~(1 << 1);
		goto node8393;
	}
node8249:
	b = randbool();
	if (b) {
		input[3] |= (1 << 3);
		goto node3650;
	} else {
		input[3] &= ~(1 << 3);
		goto node951;
	}
node2526:
	b = false;
	if (b) {
		input[3] |= (1 << 2);
		return 0;
	} else {
		input[3] &= ~(1 << 2);
		goto node3936;
	}
node9103:
	b = true;
	if (b) {
		input[1] |= (1 << 5);
		goto node723;
	} else {
		input[1] &= ~(1 << 5);
		return 0;
	}
node511:
	b = randbool();
	if (b) {
		input[2] |= (1 << 6);
		goto node8427;
	} else {
		input[2] &= ~(1 << 6);
		goto node5457;
	}
node4211:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node2762;
	} else {
		input[2] &= ~(1 << 2);
		goto node6553;
	}
node6394:
	b = true;
	if (b) {
		input[3] |= (1 << 6);
		goto node2453;
	} else {
		input[3] &= ~(1 << 6);
		return 0;
	}
node389:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node4349;
	} else {
		input[3] &= ~(1 << 5);
		goto node2800;
	}
node8450:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node2382;
	} else {
		input[3] &= ~(1 << 4);
		goto node3107;
	}
node8974:
	b = false;
	if (b) {
		input[4] |= (1 << 2);
		return 0;
	} else {
		input[4] &= ~(1 << 2);
		goto node7894;
	}
node8628:
	b = randbool();
	if (b) {
		input[1] |= (1 << 5);
		goto node1838;
	} else {
		input[1] &= ~(1 << 5);
		return 2;
	}
node5423:
	b = randbool();
	if (b) {
		input[1] |= (1 << 0);
		goto node4948;
	} else {
		input[1] &= ~(1 << 0);
		goto node6620;
	}
node8786:
	b = randbool();
	if (b) {
		input[2] |= (1 << 7);
		goto node4801;
	} else {
		input[2] &= ~(1 << 7);
		goto node1566;
	}
node7567:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node2281;
	} else {
		input[2] &= ~(1 << 4);
		goto node1597;
	}
node1444:
	b = true;
	if (b) {
		input[3] |= (1 << 2);
		goto node3377;
	} else {
		input[3] &= ~(1 << 2);
		return 0;
	}
node4675:
	b = true;
	if (b) {
		input[3] |= (1 << 0);
		goto node5818;
	} else {
		input[3] &= ~(1 << 0);
		return 0;
	}
node4438:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node8336;
	} else {
		input[2] &= ~(1 << 5);
		goto node8727;
	}
node2465:
	b = randbool();
	if (b) {
		input[2] |= (1 << 0);
		return 8;
	} else {
		input[2] &= ~(1 << 0);
		return 4;
	}
node2768:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node3420;
	} else {
		input[3] &= ~(1 << 7);
		goto node4063;
	}
node4627:
	b = false;
	if (b) {
		input[3] |= (1 << 7);
		return 0;
	} else {
		input[3] &= ~(1 << 7);
		goto node5249;
	}
node3497:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node1918;
	}
node8590:
	b = randbool();
	if (b) {
		input[1] |= (1 << 0);
		goto node8744;
	} else {
		input[1] &= ~(1 << 0);
		goto node8901;
	}
node3730:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		return 3;
	} else {
		input[2] &= ~(1 << 5);
		goto node8211;
	}
node7931:
	b = randbool();
	if (b) {
		input[2] |= (1 << 0);
		goto node2187;
	} else {
		input[2] &= ~(1 << 0);
		goto node5125;
	}
node9139:
	b = false;
	if (b) {
		input[3] |= (1 << 7);
		return 0;
	} else {
		input[3] &= ~(1 << 7);
		goto node4306;
	}
node2468:
	b = false;
	if (b) {
		input[3] |= (1 << 3);
		return 0;
	} else {
		input[3] &= ~(1 << 3);
		goto node7919;
	}
node1782:
	b = randbool();
	if (b) {
		input[1] |= (1 << 4);
		goto node8847;
	} else {
		input[1] &= ~(1 << 4);
		goto node7298;
	}
node2066:
	b = randbool();
	if (b) {
		input[2] |= (1 << 3);
		goto node7738;
	} else {
		input[2] &= ~(1 << 3);
		goto node7470;
	}
node1013:
	b = true;
	if (b) {
		input[4] |= (1 << 3);
		goto node5729;
	} else {
		input[4] &= ~(1 << 3);
		return 0;
	}
node8893:
	b = true;
	if (b) {
		input[5] |= (1 << 4);
		goto node2495;
	} else {
		input[5] &= ~(1 << 4);
		return 0;
	}
node3980:
	b = randbool();
	if (b) {
		input[1] |= (1 << 4);
		goto node8283;
	} else {
		input[1] &= ~(1 << 4);
		goto node4343;
	}
node6432:
	b = true;
	if (b) {
		input[1] |= (1 << 0);
		goto node3697;
	} else {
		input[1] &= ~(1 << 0);
		return 0;
	}
node6468:
	b = randbool();
	if (b) {
		input[1] |= (1 << 0);
		goto node2606;
	} else {
		input[1] &= ~(1 << 0);
		goto node5244;
	}
node3247:
	b = randbool();
	if (b) {
		input[2] |= (1 << 7);
		goto node1462;
	} else {
		input[2] &= ~(1 << 7);
		goto node6231;
	}
node1854:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node1805;
	} else {
		input[2] &= ~(1 << 5);
		goto node6925;
	}
node3233:
	b = false;
	if (b) {
		input[4] |= (1 << 5);
		return 0;
	} else {
		input[4] &= ~(1 << 5);
		goto node1837;
	}
node5794:
	b = false;
	if (b) {
		input[4] |= (1 << 4);
		return 0;
	} else {
		input[4] &= ~(1 << 4);
		goto node7513;
	}
node6170:
	b = randbool();
	if (b) {
		input[1] |= (1 << 0);
		goto node8204;
	} else {
		input[1] &= ~(1 << 0);
		goto node3712;
	}
node3341:
	b = false;
	if (b) {
		input[2] |= (1 << 5);
		return 0;
	} else {
		input[2] &= ~(1 << 5);
		goto node3889;
	}
node6192:
	b = false;
	if (b) {
		input[2] |= (1 << 4);
		return 0;
	} else {
		input[2] &= ~(1 << 4);
		goto node8321;
	}
node9358:
	b = true;
	if (b) {
		input[2] |= (1 << 3);
		goto node7940;
	} else {
		input[2] &= ~(1 << 3);
		return 0;
	}
node309:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		return 4;
	} else {
		input[3] &= ~(1 << 5);
		goto node5318;
	}
node3701:
	b = true;
	if (b) {
		input[3] |= (1 << 4);
		goto node4579;
	} else {
		input[3] &= ~(1 << 4);
		return 0;
	}
node1377:
	b = randbool();
	if (b) {
		input[1] |= (1 << 0);
		goto node1921;
	} else {
		input[1] &= ~(1 << 0);
		goto node7988;
	}
node3525:
	b = randbool();
	if (b) {
		input[2] |= (1 << 7);
		goto node8770;
	} else {
		input[2] &= ~(1 << 7);
		goto node815;
	}
node2080:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node8976;
	} else {
		input[2] &= ~(1 << 5);
		goto node861;
	}
node1618:
	b = true;
	if (b) {
		input[2] |= (1 << 3);
		goto node6756;
	} else {
		input[2] &= ~(1 << 3);
		return 0;
	}
node7138:
	b = true;
	if (b) {
		input[3] |= (1 << 5);
		goto node3506;
	} else {
		input[3] &= ~(1 << 5);
		return 0;
	}
node6330:
	b = true;
	if (b) {
		input[2] |= (1 << 2);
		goto node1084;
	} else {
		input[2] &= ~(1 << 2);
		return 0;
	}
node7396:
	b = false;
	if (b) {
		input[2] |= (1 << 1);
		return 0;
	} else {
		input[2] &= ~(1 << 1);
		goto node6288;
	}
node9370:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node3512;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node9363:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node3736;
	}
node7681:
	b = randbool();
	if (b) {
		input[0] |= (1 << 0);
		goto node6174;
	} else {
		input[0] &= ~(1 << 0);
		goto node5673;
	}
node7286:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		goto node2303;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node5433:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node7048;
	} else {
		input[3] &= ~(1 << 7);
		goto node6160;
	}
node1609:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node7295;
	}
node7162:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node5392;
	} else {
		input[3] &= ~(1 << 4);
		goto node6240;
	}
node4948:
	b = randbool();
	if (b) {
		input[2] |= (1 << 7);
		goto node2326;
	} else {
		input[2] &= ~(1 << 7);
		goto node4406;
	}
node2666:
	b = false;
	if (b) {
		input[2] |= (1 << 3);
		return 0;
	} else {
		input[2] &= ~(1 << 3);
		goto node189;
	}
node7479:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node3799;
	} else {
		input[2] &= ~(1 << 1);
		goto node5345;
	}
node6718:
	b = true;
	if (b) {
		input[4] |= (1 << 5);
		goto node5635;
	} else {
		input[4] &= ~(1 << 5);
		return 0;
	}
node7468:
	b = randbool();
	if (b) {
		input[5] |= (1 << 6);
		goto node1196;
	} else {
		input[5] &= ~(1 << 6);
		goto node3829;
	}
node1385:
	b = randbool();
	if (b) {
		input[2] |= (1 << 5);
		goto node3609;
	} else {
		input[2] &= ~(1 << 5);
		goto node2556;
	}
node6040:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node8755;
	} else {
		input[3] &= ~(1 << 6);
		goto node2020;
	}
node6466:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node5942;
	} else {
		input[3] &= ~(1 << 4);
		goto node2219;
	}
node2021:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node6041;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node2773:
	b = false;
	if (b) {
		input[4] |= (1 << 5);
		return 0;
	} else {
		input[4] &= ~(1 << 5);
		goto node2183;
	}
node7602:
	b = randbool();
	if (b) {
		input[1] |= (1 << 5);
		goto node592;
	} else {
		input[1] &= ~(1 << 5);
		goto node5848;
	}
node5881:
	b = randbool();
	if (b) {
		input[3] |= (1 << 2);
		goto node2181;
	} else {
		input[3] &= ~(1 << 2);
		goto node8686;
	}
node3356:
	b = randbool();
	if (b) {
		input[1] |= (1 << 4);
		goto node50;
	} else {
		input[1] &= ~(1 << 4);
		goto node4195;
	}
node2282:
	b = randbool();
	if (b) {
		input[3] |= (1 << 7);
		goto node3243;
	} else {
		input[3] &= ~(1 << 7);
		goto node8104;
	}
node4073:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node1947;
	} else {
		input[3] &= ~(1 << 5);
		goto node3506;
	}
node4502:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node4609;
	} else {
		input[2] &= ~(1 << 2);
		goto node8307;
	}
node7107:
	b = false;
	if (b) {
		input[2] |= (1 << 1);
		return 0;
	} else {
		input[2] &= ~(1 << 1);
		goto node2920;
	}
node4187:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node8933;
	}
node2811:
	b = false;
	if (b) {
		input[3] |= (1 << 2);
		return 0;
	} else {
		input[3] &= ~(1 << 2);
		goto node9003;
	}
node6426:
	b = randbool();
	if (b) {
		input[2] |= (1 << 2);
		goto node2767;
	} else {
		input[2] &= ~(1 << 2);
		return 4;
	}
node9121:
	b = false;
	if (b) {
		input[2] |= (1 << 1);
		return 0;
	} else {
		input[2] &= ~(1 << 1);
		goto node2057;
	}
node436:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node3668;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node3381:
	b = false;
	if (b) {
		input[3] |= (1 << 5);
		return 0;
	} else {
		input[3] &= ~(1 << 5);
		goto node5893;
	}
node732:
	b = randbool();
	if (b) {
		input[1] |= (1 << 5);
		goto node6725;
	} else {
		input[1] &= ~(1 << 5);
		goto node170;
	}
node6701:
	b = randbool();
	if (b) {
		input[2] |= (1 << 0);
		goto node7070;
	} else {
		input[2] &= ~(1 << 0);
		goto node1619;
	}
node6295:
	b = randbool();
	if (b) {
		input[3] |= (1 << 6);
		goto node5482;
	} else {
		input[3] &= ~(1 << 6);
		goto node1839;
	}
node8604:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node8827;
	}
node3700:
	b = randbool();
	if (b) {
		input[3] |= (1 << 4);
		goto node7661;
	} else {
		input[3] &= ~(1 << 4);
		goto node2267;
	}
node2427:
	b = true;
	if (b) {
		input[3] |= (1 << 3);
		goto node5505;
	} else {
		input[3] &= ~(1 << 3);
		return 0;
	}
node7185:
	b = false;
	if (b) {
		input[4] |= (1 << 3);
		return 0;
	} else {
		input[4] &= ~(1 << 3);
		goto node3288;
	}
node8961:
	b = randbool();
	if (b) {
		input[1] |= (1 << 2);
		goto node6905;
	} else {
		input[1] &= ~(1 << 2);
		goto node3443;
	}
node4800:
	b = randbool();
	if (b) {
		input[1] |= (1 << 0);
		goto node1296;
	} else {
		input[1] &= ~(1 << 0);
		goto node6140;
	}
node3906:
	b = true;
	if (b) {
		input[2] |= (1 << 5);
		goto node4066;
	} else {
		input[2] &= ~(1 << 5);
		return 0;
	}
node5360:
	b = false;
	if (b) {
		input[2] |= (1 << 3);
		return 0;
	} else {
		input[2] &= ~(1 << 3);
		goto node855;
	}
node6055:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node4402;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node8214:
	b = true;
	if (b) {
		input[2] |= (1 << 0);
		goto node6511;
	} else {
		input[2] &= ~(1 << 0);
		return 0;
	}
node7267:
	b = true;
	if (b) {
		input[1] |= (1 << 0);
		goto node7382;
	} else {
		input[1] &= ~(1 << 0);
		return 0;
	}
node6438:
	b = false;
	if (b) {
		input[2] |= (1 << 6);
		return 0;
	} else {
		input[2] &= ~(1 << 6);
		goto node3500;
	}
node2677:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node8457;
	} else {
		input[2] &= ~(1 << 1);
		goto node1193;
	}
node2520:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node7083;
	}
node336:
	b = randbool();
	if (b) {
		input[4] |= (1 << 1);
		return 6;
	} else {
		input[4] &= ~(1 << 1);
		goto node8570;
	}
node396:
	b = randbool();
	if (b) {
		input[0] |= (1 << 2);
		goto node2490;
	} else {
		input[0] &= ~(1 << 2);
		goto node2917;
	}
node639:
	b = false;
	if (b) {
		input[2] |= (1 << 5);
		return 0;
	} else {
		input[2] &= ~(1 << 5);
		goto node5520;
	}
node6882:
	b = randbool();
	if (b) {
		input[2] |= (1 << 4);
		goto node6323;
	} else {
		input[2] &= ~(1 << 4);
		goto node8321;
	}
node6971:
	b = false;
	if (b) {
		input[3] |= (1 << 6);
		return 0;
	} else {
		input[3] &= ~(1 << 6);
		goto node6276;
	}
node8609:
	b = false;
	if (b) {
		input[3] |= (1 << 4);
		return 0;
	} else {
		input[3] &= ~(1 << 4);
		goto node8222;
	}
node5115:
	b = randbool();
	if (b) {
		input[2] |= (1 << 1);
		goto node6553;
	} else {
		input[2] &= ~(1 << 1);
		goto node5787;
	}
node8432:
	b = true;
	if (b) {
		input[2] |= (1 << 4);
		goto node1226;
	} else {
		input[2] &= ~(1 << 4);
		return 0;
	}
node4976:
	b = true;
	if (b) {
		input[2] |= (1 << 1);
		goto node3923;
	} else {
		input[2] &= ~(1 << 1);
		return 0;
	}
node9375:
	b = randbool();
	if (b) {
		input[3] |= (1 << 5);
		goto node8138;
	} else {
		input[3] &= ~(1 << 5);
		goto node2524;
	}
node1100:
	b = false;
	if (b) {
		input[3] |= (1 << 1);
		return 0;
	} else {
		input[3] &= ~(1 << 1);
		goto node9262;
	}
node7197:
	b = false;
	if (b) {
		input[4] |= (1 << 2);
		return 0;
	} else {
		input[4] &= ~(1 << 2);
		goto node4079;
	}
node6035:
	b = randbool();
	if (b) {
	} else {