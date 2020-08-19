#include <windows.h>
#include <iostream>
#include "CImg.h"

using namespace cimg_library;
using namespace std;

void render() {
  CImg<unsigned char> image(3840,1080,1,3);

   // Fill with magenta
   cimg_forXY(image,x,y) {
      image(x,y,0,0)=22;
      image(x,y,0,1)=28;
      image(x,y,0,2)=35;
   }

   // Make some colours
   unsigned char bg[]      = { 22,  28,  35  };
   unsigned char white[]   = { 255, 255, 255 };
   unsigned char cyan[]    = { 0,   255, 255 };
   unsigned char black[]   = { 0,   0,   0   };
   unsigned char yellow[]  = { 255, 255, 0   };

   // Draw black text on cyan
   image.draw_text(32,32,"[ ] The first one task of the day...",white,bg,1,14);

   // Draw yellow partially transparent text on black
   image.draw_text(32,52,"[ ] This should be done as a second",white,bg,1,14);

   // Save result image as NetPBM PNM - no libraries required
   image.save_bmp("D:\\new-wallpaper.bmp");
}

int main(int argc, char** argv) {
  render();

  const wchar_t *path = L"D:\\new-wallpaper.bmp";
  int result;

  result = SystemParametersInfoW(SPI_SETDESKWALLPAPER, 0, (void *)path, SPIF_UPDATEINIFILE);

  return 0;
}