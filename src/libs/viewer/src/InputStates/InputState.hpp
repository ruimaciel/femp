#ifndef FEMP_VIEWER_INPUTSTATE_HPP
#define FEMP_VIEWER_INPUTSTATE_HPP

class InputStateMachine;
class QMouseEvent;
class BaseViewport;

/**
 * Implements the interface for each state in the state pattern defined by the
 * InputStateMachine class
 */
class InputState {
public:
  virtual ~InputState();

  /**
   * Depending on the state, checks which mouse button has been pressed
   */
  virtual void press(BaseViewport &viewport, QMouseEvent *event,
                     InputStateMachine *input);

  /**
   * Depending on the state, checks which mouse button has been released
   */
  virtual void release(BaseViewport &viewport, QMouseEvent *event,
                       InputStateMachine *input);

  virtual void leftClick(BaseViewport &viewport, QMouseEvent *event,
                         InputStateMachine *input);
  virtual void leftRelease(BaseViewport &viewport, QMouseEvent *event,
                           InputStateMachine *input);
  virtual void rightClick(BaseViewport &viewport, QMouseEvent *event,
                          InputStateMachine *input);
  virtual void rightRelease(BaseViewport &viewport, QMouseEvent *event,
                            InputStateMachine *input);
  virtual void move(BaseViewport &viewport, QMouseEvent *event,
                    InputStateMachine *input);
};

#endif
