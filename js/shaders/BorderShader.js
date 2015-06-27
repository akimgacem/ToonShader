THREE.BorderShader = {
	uniforms: {
		offset:{type: "f", value: 1}               
	},
	vertexShader: [
 		"uniform float offset;",
            
        "void main() {",
           "vec4 pos = modelViewMatrix * vec4( position + normal * offset, 1.0 );",
           "gl_Position = projectionMatrix * pos;",
        "}"

	].join("\n"),

	fragmentShader: [
		"void main(){",
                "gl_FragColor = vec4( 1.0, 0.0, 0.0, 1.0 );",
        "}"
	
	].join("\n")

}; 
