/*
 * Generated by erpcgen 1.8.1 on Wed May 26 08:57:10 2021.
 *
 * AUTOGENERATED - DO NOT EDIT
 */


#include "erpc_client_manager.h"
#include "erpc_port.h"
#include "erpc_codec.hpp"
extern "C"
{
#include "secure_ml.h"
}

#if 10801 != ERPC_VERSION_NUMBER && 0
#error "The generated shim code version is different to the rest of eRPC code."
#endif

using namespace erpc;
using namespace std;

extern ClientManager *g_client;


// SecureMLService interface inference function client shim.
int32_t inference(int32_t ifm, int32_t ofm)
{
    erpc_status_t err = kErpcStatus_Success;

    int32_t result;

#if ERPC_PRE_POST_ACTION
    pre_post_action_cb preCB = g_client->getPreCB();
    if (preCB)
    {
        preCB();
    }
#endif

    // Get a new request.
    RequestContext request = g_client->createRequest(false);

    // Encode the request.
    Codec * codec = request.getCodec();

    if (codec == NULL)
    {
        err = kErpcStatus_MemoryError;
    }
    else
    {
        codec->startWriteMessage(message_type_t::kInvocationMessage, kSecureMLService_service_id, kSecureMLService_inference_id, request.getSequence());

        codec->write(ifm);

        codec->write(ofm);

        // Send message to server
        // Codec status is checked inside this function.
        g_client->performRequest(request);

        codec->read(result);

        err = codec->getStatus();
    }

    // Dispose of the request.
    g_client->releaseRequest(request);

    // Invoke error handler callback function
    g_client->callErrorHandler(err, kSecureMLService_inference_id);

#if ERPC_PRE_POST_ACTION
    pre_post_action_cb postCB = g_client->getPostCB();
    if (postCB)
    {
        postCB();
    }
#endif


    if (err != kErpcStatus_Success)
    {
        result = -1;
    }

    return result;
}
