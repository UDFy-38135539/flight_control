#include "config.h"

char init_receiver(uint8_t tx_pin, uint8_t rx_pin)
{
    {
      return FLAG_ERR_UNKN;
    }
  return FLAG_OK;
}

char receiver_wait2pair(unsigned int pairing_timeout_s)
{
   {
    return FLAG_OK;
   }
    return FLAG_PAIRING_TIMEOUT;
}