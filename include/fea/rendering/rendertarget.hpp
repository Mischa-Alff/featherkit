#pragma once
#include <fea/config.hpp>
#include <stdint.h>
#include <glm/glm.hpp>
#include <fea/rendering/texture.hpp>

namespace fea
{
    class FEA_API RenderTarget
    {
        public:
            RenderTarget();
            RenderTarget(RenderTarget&& other);
            RenderTarget(const RenderTarget& other) = delete;
            RenderTarget& operator=(RenderTarget&& other);
            RenderTarget& operator=(const RenderTarget& other) = delete;
            GLuint getId() const;
            const glm::ivec2& getSize() const;
            const Texture& getTexture() const;
            void create(const glm::ivec2& size, bool smooth = false);
            void destroy();
            ~RenderTarget();
        private:
            GLuint mId;
            glm::ivec2 mSize;
            Texture mTexture;
    };
    /** @addtogroup Render2D
     *@{
     *  @class RenderTarget
     *@}
     ***
     *  @class RenderTarget
     *  @brief Container class for a render target resource that represents a buffer than can be drawn on and be used as a texture to display it.
     *
     *  Because RenderTargets represents internal buffers of the rendering system, they cannot be copied.
     *
     *  A RenderTarget instance has to be kept alive for as long as it is in use.
     ***
     *  @fn RenderTarget::RenderTarget()
     *  @brief Construct an uninitialised RenderTarget.
     ***
     *  @fn RenderTarget::RenderTarget(RenderTarget&& other)
     *  @brief Move constructor.
     *  @param other Other instance.
     ***
     *  @fn RenderTarget::RenderTarget(const RenderTarget& other) = delete
     *  @brief Deleted copy constructor.
     *  @param other Instance to copy.
     ***
     *  @fn RenderTarget& RenderTarget::operator=(RenderTarget&& other)
     *  @brief Move assignment operator.
     *  @param other Other instance.
     ***
     *  @fn RenderTarget& RenderTarget::operator=(const RenderTarget& other)
     *  @brief Deleted assignment operator.
     *  @param other Other instance.
     ***
     *  @fn int32_t RenderTarget::getId() const
     *  @brief Get the ID of the internal render target.
     ***
     *  @fn const glm::ivec2& RenderTarget::getSize() const
     *  @brief Get the size.
     *  @return The size.
     ***
     *  @fn const Texture& RenderTarget::getTexture() const
     *  @brief Get the texture tied to this RenderTarget.
     * 
     *  Using the Texture returned by this function, the content of the RenderTarget can be displayed on a drawable.
     *  @return The Texture.
     ***
     *  @fn void RenderTarget::create(const glm::ivec2& size, bool smooth = false)
     *  @brief Create a RenderTarget with the given size.
     *
     *  This method has to be called prior to using the RenderTarget. 
     *  Assert/undefined behavior if size is zero or less in any dimension.
     *  @param size Size of the RenderTarget.
     *  @param smooth If this is true, the internal texture used by the RenderTarget will be smoothed using a nearest neighbor algorithm.
     ***
     *  @fn void RenderTarget::destroy()
     *  @brief Release the resources in use by the RenderTarget.
     ***
     *  @fn RenderTarget::~RenderTarget()
     *  @brief Destroy a RenderTarget.
     **/
}
