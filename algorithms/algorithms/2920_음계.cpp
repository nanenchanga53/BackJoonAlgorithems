#include <iostream>

int main() {
	int i;
	int n[9];
	int asc = 0;
	int des = 0;

	for (i = 0; i < 8; i++) {

		scanf("%d", &n[i]);

		if (n[i] == i + 1) {

			asc++;

		}

		else if (n[i] == 8 - i) {

			des++;

		}

	}

	if (asc == 8) {

		printf("ascending\n");
	}


	else if (des == 8) {

		printf("descending\n");
	}

	else {

		printf("mixed\n");
	}

}