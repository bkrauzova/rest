This document proposes new structure of REST API

NOTE: this is just to give brief overview of the approach I chose. It's not complete.

TODO: alerts, maybe admin and sys stuff as well

### ASSETS
  * /assets					# GET
  * /asset/datacenters			 	# GET
  * /asset/rooms				# GET
  * /asset/racks				# GET
  * /asset/devices				# GET
  * /asset/groups				# GET
  * /asset/device/upses			 	# GET
  * /asset/<asset-id>			 	# GET, DELETE (PUT, POST - both done by csv import now)

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
  * /asset/<dc_id>/powerchain			# GET
    * (/asset/topology/powerchain?id=)		# currently topology call

### METRICS
  * /metric/current_metrics?ids=1,2,3,4		# GET, more, than 1 asset?!
    * (/asset/<asset-id>/current_metrics)
  * /metric/rack_total?ids=1,2,3&type=total_power,avg_power_last_day          # GET
  * /metric/datacenter_indicators?ids=1,2,3&type=power,avg_power_last_day     # GET, dc_statistics?
  * /metrics/averages?type=csv&id=1,23&start=445456...			  # GET exp. avgs
    * (/metric/averages/cs)
  * /metric/uptime?ids=1,2,3			# GET, does it make sence to have more than 1 id in the call?