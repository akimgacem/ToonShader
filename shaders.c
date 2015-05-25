varying vec3 vNormal;
varying vec3 vViewPosition;

void main() {
	gl_Position = projectionMatrix * modelViewMatrix * vec4( position, 1.0 );
	vNormal = normalize(normalMatrix * normal);
	vec4 mvPosition = modelViewMatrix * vec4( position, 1.0 );
	vViewPosition = -mvPosition.xyz;
}




uniform vec3 uMaterialColor;
uniform vec3 uDirLightPos;
uniform vec3 uDirLightColor;

uniform float uKd;
uniform float uBorder;

varying vec3 vNormal;
varying vec3 vViewPosition;

void main(){
	vec4 lDirection = viewMatrix * vec4( uDirLightPos, 0.0 );
	vec3 lVector = normalize( lDirection.xyz );
	vec3 normal = normalize( vNormal );
						
	float diffuse = dot( normal, lVector );
	
	if (diffuse > 0.8){diffuse = 1.0;}
	else if(diffuse > 0.4){diffuse = 0.8;}
	else if(diffuse > 0.0){diffuse = 0.6;}
	else if(diffuse > -0.3){diffuse = 0.4;}
	else{diffuse = 0.2;}

	gl_FragColor = vec4( uKd * uMaterialColor * uDirLightColor * diffuse, 1.0 );
}






