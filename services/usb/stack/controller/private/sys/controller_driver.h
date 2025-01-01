

/*25*//*<bdc96>*/typedef struct _usb_controller_driver_ctrl usb_controller_driver_ctrl_t;
/*26*//*<bdcd2>*/typedef struct _usb_controller_driver usb_controller_driver_t;

/*42*//*<bdcdd>*/struct _usb_controller_driver {
    obj_t* obj; //0
    void* dll_hdl; //4
    void* resmgr_hdl; //8
    io_usb_otg_dll_entry_t* entry_point; //12
    char* dll_name; //16
    char* args; //20
    uint32_t flags; //24
    uint32_t num_ctrl; //28
    obj_pool_t* controller_pool; //32
    usb_controller_entry_t* usb_controllers[20]; //36
    char* cargs[20]; //116
    usb_controller_driver_ctrl_t* controller_driver_ctrl; //196
    usb_hwi_driver_t* hwi_driver; //200
    //204
};

/*83*//*<bdca1>*/struct _usb_controller_driver_ctrl {
    uint32_t flags; //0
    obj_pool_t* pool; //4
    struct _usb_core_ctrl* core_ctrl; //8
    //12
};


