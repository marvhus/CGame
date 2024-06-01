#include <Engine/Core/engine.h>
#include <Engine/Core/event.h>
#include <Engine/Logger/logger.h>

void update(float delta);
void render(float delta);
void handle_event(Event event);

int main(int argc, char **argv)
{
    Engine engine = {
        .window_title = "Template",
        .window_width = 1280,
        .window_height = 720,
        .background_color = 0x181818FF,

        .update_callback = update,
        .render_callback = render,
        .handle_event_callback = handle_event,
    };
    eng_log(LL_INFO, "Hello, World!\n");
    eng_start(engine);
}

void update(float delta)
{
}

void render(float delta)
{

}

void handle_event(Event event)
{

}
