
#include <GL/glut.h>
#include <GL/freeglut.h>
#include <GL/gl.h>
void pixel(int x,int y){
    glBegin(GL_POINTS);
    glVertex3i(x,y,-10);
    glEnd();
}

void algoritmoBresenham(int xi, int xf,int yi, int yf){
     int dx=abs(xf-xi);
    int dy=abs(yf-yi);
    int xk,yk;
    int p0 = 2*dy - dx;
    glBegin(GL_POINTS);
    if(dx >=dy){
        if(xi < xf){
            xk = xi;
            yk = yi;
        }else{
            xk = xf;
            yk = yf;
            xf = xi;
            yf = yi;
        }
        glVertex3i(xk,yk,-10);
        for(int i=0;i<dx;i++){
            if(p0 >= 0){
                if(yk < yf){
                   yk += 1;
                }else{
                    yk -= 1;
                }
                xk = xk + 1;
                glVertex3i(xk,yk,-10);
                p0 = p0 + (2*dy-2*dx);
            }else{
                xk = xk + 1;
                glVertex3i(xk,yk,-10);
                p0 = p0 + 2*dy;
            }
        }
    }else{
        if(yi < yf){
            xk = xi;
            yk = yi;
        }else{
            xk = xf;
            yk = yf;
            xf = xi;
            yf = yi;
        }
        glVertex3i(xk,yk,-10);
        for(int i=0;i < dy;i++){
            if(p0 >= 0){
                if(xk > xf){
                    xk -= 1;
                }else{
                    xk += 1;
                }
                yk += 1;
                glVertex3i(xk,yk,-10);
                p0 = p0 + (2*dx - 2*dy);
            }else{
                yk += 1;
                glVertex3i(xk,yk,-10);
                p0 = p0 + 2*dx;
            }
        }
    }
    glEnd();
}

void puntoMedio(int xc,int yc,int r){
    int x = 0;
    int y = r;
    int pk = 1-r;
    glBegin(GL_POINTS);
    while(x <= y) {
            glVertex3i(xc+x,yc+y,-10);
            glVertex3i(xc-x,yc-y,-10);
            glVertex3i(xc+x,yc-y,-10);
            glVertex3i(xc-x,yc+y,-10);
            glVertex3i(xc+y,yc+x,-10);
            glVertex3i(xc-y,yc+x,-10);
            glVertex3i(xc+y,yc-x,-10);
            glVertex3i(xc-y,yc-x,-10);
            if(pk < 0){
                pk += 2*x+1;
            }else{
                pk += 2*(x+1)+1 - 2*(y-1);
                y--;
            }
        x++;
    }
    glEnd();
}

void mediaElipse(int xc,int yc, int rx,int ry, int region){
//Region Sup region ==1
    if(region==1){
        glBegin(GL_POINTS);
        int x, y, p, px, py;
        int rx2, ry2, tworx2, twory2;
        ry2 = ry*ry; rx2 = rx*rx;
        twory2 = 2 * ry2;
        tworx2 = 2 * rx2;
        x = 0; y = ry;
        glVertex3i(xc+x,yc+y,-10);
        glVertex3i(xc-x,yc+y,-10);
        p = (int)round(ry2 - rx2*ry + 0.25*rx2);
        px = 0; py = tworx2*y;
        //Región 1
        while (px < py){
                x++;
                px += twory2;
                if (p < 0)
                    p += ry2 + px;
                else{
                    y--;
                    py -= tworx2;
                    p += ry2 + px - py;
                }
                glVertex3i(xc+x,yc+y,-10);
                glVertex3i(xc-x,yc+y,-10);
        }
        //Región 2
        p = (int)round(ry2*(x+0.5)*(x+0.5) + rx2*(y-1)*(y-1) - rx2*ry2);
        while (y > 0){
            y--;
            py -= tworx2;
            if (p > 0)
                p += rx2 - py;
            else{
                x++;
                px += twory2;
                p += rx2 - py + px;
            } glVertex3i(xc+x,yc+y,-10);
            glVertex3i(xc-x,yc+y,-10);
        }

    }
    //REGION INFERIOR
    if(region==2){
        int x, y, p, px, py;
        int rx2, ry2, tworx2, twory2;
        ry2 = ry*ry; rx2 = rx*rx;
        twory2 = 2 * ry2;
        tworx2 = 2 * rx2;
        x = 0; y = ry;
        glVertex3i(xc+x,yc-y,-10);
        glVertex3i(xc-x,yc-y,-10);
        p = (int)round(ry2 - rx2*ry + 0.25*rx2);
        px = 0; py = tworx2*y;
        //Región 1
        while (px < py){
                x++;
                px += twory2;
                if (p < 0)
                    p += ry2 + px;
                else{
                    y--;
                    py -= tworx2;
                    p += ry2 + px - py;
                }
                glVertex3i(xc+x,yc-y,-10);
                glVertex3i(xc-x,yc-y,-10);
        }
        //Región 2
        p = (int)round(ry2*(x+0.5)*(x+0.5) + rx2*(y-1)*(y-1) - rx2*ry2);
        while (y > 0){
            y--;
            py -= tworx2;
            if (p > 0)
                p += rx2 - py;
            else{
                x++;
                px += twory2;
                p += rx2 - py + px;
            }
            glVertex3i(xc+x,yc-y,-10);
            glVertex3i(xc-x,yc-y,-10);
        }
        glEnd();
    }
}

