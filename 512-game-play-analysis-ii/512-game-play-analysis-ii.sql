select distinct player_id, first_value(device_id) over (partition by player_id order by event_date) device_id
from activity