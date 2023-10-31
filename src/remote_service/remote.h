
#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>

#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/bluetooth/uuid.h>
#include <zephyr/bluetooth/gatt.h>
#include <zephyr/bluetooth/hci.h>

/** @brief UUID of the Remote Service. **/
#define BT_UUID_REMOTE_SERV_VAL \
	BT_UUID_128_ENCODE(0xe9ea0001, 0xe19b, 0x482d, 0x9293, 0xc7907585fc48)

/** @brief UUID of the Button Characteristic. **/
#define BT_UUID_REMOTE_BUTTON_CHRC_VAL \
	BT_UUID_128_ENCODE(0xe9ea0002, 0xe19b, 0x482d, 0x9293, 0xc7907585fc48)

/** @brief UUID of the Message Characteristic. **/
#define BT_UUID_REMOTE_MESSAGE_CHRC_VAL \
	BT_UUID_128_ENCODE(0xe9ea0003, 0xe19b, 0x482d, 0x9293, 0xc7907585fc48)

#define BT_UUID_REMOTE_SERVICE          BT_UUID_DECLARE_128(BT_UUID_REMOTE_SERV_VAL)
#define BT_UUID_REMOTE_BUTTON_CHRC 	    BT_UUID_DECLARE_128(BT_UUID_REMOTE_BUTTON_CHRC_VAL)
#define BT_UUID_REMOTE_MESSAGE_CHRC     BT_UUID_DECLARE_128(BT_UUID_REMOTE_MESSAGE_CHRC_VAL)



enum bt_button_notifications_enabled {
	BT_BUTTON_NOTIFICATIONS_ENABLED,
	BT_BUTTON_NOTIFICATIONS_DISABLED,
};

struct bt_remote_service_cb {
	void (*notif_changed)(enum bt_button_notifications_enabled status);
    void (*data_received)(struct bt_conn *conn, const uint8_t *const data, uint16_t len);
};


void request_mtu_exchange(struct bt_conn *conn);
int send_button_notification(struct bt_conn *conn);
void set_accel_status(int8_t x_int, int8_t x_dec, int8_t y_int, int8_t y_dec, int8_t z_int, int8_t z_dec, uint16_t ppg, int count);
int bluetooth_init(struct bt_conn_cb *bt_cb, struct bt_remote_service_cb *remote_cb);
