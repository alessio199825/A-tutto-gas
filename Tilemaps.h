//
// Created by alessio on 17/06/19.
//

#ifndef ALL_ULTIMO_GAS_TILEMAPS_H
#define ALL_ULTIMO_GAS_TILEMAPS_H


#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Tilemaps : public Drawable, public Transformable
{
public:

    bool CreateMap1();
    bool CreateMap2();
    bool CreateMap3();
    //int TileNumber(int i, int j);

private:

    bool load(Vector2u tileSize, const int* level);
    virtual void draw(RenderTarget& target, RenderStates states) const;
    VertexArray m_vertices;
    int width=50, height=30;
    //const int *tiles;

};


#endif //ALL_ULTIMO_GAS_TILEMAPS_H
