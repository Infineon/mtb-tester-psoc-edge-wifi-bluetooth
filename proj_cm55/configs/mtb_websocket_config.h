/*
 * (c) 2026, Infineon Technologies AG, or an affiliate of Infineon
 * Technologies AG. All rights reserved.
 * This software, associated documentation and materials ("Software") is
 * owned by Infineon Technologies AG or one of its affiliates ("Infineon")
 * and is protected by and subject to worldwide patent protection, worldwide
 * copyright laws, and international treaty provisions. Therefore, you may use
 * this Software only as provided in the license agreement accompanying the
 * software package from which you obtained this Software. If no license
 * agreement applies, then any use, reproduction, modification, translation, or
 * compilation of this Software is prohibited without the express written
 * permission of Infineon.
 *
 * Disclaimer: UNLESS OTHERWISE EXPRESSLY AGREED WITH INFINEON, THIS SOFTWARE
 * IS PROVIDED AS-IS, WITH NO WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
 * INCLUDING, BUT NOT LIMITED TO, ALL WARRANTIES OF NON-INFRINGEMENT OF
 * THIRD-PARTY RIGHTS AND IMPLIED WARRANTIES SUCH AS WARRANTIES OF FITNESS FOR A
 * SPECIFIC USE/PURPOSE OR MERCHANTABILITY.
 * Infineon reserves the right to make changes to the Software without notice.
 * You are responsible for properly designing, programming, and testing the
 * functionality and safety of your intended application of the Software, as
 * well as complying with any legal requirements related to its use. Infineon
 * does not guarantee that the Software will be free from intrusion, data theft
 * or loss, or other breaches ("Security Breaches"), and Infineon shall have
 * no liability arising out of any Security Breaches. Unless otherwise
 * explicitly approved by Infineon, the Software may not be used in any
 * application where a failure of the Product or any consequences of the use
 * thereof can reasonably be expected to result in personal injury.
 */

/**
 * @file mtb_websocket_config.h
 * @brief This header sets configuration macros for the WebSocket library.
 *        Copy this file to your application and modify the values as needed.
 */

#ifndef MTB_WEBSOCKET_CONFIG_H_
#define MTB_WEBSOCKET_CONFIG_H_

/******************************************************
 *                 WebSocket Timeouts
 ******************************************************/

/**
 * WebSocket message send timeout in milliseconds.
 * The WebSocket library function returns to the caller immediately if the WebSocket
 * message is sent before the timeout. Otherwise, the function returns failure status
 * at the end of wait time.
 *
 * Default: 1000ms (1 second)
 */
#ifndef MTB_WEBSOCKET_MESSAGE_SEND_TIMEOUT_MS
#define MTB_WEBSOCKET_MESSAGE_SEND_TIMEOUT_MS          ( 1000U )
#endif

/**
 * WebSocket message receive timeout in milliseconds.
 * WebSocket network receive function waits for this timeout value in case partial
 * data is received from the network socket. If complete data is received before
 * this timeout, the function returns immediately.
 *
 * Default: 500ms
 */
#ifndef MTB_WEBSOCKET_MESSAGE_RECEIVE_TIMEOUT_MS
#define MTB_WEBSOCKET_MESSAGE_RECEIVE_TIMEOUT_MS       ( 500U )
#endif

/******************************************************
 *              WebSocket Instance Limits
 ******************************************************/

/**
 * Maximum number of WebSocket client instances supported simultaneously.
 * Each client instance consumes memory for buffers and state management.
 *
 * Default: 2
 */
#ifndef MTB_MAX_NUM_OF_WEBSOCKET_CLIENTS
#define MTB_MAX_NUM_OF_WEBSOCKET_CLIENTS               ( 2U )
#endif

/**
 * Maximum number of concurrent client connections per WebSocket server.
 * This defines how many clients can connect to a single server instance.
 *
 * Default: 5
 */
#ifndef MTB_WEBSOCKET_MAX_CLIENTS_PER_SERVER
#define MTB_WEBSOCKET_MAX_CLIENTS_PER_SERVER           ( 5U )
#endif

/******************************************************
 *               WebSocket Threading
 ******************************************************/

/**
 * Stack size for WebSocket event processing thread in bytes.
 * The event processing thread handles incoming messages and connection events.
 * Additional stack space is allocated when logging is enabled.
 */
#ifndef MTB_WEBSOCKET_EVENT_THREAD_STACK_SIZE
    #ifdef ENABLE_WEBSOCKET_LOGS
        #if defined(__llvm__) && !defined(__ARMCC_VERSION)
            #define MTB_WEBSOCKET_EVENT_THREAD_STACK_SIZE     ( 1024 * 14 )
        #else
            #define MTB_WEBSOCKET_EVENT_THREAD_STACK_SIZE     ( 1024 * 12 )
        #endif
    #else
        #if defined(__llvm__) && !defined(__ARMCC_VERSION)
            #define MTB_WEBSOCKET_EVENT_THREAD_STACK_SIZE     ( 1024 * 12 )
        #else
            #define MTB_WEBSOCKET_EVENT_THREAD_STACK_SIZE     ( 1024 * 10 )
        #endif
    #endif
#endif

/**
 * Priority of the WebSocket event processing thread.
 * Higher priority ensures timely processing of WebSocket events.
 * Increased to HIGH priority for responsive message processing.
 *
 * Options: CY_RTOS_PRIORITY_LOW, CY_RTOS_PRIORITY_NORMAL, CY_RTOS_PRIORITY_HIGH
 */
#ifndef MTB_WEBSOCKET_EVENT_THREAD_PRIORITY
#define MTB_WEBSOCKET_EVENT_THREAD_PRIORITY            ( CY_RTOS_PRIORITY_NORMAL )
#endif

/******************************************************
 *               WebSocket Protocol
 ******************************************************/

/**
 * Maximum WebSocket frame size in bytes.
 * This limits the size of individual WebSocket frames for security and memory management.
 * Frames larger than this will trigger a warning.
 *
 * Default: 65536 bytes (64KB)
 */
#ifndef MTB_WEBSOCKET_MAX_FRAME_SIZE
#define MTB_WEBSOCKET_MAX_FRAME_SIZE                   ( 65536U )
#endif

/**
 * Maximum WebSocket frame chunk size in bytes.
 * This limits the size of individual frame chunks during reception.
 * Large chunks may indicate potential issues or attacks.
 *
 * Default: 8192 bytes (8KB)
 */
#ifndef MTB_WEBSOCKET_MAX_CHUNK_SIZE
#define MTB_WEBSOCKET_MAX_CHUNK_SIZE                   ( 8192U )
#endif

/******************************************************
 *               WebSocket Buffers
 ******************************************************/

/**
 * Size of the internal event queue for WebSocket events.
 * Larger queue can handle bursts of events but consumes more memory.
 *
 * Default: 30 events
 */
#ifndef MTB_WEBSOCKET_EVENT_QUEUE_SIZE
#define MTB_WEBSOCKET_EVENT_QUEUE_SIZE                 ( 30U )
#endif

/******************************************************
 *              WebSocket Statistics
 ******************************************************/

/**
 * Enable WebSocket frame statistics tracking.
 * When enabled, the library tracks detailed frame reception statistics
 * including frame counts, byte counts, and chunk information.
 *
 * Default: 0 (disabled)
 * Options: 0 (disabled), 1 (enabled)
 */
#ifndef MTB_WEBSOCKET_ENABLE_STATISTICS
#define MTB_WEBSOCKET_ENABLE_STATISTICS                ( 0 )
#endif

#endif /* ifndef MTB_WEBSOCKET_CONFIG_H_ */
