This document proposes new structure of REST API

NOTE: this is just to give brief overview of the approach I chose. It's not complete.

TODO: alerts, maybe admin and sys stuff as well

### ASSETS
  * /assets					# GET
  * /assets/datacenters			 	# GET
  * /assets/rooms				# GET
  * /assets/racks				# GET
  * /assets/devices				# GET
  * /assets/groups				# GET
  * /assets/device/upses			 	# GET
  * /assets/<asset-id>			 	# GET, DELETE (PUT, POST - both done by csv import now)

#### EXP/IMP
  * /assets/csv					# GET - export
    * (/assets?type=csv)
  * /assets/csv				 	# POST - import
    * (/assets?type=csv)


### TOPOLOGY
  * /asset/topology?from=sth&recursive=sth..	# GET, currently - topology/location

  parameter | description
  ----------|-------------
  from	    | starting point of requested topology
  to        | end point of the topology
  recursive | true/false recursive walk
  feed_by   | who knows
  filter    | filter by asset type

  * /asset/topology/power?filter,from,to,..  	# GET
    * (/asset/power_topology?filtr=...from)


### (ASSETS-PW CHAIN)
  * /assets/<dc_id>/powerchain			# GET
    * (/assets/topology/powerchain?id=)		# currently topology call

## METRICS IN ASSET ns
   * /assets/<id>/uptime
   * /assets/<id-rack>/power?type=avg_power_last_day,avg_power_last_week ...    # GET, rack total is does not return much info
   * /assets/<id-dc>/indicators/<type>					       	      # GET
   * /assets/<id>/currect_metrics

### METRICS
  * /metric/current_metrics?ids=1,2,3,4		# GET, more, than 1 asset?!
    * (/asset/<asset-id>/current_metrics)
  * /metric/rack_total?ids=1,2,3&type=total_power,avg_power_last_day          # GET
  * /metric/datacenter_indicators?ids=1,2,3&type=power,avg_power_last_day     # GET, dc_statistics?
  * /metrics/averages?type=csv&id=1,23&start=445456...			  # GET exp. avgs
    * (/metric/averages/cs)

### ALERTS
  * /alerts				        # GET, aletrs with state (all, active, ack-wip...)
  * /alerts/<state>
  * /alerts/<state>/<asset-id>
  * /alerts/<asset-id>/<state>/<recursive>
  * /alerts/rules				# GET, POST
  * /alerts/rules/<type>				# GET, patter/threshold/all/ single
  * /alerts/rules/<name>				# GET, PUT (update) skipping par. rule_class (i have no idea what it is good for)
  * /alerts/<asset-id>/<rule_name> 		# PUT, json ex. {"state":"ignore"}



### ADMIN