void muslos(int xc, int yc,int r){
    int x = 0;
    int y = r;
    int pk = 1-r;
    glBegin(GL_POINTS);
    while(x <= y) {
            glVertex3i(xc+y,yc+x,-10);
            glVertex3i(xc-y,yc+x,-10);
            glVertex3i(xc+y,yc-x,-10);
            glVertex3i(xc-y,yc-x,-10);
            if(pk < 0){
                pk += 2*x+1;
            }else{
                pk += 2*(x+1)+1 - 2*(y-1);
                y--;
            }
        x++;
    }
    glEnd();
}

void perroPrimeraEntrega(){
    glPointSize(4.0);
    // Cuerpo
    mediaElipse(430,230,170,30,1);
    mediaElipse(430,180,170,45,2);
    //cola
    algoritmoBresenham(260,230,230,205);
    algoritmoBresenham(230,220,205,180);
    algoritmoBresenham(220,215,180,110);
    algoritmoBresenham(215,200,110,90);
    algoritmoBresenham(200,205,90,80);
    algoritmoBresenham(205,210,80,78);
    algoritmoBresenham(210,220,78,82);
    algoritmoBresenham(220,225,82,90);
    algoritmoBresenham(225,240,90,140);
    algoritmoBresenham(240,270,140,164);
    //PATAS FRONTALES
    muslos(505,140,35);
    algoritmoBresenham(481,498,115,95);
    algoritmoBresenham(498,494,95,55);
    algoritmoBresenham(494,540,55,25);
    algoritmoBresenham(540,550,25,35);
    algoritmoBresenham(550,520,35,65);
    algoritmoBresenham(520,530,65,115);
    algoritmoBresenham(538,558,115,70);
    algoritmoBresenham(558,595,70,45);
    algoritmoBresenham(595,605,45,55);
    algoritmoBresenham(605,585,55,75);
    algoritmoBresenham(585,570,75,115);
    algoritmoBresenham(570,580,115,140);
    algoritmoBresenham(580,585,140,160);
    //PATAS TRASERAS
    muslos(315,140,35);
    algoritmoBresenham(290,300,115,100);
    algoritmoBresenham(300,305,100,50);
    algoritmoBresenham(305,355,50,35);
    algoritmoBresenham(355,362,35,50);
    algoritmoBresenham(362,332,50,63);
    algoritmoBresenham(332,340,63,110);
    algoritmoBresenham(345,375,125,55);
    algoritmoBresenham(345,375,125,55);
    algoritmoBresenham(375,405,55,45);
    algoritmoBresenham(405,410,45,60);
    algoritmoBresenham(410,393,60,70);
    algoritmoBresenham(393,396,70,115);
    algoritmoBresenham(396,391,115,135);
    //CARA
    algoritmoBresenham(600,610,230,250);
    algoritmoBresenham(610,612,250,340);
    algoritmoBresenham(612,625,340,310);
    algoritmoBresenham(625,628,325,340);
    algoritmoBresenham(628,640,340,320);
    algoritmoBresenham(640,643,320,310);
    algoritmoBresenham(643,695,310,300);
    algoritmoBresenham(695,698,300,275);
    algoritmoBresenham(698,735,275,260);
    algoritmoBresenham(735,742,260,252);
    algoritmoBresenham(742,746,252,240);
    algoritmoBresenham(746,741,240,230);
    algoritmoBresenham(741,730,230,220);
    algoritmoBresenham(730,715,220,215);
    algoritmoBresenham(715,685,215,210);
    algoritmoBresenham(685,655,210,200);
    algoritmoBresenham(655,630,200,190);
    algoritmoBresenham(630,615,190,180);
    algoritmoBresenham(615,600,180,170);
    //BOCA y OJO
    algoritmoBresenham(740,715,230,235);
    puntoMedio(662,280,3);
    //COLORRRRR
    glPointSize(5.0);
    glColor3ub(138, 75, 8);//CAFE
    algoritmoBresenham(265,605,202,202);
    glPointSize(2.5);
    algoritmoBresenham(275,585,180,180);
    glPointSize(3.5);
    algoritmoBresenham(275,585,222,222);
    pixel(510,100);
    glPointSize(6.0);
    pixel(510,115);
    pixel(510,130);
    pixel(510,150);
    pixel(510,170);
    pixel(495,170);
    pixel(495,150);
    pixel(495,130);
    glPointSize(3.5);
    pixel(510,90);
    pixel(510,80);
    pixel(510,70);
    glPointSize(2.5);
    pixel(510,60);
    glPointSize(1.5);
    pixel(515,60);
    glPointSize(1.0);
    pixel(515,52);
    pixel(510,52);
    pixel(516,48);
    pixel(519,47);
    pixel(521,46);
    pixel(524,44);
    pixel(527,42);
    pixel(530,40);
    pixel(533,37);
    pixel(536,34);
    pixel(538,34);
    pixel(539,36);
    pixel(534,38);
    pixel(533,40);
    pixel(532,42);
    pixel(530,44);
    pixel(525,46);
    pixel(524,48);
    pixel(523,50);
    pixel(522,52);
    pixel(510,52);
    pixel(505,55);
    pixel(502,59);
    pixel(503,62);
    pixel(504,67);
    pixel(515,75);
    pixel(516,80);
    pixel(517,85);
    pixel(518,90);
    pixel(519,95);
    pixel(520,100);
    pixel(521,105);
    pixel(522,110);
    pixel(523,115);
    pixel(524,120);
    pixel(488,115);
    pixel(492,110);
    pixel(497,105);
    pixel(502,100);
    pixel(494,115);
    pixel(494,110);
    pixel(530,130);
    pixel(528,125);
    pixel(532,135);
    pixel(533,140);
    pixel(532,145);
    pixel(530,150);
    pixel(528,155);
    pixel(526,160);
    pixel(526,155);
    pixel(526,150);
    pixel(526,145);
    pixel(526,140);
    pixel(526,135);
    pixel(526,130);
    pixel(526,125);
    pixel(526,120);
    pixel(482,120);
    pixel(480,125);
    pixel(478,130);
    pixel(476,135);
    pixel(478,140);
    pixel(480,145);
    pixel(481,150);
    pixel(482,155);
    pixel(485,135);
    glPointSize(3.3);
    pixel(490,135);
    glPointSize(1.5);
    pixel(526,165);
    pixel(526,170);
    glPointSize(4.0);
    pixel(560,170);
    pixel(550,170);
    glPointSize(4.0);
    pixel(545,180);
    pixel(540,180);
    glPointSize(1.6);
    pixel(555,160);
    pixel(550,157);
    pixel(548,155);
    pixel(575,165);
    pixel(575,170);
    pixel(580,167);
    pixel(585,169);
    pixel(590,173);
    pixel(595,180);
    pixel(595,185);
    pixel(605,185);
    pixel(610,185);
    pixel(590,60);
    pixel(595,56);
    pixel(585,64);
    pixel(580,68);
    pixel(575,72);
    pixel(570,74);
    pixel(565,76);
    pixel(563,78);
    pixel(561,80);
    pixel(560,82);
    pixel(559,84);
    pixel(558,86);
    pixel(557,88);
    pixel(556,90);
    pixel(555,92);
    pixel(554,94);
    pixel(553,96);
    pixel(552,98);
    pixel(551,100);
    pixel(550,102);
    pixel(548,104);
    pixel(548,106);
    pixel(547,108);
    pixel(547,110);
    pixel(546,112);
    pixel(546,114);
    pixel(545,118);
    pixel(546,122);
    pixel(547,126);
    pixel(548,130);
    pixel(549,134);
    pixel(550,138);
    pixel(555,140);
    pixel(560,142);
    pixel(565,144);
    pixel(570,146);
    pixel(575,148);
    pixel(577,150);
    pixel(575,145);
    pixel(573,140);
    pixel(571,135);
    pixel(569,130);
    pixel(567,125);
    pixel(565,120);
    pixel(563,115);
    pixel(561,110);
    pixel(559,105);
    pixel(555,110);
    pixel(555,115);
    pixel(555,120);
    pixel(555,125);
    pixel(560,130);
    pixel(560,135);
    pixel(560,140);
    pixel(562,140);
    pixel(556,144);
    pixel(563,105);
    pixel(565,100);
    pixel(567,95);
    pixel(569,90);
    pixel(571,85);
    pixel(573,80);
    pixel(575,75);
    pixel(572,75);
    pixel(570,80);
    pixel(568,85);
    //PIERNA 2
    glPointSize(7.3);
    pixel(315,160);
    pixel(315,140);
    glPointSize(4.0);
    pixel(320,110);
    pixel(320,90);
    pixel(318,70);
    glPointSize(2.5);
    pixel(321,55);
    pixel(319,56);
    pixel(317,57);
    pixel(315,58);
    pixel(313,100);
    pixel(325,102);
    glPointSize(2.0);
    pixel(330,53);
    pixel(332,50);
    pixel(334,49);
    pixel(336,49);
    pixel(338,48);
    pixel(340,47);
    pixel(342,46);
    pixel(344,45);
    pixel(346,45);
    pixel(348,45);
    pixel(350,44);
    pixel(325,80);
    pixel(327,85);
    pixel(329,90);
    pixel(330,92);
    pixel(330,94);
    pixel(331,96);
    pixel(331,98);
    pixel(332,100);
    pixel(332,102);
    pixel(332,107);
    pixel(332,110);
    pixel(332,113);
    pixel(336,126);
    pixel(338,129);
    pixel(340,132);
    pixel(340,135);
    pixel(342,138);
    pixel(341,141);
    pixel(340,144);
    pixel(340,147);
    pixel(340,150);
    pixel(330,153);
    pixel(330,156);
    pixel(330,159);
    pixel(328,162);
    pixel(334,162);
    pixel(310,110);
    pixel(308,110);
    pixel(308,105);
    pixel(308,100);
    pixel(308,95);
    pixel(309,90);
    pixel(309,85);
    pixel(309,80);
    pixel(309,75);
    pixel(304,112);
    pixel(302,115);
    pixel(300,118);
    pixel(298,121);
    pixel(296,124);
    pixel(294,127);
    pixel(292,130);
    pixel(290,133);
    pixel(291,136);
    pixel(291,139);
    pixel(292,142);
    pixel(292,145);
    pixel(293,148);
    pixel(293,151);
    pixel(294,154);
    pixel(294,156);

glPointSize(3.3);
    pixel(385,100);
    pixel(382,115);
    pixel(375,100);
    pixel(368,115);
    pixel(364,125);
    pixel(380,124);
    pixel(382,85);
    glPointSize(2.5);
    pixel(382,67);
    glPointSize(2.0);
    pixel(385,62);
    glPointSize(1.5);
    pixel(390,61);
    pixel(395,59);
    pixel(400,57);

    pixel(372,85);
    pixel(374,80);
    pixel(376,75);
    pixel(378,70);
    pixel(380,65);
    pixel(370,90);
    pixel(368,95);
    pixel(366,100);
    pixel(364,105);
    pixel(362,110);
    pixel(360,115);
    pixel(358,120);
    pixel(356,125);
    pixel(358,130);

    pixel(215,90);
    pixel(211,88);
    pixel(216,95);
    pixel(218,98);
    pixel(222,105);
    pixel(223,110);
    pixel(224,115);
    pixel(226,120);
    pixel(228,125);
    pixel(230,130);
    pixel(232,135);
    pixel(234,140);
    pixel(235,145);
    pixel(236,150);
    pixel(227,130);
    pixel(228,135);
    pixel(228,140);
    pixel(228,145);
    pixel(228,150);

    glPointSize(4.0);
    pixel(240,180);
    pixel(240,165);

    glPointSize(1.5);
    pixel(228,165);
    pixel(228,160);
    pixel(230,170);
    pixel(230,175);
    pixel(240,155);
    pixel(255,160);
    pixel(257,165);
    pixel(255,170);
    pixel(254,175);
    pixel(254,180);
    pixel(258,185);
    pixel(262,185);
    pixel(271,180);
    pixel(274,175);
    pixel(276,170);
    pixel(280,168);
    pixel(285,173);
    pixel(289,173);

    glPointSize(3.3);
    pixel(246,200);
    glPointSize(1.6);
    pixel(237,190);
    pixel(237,195);
    pixel(238,200);
    pixel(246,210);
    pixel(260,220);
    pixel(255,215);
    pixel(265,222);
    pixel(267,224);

    glPointSize(6.6);
    pixel(656,230);
    pixel(628,220);
    pixel(636,260);
    pixel(636,285);
    pixel(660,255);
    pixel(690,240);
    pixel(690,250);

    glPointSize(3.3);
    pixel(678,280);
    pixel(683,280);
    pixel(683,290);
    glPointSize(2.5);
    pixel(675,292);
    pixel(665,294);
    pixel(660,295);

    glPointSize(2.5);
    pixel(660,215);
    pixel(655,210);
    pixel(650,208);
    pixel(645,207);
    pixel(640,206);
    pixel(635,205);
    pixel(630,204);
    pixel(625,203);
    pixel(620,197);
    pixel(615,195);
    pixel(665,217);
    pixel(670,219);
    pixel(675,221);
    pixel(680,222);
    pixel(685,222);
    pixel(690,223);
    pixel(695,223);
    pixel(700,224);
    pixel(705,224);
    pixel(705,230);
    pixel(705,235);
    pixel(705,240);
    pixel(705,245);
    pixel(705,250);
    pixel(705,255);
    pixel(705,260);
    pixel(695,264);
    pixel(710,255);
    pixel(715,254);
    pixel(720,254);
    pixel(725,252);
    pixel(730,251);
    pixel(733,249);
    pixel(734,245);
    pixel(735,243);
    pixel(730,244);
    pixel(725,245);
    pixel(720,245);
    pixel(717,245);
    pixel(710,224);
    glPointSize(1.5);
    pixel(715,225);
    pixel(720,225);
    pixel(725,225);
    pixel(730,226);
    pixel(732,226);

    pixel(631,320);
    pixel(632,315);
    pixel(632,310);
    pixel(639,305);
    pixel(625,305);
    pixel(620,305);
    glPointSize(0.8);
    pixel(617,312);

    glPointSize(1.5);
    pixel(614,243);
    pixel(609,230);
    pixel(609,225);
    pixel(604,225);
    pixel(600,225);
    pixel(595,225);
    pixel(595,222);
    pixel(600,222);
    pixel(605,222);
    pixel(610,222);

    glPointSize(4.0);
    pixel(410,150);
    pixel(435,151);
    pixel(450,151);
    pixel(455,151);
    pixel(385,151);
    pixel(365,153);
    pixel(365,165);
    pixel(385,165);
    pixel(410,165);
    pixel(435,165);
    pixel(450,165);
    pixel(458,165);
    glPointSize(1.5);
    pixel(475,168);
    pixel(478,171);
    pixel(350,171);
    pixel(340,171);
    pixel(352,168);
    pixel(354,166);

    glPointSize(5.0);
    pixel(354,240);
    pixel(324,236);
    pixel(294,230);
    pixel(280,225);
    pixel(384,240);
    pixel(414,242);
    pixel(444,242);
    pixel(474,240);
    pixel(504,240);
    pixel(534,236);
    pixel(564,230);
    pixel(594,225);
}
