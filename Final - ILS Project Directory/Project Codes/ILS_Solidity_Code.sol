//~~Solidity Code for Incentivizing Valid Use of Energy ~~
//Group: Intelligent Lighting System~~
//Group Member: 
//Abisade Folarin
//Ahsan Ullah Jawad
//Muhammad Fuad Shofly
//Pritam Kumar Patel
//Saeid Panahi


//SPDX-License-Identifier: MIT
pragma solidity ^0.8.13;
//~~declaration of state variables~~
contract intelligent_light {
    receive () external payable {}
    int Pb_value;
    int Rtc_value;
    int Ldr_value;
    int Pir_value;
    uint Time;
    uint Led_status;
    uint validity;
    uint idDigits=16;
    uint idModulus=10^idDigits;
    address payable shipCrew;
    address public shipowner;
    
    //~~struct generation~~
   //--each time of sensors input will be considered as an incident, an incident will have 7 parameters--
    struct Incident{
        uint incident_id;
        int pb_value;
        int rtc_value;
        int ldr_value;
        int pir_value;
        uint led_status;
        uint time_stamp;
    }

    //--all incidents will be stored in the array of Incident--
    Incident[] public incidents;
    
    //--an event will register all incidents, this registry will contain incident index, sensor values and time--
    event incident_register(uint incident_indx, uint time);
    
    
    //--function for adding each incident to Incident Array-- 
    function _new_incident( uint _incident_id, int _pb_value, int _rtc_value, int _ldr_value, int _pir_value, uint _led, uint _time) private {
        incidents.push(Incident(_incident_id, _pb_value, _rtc_value, _ldr_value, _pir_value,_led , _time));
        uint incident_indx=(incidents.length-1);
        emit incident_register( incident_indx, _time);
    }

    //--generating a unique id of each incident using hash function-- 
    function _generateincidentId(int _pb_value,int _rtc_value, int _ldr_value, int _pir_value, uint _led, uint _time) private view returns(uint) {
        uint rand=uint(keccak256(abi.encodePacked(_pb_value, _rtc_value, _ldr_value, _pir_value, _led , _time )));
        return (rand%idModulus);

    }
    //--function for creating incidents and adding them to Incident Array--
    function createincidents(int _pb_value, int _rtc_value, int _ldr_value, int _pir_value, uint _led, uint _time) public {
        
        Pb_value=_pb_value;
        Rtc_value=_rtc_value;
        Ldr_value=_ldr_value;
        Pir_value=_pir_value;
        Led_status= _led;
        Time=_time;

        uint incId=_generateincidentId(Pb_value, Rtc_value, Ldr_value,Pir_value,Led_status,Time);
        _new_incident( incId, Pb_value, Rtc_value, Ldr_value,Pir_value,Led_status,Time);
    } 
   
//--checking the condition of the sensors and getting the output of the led--
//~~in case of no value required, (-1) should be input~~
    function check_validity() public returns(uint) {
        if ( Pb_value==1 && Rtc_value==(-1) && Ldr_value==(-1) && Pir_value==(-1) && Led_status==(1) ){
            return validity=1;
        }else if (Pb_value==0 && Rtc_value>8 && Rtc_value<=20 && Ldr_value<600 && Pir_value==1 && Led_status==(1)){
            return validity=1;
        }else if(Pb_value==0 && (Rtc_value<=8 || Rtc_value>20) && Ldr_value==(-1) && Pir_value==(-1) && Led_status==(1) ){
            return validity=1;
        }else {
            return validity=0;
            
        }
        
    }

    function Validity() public view returns(uint){
        return validity;
    }
    
    //--function for receing wei from ship ownner to this contract--
    mapping (address=> uint) totalreceivedwei;
    function receivewei() external payable {
        require(msg.value>=500,"Please send atleast 500 wei");
        shipowner=msg.sender;
        totalreceivedwei[msg.sender]+=msg.value;

    }
    //~~function for checking balance of the contract~~
    function checkbalance() external view returns(uint){
        return address(this).balance;
    }
     
    //--function for sending 100 wei from this contract to the ship crew--
    function sendwei(address payable _shipCrew)  payable external  {
        _shipCrew.transfer(msg.value);
        require((validity==1),"Invalid reason. They do not deserve incentive");
        require(address(this).balance>=100,"Insufficient wei, Please add more wei to the contract");
    }
 
}

