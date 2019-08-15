//
    // SFML - Simple and Fast Multimedia Library
    // Copyright (C) 2007-2018 Laurent Gomila (laurent@sfml-dev.org)
    //
    // This software is provided 'as-is', without any express or implied warranty.
    // In no event will the authors be held liable for any damages arising from the use of this software.
    //
    // Permission is granted to anyone to use this software for any purpose,
    // including commercial applications, and to alter it and redistribute it freely,
    // subject to the following restrictions:
    //
    // 1. The origin of this software must not be misrepresented;
    //    you must not claim that you wrote the original software.
    //    If you use this software in a product, an acknowledgment
    //    in the product documentation would be appreciated but is not required.
    //
    // 2. Altered source versions must be plainly marked as such,
    //    and must not be misrepresented as being the original software.
    //
    // 3. This notice may not be removed or altered from any source distribution.
    //

    #ifndef SFML_SPRITE_HPP
    #define SFML_SPRITE_HPP

    // Headers
    #include <SFML/Graphics/Export.hpp>
    #include <SFML/Graphics/Drawable.hpp>
    #include <SFML/Graphics/Transformable.hpp>
    #include <SFML/Graphics/Vertex.hpp>
    #include <SFML/Graphics/Rect.hpp>


    namespace sf
    {
    class Texture;

    class SFML_GRAPHICS_API Sprite : public Drawable, public Transformable
        {
        public:

        Sprite();

        explicit Sprite(const Texture& texture);

        Sprite(const Texture& texture, const IntRect& rectangle);

        void setTexture(const Texture& texture, bool resetRect = false);

        void setTextureRect(const IntRect& rectangle);

       void setColor(const Color& color);

        const Texture* getTexture() const;

        const IntRect& getTextureRect() const;

        const Color& getColor() const;

        FloatRect getLocalBounds() const;

        FloatRect getGlobalBounds() const;

    private:

        virtual void draw(RenderTarget& target, RenderStates states) const;

        void updatePositions();

        void updateTexCoords();

        // Member data
        Vertex         m_vertices[4];
        const Texture* m_texture;
        IntRect        m_textureRect;
        };

    } // namespace sf


    #endif // SFML_SPRITE_HPP
