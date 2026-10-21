#include <stdio.h>

int main(void) {
	char buf[256];
	for (int i = 0; i < 60; i++) {
		snprintf(buf, sizeof(buf), "output-%02d.ppm", i);
		const char *output = buf;
		FILE *fp = fopen(output, "wb");

		const int w = 16 * 60;
		const int h = 9 * 60;

		fprintf(fp, "P6\n");
		fprintf(fp, "%d %d\n", w, h);
		fprintf(fp, "255\n");
		for (int y = 0; y < h; y++) {
			for (int x = 0; x < w; x++) {
				if (((x + i) / 60 + (y + i) / 60) % 2) {
					fputc(0xEB, fp);
					fputc(0x75, fp);
					fputc(0xA2, fp);
				} else {
					fputc(0x1E, fp);
					fputc(0x1D, fp);
					fputc(0x20, fp);
				}
			}
		}
		printf("Generating %s\n", output);
		fclose(fp);
	}
}
