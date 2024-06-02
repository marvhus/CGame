#include <CGame/Core/engine.h>
#include <CGame/Core/event.h>
#include <CGame/Logger/logger.h>

void update(float delta);
void render(float delta);
void handle_event(CG_Event event);

int main(int argc, char **argv)
{
    CG_Engine engine = {
        .window_title = "Template",
        .window_width = 1280,
        .window_height = 720,
        .background_color = 0x181818FF,

        .update_callback = update,
        .render_callback = render,
        .handle_event_callback = handle_event,
    };
    cg_log_log(CG_LOG_INFO, "Hello, World!");
    cg_log_log(CG_LOG_DEBUG, "Starting engine.");
    cg_core_run(engine);
}

void update(float delta)
{
}

void render(float delta)
{

}

void handle_event(CG_Event event)
{
}
