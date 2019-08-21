//
// Created by alessio on 09/08/19.
//

#include "Collision.h"

Collision::Collision() {}



void Collision::setSCar(Sprite &sBox1, Sprite &sBox2) {
    S_CarBox1 = sBox1;
    S_CarBox2 = sBox2;
}

bool Collision::CarPlayer_Menagement() {

    for(int i=0; i<5; i++) {
        if (PixelPerfectTest(S_CarBox1, S_CpuBox2[i]))
            return true;
    }
    return false;
}

bool Collision::CarPlayer_Reverse() {
    for(int i=0; i<5; i++) {
        if (PixelPerfectTest(S_CarBox2, S_CpuBox1[i]) || PixelPerfectTest(S_CarBox2, S_CpuBox2[i]))
            return true;
    }
    return false;
}


void Collision::set_sCarCpu(Sprite sCpuBox1[], Sprite sCpuBox2[]) {

    for(int i=0; i<5; i++){
        S_CpuBox1[i]=sCpuBox1[i];
        S_CpuBox2[i]=sCpuBox2[i];
    }

}

bool Collision::Cpu_Menagement(int CpuCar) {

    for(int i=0; i<5; i++) {
        if(i != CpuCar) {

            if (PixelPerfectTest(S_CpuBox1[CpuCar], S_CpuBox2[i])) {
                return true;
            }

        }
    }

    return PixelPerfectTest(S_CpuBox1[CpuCar], S_CarBox2);

}



bool Collision::PixelPerfectTest(const sf::Sprite &Object1, const sf::Sprite &Object2, Uint8 AlphaLimit) {
    sf::FloatRect Intersection;
    if (Object1.getGlobalBounds().intersects(Object2.getGlobalBounds(), Intersection)) {
        sf::IntRect O1SubRect = Object1.getTextureRect();
        sf::IntRect O2SubRect = Object2.getTextureRect();

        sf::Uint8 *mask1 = Bitmasks.GetMask(Object1.getTexture());
        sf::Uint8 *mask2 = Bitmasks.GetMask(Object2.getTexture());

        // Loop through our pixels
        for (int i = Intersection.left; i < Intersection.left + Intersection.width; i++) {
            for (int j = Intersection.top; j < Intersection.top + Intersection.height; j++) {

                sf::Vector2f o1v = Object1.getInverseTransform().transformPoint(i, j);
                sf::Vector2f o2v = Object2.getInverseTransform().transformPoint(i, j);

                // Make sure pixels fall within the sprite's subrect
                if (o1v.x > 0 && o1v.y > 0 && o2v.x > 0 && o2v.y > 0 &&
                    o1v.x < O1SubRect.width && o1v.y < O1SubRect.height &&
                    o2v.x < O2SubRect.width && o2v.y < O2SubRect.height) {

                    if (Bitmasks.GetPixel(mask1, Object1.getTexture(), (int) (o1v.x) + O1SubRect.left,
                                          (int) (o1v.y) + O1SubRect.top) > AlphaLimit &&
                        Bitmasks.GetPixel(mask2, Object2.getTexture(), (int) (o2v.x) + O2SubRect.left,
                                          (int) (o2v.y) + O2SubRect.top) > AlphaLimit)
                        return true;

                }
            }
        }
    }
    return false;
}

bool Collision::CreateTextureAndBitmask(sf::Texture &LoadInto, const std::string &Filename) {
    sf::Image img;
    if (!img.loadFromFile(Filename))
        return false;
    if (!LoadInto.loadFromImage(img))
        return false;

    Bitmasks.CreateMask(&LoadInto, img);
    return true;
}




