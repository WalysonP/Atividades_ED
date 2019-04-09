#include "xpaint.h.txt"
#include <stdlib.h>

void galhos(float x, float y, float ang, float lado){
    float delta = xm_rand(20, 30); /* angulo de rotacao */
    float dec = xm_rand(16, 28);
    if(lado < 10)
        return;

    float fx = x + lado * xm_cos(ang);
    float fy = y - lado * xm_sin(ang);
    xs_color((XColor){xm_rand(0, 255), xm_rand(0, 255), xm_rand(0, 255)});
    xd_thick_line(x, y, fx, fy, 3); /* desenha a linha */

	int qntGalhos = xm_rand(2, 3);
	if(qntGalhos == 2){
		galhos(fx, fy, ang - delta, lado - dec);
    	galhos(fx, fy, ang + delta, lado - dec);
	}
	else if(qntGalhos == 3){
		galhos(fx, fy, ang - delta, lado - dec);
    	galhos(fx, fy, ang        , lado - dec);
    	galhos(fx, fy, ang + delta, lado - dec);
	}

}

int main(){
    x_open(2400, 1400);
    x_clear(make_xcolor(40, 40, 40));
    srand((unsigned) time(NULL));
    galhos(1200, 1400, 90, 220);
    x_save("figura_arvore");
    x_close();
    return 0;
}
