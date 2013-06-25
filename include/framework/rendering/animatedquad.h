#pragma once
#include <framework/rendering/quad.h>
#include <framework/rendering/animation.h>
#include <unordered_map>
#include <memory>

namespace windbreeze
{
    class AnimatedQuad : public Quad
    {
        public:
            AnimatedQuad() : Quad() {}
            AnimatedQuad(float w, float h) : Quad(w, h) {}
            void addAnimation(AnimationId id, std::weak_ptr<Animation> animation);
            void setAnimation(AnimationId id);
            virtual void getRenderData(RenderData& renderData, uint32_t time) const override;
            void tick();
            void playAnimation(uint32_t startFrame = 0);
            void stopAnimation();
            void setAnimationFrame(uint32_t frame);
        private:
            std::weak_ptr<Animation> currentAnimation;
            std::unordered_map<AnimationId, std::weak_ptr<Animation> > animations;

            uint32_t clock = 0;
            uint32_t currentFrame = 0;
            bool animate = false;
    };
    /** @addtogroup Render2D
     *@{
     *  @class AnimatedQuad
     *@}
     ***
     *  @class AnimatedQuad
     *  @brief A Quad capable of manipulating its displayed texture by cycling through animation frames.
     ***
     *  @fn AnimatedQuad::AnimatedQuad()
     *  @brief Construct an AnimatedQuad.
     *  
     *  Uses the Quad::Quad() constructor.
     ***
     *  @fn AnimatedQuad::AnimatedQuad(float w, float h)
     *  @brief Construct an AnimatedQuad with the given size.
     *  
     *  Uses the Quad::Quad(float w, float h) constructor.
     *  @param w Width.
     *  @param h Height.
     ***
     *  @fn void AnimatedQuad::addAnimation(AnimationId id, std::weak_ptr<Animation> animation)
     *  @brief Add an animation.
     * 
     *  After an animation is added, the animation can be set and played using AnimatedQuad::setAnimation and AnimatedQuad::playAnimation.
     *  @param id Id to be used to refer to the animation.
     *  @param animation Pointer to the animation to add. Pointers to animations can be gotten from the AnimationManager.
     ***
     *  @fn void AnimatedQuad::setAnimation(AnimationId id)
     *  @brief Change the current animation.
     *
     *  When an animation is set, it will start off still at the first frame. For an animation to play, the function AnimatedQuad::playAnimation has to be called after an animation is set.
     *  @param id Id of the animation to set.
     ***
     *  @fn virtual void AnimatedQuad::getRenderData(RenderData& renderData, uint32_t time) const override
     *  @brief Overrides Quad::getRenderData.
     *  @param renderData See Quad::getRenderData.
     *  @param time See Quad::getRenderData.
     ***
     *  @fn void AnimatedQuad::tick()
     *  @brief Advance the animation one tick.
     *  
     *  This function should always be called on all AnimatedQuad instances every frame as it acts as the clock which drives the animation logic. If it isn't called, no animations will animate.
     ***
     *  @fn void AnimatedQuad::playAnimation(uint32_t startFrame = 0)
     *  @brief Start the animation sequence for the current set animation.
     *  @param startFrame Animation frame from which the sequence should start. Default is 0.
     ***
     *  @fn void AnimatedQuad::stopAnimation()
     *  @brief Stop the current animation.
     *
     *  This makes the AnimatedQuad constantly display the frame it was up to in the animation sequence when the animation was stopped.
     ***
     *  @fn void AnimatedQuad::setAnimationFrame(uint32_t frame)
     *  @brief Set the animation frame.
     *  @param frame Frame to set it to.
     **/
}
