module device_manager;

// TODO

void DeviceManager::PowerSw() {
    if (m_deviceState == DeviceStateType::OFF)
    {
        // 设备上电
        m_deviceState = DeviceStateType::INITIAL;
        // 设备初始化
        // Initialize();
        EmitEvent(DeviceEventType::PowerOnEvent);
    } else {
        // 设备下电
        m_deviceState = DeviceStateType::OFF;
        // 设备释放
        // Release();
        EmitEvent(DeviceEventType::PowerOffEvent);
    }
}

void DeviceManager::PowerReset() {
    if (m_deviceState != DeviceStateType::OFF)
    {
        EmitEvent(DeviceEventType::PowerResetEvent);
    }
}