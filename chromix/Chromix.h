#ifndef MOTIONBOX_CHROMIX_CHROMIX_H_
#define MOTIONBOX_CHROMIX_CHROMIX_H_

namespace Chromix {
enum InitializeResult { InitializeFailure, InitializeSuccess, InitializeAlready };

// Chromix must be initialized, used, and shutdown from the same thread
InitializeResult initialize();
void shutdown();    
}
#endif