#include "ppb_flash_message_loop.h"
#include <ppapi/c/pp_errors.h>
#include <stdlib.h>
#include "trace.h"
#include "tables.h"
#include "pp_resource.h"


PP_Resource
ppb_flash_message_loop_create(PP_Instance instance)
{
    struct pp_instance_s *pp_i = tables_get_pp_instance(instance);
    if (!pp_i)
        return 0;
    PP_Resource message_loop = pp_resource_allocate(PP_RESOURCE_FLASH_MESSAGE_LOOP, pp_i);
    struct pp_flash_message_loop_s *fml =
                        pp_resource_acquire(message_loop, PP_RESOURCE_FLASH_MESSAGE_LOOP);

    fml->loop = g_main_loop_new(NULL, FALSE);

    pp_resource_release(message_loop);
    return message_loop;
}

void
ppb_flash_message_loop_destroy(void *p)
{
    struct pp_flash_message_loop_s *fml = p;
    g_main_loop_unref(fml->loop);
}

PP_Bool
ppb_flash_message_loop_is_flash_message_loop(PP_Resource resource)
{
    return pp_resource_get_type(resource) == PP_RESOURCE_FLASH_MESSAGE_LOOP;
}

int32_t
ppb_flash_message_loop_run(PP_Resource flash_message_loop)
{
    struct pp_flash_message_loop_s *fml =
                        pp_resource_acquire(flash_message_loop, PP_RESOURCE_FLASH_MESSAGE_LOOP);
    if (!fml)
        return PP_ERROR_BADRESOURCE;
    GMainLoop *loop = fml->loop;
    pp_resource_release(flash_message_loop);
    g_main_loop_run(loop);
    return PP_OK;
}

void
ppb_flash_message_loop_quit(PP_Resource flash_message_loop)
{
    struct pp_flash_message_loop_s *fml =
                        pp_resource_acquire(flash_message_loop, PP_RESOURCE_FLASH_MESSAGE_LOOP);
    GMainLoop *loop = fml->loop;
    pp_resource_release(flash_message_loop);
    g_main_loop_quit(loop);
}


// trace wrappers
TRACE_WRAPPER
PP_Resource
trace_ppb_flash_message_loop_create(PP_Instance instance)
{
    trace_info("[PPB] {full} %s instance=%d\n", __func__+6, instance);
    return ppb_flash_message_loop_create(instance);
}

TRACE_WRAPPER
PP_Bool
trace_ppb_flash_message_loop_is_flash_message_loop(PP_Resource resource)
{
    trace_info("[PPB] {full} %s resource=%d\n", __func__+6, resource);
    return ppb_flash_message_loop_is_flash_message_loop(resource);
}

TRACE_WRAPPER
int32_t
trace_ppb_flash_message_loop_run(PP_Resource flash_message_loop)
{
    trace_info("[PPB] {full} %s flash_message_loop=%d\n", __func__+6, flash_message_loop);
    return ppb_flash_message_loop_run(flash_message_loop);
}

TRACE_WRAPPER
void
trace_ppb_flash_message_loop_quit(PP_Resource flash_message_loop)
{
    trace_info("[PPB] {full} %s flash_message_loop=%d\n", __func__+6, flash_message_loop);
    return ppb_flash_message_loop_quit(flash_message_loop);
}


const struct PPB_Flash_MessageLoop_0_1 ppb_flash_message_loop_interface_0_1 = {
    .Create =               TWRAPF(ppb_flash_message_loop_create),
    .IsFlashMessageLoop =   TWRAPF(ppb_flash_message_loop_is_flash_message_loop),
    .Run =                  TWRAPF(ppb_flash_message_loop_run),
    .Quit =                 TWRAPF(ppb_flash_message_loop_quit),
};
