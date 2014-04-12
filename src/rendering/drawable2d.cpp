#include <featherkit/rendering/drawable2d.hpp>
#include <featherkit/assert.hpp>

namespace fea
{
    Drawable2D::Drawable2D() : mDrawMode(0), mRotation(0.0f), mScaling(glm::vec2(1.0f, 1.0f)), mParallax(glm::vec2(1.0f, 1.0f)), mColor(1.0f, 1.0f, 1.0f, 1.0f)
    {
    }

    const std::vector<float>& Drawable2D::getVertices() const
    {
        return mVertices;
    }
    
    void Drawable2D::setPosition(const glm::vec2& position)
    {
        mPosition = position;
    }
    
    const glm::vec2& Drawable2D::getPosition() const
    {
        return mPosition;
    }
    
    void Drawable2D::translate(const glm::vec2& position)
    {
        mPosition += position;
    }
    
    void Drawable2D::setOrigin(const glm::vec2& origin)
    {
        mOrigin = origin;
    }

    const glm::vec2& Drawable2D::getOrigin() const
    {
        return mOrigin;
    }

    void Drawable2D::setRotation(const float radians)
    {
        mRotation = radians;
    }
    
    float Drawable2D::getRotation() const
    {
        return mRotation;
    }

    void Drawable2D::rotate(const float radians)
    {
        mRotation += radians;
    }

    void Drawable2D::setScale(const glm::vec2& scaling)
    {
        mScaling = scaling;
    }

    const glm::vec2& Drawable2D::getScale() const
    {
        return mScaling;
    }

    void Drawable2D::scale(const glm::vec2& scaling)
    {
        mScaling *= scaling;
    }
    
    void Drawable2D::setParallax(float parallax)
    {
        mParallax = glm::vec2(parallax, parallax);
    }

    void Drawable2D::setParallax(const glm::vec2& parallax)
    {
        mParallax = parallax;
    }
    
    float Drawable2D::getParallax() const
    {
        return mParallax.x;
    }
    
    const glm::vec2& Drawable2D::getParallaxVector() const
    {
        return mParallax;
    }
        
    void Drawable2D::setColor(const Color& color)
    {
        mColor = color;
    }
    
    Color Drawable2D::getColor() const
    {
        return mColor;
    }
    
    void Drawable2D::setOpacity(float opacity)
    {
        FEA_ASSERT(opacity >= 0.0f && opacity <= 1.0f, "Opacity must be within the range of [0.0f, 1.0f]! " + std::to_string(opacity) + " provided.");
        mColor.setA(opacity);
    }

    float Drawable2D::getOpacity() const
    {
        return mColor.a();
    }

    RenderInfo Drawable2D::getRenderInfo() const
    {
        RenderInfo temp;
        std::hash<std::string> stringHasher;

        glm::vec3 colorInfo = glm::vec3(mColor.r(), mColor.g(), mColor.b());
        float opacity = mColor.a();

        temp.mDrawMode = mDrawMode;
        temp.mElementAmount = mVertices.size() / 2;

        temp.mVertexAttributes.push_back(VertexAttribute(stringHasher("vertex"), 2, &mVertices[0]));
        temp.mVertexAttributes.push_back(VertexAttribute(stringHasher("texCoords"), 2, &mTexCoords[0]));
        temp.mVertexAttributes.push_back(VertexAttribute(stringHasher("colors"), 4, &mVertexColors[0]));

        temp.mUniforms.push_back(Uniform(stringHasher("position"), VEC2, mPosition));
        temp.mUniforms.push_back(Uniform(stringHasher("origin"), VEC2, mOrigin));
        temp.mUniforms.push_back(Uniform(stringHasher("rotation"), FLOAT, mRotation));
        temp.mUniforms.push_back(Uniform(stringHasher("scaling"), VEC2, mScaling));
        temp.mUniforms.push_back(Uniform(stringHasher("parallax"), VEC2, mParallax));
        //temp.uniforms.push_back(Uniform(stringHasher("texture"), TEXTURE, (GLuint)0)); maybe not needed
        temp.mUniforms.push_back(Uniform(stringHasher("constraints"), VEC4, glm::vec4(0.0f, 1.0f, 0.0f, 1.0f)));
        temp.mUniforms.push_back(Uniform(stringHasher("color"), VEC3, colorInfo));
        temp.mUniforms.push_back(Uniform(stringHasher("opacity"), FLOAT, opacity));

        return temp;
    }
}
