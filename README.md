This document proposes new structure of REST API

NOTE: this is just to give brief overview of the approach I chose. It's not complete.

TODO: alerts, topo, maybe admin and sys stuff as well

### ASSETS

  URI					|       methods + some desc.
-----------------------------------------------------------------------
   /assets				| GET, POST (create)
   /assets/datacenters			| GET
   /assets/rooms			| GET
   /assets/racks			| GET
   /assets/devices			| GET
   /assets/groups			| GET
   /assets/device/upses			| GET
   /assets/<asset_id>			| GET, DELETE (PUT - done by csv import now)

#### EXP/IMP

  URI					|       methods + some desc.
-----------------------------------------------------------------------
   /assets/csv				| GET - export
    * (/assets?type=csv)		|
   /assets/csv				| POST - import
    * (/assets?type=csv)		|

### (ASSETS-PW CHAIN)

  URI					|       methods + some desc.
-----------------------------------------------------------------------
   /assets/<dc_id>/powerchain		| GET
    * (/assets/topology/powerchain?id=)	| currently topology call

### METRICS IN ASSET ns

  URI					|       methods + some desc.
-----------------------------------------------------------------------
   /assets/<dc_id>/uptime               |
   /assets/<id_rack>/power?type=avg_power_last_day,avg_power_last_week ...    | GET, rack total is does not return much info, but not consistent?
   /assets/<id_dc>/indicators/<type>					      | GET
   /assets/<asset_id>/currect_metrics   |


### TOPOLOGY IN ASSET ns - TODO
  * /assets/topology?from=sth&recursive=sth..	# GET, currently - topology/location

  parameter | description
  ----------|-------------
  from	    | starting point of requested topology
  to        | end point of the topology
  recursive | true/false recursive walk
  feed_by   | who knows
  filter    | filter by asset type

  * /assets/topology/power?filter,from,to,..  	# GET
    * (/asset/power_topology?filtr=...from)


______________________________________________________________________________________________________________________________

### METRICS
  * /metric/current_metrics?ids=1,2,3,4		# GET, more, than 1 asset?!
    * (/asset/<asset-id>/current_metrics)
  * /metric/rack_total?ids=1,2,3&type=total_power,avg_power_last_day          # GET
  * /metric/datacenter_indicators?ids=1,2,3&type=power,avg_power_last_day     # GET, dc_statistics?
  * /metrics/averages?type=csv&id=1,23&start=445456...			  # GET exp. avgs
    * (/metric/averages/cs)

### ALERTS
  * /alerts				        # GET, aletrs with state (all, active, ack-wip...)
  * /alerts/<alert_state>
  * /alerts/<alert_state>/<asset_id>
  * /alerts/<asset_id>/<alert_state>/<_recursive>
  * /alerts/rules				# GET, POST
  * /alerts/rules/<rule_type>				# GET, patter/threshold/all/ single
  * /alerts/rules/<rule_name>				# GET, PUT (update) skipping par. rule_class (i have no idea what it is good for)
  * /alerts/<asset_id>/<rule_name> 		# PUT, json ex. {"state":"ignore"}

### ADMIN