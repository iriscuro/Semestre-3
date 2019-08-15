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

    #ifndef SFML_IMAGE_HPP
    #define SFML_IMAGE_HPP
    // Headers
    #include <SFML/Graphics/Export.hpp>
    #include <SFML/Graphics/Color.hpp>
    #include <SFML/Graphics/Rect.hpp>
    #include <string>
   #include <vector>


        namespace sf
    {
        class InputStream;

        class SFML_GRAPHICS_API Image
        {
    public:

        Image();

        ~Image();

        void create(unsigned int width, unsigned int height, const Color& color = Color(0, 0, 0));

        void create(unsigned int width, unsigned int height, const Uint8* pixels);

        bool loadFromFile(const std::string& filename);

        bool loadFromMemory(const void* data, std::size_t size);

        bool loadFromStream(InputStream& stream);

        bool saveToFile(const std::string& filename) const;

        Vector2u getSize() const;

        void createMaskFromColor(const Color& color, Uint8 alpha = 0);

        void copy(const Image& source, unsigned int destX, unsigned int destY, const IntRect& sourceRect = IntRect(0, 0, 0, 0), bool applyAlpha = false);

        void setPixel(unsigned int x, unsigned int y, const Color& color);

        Color getPixel(unsigned int x, unsigned int y) const;

        const Uint8* getPixelsPtr() const;

        void flipHorizontally();

        void flipVertically();
    private:

// Member data
       Vector2u           m_size;
       std::vector<Uint8> m_pixels;
    };

    } // namespace sf
  #endif // SFML_IMAGE_HPP
